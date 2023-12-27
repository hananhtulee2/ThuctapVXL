usi8 chuc=0,donvi=0,sv_cai,mp;
int1 tt_cai=0,tt_ss=0;
void lcd_ht_for_inv()
{
   lcd_goto_xy(1,0);
   if(stepmotor_tn) lcd_data("FOR ");
   else             lcd_data("REV ");  
}

void lcd_ht_stop()
{
   lcd_goto_xy(1,0);
   lcd_data("STOP");
}

void lcd_ht_start()
{
   lcd_goto_xy(1,0);
   lcd_data("START");
}

void lcd_ht_full_half()
{
   lcd_goto_xy(1,5);
   if(stepmotor_fh) lcd_data("FULL");
   else             lcd_data("HALF");
}

void lcd_hienthi_ena()
{
   lcd_goto_xy(1,12);
   lcd_data("ena");
}

void lcd_hienthi_dis()
{
   lcd_goto_xy(1,12);
   lcd_data("dis");
}

void lcd_ht_sv_cai(usi8 x,y)
{
   sv_cai = chuc*10 +donvi;
   lcd_gm_ht_2so_to_xvn(sv_cai,x,y,cx_vn);
}

void khoi_tao_ts()
{
   stepmotor_onoff=1;
   tt_ss=1;
   lcd_ht_full_half();
   lcd_ht_for_inv();
   sb=0;sv=0;
}

void xu_ly_cac_phim()
{
   if(!tt_ss)
   {
      mp =key_4x4_dw();
      if(mp==0x0e)
      {
         tt_cai=1;
         lcd_hienthi_ena();
      }
      else if(mp==0x0f)
      {
         tt_cai=0;
         lcd_hienthi_dis();
      }
      else if((mp<10)&&(tt_cai))
      {
         chuc = donvi;
         donvi =mp;
         lcd_ht_sv_cai(2,14);
      }
      else if((mp==0x0a)&&(sv_cai>0))
      {
         stepmotor_fh=1;
         stepmotor_tn=1;
         khoi_tao_ts();
      }
      else if((mp==0x0b)&&(sv_cai>0))
      {
         stepmotor_fh=1;
         stepmotor_tn=0;
         khoi_tao_ts();         
      }
   }
}

void lcd_ht_sv_to_sb(usi8 x,y, int1 ht_lcd,ht_tp)
{
   if(svt!=sv)
   {
      svt=sv;
      if(ht_lcd) lcd_gm_ht_2so_to_xvn(sv,x,y,cx_vn);
   }
   if(sbt!=sb)
   {
      sbt=sb;
      if(ht_tp) lcd_hien_thi_3so_tp_nho(sb,x,y+6);
   }
}
/*void phim_bt3_fs_hs()
{
   if(phim_bt3_c2(20))
    {
      if(stepmotor_onoff)
      {
         stepmotor_fh = ~stepmotor_fh;
         y=~y;
         xuat_32led_don_4byte(0,0,y,~y);
         lcd_ht_full_half();
         delay_ms(100);
      }
      else buzzer_on_off(100);
    }
}

void step_motor_on_off_inv()
{
   if(!input(on))
   {
      stepmotor_onoff=1;
      xuat_32led_don_4byte(0,0,y,~y);
      lcd_ht_start();
   }
   else if(!input(off))
   {
      stepmotor_onoff=0;
      xuat_32led_don_4byte(0,0,0,0);
      lcd_ht_stop();
   }
   else if(phim_inv_c2(20))
   {
      if(stepmotor_onoff)
      {
         stepmotor_tn=~stepmotor_tn;
         y = ~y;
         xuat_32led_don_4byte(0,0,y,~y);
         lcd_ht_for_inv();
      }
      else buzzer_on_off(100);
   }
}*/
