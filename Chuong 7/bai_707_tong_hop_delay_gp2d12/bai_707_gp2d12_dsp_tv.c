usi8 dkc=0, dkct=1,  g_han=10;
int1 tt=0;
#define kcn 15
#define kcd 18

void ht_lcd_dem_sp_kcach (usi8 x,y)
{
   if(dkct!=dkc)
   {
      dkct=dkc;
      lcd_gm_ht_2so_to_xvn(dkc,x,y,cx_vn);
   }
}
void dem_sp_dung_kcach()
{
   if ((kc_ng<kcn)&&(tt==0))
   {
      tt=1;
      if(dkc<g_han)
      {
         dkc++;
         buzzer_on_off(100);
      }
      else
      {
         dkc=0;
         buzzer_on_off(500);
      }
      ht_lcd_dem_sp_kcach(2,3);
   }
   else if((kc_ng>kcd)&&(tt==1)) tt=0;
   
}


