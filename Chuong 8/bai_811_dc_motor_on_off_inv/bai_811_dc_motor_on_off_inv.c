#include <tv_kit_vdk_pic_all.c> 
#include <tv_08_dc_motor.c>
#include <bai_811_dc_motor_on_off_inv_tv.c>
void main()
{
   set_up_port();
   dc_motor_enable();
   dc_motor_stop();
   while (true)
   {
      phim_on_off_inv_dkdc();
   }
}

