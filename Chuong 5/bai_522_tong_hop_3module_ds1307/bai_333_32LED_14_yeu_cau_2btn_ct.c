#include <bai_327_tv.c>

void b333_2bt_up_dw_c2()
{
   
   if(phim_bt0_c2(2) == co_nhan)
   {
      if(tt_ct<2)
      {
         tt_ct++;
      }
      else
      {
         if(dir<10)
            dir++;
      }
            h327_reset_bien();   
   }     
 
 
   if(phim_bt1_c2(2) == co_nhan)
   {
      if(dir>0)
      {
         dir--;
      }
      else
      {
         if(tt_ct>0)
            tt_ct--;
      }
            h327_reset_bien();   
   }
}



void chon_kieu_sang_led()
{
   
   if(dir==0)
      h327_32led_std_NvT_if();
   else if(dir==1)  
      h327_32led_std_TrN_if();
   else if(dir==2)  
      h327_16led_2word_std_pst_if();
   else if(dir==3) 
      h327_16led_2word_std_tsp_if();
   else if(dir==4)
      h327_32led_SD_PsT_if();
   else if(dir==5)
      h327_32led_SD_TsP_if();
   else if(dir==6)
      h327_32led_SD_NvT_if();
   else if(dir==7)
      h327_32led_SD_TrN_if();
   else if(dir==8)
      h327_32led_2word_SD_PsT_if();
   else if(dir==9)
      h327_32led_2word_SD_TsP_if();
   else if(dir==10)
      h327_32LED_1dsp_mp_if();
   else if(dir==11)
      h327_32LED_1dst_mp_if();

}

void b333_tong_hop()
{
      b333_2bt_up_dw_c2();

      if(tt_ct==0)
         h327_32led_std_pst_if();
      else if(tt_ct==1)
         h327_32led_std_tsp_if();
      else 
         chon_kieu_sang_led();
   
         delay_ms(50);   // Mau chot o day 
}


