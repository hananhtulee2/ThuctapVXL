#include<tv_kit_vdk_pic_all.c> 
unsigned char hang0[]={"TDL UART: PIC<=>PC"};
unsigned int8 i , rdata=0,vitri=0;     
int1 tt = 0 ;                                                                         
signed int8 giay,bdn ;                                        
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
#int_timer3 
void interrupt_timer3() {
   bdn++;
   set_timer3(3036) ;      

}
void lcd_hthi_giay_bcd_soto() {
   lcd_hien_thi_so_to(giay/10,1,14);
   lcd_hien_thi_so_to(giay%10,1,17);                                 
}     
void lcd_hthi_giay_hex_soto() {
   lcd_hien_thi_so_to(giay/16,1,0);
   lcd_hien_thi_so_to(giay%16,1,3);                               

}
void tang_giay() {
   bdn = bdn - 10 ; giay++ ;
   if(giay == 60) ; giay=0;
}
void main() {        
   set_up_port();     
   lcd_setup();
   lcd_goto_xy(0,0);                                        
   for(i=0;i<20;i++)   lcd_data(hang0[i]) ;   
      
   enable_interrupts(global) ; 
   enable_interrupts(int_rda) ;  
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   enable_interrupts(int_timer3);  
   
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(1,7);
   lcd_data("Dem");
   lcd_goto_xy(2,7);
   lcd_data("Giay");
   giay = 0 ; bdn = 0 ;
   while(true){ 
      if(bdn<10){
         nhan_dulieu() ;
      }else {            
          tang_giay() ; 
          lcd_hthi_giay_bcd_soto() ;
          lcd_hthi_giay_hex_soto() ;
          putc(giay);
      
      
      }
   } 

}
   



