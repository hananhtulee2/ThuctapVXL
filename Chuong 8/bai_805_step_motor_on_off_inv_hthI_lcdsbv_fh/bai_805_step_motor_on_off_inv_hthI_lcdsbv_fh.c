#include <tv_kit_vdk_pic_all.c> 
#include <tv_08_step_motor.c>
usi16 sb=0,sbt=1,sv=0,svt=1;
#include <bai_805_step_motor_tv.c>

void hthi_sb_sv_7doan()
{
   md4l7d_giaima_4so_vitri_vn(sb,3,cx_vn);
   dl_4l7d[0] = ma7doan[sv%10]&0x7f;
   xuat_4led_7doan_4so();
}


void main()
{
   set_up_port();
   stepmotor_delay=20;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   sb=0;sv=0;
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   lcd_data("STEP MOTOR:");
   lcd_ht_stop();
   lcd_ht_full_half();
   lcd_ht_sv_to_sb(2,0,1,1);
   hthi_sb_sv_7doan();
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
         if(sb==200)
         {
            sb=0;  sv++;
            if(sv==9) sv=0;
         }
         lcd_ht_sv_to_sb(2,0,1,1);
         hthi_sb_sv_7doan();
      }
   }
}

