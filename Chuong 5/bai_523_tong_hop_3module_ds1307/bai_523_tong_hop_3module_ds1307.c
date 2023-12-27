#include <tv_kit_vdk_pic_all.c>
#include <bai_411_t0_tv.c>
#include <bai_520_tv.c>                     
void main()                                                        
{                                               
   set_up_port(); 
   setup_timer_0(t0_ext_L_to_H|t0_div_1);
   set_timer0(0);
   
   t0_tam = 1; 
   g_han = 50;

   setup_timer_3(t3_internal|t3_div_by_8);     // Thay doi "t3_div_by_1" de dem nhanh hon de quan sat
   set_timer3(3036);
   
   enable_interrupts(global);                                       
   enable_interrupts(int_timer3);
   
   bdn = 0;
   gt_mod = 0;
   
   ds1307_kiem_tra_ma();
   while(true)                                        
   {
      b411_dem_xung_ngoai_t0();    

      if(bdn<10)
      {
         if(gt_mod!=0)
            xu_ly_chop_tat();
            for(usi8 j=0;j<10;j++)
               hien_thi_8led_7doan_quet();
         
         phim_mod(60);
         phim_up(40);
         phim_dw(40);   
      }
      else
      {  
         bdn = 0;
         if(tg_chinh<10)
            tg_chinh++;
         else 
            gt_mod = 0;
            
         ds1307_doc_time(8);
         if(giay_tam != giay_ds)
         {
            giay_tam = giay_ds;
            giai_ma_GPG();
         }
      } 
   }    
}  

