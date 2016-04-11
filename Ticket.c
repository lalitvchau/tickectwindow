#include<stdio.h>
#include"lib/login.h"
#include"lib/screen.h"
void main(){
        printf("\n\n\n\n\n************************************************************************************");
        printf("\n\t\t\tTicket Window (Train Reservation)");
        printf("\n************************************************************************************");

       if(login()==1){
          dispScreen();
       }else          printf("\n\tSystem Wrong !");
       printf("\n************************************************************************************\n");
       printf("\t\t\tThank you for use... Ticket Window (Train Reservation)");
       printf("\n************************************************************************************\n");
}

