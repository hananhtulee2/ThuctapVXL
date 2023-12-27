#include<tv_kit_vdk_pic_all.c>
#include<bai_615_clock_ds1307_lcd_tv.c>
usi8 giay_tam;             
void giai_ma_8led_quet()                       
{
   md8l7d_gma_so_bcd_vitri_vn(giay_ds,0,kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(phut_ds,3,kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(gio_ds,6,cx_vn);
}                                    
void main()
{
   set_up_port();
   ds1307_kiem_tra_ma();
   
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   ds1307_hthi_text_lcd();
   ds1307_hthi_thu_lcd();
   ds1307_hthi_giay_lcd_soto();
   ds1307_hthi_phut_lcd_soto();
   ds1307_hthi_gio_lcd_soto();
   ds1307_hthi_ntn_lcd();
   while(true)
   {
      for(int8 i=0;i<5;i++)   hien_thi_8led_7doan_quet();
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)                                                         
      {              
         giay_tam=giay_ds;
         giai_ma_8led_quet();  
         ds1307_hthi_lcd_soto(); 
      }                                       
   }
}
