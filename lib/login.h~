#include<string.h>
/*This method check whether conform and password are match or not 
* 
*/
int isPass(char *pass, char *repass){
    if(strcmp(pass,repass)==0) return 1;
    else return 0;
}
/*This method check whether enterPassword and password are match or not 
* 
*/
int doLogin(char *pass){
    char ch[20];
    int i=0;  
    FILE *fpr = fopen("lib/files/pass","r");
  
    if(fpr){
        while((ch[i++]=getc(fpr))!=EOF);
        ch[--i]='\0';ch[--i]='\0';
        if(strcmp(pass,ch)==0){
             fclose(fpr);
             return 1;
          }
         fclose(fpr);
        return 0;
    }
    else{
         fclose(fpr);
         return 0;
    }
}
// Login Window Method
int login(){
   int flag=0,flag1=0;
   char pass[20]="xyz", repass[20]="zxy";

  while(1){

        if(flag1>5){
           printf("\nAttempt Over ... System Exiting");
           return 0;
        }

   while(isPass(pass,repass)==0){
        if(flag>5){
           printf("\nAttempt Over ... System Exiting");
           return 0;
        }
        printf("\n\t\t\tEnter Your Password = ");
        scanf("%s",pass);
        printf("\n\t\t\tConform Your Password = ");
        scanf("%s",repass);
        if(isPass(pass,repass)==0) {
                 flag++;
                 printf("\nSorry ! Password and Conform Password Not Matched . Try Agian !\nAttempt = %d\n",flag);
         }
   }
        if(doLogin(pass)==1){
                 printf("\n****************************\n\t\tLogin Success !\n****************************\n\n");
                 break;
        }
        flag1++;
        printf("\n****************************\n\t\tWrong Password !\tAttempt = %d\n\t\tTry Again\n****************************\n",flag1);
        pass[0]='\0';
        
  }
   return 1;
}


