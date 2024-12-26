#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char id[10];
    char name[30];
    int age;
}sinhvien;
sinhvien a[100];
char checkID[10];
void cinString(char *s, int length){
    fgets(s,length,stdin);
    if(strlen(s)>0&&s[strlen(s)-1]=='\n')s[strlen(s)-1]='\0';
}
void swap(sinhvien *a, sinhvien *b){
    sinhvien temp= *a;
    *a=*b;
    *b=temp;
}
void getLastName(char *name, char *lastName){
    char *i=strrchr(name,' ');
    if (i!=NULL)strcpy(lastName,i+1);
    else strcpy(lastName,name);
}
void selectionSort(sinhvien *a, int size) {
    char lastName1[50],lastName2[50];
    for (int i=0;i<size-1;i++)for(int j=i+1;j<size;j++){
        getLastName(a[i].id,lastName1);
        getLastName(a[j].id,lastName2);
        if (strcmp(lastName1,lastName2)>0)swap(&a[i],&a[j]);
    }
}
int choose,n;
int main(){
    FILE *finp=fopen64("sinhvien.bin","rb");
    FILE *fout=fopen64("sinhvien.bin","wb");
    do{
        printf("...\nLua chon cua ban: ");
        scanf("%d",&choose);
        getchar();
        switch (choose){
            case 1:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                for(int i=0;i<n;i++)printf("%10s | %30s | %3d\n",a[i].id,a[i].name,a[i].age);
                break;
            case 2:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                if(n>100)printf("Danh sach sinh vien da day");
                else{
                    printf("Nhap id sinh vien: ");
                    cinString(a[n].id,100);
                    printf("Ho va ten sinh vien: ");
                    cinString(a[n].name,100);
                    printf("Tuoi: ");
                    scanf("%d",&a[n].age);
                    getchar();
                    n++;
                    fwrite(&n,sizeof(int),1,fout);
                    fwrite(a,sizeof(sinhvien),n,fout);
                    fclose(fout);
                }
                break;
            case 3:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                printf("Nhap id sinh vien can sua: ");
                cinString(checkID,10);
                int tg=0;
                for(int i=0;i<n;i++)if(strcmp(checkID,a[i].id)==0){
                    tg=1;
                    printf("Cap nhat thong tin sinh vien: ");
                    printf("Ho va ten: ");
                    cinString(a[i].name,100);
                    printf("Tuoi: ");
                    scanf("%d",&a[i].age);
                    getchar();
                    printf("Cap nhat thong tin thanh cong!\n");
                    fwrite(&n,sizeof(int),1,fout);
                    fwrite(a,sizeof(sinhvien),n,fout);
                    fclose(fout);
                    break;
                }
                if(!tg)printf("Khong tim thay ma sinh vien!\n");
                break;
            case 4:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                printf("Nhap id sinh vien can xoa: ");
                cinString(checkID,10);
                int tg=0;
                for(int i=0;i<n;i++)if(strcmp(checkID,a[i].id)==0){
                    tg=1;
                    for(int j=i;j<n-1;i++)a[j]=a[j+1];
                    n--;
                    printf("Da xoa thong tin sinh vien!\n");
                    fwrite(&n,sizeof(int),1,fout);
                    fwrite(a,sizeof(sinhvien),n,fout);
                    fclose(fout);
                    break;
                }
                if(!tg)printf("Khong tim thay ma sinh vien!\n");
                break;
            case 5:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                printf("Nhap id sinh vien can tim kiem: ");
                cinString(checkID,10);
                int tg=0;
                for(int i=0;i<n;i++)if(strcmp(checkID,a[i].id)==0){
                    tg=1;
                    printf("Thong tin ma sinh vien %s:\nHo va ten: %s\nTuoi: %d\n",a[i].id,a[i].name,a[i].age);
                    break;
                }
                if(!tg)printf("Khong tim thay ma sinh vien!\n");
                break;
            case 6:
                fread(&n,sizeof(int),1,finp);
                fread(a,sizeof(sinhvien),n,finp);
                fclose(finp);
                selectionSort(&a,100);
                printf("Danh sach sinh vien da sap xep theo id!\n");
            default:
                break;
        }
    }while(choose!=7);
}