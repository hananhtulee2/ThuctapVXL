usi8 y=0;
void phim_on_off_inv_dkdc()
{
   if(!input(on)&&(!dcmotor_onoff))
   {
      dcmotor_onoff=1;
      dc_motor_run();
      xuat_32led_don_4byte(0,0,y,y);
   }
   else if(!input(off)&&(dcmotor_onoff))
   {
      dcmotor_onoff=0;
      dc_motor_run();
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if(phim_inv_c2(20))
   {
      if(dcmotor_onoff)
      {
         dc_motor_stop();
         y = ~y;
         xuat_32led_don_4byte(0,0,y,y);
         delay_ms(500);
         dcmotor_tn=~dcmotor_tn;
         dc_motor_run();
      }
      else buzzer_on_off(100);
   }
}

