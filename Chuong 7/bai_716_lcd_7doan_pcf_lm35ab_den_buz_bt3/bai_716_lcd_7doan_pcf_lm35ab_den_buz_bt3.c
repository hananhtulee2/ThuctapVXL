#include <tv_kit_vdk_pic_all.c>
#include <bai_701_bt3_lcd_tv.c>
#define solan 50
unsigned int8 pcf_lm35a,pcf_lm35b;
unsigned int8 pcf_lm35at=0,pcf_lm35bt=0;
#include <bai_716_pcf_tv.c>

void main() 
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   lcd_goto_xy(1,0);
   lcd_data("PCF-LM35A");
   lcd_goto_xy(1,10);
   lcd_data("PCF-LM35B");
   lcd_goto_xy(0,0);
   lcd_data("BUZZ:");
   buz_ena=0;
   lcd_ena_buz_off();
   while(true)
   {
      pcf_do_ht_2_lm35();
      so_sanh_nd_dk_buzzer(pcf_lm35a,pcf_lm35b,2);
      
      phim_bt3_tat_mo_buz();
   }
}

   
      
 


