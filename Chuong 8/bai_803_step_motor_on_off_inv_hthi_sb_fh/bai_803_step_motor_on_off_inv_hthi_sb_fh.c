#include <tv_kit_vdk_pic_all.c> 
#include <tv_08_step_motor.c>
#include <bai_801_step_motor_on_off_inv_tv.c>
usi16 sb;
void hthi_sobuoc_7doan()
{
   md4l7d_giaima_4so_vitri_vn(sb,3,cx_vn);
   xuat_4led_7doan_4so();
}
void phim_bt3_fs_hs()
{
   if(phim_bt3_c2(20))
    {
      if(stepmotor_onoff)
      {
         stepmotor_fh = ~stepmotor_fh;
         y=~y;
         xuat_32led_don_4byte(0,0,y,~y);
         delay_ms(100);
      }
      else buzzer_on_off(100);
    }
}

void main()
{
   set_up_port();
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   sb=0;
   hthi_sobuoc_7doan();
   while (true)
   {
      step_motor_on_off_inv();
      phim_bt3_fs_hs();
      if(stepmotor_onoff)
      {
         step_motor_run_fs_hs();
         delay_ms(stepmotor_delay);
         if(stepmotor_fh==0)
         {
            step_motor_run_fs_hs();
            delay_ms(stepmotor_delay);
         }
         sb++;
         hthi_sobuoc_7doan();
      }
   }
}

