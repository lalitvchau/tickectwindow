#include<stdio.h>
int showTick(char path[], int ticNum,int type){
    int tNum,flag=1,tel,trainNum,SH,SM,DH,DM,dd,yy;
    char fName[50],lName[50],city[50],src[50],tName[50],mm[3],seat[10],des[50];
    float rate;
    FILE *fpr;
//    printf("%s",path);
    if(fpr=fopen(path,"r")){
//      printf("\nABCBC\n");
        while(!feof(fpr)){
            fscanf(fpr,"%d%s%s%s%d%d%s%s%d%d%s%d%d%s%d%d%f%s",&tNum,fName,lName,city,&tel,&trainNum,tName,src,&SH,&SM,des,&DH,&DM,mm,&dd,&yy,&rate,seat);

            if(tNum==ticNum){
                flag=0;
                            fcloseall();
                 break;
            }
        }
     fcloseall();
        if(flag==0){
            
    printf("\n\n\n\n************************************************************");
    if(type==2)  printf("\n\t\tTicket Details\t(Sleeper Class Ticket)");
    if(type==1)  printf("\n\t\tTicket Details\t(AC Class Ticket)");
    printf("\n*************************************************************");
    printf("\nPassenger Name =%s %s",fName,lName);
    printf("\nPassenger City =%s\tCont = %d",city,tel);
    printf("\nTicket Number =%d",ticNum);
    printf("\n_____________________________________________________________");
    printf("\nTrain  = ( %d ) %s ",trainNum,tName);
    printf("\nSource = %s Time - %d:%d o'clock",src,SH,SM);
    printf("\nDestination = %s Time - %d:%d o'clock",des,DH,DM);
    printf("\n\nSheet Number : %s ",seat);
    printf("\n_____________________________________________________________");
    printf("\nDate- %s %d %d     Total Charge : %.2f INR",mm,dd,yy,rate);
    printf("\n*************************************************************\n\n");    
            fcloseall();

            return 1;
        }else   return 0;
    }else{
        return 0;
    }
    return 1;
}
void  isTicAvailable(int dt,int ticNum){
    char path[100];
    char dtt[10];
    
  path[0]='\0';
  
        charDate(dtt,dt);
    if(ticNum/300000==1){
           strcat(path,"lib/files/Tickets/AC/");
           strcat(path,dtt);

           if(showTick(path,ticNum,1)==0) { printf("\nTicket Number :  %d is not Available right now !",ticNum); return; }
    }else if(ticNum/200000==1){
           strcat(path,"lib/files/Tickets/SL/");
           strcat(path,dtt);
           if(showTick(path,ticNum,2)==0) { printf("\nTicket Number :  %d is not Available right now !",ticNum); return; }
    }
    else{
        printf("\n Sorry ! You have Entred Wrong Ticket Number ! Try with new Number");
        return;
    }

}
void isTAvailable(int date,int trNum){
    char fileName[100]="lib/files/Trains/";
    char fileName2[100]="lib/files/Trains/";
    int num=0;
    char tNum[10];
    char cDate[12];
    int total,booked;
    FILE *fpr;
    toChar(tNum,pass.trNum);
    toChar(cDate,date);
      strcat(fileName,tNum);
      strcat(fileName,cDate);
      strcat(fileName,"SL");
      strcat(fileName2,tNum);
      strcat(fileName2,cDate);
      strcat(fileName2,"AC");
    fpr=fopen(fileName,"r");
    if(fpr){
       fscanf(fpr,"%d %d",&total,&booked);
       fclose(fpr);
       pass.sheet=(booked+1);
       printf("Total Sleeper Class Sheet = %d Availble = %d",total,(total-booked));
    
    }
    else
    {
//       fclose(fpr);
       num=findSheet(1,trNum);
       printf("\n\tTotal Sleeper Class Sheet = %d Availble = %d",num,(num));
       fcloseall();
    }
    fpr=fopen(fileName2,"r");
    if(fpr){
       fscanf(fpr,"%d %d",&total,&booked);
       fclose(fpr);
       pass.sheet=(booked+1);
       printf("\n\tTotal AC Class Sheet = %d Availble = %d",total,(total-booked));
    
    }
    else
    {
//       fclose(fpr);
       num=findSheet(2,trNum);
       printf("\n\tTotal AC Class Sheet = %d Availble = %d",num,(num));
       fcloseall();
    }
}

int trainStatus(){
   int trNum,dt,cDt,ptp,len;
   char tnDate[12],dd[2],mm[3],yy[4];
   char temp[11];


     printf("\n----------------------------------------------------------------");
     printf("\n\t\tTrain Status Window");
     printf("\n----------------------------------------------------------------");
     printf("\nEnter the Train Number : ");
     scanf("%d",&trNum);
  while(1){
    while(1){
     tnDate[0]='\0';
     temp[0]='\0';
     printf("\nEnter the Date : ");
     scanf("%s%s%s",mm,dd,yy);
     strcat(tnDate,mm);
     strcat(tnDate," ");
     strcat(tnDate,dd);
     strcat(tnDate," ");
     strcat(tnDate,yy);
     strcpy(temp,__DATE__);
     cDt=intDate(temp);
     dt=intDate(tnDate);
     len=strlen(tnDate);
    
       ptp=(dt/1000000);
       
           if(len<=11&&len>9&&(ptp!=0)) { 
                 if(isDay(((dt%1000000)/10000),ptp,dt%10000)==1) break;
                 printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
                 continue;
           }
           else {
                printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
                continue;
             }
 
          }
             if(isVerify(temp,tnDate)==1){
                  break;
              }
             else {
                  printf("\n Sorry ! You Can not know about train seats available on the %s date Try Again New Date .......",tnDate);
                  continue;
             }
   
     }
     isTAvailable(dt,trNum);
     printf("\n----------------------------------------------------------------");
     printf("\n\t\tTrain Status Window is Exit..............!");
     printf("\n----------------------------------------------------------------");
}
void tickStatus(){
 int ticNum,dt,cDt,ptp,len;
   char tnDate[12],dd[2],mm[3],yy[4];
   char temp[11];


     printf("\n----------------------------------------------------------------");
     printf("\n\t\tTicket Status Window");
     printf("\n----------------------------------------------------------------");
     printf("\nEnter the Ticket Number : ");
     scanf("%d",&ticNum);
  while(1){
    while(1){
     tnDate[0]='\0';
     temp[0]='\0';
     printf("\nEnter Ticket's Date : ");
     scanf("%s%s%s",mm,dd,yy);
     strcat(tnDate,mm);
     strcat(tnDate," ");
     strcat(tnDate,dd);
     strcat(tnDate," ");
     strcat(tnDate,yy);
     strcpy(temp,__DATE__);
     cDt=intDate(temp);
     dt=intDate(tnDate);
     len=strlen(tnDate);
    
       ptp=(dt/1000000);
       
           if(len<=11&&len>9&&(ptp!=0)) { 
                 if(isDay(((dt%1000000)/10000),ptp,dt%10000)==1) break;
                 printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
                 continue;
           }
           else {
                printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
                continue;
             }
 
          }
             if(isVerify(temp,tnDate)==1){
                  break;
              }
             else {
                  printf("\n Sorry ! You Can not know about train seats available on the %s date Try Again New Date .......",tnDate);
                  continue;
             }
   
     }
     isTicAvailable(dt,ticNum);
     printf("\n----------------------------------------------------------------");
     printf("\n\t\tTicket Status Window is Exit..............!");
     printf("\n----------------------------------------------------------------");
}
void showStatus(){
     int T=0;
     int flag=1;
     printf("\n----------------------------------------------------------------");
     printf("\n\t\tStatus Window");
     printf("\n----------------------------------------------------------------");
  while(1) {
     printf("\n Choices : 1 for Train Status.\n\t2 : for PNR Status or Reprint\n\t3: Go to Back Main Menu");
     printf("\nPlease Enter Your Choice : ");
     scanf("%d",&T);

    switch(T){
         case 1 : trainStatus();
                  break;
         case 2 : tickStatus(); 
                  break;
         case 3 :  
                 printf("\n----------------------------------------------------------------");
		     printf("\n\t\tStatus Window is Exit..............!");
		     printf("\n----------------------------------------------------------------");
                   
                  return; 
         default :  printf("\n\tYou have entered choice invalid..! Please Re-Enter Choice ");
       
      
           }
   }
 
}
