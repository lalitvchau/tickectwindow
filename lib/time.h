#include<string.h>
int isHH(int hh){
    if(hh>=0&&hh<=24) return 1;
    else return 0;
 }
int isMM(int mm){
    if(mm>=0&&mm<=59) return 1;
    else return 0;
 }
int isDay(int dt,int mo,int year){
     if(mo==1&&dt>0&&dt<=31) return 1;
     if(mo==2&&dt>0&&dt<=29&&year%4==0) return 1;
     if(mo==2&&dt>0&&dt<=28&&year%4!=0) return 1;
     if(mo==3&&dt>0&&dt<=31) return 1;
     if(mo==4&&dt>0&&dt<=30) return 1;
     if(mo==5&&dt>0&&dt<=31) return 1;
     if(mo==6&&dt>0&&dt<=30) return 1;
     if(mo==7&&dt>0&&dt<=31) return 1;
     if(mo==8&&dt>0&&dt<=31) return 1;
     if(mo==9&&dt>0&&dt<=30) return 1;
     if(mo==10&&dt>0&&dt<=31) return 1;
     if(mo==11&&dt>0&&dt<=30) return 1;
     if(mo==12&&dt>0&&dt<=31) return 1;
     return 0;
}
int toDay(int mo,int year){
     int day=0;
     if(mo==1) day=31;
     if(mo==2) day=59;
     if(mo==3) day=90;
     if(mo==4) day=120;
     if(mo==5) day=151;
     if(mo==6) day=181;
     if(mo==7) day=212;
     if(mo==8) day=243;
     if(mo==9) day=273;
     if(mo==10) day=304;
     if(mo==11) day=334;
     if(mo==12) day=365;
     if((year%4==0)&&mo>=2) return day+1;
     else return day;
}

void charDate(char dd[],int d){
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
int intDate(char date[]){
    int i=0;
    int dat=0;
    int ch;
    char t[3];
    while(i<11){
       if(i<=2){
         t[i]=date[i];
         if(i==2){
             t[3]='\0';
             dat=intMonth(t);
         }
       }
       else{
         ch=date[i];
         if(ch!=' '){
             dat=(dat*10)+(ch-48);
         }
       }
       i++;
    }
   return dat;
}
int intMonth(char *mon){
    if(strcmp(mon,"JAN")==0||strcmp(mon,"Jan")==0||strcmp(mon,"jan")==0) return 1;
    if(strcmp(mon,"FEB")==0||strcmp(mon,"Feb")==0||strcmp(mon,"feb")==0) return 2;
    if(strcmp(mon,"Mar")==0||strcmp(mon,"MAR")==0||strcmp(mon,"mar")==0) return 3;
    if(strcmp(mon,"APR")==0||strcmp(mon,"Apr")==0||strcmp(mon,"apr")==0) return 4;
    if(strcmp(mon,"MAY")==0||strcmp(mon,"May")==0||strcmp(mon,"may")==0) return 5;
    if(strcmp(mon,"JUN")==0||strcmp(mon,"Jun")==0||strcmp(mon,"jun")==0) return 6;
    if(strcmp(mon,"JUL")==0||strcmp(mon,"Jul")==0||strcmp(mon,"jul")==0) return 7;
    if(strcmp(mon,"AUG")==0||strcmp(mon,"Aug")==0||strcmp(mon,"aug")==0) return 8;
    if(strcmp(mon,"SEP")==0||strcmp(mon,"Sep")==0||strcmp(mon,"sep")==0) return 9;
    if(strcmp(mon,"OCT")==0||strcmp(mon,"Oct")==0||strcmp(mon,"oct")==0) return 10;
    if(strcmp(mon,"NOV")==0||strcmp(mon,"Nov")==0||strcmp(mon,"nov")==0) return 11;
    if(strcmp(mon,"DEC")==0||strcmp(mon,"Dec")==0||strcmp(mon,"dec")==0) return 12;
    else return 0;
}
int toIntDay(char dt[]){
  int dateInt = intDate(dt);
  int yr = (dateInt%10000);
  int dd = (dateInt/10000)%100;
  int mo = (dateInt/1000000);
  int crrntDay=(int)(yr*365.25);
  if(dd>31) { 
        mo=dd/10;
        dd=dd%10;
  }

  mo=toDay(mo,yr);
//  printf("%d %d %d",yr,dd,mo);
  crrntDay+=mo+dd;
  return crrntDay;
}
int isVerify(char crrDate[], char reqDate[]){
  int cD=toIntDay(crrDate);
  int rD=toIntDay(reqDate);
  if(rD>cD){
        if(rD<=(cD+90)) return 1;
  }
  return 0;
}
