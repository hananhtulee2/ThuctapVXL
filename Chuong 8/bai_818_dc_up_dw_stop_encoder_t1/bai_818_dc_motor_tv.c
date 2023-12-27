#define hstd 20
usi16 pwm_tdo =0;
usi16 lt,lp;
usi8 i;
int1 tt_stop=0;
void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_tdo,5,cx_vn);
   dl_8l7dq[4] = 0xbf;
}

void quay_thuan_tang_toc()
{
   if(pwm_tdo<50)
   {
      dcmotor_tn=1; tt_stop=1;
      dc_motor_ktao_ccpx();
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;
      dc_motor_set_pwmx_duty();
      giai_ma_7doan_quet();
      lt=0xff;lp=0xff;
      xuat_32led_don_2word(lt,lp);
   }
}

void quay_nghich_tang_toc()
{
   if(pwm_tdo<50)
   {
      dcmotor_tn=0; tt_stop=1;
      dc_motor_ktao_ccpx();
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;
      dc_motor_set_pwmx_duty();
      giai_ma_7doan_quet();
      lt=0xff;lp=0xff;
      xuat_32led_don_2word(lt,lp);
   }
}

void motor_dc_stop()
{
   if(tt_stop)
   {
      tt_stop=0;
      pwm_tdo=0;
      pwm_duty=pwm_tdo*hstd;
      dc_motor_pwm_ccp1_ccp2_stop();
      lt=0; lp=0;
      xuat_32led_don_2word(lt,lp);
      giai_ma_7doan_quet();
   }
}


