usi16 lt,lp;
int1 tt_qt=0, tt_qn=0,tt_n=0;
void phim_on_off()
{
   if(!input(on)&&(!dcmotor_onoff))
   {
      dcmotor_onoff=1;
      dc_motor_run();
      xuat_32led_don_2word(lt,lp);
   }
   else if(!input(off)&&(dcmotor_onoff))
   {
      dcmotor_onoff=0;
      dc_motor_run();
      xuat_32led_don_4byte(0,0,0,0);
   }
}
void dkdc_theo_giay(usi8 giay)
{
   if(dcmotor_onoff)
   {
      if((4<giay)&&(giay<26))
      {
         if(tt_qt==0)
         {
            tt_qt = 1; dcmotor_tn = 0;
            dc_motor_run();
            lp=0xff;lt=0x00;tt_n=0;
            xuat_32led_don_2word(lt,lp);
         }
      }
         else if((34<giay)&&(giay<56))
         {
            if(tt_qt==0)
            {
               tt_qt = 1; dcmotor_tn = 1;
               dc_motor_run();
               lt=0xff;lp=0x00;tt_n=0;
               xuat_32led_don_2word(lt,lp);
            }           
         }
         else if(tt_n==0)
         {
            tt_n =1; dc_motor_stop();
            lp=0;
            xuat_32led_don_2word(lt,lp);
            tt_qt=0;tt_qn=0;
         }
   }
}

