int showCancelTick(char path[], int ticNum,int type,int trrNum){
    int tNum,tel,trainNum,SH,SM,DH,DM,dd,yy,flag2=0,flag3=0,size=0;
    char fName[50],lName[50],city[50],src[50],tName[50],mm[3],seat[10],des[50];
    float rate;
    char flag[10];
    FILE *fpr,*fpr2;
//    printf("%s",path);
    fpr2=fopen("lib/files/Tickets/temp","w");
    if(fpr=fopen(path,"r")){
//      printf("\nABCBC\n");
        while(!feof(fpr)){
            fscanf(fpr,"%d%s%s%s%d%d%s%s%d%d%s%d%d%s%d%d%f%s",&tNum,fName,lName,city,&tel,&trainNum,tName,src,&SH,&SM,des,&DH,&DM,mm,&dd,&yy,&rate,seat);
            size++;
        }
         fclose(fpr);
         fpr=fopen(path,"r");
        while(size-->1){
            fscanf(fpr,"%d%s%s%s%d%d%s%s%d%d%s%d%d%s%d%d%f%s",&tNum,fName,lName,city,&tel,&trainNum,tName,src,&SH,&SM,des,&DH,&DM,mm,&dd,&yy,&rate,seat);
            
            if(tNum==ticNum&&trrNum==trainNum){
                  flag[0]='\0';
                  strcpy(flag,seat);
                   
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
                    printf("\n\t Total Cancellatin Charge : %.2f INR\n\tYou have get back only :%.2f INR",(rate*30/100),rate-(rate*30/100));
                    printf("\n\n Do you want to cancel ticket ? If yes then enter 1 otherwise enter 0 = ");  
                    scanf("%d",&flag2);
                    if(flag2!=1){
                        fcloseall();
                        printf("\n\tThank you ! you have not cancel ticket......");
                        return 1;
                    }
            }else{ 
                fprintf(fpr2,"%d %s %s %s %d %d %s %s %d %d %s %d %d %s %d %d %f %s\n",tNum,fName,lName,city,tel,trainNum,tName,src,SH,SM,des,DH,DM,mm,dd,yy,rate,seat);

            }
        }
            fcloseall();
    }else{
        return 0;
    }
    fcloseall();
    fpr2=fopen(path,"w");

    if(fpr=fopen("lib/files/Tickets/temp","r")){
//      printf("\nABCBC\n");
        while(!feof(fpr)){
            fscanf(fpr,"%d%s%s%s%d%d%s%s%d%d%s%d%d%s%d%d%f%s",&tNum,fName,lName,city,&tel,&trainNum,tName,src,&SH,&SM,des,&DH,&DM,mm,&dd,&yy,&rate,seat);
            size++;
        }
         fclose(fpr);
         fpr=fopen("lib/files/Tickets/temp","r");
        while(size-->1){
            fscanf(fpr,"%d%s%s%s%d%d%s%s%d%d%s%d%d%s%d%d%f%s",&tNum,fName,lName,city,&tel,&trainNum,tName,src,&SH,&SM,des,&DH,&DM,mm,&dd,&yy,&rate,seat);
            
            if(trrNum==trainNum&&seat[0]=='W'&&flag3==0){
                         fprintf(fpr2,"%d %s %s %s %d %d %s %s %d %d %s %d %d %s %d %d %f %s\n",tNum,fName,lName,city,tel,trainNum,tName,src,SH,SM,des,DH,DM,mm,dd,yy,rate,flag);
                          flag3=1;
            }else{ 
                fprintf(fpr2,"%d %s %s %s %d %d %s %s %d %d %s %d %d %s %d %d %f %s\n",tNum,fName,lName,city,tel,trainNum,tName,src,SH,SM,des,DH,DM,mm,dd,yy,rate,seat);

            }
        }
            fcloseall();
    }else{
        printf("System Error !");
        return 0;
    }
   



    if(flag2==1){
              printf("\n\tYou cancel Ticket Successfully ! ... Hope you book ticket again... ");
              if(flag3==1) return 10;
    }          
    else return 0;
    return 1;
}

void isTicCancel(int dt,int ticNum,int tNum){
    char path[100];
    char dtt[10];
    char trrNum[100];
    int total=0,num=0; 
    int result;
   FILE *fpr;
 
  path[0]='\0';
  
        charDate(dtt,dt);
        charDate(trrNum,tNum);
    if(ticNum/300000==1){
           strcat(path,"lib/files/Tickets/AC/");
           strcat(path,dtt);
           result=showCancelTick(path,ticNum,1,tNum);
           if(result==0) { printf("\nSorry We can cancel Ticket Number :  %d Ticket right now !",ticNum); return; }
           else if(result==10){
                path[0]='\0';
                strcat(path,"lib/files/Trains/");
                strcat(path,trrNum);
                strcat(path,dtt);
                strcat(path,"AC");                
                if(fpr=fopen(path,"r")){
                      fscanf(fpr,"%d%d",&total,&num);
                }else{
                     printf("\n\n\n\nSystem Error !");
                     return;
                }
                fclose(fpr);
                fpr=fopen(path,"w");
                num--;
                fprintf(fpr,"%d %d",total,num);
                fclose(fpr);
                return;
           }
    }else if(ticNum/200000==1){
           strcat(path,"lib/files/Tickets/SL/");
           strcat(path,dtt);
           result=showCancelTick(path,ticNum,2,tNum);
           if(result==0) { printf("\nSorry We can cancel Ticket Number :  %d Ticket right now!",ticNum); return; }
           else if(result==10){
                path[0]='\0';
                strcat(path,"lib/files/Trains/");
                strcat(path,trrNum);
                strcat(path,dtt);
                strcat(path,"SL");                
                if(fpr=fopen(path,"r")){
                      fscanf(fpr,"%d%d",&total,&num);
                }else{
                     printf("\n\n\n\nSystem Error !");
                     return;
                }
                fclose(fpr);
                fpr=fopen(path,"w");
                num--;
                fprintf(fpr,"%d %d",total,num);
                fclose(fpr);
                return;
           }

    }
    else{
        printf("\n Sorry ! You have Entred Wrong Ticket Number ! Try with new Number");
        return;
    }



}
void tikCancel(){
     int ticNum,dt,cDt,ptp,len,tNum;
     char tnDate[12],dd[2],mm[3],yy[4];
     char temp[11];

     printf("\n\n**********************************************************");
     printf("\n\t\tTicket Cancellation Window");
     printf("\n**********************************************************");
     printf("\nEnter the Ticket Number : ");
     scanf("%d",&ticNum);
     printf("\nEnter the Train Number : ");
     scanf("%d",&tNum);
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
                  printf("\n Sorry ! You are Going wrong This  %s date is past date. Try Again New Date .......",tnDate);
                  continue;
             }
   
     }
     isTicCancel(dt,ticNum,tNum);
     printf("\n\n**********************************************************");
     printf("\n\t\tExit Ticket Cancellation Window....");
     printf("\n**********************************************************");
}
