unsigned int8 t0, t0_tam, g_han, led;


void phim_RUN()
{
   if(phim_bt0_c2(100))
   {
      led = 0x00FF;
      setup_timer_0(t0_EXT_L_to_H|t0_div_1);
      xuat_32led_don_2word(led,0);
   }
}


void phim_STOP()
{
   if(phim_bt1_c2(100))
   {
      setup_timer_0(t0_off);
      xuat_32led_don_2word(0,0);
   }
}



void b411_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn(t0, 3, cx_vn);
   md4l7d_giaima_2so_vitri_vn(g_han, 1, cx_vn);
   xuat_4led_7doan_4so();
}


void b411_dem_xung_ngoai_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      if(t0>g_han)
      {
         set_timer0(0);
         buzzer_on_off(100);
      }
   }
}


