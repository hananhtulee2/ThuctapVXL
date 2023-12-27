void pcf_lm35a_ht_lcd(usi8 x,y)
{
   if(pcf_lm35at!=pcf_lm35a)
   {
      pcf_lm35at=pcf_lm35a;
      lcd_gm_ht_2so_to_xvn(pcf_lm35a,x,y,kx_vn);
   }
}
void pcf_lm35b_ht_lcd(usi8 x,y)
{
   if(pcf_lm35bt!=pcf_lm35b)
   {
      pcf_lm35bt=pcf_lm35b;
      lcd_gm_ht_2so_to_xvn(pcf_lm35b,x,y,kx_vn);
   }
}
void pcf_do_ht_2_lm35()
{
   pcf_lm35a=pcf_doc_chan(pcf_chan0,solan);
   pcf_lm35b=pcf_doc_chan(pcf_chan1,solan);
   
   pcf_lm35a_ht_lcd(2,0);
   pcf_lm35b_ht_lcd(2,10);
   
   md4l7d_giaima_2so_vitri_vn(pcf_lm35a,1,kx_vn);
   md4l7d_giaima_2so_vitri_vn(pcf_lm35b,3,kx_vn);
   xuat_4led_7doan_4so();
}
