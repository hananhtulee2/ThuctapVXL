#include<tv_kit_vdk_pic_all.c> 
#define solan 100 
#include<bai_702_lm35b_tv.c> 
#include<bai_702_bt3_lcd_tv.c> 

void main() {
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
                           
   lcd_goto_xy(0,0); 
   lcd_data("LM35B BUZZ:"); //11 ky tu 
   buz_ena=0 ;                          
   lcd_ena_buz_off() ;                                               
   
   while(true) {
      adc_lm35b_doc_xuly(solan) ; 
      adc_lm35b_ht_lcd(1,0,1,1) ; 
      adc_lm35b_ht_7doan(3,1) ; 
      
      so_sanh_nd_dk_buzzer(lm35b_ng,0,1) ; 
   
   
   }
}                             
