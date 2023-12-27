#define hstd 20
usi16 pwm_tdo =0;
usi16 lt,lp;
usi8 i;
int1 tt_onoff=0;
void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_tdo,5,cx_vn);
   dl_8l7dq[4] = 0xbf;
}

void phim_up()
{
   if(phim_up_c2(10)&&(pwm_tdo<50))
   {
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet(); tt_onoff=1;
      lt=0xff;lp=0xff;
      xuat_32led_don_2word(lt,lp);
   }
}

void phim_dw()
{
   if(phim_dw_c2(10)&&(pwm_tdo>0))
   {
      pwm_tdo--;
      pwm_duty=pwm_tdo*hstd;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet(); tt_onoff=1;
      if(pwm_duty==0)
      {
         lt=0x00;lp=0x00;
         xuat_32led_don_2word(lt,lp);
      }
   }
}

void phim_stop()
{
   if(!input(stop)&&(tt_onoff))
   {
      tt_onoff=0;
      pwm_tdo=0;
      pwm_duty=pwm_tdo*hstd;
      set_pwm1_duty(pwm_duty);
      lt=0; lp=0;
      xuat_32led_don_2word(lt,lp);
      giai_ma_7doan_quet();
   }
}


