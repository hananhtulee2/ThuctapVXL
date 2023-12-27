#include <tv_kit_vdk_pic_all.c>    
signed int8 t0_tam,t0;                 
signed int8 g_han ;                                                                  
                                   
void giai_ma_8_led_quet() {    
   md8l7d_gma_2so_vitri_vn(t0,0,kx_vn); 
   md8l7d_gma_2so_vitri_vn(g_han,6,kx_vn);                        
}  
void b411_hienthi_4led7doan() {    
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);                                                         
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();                        
}
void b411_dem_xung_ngoai() {                
   t0 = get_timer0() ;                                        
   if(t0_tam != t0) {                         
      t0_tam = t0 ;     
      if(t0 >= g_han) { 
         set_timer0(0) ;          
         buzzer_on_off(300) ;            
      }
      giai_ma_8_led_quet();       
      b411_hienthi_4led7doan()    ;                              
   }
}
                                                                              
void main() {                                   
   set_up_port() ; 
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0) ;   
   t0_tam = 1 ; 
   g_han = 50 ;                              
   while(TRUE) {        
     
      b411_dem_xung_ngoai();
      hien_thi_8led_7doan_quet(); 
   }                                             
                                                      
}
