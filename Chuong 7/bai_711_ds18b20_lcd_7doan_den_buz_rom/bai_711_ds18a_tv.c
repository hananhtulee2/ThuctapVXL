unsigned int8 ds18a_ng, ds18a_ngt=0;
unsigned int16 ds18a_w,ds18a_tp,ds18a_tpt=50;

void ds18b20_a_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
   if(ds18a_ngt!=ds18a_ng)
   {
      ds18a_ngt=ds18a_ng;
      if(ht_lcd)  lcd_gm_ht_2so_to_xvn(ds18a_ng,x,y,kx_vn);
   }
   if(ds18a_tpt!=ds18a_tp)
   {
      ds18a_tpt=ds18a_tp;
      if (ht_tp)  lcd_hien_thi_3so_tp_nho((ds18a_tp*625)/10,x+1,y+6);
   }
}
void ds18b20_a_ht_7doan(usi8 z, int1 ht_l7d)
{
   if(ht_l7d) 
   {
      md4l7d_giaima_2so_vitri_vn(ds18a_ng,z,kx_vn);
      xuat_4led_7doan_4so();
   }
}
void ds18b20_a_doc_xuly_hthi()
{
   if(touch_present())
   {
      ds18a_w = ds18b20_read_temp();
      ds18a_ng= ds18a_w>>4;
      ds18a_tp = ds18a_w & 0x000f;
      
      ds18b20_a_ht_lcd(1,0,1,1);
      ds18b20_a_ht_7doan(1,1);
   }
   else ds18b20_no_ds18b(1,7);
}
