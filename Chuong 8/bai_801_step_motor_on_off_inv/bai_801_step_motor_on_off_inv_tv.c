usi8 y=0;
void step_motor_on_off_inv()
{
   if(!input(on))
   {
      stepmotor_onoff=1;
      xuat_32led_don_4byte(0,0,y,~y);
   }
   else if(!input(off))
   {
      stepmotor_onoff=0;
      xuat_32led_don_4byte(0,0,0,0);
   }
   else if(phim_inv_c2(20))
   {
      if(stepmotor_onoff)
      {
         stepmotor_tn=~stepmotor_tn;
         y = ~y;
         xuat_32led_don_4byte(0,0,y,~y);
      }
      else buzzer_on_off(100);
   }
}

