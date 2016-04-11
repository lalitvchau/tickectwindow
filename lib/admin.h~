#include<stdio.h>
#include"time.h"
#include"data.h"
void adminScreen();
void doAdmin();
void changePassword();
void addTrain();
void removeTrain();
void changePassword(){
    char pass[20],pass1[20];
    FILE *fpr;
    printf("\n\n\n\n\tChange Password"); 
    printf("\n\t\t\tPlease Enter Your Current Password : ");
    scanf("%s",pass);
    if(doLogin(pass)==1){
            printf("\n\t\t\tPlease Enter Your New Password : ");
            scanf("%s",pass);
            printf("\n\t\t\tPlease Enter Conform Password : ");
            scanf("%s",pass1);
            if(isPass(pass,pass1)==1){
                 fpr=fopen("lib/files/pass","w");
                 if(!fpr) { printf("\nSorry ! System Error"); return;}
                 fprintf(fpr,"%s",pass);
                 printf("\n\t\t\tPassword Successfully Updated ! ");
                 fflush(fpr);
                 fcloseall();
                 return;
            }
            else{
                  printf("\n\tSorry ! New and Comform passwords Does not Match ! Try Again.........");
                  return;
            }
    }
    else{
       printf("\n\tSorry ! Password Does not Match ! Try Again.........");
       return;
    }
}

void addTrain(){
     
     char name[50],sta[15][100];
     int noSt;
     int hh[15];
     int i=0;
     int mm[15],number,ac,sleep;
     float rate;
     FILE *fprt;

     printf("\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
     printf("\n\t\t\t\tNew Train Add Window");
     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
     printf("\n\tPlease Enter Detail of New Train");
     printf("\n\t\tTrain Number = ");
     scanf("%d",&number);
     printf("\n\t\tName =");
     scanf("%s",name);
     printf("\n\t\tRate per Railway Station Gen. Ticket= ");
     scanf("%f",&rate);
     printf("\n\t\tTotal Number AC Class Seats =");
     scanf("%d",&ac);
     printf("\n\t\tTotal Number of Sleeper Class Seats = ");
     scanf("%d",&sleep);
     printf("\n\t\tTotal Station : ");
     scanf("%d",&noSt);
     for(i=0;i<noSt;i++){
          printf("\n\t\tStation[%d] = ",i+1);
          scanf("%s",sta[i]);
          printf("\n\t\tStation[%d] Time = \n\t\tHours =",i+1);
          scanf("%d",&hh[i]);
          if(isHH(hh[i])==0){ printf("\n\t\tPlease ReEnter");i--;continue; }
          printf("\n\t\tMinute =");
          scanf("%d",&mm[i]);
          if(isMM(mm[i])==0){ printf("\n\t\tPlease ReEnter");i--;continue; }
     }
     fprt=fopen("lib/files/Trains/trainList","a");
      if(fprt){
          fprintf(fprt,"%d %s %f %d %d %d",number,name,rate,ac,sleep,noSt);
           for(i=0;i<noSt;i++){
             fprintf(fprt," %s %d %d",sta[i],hh[i],mm[i]);
            }
          fprintf(fprt,"\n");
          fclose(fprt);
         printf("\n\t\tSuccessfully ! Added New Train the list.....................");
     }
     else{
         printf("\n\t\tSystem Error ! .....................");
      return;
     }
     printf("\nExit Add Train Window\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
void adminScreen(){
      int ch=0;
      while(1){
         printf("\n...............................................................................");
         printf("\n\t\tAdmin Window");
         printf("\n...............................................................................");
         printf("\nChoices :  \n\t1. Add Train\n\t2. Remove Train\n\t3. Change Admin Password\n\t4. Go to Main Menu");
         printf("\n...............................................................................");
         printf("\n\tEnter Your Choise = ");
         scanf("%d",&ch);
         switch(ch){
           case 1 : addTrain();
                    break;
           case 2 : removeTrain();
                    break;
           case 3 : changePassword();
                    break;
           case 4 : printf("\nSystem go back Main Menu ....... !\n");
                    printf("\n=================================================================================\n");
                    return;
                    break;
           default : printf("\nWrong Choice ! Try Again .... Choice Should be between 1 to 5\n");
                       break;
          }
      }
             printf("\n...............................................................................");
}
void doAdmin(){
   if(login()==1){
       adminScreen();
   }
    else{
         printf("\n\tSystem Wrong !");
   }
}

void removeTrain(){
     int flag=0;
     int num;
     char name[50],sta[15][100];
     int noSt;
     int hh[15];
     int i=0;
     int mm[15],number,ac,sleep;
     float rate;
     int size=0;
     FILE *fpr1,*fpr2=fopen("lib/files/Trains/temp","w");
      printf("\n**************************************************************************");
      printf("\n\t\tRemove Train Window");
      printf("\n**************************************************************************");
      printf("\n\t\tPlease Enter The Train Number =");
      scanf("%d",&num);
       
      if(fpr1=fopen("lib/files/Trains/trainList","r")){
           while( !feof(fpr1) ){ 
                     fscanf(fpr1,"%d %s %f %d %d %d",&number,name,&rate,&ac,&sleep,&noSt);
                       for(i=0;i<noSt;i++){

                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                           }
                     size++;}
           fclose(fpr1);
           fpr1=fopen("lib/files/Trains/trainList","r");
           while( size-->1 ){
                      fscanf(fpr1,"%d %s %f %d %d %d",&number,name,&rate,&ac,&sleep,&noSt);
                      if(number!=num)
                      fprintf(fpr2,"%d %s %f %d %d %d",number,name,rate,ac,sleep,noSt);
                      for(i=0;i<noSt;i++){

                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                             if(number!=num)
                                 fprintf(fpr2," %s %d %d",sta[i],hh[i],mm[i]);
                           }
                     if(number!=num)
                             fprintf(fpr2,"\n");
                     else flag=1;
                      
               }
               fcloseall();
               if(copyFiles("lib/files/Trains/temp","lib/files/Trains/trainList")!=1) {printf("\n\nSYSTEM ERROR !"); return;}
               if(flag==1) printf("\n\t\t\tThe Train Has been Removed !...");
               else printf("\n\t\t\tThe Given Number Train Not Available !........");
      }
      else{
           printf("\n\t\tSystem Error...................!");
      }


      printf("\nExit Remove Train\n**************************************************************************");
}
