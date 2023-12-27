#include <tv_kit_vdk_pic_all.c> 
#include <tv_08_dc_motor.c>
#include <bai_815_dc_motor_tv.c>
usi16 t1;
usi8 bdn;
int1 refresh;
#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
   if(bdn==10)
   {
      bdn=0; refresh=1;
   }
}

void tinh_toc_do_hthi()
{
   t1= get_timer1();
   set_timer1(0);// doc sau 1 giay
   t1=t1/45; 
   t1=t1*60;
   md4l7d_giaima_4so_vitri_vn(t1,3,cx_vn);
   xuat_4led_7doan_4so();
   refresh = 0;
}
void main()
{
   set_up_port();
   dc_motor_enable();
   setup_ccp1(ccp_pwm);
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;
   pwm_tdo=0;
   set_pwm1_duty(pwm_duty);
   dl_8l7dq[4] = 0xbf;
   giai_ma_7doan_quet();
   setup_timer_1(t1_external_sync|t1_div_by_1);
   set_timer1(0);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_external_sync|t3_div_by_8);
   set_timer3(3036);
   bdn=0; refresh =1;
   while (true)
   {
      phim_dw();phim_up();phim_stop();
      for(i=0;i<2;i++) hien_thi_8led_7doan_quet();
      if(refresh) tinh_toc_do_hthi();
   }
}

