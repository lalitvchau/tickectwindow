#include<string.h>
struct details{
  char name[50],city[50],lName[50],con[12];
  char date[12];
  char src[100];
  char des[100];
  int sheet;
  int nn;
  int dty;
  int trNum;
  int hh[100],mm[100];
  int srcHH,srcMM,desHH,desMM;
  char stList[1000][100];
  int num[1000];
  int totTrain;
  char trainName[100];
  float charge;
  char stat;
  char stFile[100];
}pass;
void viewTr(){
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
     pass.totTrain=0;
     printf("\n-------------------------------------------------------------------------------");
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
                     pass.num[pass.totTrain++]=number;
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
}
int isTrain(int num){
  int i=0;
   while(i<pass.totTrain){
       if(num==pass.num[i]) return 1;
       i++;
   }
   return 0;
}
int viewStation(int num)
{
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
     printf("\n-------------------------------------------------------------------------------");
     printf("\n\t\t\tTrain No %d Station list",num);
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
                     pass.charge=rate;
                       for(i=0;i<noSt;i++){
                                 printf("\t");
                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                                 if(num==number){
                                    strcpy(pass.stList[i],sta[i]);
                                    pass.hh[i]=hh[i];
                                    pass.mm[i]=mm[i];
                                    printf("\n Enter %d For %s %2d : %2d o'clock",i+1,sta[i],hh[i],mm[i]); 
                                 }
                           }
                     if(num==number){
                         strcpy(pass.trainName,name);
                         fclose(fpr1);
                     printf("\n--------------------------------------------------------------");
                         return i;
                     }
                 }
           fclose(fpr1);
      }
     else {
           printf("\n\tSystem Error ................... !");

      }
                     printf("\n--------------------------------------------------------------");
  return  0;
}
int findTicketNum(int type){
    int nn=100000;
    int dtt=intDate(pass.date);
    char dt[15],ch;
    char fileName[50]="lib/files/Tickets/";
    char tem1[]="SL/";
    char tem2[]="AC/";
    int flag=0;
    FILE *fpr,*fpr5;
    charDate(dt,dtt);
    if(type==1) strcat(fileName,dt);
    if(type==2) {nn=200000;strcat(fileName,tem1);strcat(fileName,dt);}
    if(type==3) {nn=300000; strcat(fileName,tem2);strcat(fileName,dt);}
    if(fpr=fopen(fileName,"r")){
      ch=fgetc(fpr);
      while( ch!=EOF){
          if(ch=='\n'){
            flag+=1;
          }
         ch=fgetc(fpr);

      }
      fclose(fpr);
      nn+=flag;
      return nn+1;
    }
   return nn+1;  
}
int saveTicket(int type){
    int nn=100000;
    int dtt=intDate(pass.date);
    char dt[15],ch;
    char fileName[50]="lib/files/Tickets/";
    char tem1[]="SL/";
    char tem2[]="AC/";
    int flag=0;
    FILE *fpr,*fpr5;
    charDate(dt,dtt);
    if(type==1) strcat(fileName,dt);
    if(type==2) {strcat(fileName,tem1);strcat(fileName,dt);}
    if(type==3) { strcat(fileName,tem2);strcat(fileName,dt);}
    if(fpr=fopen(fileName,"r")){
      fclose(fpr);
      fpr5=fopen(fileName,"a+");
      fprintf(fpr5,"%d %s %s %s %s %d %s %s %d %d %s %d %d %s %f",pass.nn,pass.name,pass.lName,pass.city,pass.con,pass.trNum,pass.trainName,pass.src,pass.srcHH,pass.srcMM,pass.des,pass.desHH,pass.desMM,pass.date,pass.charge);
      if(type!=1){ fprintf(fpr5," %c%d\n",pass.stat,pass.sheet);}
      else{
         fprintf(fpr5,"\n");
      }
      fclose(fpr);

      return 1;
    }
    else{
      fpr=fopen(fileName,"w");
      fprintf(fpr,"%d %s %s %s %s %d %s %s %d %d %s %d %d %s %f",pass.nn,pass.name,pass.lName,pass.city,pass.con,pass.trNum,pass.trainName,pass.src,pass.srcHH,pass.srcMM,pass.des,pass.desHH,pass.desMM,pass.date,pass.charge);
      if(type!=1){ fprintf(fpr," %c%d\n",pass.stat,pass.sheet);}
      else{
         fprintf(fpr,"\n");
      }
      fclose(fpr);


       return 1;
    }
       printf("\n\tSYstem Error !");
     return 0;
}
void toChar(char dd[],int d){
   int i=0,res=0,tmp=0;
   while(d!=0){
      res=d%10;
      tmp=tmp*10+res; 
      d/=10;
   }
   while(tmp!=0){
      res=tmp%10;
      dd[i]=res+48; 
      i++;
      dd[i]='\0'; 
      tmp/=10;
   }
}
int toInt(char num[]){
    int rsltNum=0,i=0;
    while(num[i]!='\0'){
        rsltNum=(rsltNum*10)+(num[i++]-48);
    }
    return rsltNum;
}
int findSheet(int type,int tNum){
    int flag=0;
     char name[50],sta[15][100];
     int noSt;
     int hh[15];
     int i=0;
     int mm[15],number,ac,sleep;
     float rate;
     int size=0;
     FILE *fpr1;
      if(fpr1=fopen("lib/files/Trains/trainList","r")){
           while( !feof(fpr1) ){ 
                      fscanf(fpr1,"%d %s %f %d %d %d",&number,name,&rate,&ac,&sleep,&noSt);
                     if(tNum==number){ fclose(fpr1);if(type==3) return ac;
                                       else return sleep;
                     }
                       for(i=0;i<noSt;i++){

                                 fscanf(fpr1," %s %d %d",sta[i],&hh[i],&mm[i]);
                           }
                      
               }
               fclose(fpr1);
      }
      else{
           printf("\n\t\tSystem Error...................!");
      }return 0;
}
int isAvailable(int type){
    char fileName[100]="lib/files/Trains/";
    int num=0;
    char tNum[10];
    char cDate[12];
    int total,booked;
    FILE *fpr;
    toChar(tNum,pass.trNum);
    toChar(cDate,pass.dty);
//    printf("!!!!%d",type);
    if(type==2){
      strcat(fileName,tNum);
      strcat(fileName,cDate);
      strcat(fileName,"SL");
    }
   else if(type==3){
      strcat(fileName,tNum);
      strcat(fileName,cDate);
      strcat(fileName,"AC");
    }
    strcpy(pass.stFile,fileName);
    fpr=fopen(fileName,"r");
    if(fpr){
       fscanf(fpr,"%d %d",&total,&booked);
       fclose(fpr);
       pass.sheet=(booked+1);
    //   printf("######File %s Total = %d type %d no %d",fileName,num,type,pass.sheet);
       if(booked<total) return 1;
       else return 0;
    }
    else
    {
//       fclose(fpr);
       fpr=fopen(fileName,"w");
       num=findSheet(type,pass.trNum);
       pass.sheet=1;
     //  printf("****File %s Total = %d type %d no %d",fileName,num,type,pass.sheet);
       fprintf(fpr,"%d %d",num,pass.sheet);
       fcloseall();
       return 1;
    }
    return 0;
}
int printTC(int type){
    int ch,num;
    FILE *fpr;
    pass.stat='C';
    if(isAvailable(type)==0) pass.stat='W';
  //if(isAvailable(type)==0) pass.stat='W';     
//     int  numx=findSheet(type,pass.trNum);
 //   printf("****%d",numx);
    if(type==2)  {     pass.charge+=pass.charge*1.2;  pass.nn=findTicketNum(2);}
    if(type==3)  {  pass.nn=findTicketNum(3);pass.charge+=pass.charge*5.2;}
    printf("\n\n\n\n************************************************************");
    if(type==2)  printf("\n\t\tTicket Details\t(Sleeper Class Ticket)");
    if(type==3)  printf("\n\t\tTicket Details\t(AC Class Ticket)");
    printf("\n*************************************************************");
    printf("\nPassenger Name =%s %s",pass.name,pass.lName);
    printf("\nPassenger City =%s\tCont = %s",pass.city,pass.con);
    printf("\nTicket Number =%d",pass.nn);
    printf("\n_____________________________________________________________");
    printf("\nTrain  = ( %d ) %s ",pass.trNum,pass.trainName);
    printf("\nSource = %s Time - %d:%d o'clock",pass.src,pass.srcHH,pass.srcMM);
    printf("\nDestination = %s Time - %d:%d o'clock",pass.des,pass.desHH,pass.desMM);
    if(type==2)    if(pass.stat=='C')
    printf("\n\nSheet Number %c-%d: Coach No: %dSL",pass.stat,(pass.sheet%60),(pass.sheet/60)+1);
    else
    printf("\n\nSheet Number %c-%d: Coach No: Waiting",pass.stat,(pass.sheet%60));
    else {
     if(pass.stat=='C')
    printf("\n\nSheet Number %c-%d: Coach No: %dAC",pass.stat,(pass.sheet%60),(pass.sheet/60)+1);
    else
    printf("\nSheet Number %c-%d: Coach No: Waiting",pass.stat,(pass.sheet%60));
    }
    printf("\n_____________________________________________________________");
    printf("\nDate- %s     Total Charge : %.2f INR",pass.date,pass.charge);
    printf("\n*************************************************************");    
    printf("\n\nDo you Want to  Book ? 1 For yes and other for No = ");
    scanf("%d",&ch);
    if(ch==1) {
         if(saveTicket(type)==1)  {
               fpr=fopen(pass.stFile,"w");
       num=findSheet(type,pass.trNum);
       fprintf(fpr,"%d %d",num,pass.sheet);
       fcloseall();
              return 1;}
         else return 0;
    }else{
         printf("\n\nYou has Been not booked Ticket !");
         return 0;
    }
}

int printGN(){
    int ch;
    pass.nn=findTicketNum(1);
    printf("\n\n\n\n*************************************************************");
    printf("\n\t\tTicket Details\t(Genral Ticket)");
    printf("\n*************************************************************");
    printf("\nPassenger Name =%s %s",pass.name,pass.lName);
    printf("\nPassenger City =%s\tCont = %s",pass.city,pass.con);
    printf("\nTicket Number =%d",pass.nn);
    printf("\n_____________________________________________________________");
    printf("\nTrain  = ( %d ) %s ",pass.trNum,pass.trainName);
    printf("\nSource = %s Time - %d:%d o'clock",pass.src,pass.srcHH,pass.srcMM);
    printf("\nDestination = %s Time - %d:%d o'clock",pass.des,pass.desHH,pass.desMM);
    printf("\n_____________________________________________________________");
    printf("\nDate- %s     Total Charge : %.2f INR",pass.date,pass.charge);
    printf("\n*************************************************************");    
    printf("\n\nDo you Want to  Book ? 1 For yes and other for No = ");
    scanf("%d",&ch);
    if(ch==1) {
         if(saveTicket(1)==1)  return 1;
         else return 0;
    }else{
         printf("\n\nYou has Been not booked Ticket !");
         return 0;
    }
}
void bookTicke(int type){
     int i=0,tot,num;
     int ch1,ch2;
     int dtTick,len,dtt;
     char temp[12];
     int ptp;
     char dy[2],mo[3],yy[4];
     printf("\n\n\n................................................................");
     if(type==1)  printf("\n\t\tGenral Ticket Booking....");
     if(type==2)  printf("\n\t\tSleeper Ticket Booking....");
     if(type==3)  printf("\n\t\tAC Class Ticket Booking....");     
     printf("\n................................................................");
     printf("\n\t\tEnter Following The Passenger Details - ");
     printf("\n\t\tName (First Name) = "); scanf("%s",pass.name);
     printf("\n\t\tLast Name = "); scanf("%s",pass.lName);
     printf("\n\t\tCity = "); scanf("%s",pass.city);
     printf("\n\t\tMobile No. = "); scanf("%s",pass.con);
     printf("\n\t\tEnter Following The Journey Details - ");
     if(type!=1) {
       while(1){
          while(1){
          temp[0]!='\0';
          strcpy(temp,__DATE__);
           pass.date[0]='\0';
           mo[0]='\0';
           dy[0]='\0';
           yy[0]='\0';
           printf("\n\t\tPlease Enter The Journey Date (Apr 05 2016) = ");
           scanf("%s%s%s",mo,dy,yy);
           if((strlen(mo)!=3)||(strlen(dy)!=2)||(strlen(yy)!=4)) { printf("\nDate Should be Mon DD YYYY Formet");continue; }
           strcat(pass.date,mo);
           strcat(pass.date," ");
           strcat(pass.date,dy);
           strcat(pass.date," ");
           strcat(pass.date,yy);
           len=strlen(pass.date);
           dtTick=intDate(pass.date);
           dtt=intDate(temp);
           pass.dty=dtTick;
//           printf("\n\n%d\n\n",dtTick);
           ptp=(dtTick/1000000);
           if(len<=11&&len>9&&(ptp!=0)) { 
                 if(isDay(((dtTick%1000000)/10000),ptp,dtTick%10000)==1) break;
           printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
           }

           else printf("\nInvalid Date, Please Enter Correct Date Fromet (Apr 05 2016)! ......");
           }  

             if(isVerify(temp,pass.date)==1){
                  break;
              }
             else {
                  printf("\n Sorry ! You Can not book Ticket on the %s date Try Again New Date .......",pass.date);
             }
        }    
           
     }else{
           pass.date[0]='\0';
          strcpy(pass.date,__DATE__);
     }
     viewTr();
     while(1){
        printf("\nPlease Enter Train Number = ");
        scanf("%d",&pass.trNum);
        if(isTrain(pass.trNum)==1) break;
        else printf("\nSorry ! The Train not Available right now..........Try Again");
      }
     tot=viewStation(pass.trNum);
 
    while(1){
         printf("\nPlease Select Source Station From Station List = ");
         scanf("%d",&ch1);
         pass.srcHH=pass.hh[ch1-1];
         pass.srcMM=pass.mm[ch1-1];

         strcpy(pass.src,pass.stList[ch1-1]);     
         printf("\nPlease Select Desinition Station From Station List = ");
         scanf("%d",&ch2);
         strcpy(pass.des,pass.stList[ch2-1]);
         pass.desHH=pass.hh[ch2-1];
         pass.desMM=pass.mm[ch2-1];
         if(ch1<ch2&&ch1<=tot&&ch2<=tot&&ch1!=0) break;
         else printf("\n\t!Sorry , Please Enter Right Source/Destinition Station Details");
     }
     
     pass.charge=pass.charge*(ch2-ch1);
     if(type==1){
         if(printGN()==1)
         printf("\n\tThank you ! Ticket Booked Succesfully !");
         else
            printf("\n\tSorry ! Ticket not Book right now Try latter....");
     }
     else{

        if(printTC(type)==1)
         printf("\n\tThank you ! Ticket Booked Succesfully !");
         else
            printf("\n\tSorry ! Ticket not Book right now Try latter....");
     }
     printf("\n\n\n................................................................");
     if(type==1)  printf("\n\t\tGenral Ticket Book EXIT....");
     if(type==2)  printf("\n\t\tSleeper Ticket EXIT....");
     if(type==3)  printf("\n\t\tAC Class Ticket EXIT....");     
     printf("\n................................................................");
 }
void bookTicket(){
    int ch=0;
    while(1){
       printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
       printf("\n\t\t\tTicket Booking Window");
       printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
       printf("\n\tEnter the Choice = ");
       printf("\n\t\t1. Book Genaral Ticket");
       printf("\n\t\t2. Book Sleeper Class Ticket");
       printf("\n\t\t3. Book AC Class Ticket");
       printf("\n\t\t4. Go Back To Main Window");
       printf("\n\tChoice = ");
       scanf("%d",&ch);
       switch(ch){
            case 1 : bookTicke(1);
                     break;
            case 2 : bookTicke(2);
                     break;
            case 3 : bookTicke(3);
                     break;
            case 4 : printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                     printf("\n\t\t\tExiting Ticket Booking Window");
                     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                     return;
            default : printf("\n\t\t\tWrong Choice ..! Try Again ........");
        }
   }
}
