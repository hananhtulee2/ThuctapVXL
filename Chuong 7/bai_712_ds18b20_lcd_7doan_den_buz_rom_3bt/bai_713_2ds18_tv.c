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
unsigned int8 ds18b_ng, ds18b_ngt=0;
unsigned int16 ds18b_w,ds18b_tp,ds18b_tpt=50;

void ds18b20_a_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
   if(ds18b_ngt!=ds18b_ng)
   {
      ds18b_ngt=ds18b_ng;
      if(ht_lcd)  lcd_gm_ht_2so_to_xvn(ds18b_ng,x,y,kx_vn);
   }
   if(ds18b_tpt!=ds18b_tp)
   {
      ds18b_tpt=ds18b_tp;
      if (ht_tp)  lcd_hien_thi_3so_tp_nho((ds18b_tp*625)/10,x+1,y+6);
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
void ds18b20_b_ht_7doan(usi8 z, int1 ht_l7d)
{
   if(ht_l7d) 
   {
      md4l7d_giaima_2so_vitri_vn(ds18b_ng,z,kx_vn);
      xuat_4led_7doan_4so();
   }
}
unsigned int16 ds18b20_read_temp_me(int1 sel)
{
   unsigned int8 bl,bh; unsigned int16 w;
   touch_write_byte(match_rom);
   if(!sel) { for(i=7; i>-1;i--)
      touch_write_byte(ds_a[i]);}
      else { for(i=7; i>-1;i--)
      touch_write_byte(ds_b[i]); }
      
      touch_write_byte(read_scratchpad);
      bl= touch_read_byte();
      bh = touch_read_byte();
      w=make16(bh,bl);
      
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
