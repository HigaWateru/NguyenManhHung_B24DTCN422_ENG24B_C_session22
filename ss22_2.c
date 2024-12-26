#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char accout[100];
    char pass[100];
}accout;
accout a[100];
int choose,n,tg,vt;
char checkPass[100],checkName[100],pass[100];
void cinString(char *s, int length){
    fgets(s,length,stdin);
    if(strlen(s)>0&&s[strlen(s)-1]=='\n')s[strlen(s)-1]='\0';
}
int main(){
    FILE *finp=fopen64("accout.bin","rb");
    FILE *fout=fopen64("accout.bin","wb");
    do{
        printf("MENU\n1.Dang nhap\n2.Dang ky\n3.Thoat\nLua chon cua ban: ");
        scanf("%d",&choose);
        getchar();
        switch (choose){
            case 1:
                tg=0;
                fread(&n,sizeof(int),1,fout);
                fread(a,sizeof(accout),n,fout);
                fclose(finp);
                printf("DANG NHAP\nTen dang nhap: ");
                cinString(checkName,100);
                for(int i=0;i<n;i++)if(strcmp(checkName,a[i].accout)==0){
                    tg=1;
                    vt=i;
                }
                if(!tg)printf("Khong tim thay tai khoan!\n");
                else{
                    printf("Mat khau: ");
                    cinString(checkPass,100);
                    if(strcmp(checkPass,a[vt].pass)==0)printf("Dang nhap thanh cong!\n");
                    else printf("Sai mat khau!\n");
                }
                break;
            case 2:
                tg=0;
                printf("Dang ky tai khoan moi:\n");
                fread(&n,sizeof(int),1,fout);
                fread(a,sizeof(accout),n,fout);
                if(n>=100)printf("He thong da du nguoi dang ki!\n");
                else{
                    printf("Ten dang nhap: ");
                    cinString(checkName,100);
                    for(int i=0;i<n;i++)if(strcmp(checkName,a[i].accout)==0){
                        printf("Ten dang nhap da ton tai!\n");
                        tg=1;
                        break;
                    }
                    if(!tg){
                        printf("Mat khau: ");
                        cinString(pass,100);
                        printf("Nhap lai mat khau: ");
                        cinString(checkPass,100);
                        if(strcmp(pass,checkPass)!=0)printf("Mat khau khong hop le!\n");
                        else{
                            strcpy(a[n].accout,checkName);
                            strcpy(a[n].pass,pass);
                            n++;
                            fwrite(&n,sizeof(int),1,fout);
                            fwrite(a,sizeof(accout),n,fout);
                            fclose(fout);
                            printf("Dang ky tai khoan thanh cong!\n");
                        }
                    }
                }
            default:
                break;
        }
    }while(choose!=3);
}