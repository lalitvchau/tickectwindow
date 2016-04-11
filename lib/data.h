int copyFiles(char *rFile,char *wFile){
  char ch; 
  FILE *rf,*wf;
   
   if(rf=fopen(rFile,"r")){
       wf=fopen(wFile,"w");
       while( (ch=getc(rf)) != EOF) {
          putc(ch,wf);
       }
     fcloseall();
    }
   else{
       return 0;
   }
   return 1;
}
