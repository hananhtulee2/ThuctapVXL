#include <tv_kit_vdk_pic_all.c>         
unsigned int16 mp,y=0 ;  
unsigned int16 led_tam =0x0001 ;
                                                              
void dieukhien_16led_on_off() {           
   mp = key_4x4_dw() ;            
   if(mp !=0xff){  
      led_tam =0x0001 ;                  
      led_tam = led_tam << mp ;              
      y = y^led_tam ;               
      xuat_32led_don_2word(0,y);                     
   }                                                                           
                                                  
}
void main(){                                
   set_up_port() ;                
   while(TRUE){                  
      dieukhien_16led_on_off() ; 
   }                   
}                                  
