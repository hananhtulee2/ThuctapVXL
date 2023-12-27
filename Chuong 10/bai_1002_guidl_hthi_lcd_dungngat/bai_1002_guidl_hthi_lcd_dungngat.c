#include<tv_kit_vdk_pic_all.c> 
unsigned char hang0[]={"Truyen Du Lieu UART"};
unsigned char hang1[]={"  PIC18F4550 va PC "};
unsigned int8 i , rdata=0,vitri=0;     
int1 tt = 0 ;                                  
                                       
#int_rda     
void interrupt_uart() {             
     if(kbhit()) {
         rdata = getch() ; 
         tt = 1;               
     }
}
                           
void nhan_dulieu() {
   if(tt) {
      lcd_goto_xy(3,vitri);                          
      lcd_data(rdata);
      if(vitri<19) vitri++ ;                           
      else         vitri=0;
      tt = 0 ;
                                              
   }                          
}
void main() {            
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);                                        
   for(i=0;i<20;i++)   lcd_data(hang0[i]) ;
   lcd_goto_xy(1,0);
   for(i=0;i<20;i++)   lcd_data(hang1[i]) ;   
   
   enable_interrupts(global) ; 
   enable_interrupts(int_rda) ;
   while(true){
      nhan_dulieu() ;
   
   } 

}
   



