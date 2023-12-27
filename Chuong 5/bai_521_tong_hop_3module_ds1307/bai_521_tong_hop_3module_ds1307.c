#include <tv_kit_vdk_pic_all.c>
#include <bai_411_t0_tv.c> 
                                        
unsigned int8   giay_tam;                                    
                            
void giai_ma_8led_quet()                       
{
   md8l7d_gma_so_bcd_vitri_vn(giay_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(phut_ds, 3, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(gio_ds, 6, kx_vn);
}



void main()                                                        
{                                               
   set_up_port(); 
   setup_timer_0(t0_ext_L_to_H|t0_div_1);
   set_timer0(0);
   
   t0_tam = 1; 
   g_han = 50;
   ds1307_kiem_tra_ma();
   while(true)                                        
   {                                 
      b411_dem_xung_ngoai_t0();
      //b333_tong_hop(); 

      for(int8 i=0;i<100;i++)
         hien_thi_8led_7doan_quet();
         
      ds1307_doc_time(8); 
      if(giay_tam != giay_ds)
      {  
         giay_tam = giay_ds;
         giai_ma_8led_quet();
      }

   }    
}  

