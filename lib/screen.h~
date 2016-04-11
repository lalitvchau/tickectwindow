#include<stdio.h>
#include"admin.h"
#include"ticket.h"
#include"status.h"
void viewTrains(){
     char name[100];
     int number;
     float rate;
     int ac,sleep;
     int noSt;
     char sta[15][100];
     int hh[15];
     int mm[15];
     int i,size=0,len=0;
     FILE *fpr1;
     printf("\n\n\n\n\n\n-------------------------------------------------------------------------------");
     printf("\n\t\t\tTrains Details");
     printf("\n-------------------------------------------------------------------------------");
     if(fpr1=fopen("lib/files/Trains/trainList","r"))
     {
           

           while( !feof(fpr1) ){ 
                     fscanf(fpr1,"%d %s %f %d %d %d",&number,name,&rate,&ac,&sleep,&noSt);
                       for(i=0;i<noSt;i++){

                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                           }
                     size++;}
           fclose(fpr1);
           fpr1=fopen("lib/files/Trains/trainList","r");

          

           while( --size>0 ){ 
                     fscanf(fpr1,"%d %s %f %d %d %d",&number,name,&rate,&ac,&sleep,&noSt);
                     printf("\n Train Number =%d\t Train Name =%s Stations are \n-------------------------------------------------------------- \n",number,name);
                       for(i=0;i<noSt;i++){
                                 printf("\t");
                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                                 if(i==0) printf("Source  : ");
                                 if(i==noSt-1) printf("Desitination : ");
                                 printf("%s %2d : %2d o'clock",sta[i],hh[i],mm[i]);
                           }
                     printf("\n--------------------------------------------------------------");
                 }
           fclose(fpr1);
      }
     else {
           printf("\n\tSystem Error ................... !");
      }
     printf("\n-------------------------------------------------------------------------------");
     printf("\n\t\t\tTrain Details Exit ..... ");
     printf("\n-------------------------------------------------------------------------------");
}
/*This method display the Main Window 
* 
*/
void dispScreen(){
   int choice=0;
   while(1){
      printf("\n\n\n=================================================================================\n");
      printf("The Main Menus :: Choices are Follwing\n-------------------------------------------\n\t\t1. Ticket Reservation\n\t\t2. Ticket Cancel\n\t\t3. Tickets and Trains Status\n\t\t4. Train Details Chart \n\t\t5. Admin Login\n\t\t6. Exit");
      printf("\n=================================================================================\n");   
      printf("\nPlease Enter The Choice = ");
      scanf("%d",&choice);
      printf("\n=================================================================================\n");

      switch(choice){
           case 1 : bookTicket();
                    break;
           case 2 : break;
           case 3 : showStatus();
                    break;
           case 4 : viewTrains();
                    break;
           case 5 : doAdmin();
                    break;
           case 6 : printf("\nSystem Is Exiting ....... !\n");
                    printf("\n=================================================================================\n");
                    return;
                    break;
           default : printf("\nWrong Choice ! Try Again .... Choice Should be between 1 to 6\n");
                       break;
      }
      printf("\n=================================================================================\n");
   }
   return;
}
