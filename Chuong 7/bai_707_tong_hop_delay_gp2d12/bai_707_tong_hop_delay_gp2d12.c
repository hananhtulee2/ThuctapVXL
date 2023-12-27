#include <tv_kit_vdk_pic_all.c>
#define solan 50
#include <bai_706_gp2dl2_tv.c>
#include <bai_707_gp2d12_dsp_tv.c>           
void main()                                     
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,10);
   lcd_data("GP2D12");                                         
   lcd_goto_xy(0,0);
   lcd_data("GHD");
   lcd_gm_ht_2so_to_xvn(g_han,0,3,kx_vn);
   lcd_goto_xy(2,0);
   lcd_data("GHD");
   dkc=0;
   while(true)
   {
      h706_adc_gp2dl2_doc_xuly(solan);
      h706_adc_gp2dl2_ht_lcd(1,10,1,1);
      h706_adc_gp2dl2_ht_7doan(3,1);                 
      dem_sp_dung_kcach();
   }
}
  
