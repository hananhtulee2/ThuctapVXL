#include <tv_kit_vdk_pic_all.c>         
signed int16 t0_tam,t0; 
signed int16 g_han ;                              
void b411_hienthi_4led7doan() {             
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);                                                         
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);             
   xuat_4led_7doan_4so();                        
}                                
void ktra_run() {
   if(phim_run_c2(250) == co_nhan){
      setup_timer_0(t0_ext_l_to_h|t0_div_1) ; 
      set_timer0(t0);          
                 
   }                                                     
}
void ktra_stop() {               
   if(phim_stop_c2(250) == co_nhan){                               
      setup_timer_0(T0_OFF) ; 
   }                                                           
}
void b411_dem_xung_ngoai() {  
         t0 = get_timer0() ;                           
         if(t0_tam != t0) {           
         t0_tam = t0 ;          
         b411_hienthi_4led7doan() ; 
         if(t0 >= g_han) {     
            set_timer0(0) ;     
            buzzer_on_off(300) ;     
         }                        
      }
                      
 }
                                   
void main() {                                         
   set_up_port();                 
   setup_timer_0(t0_ext_l_to_h|t0_div_1) ; 
   set_timer0(0);              
   t0_tam = 1 ;         
   g_han = 50 ;                 
   while(TRUE) {                 
      b411_dem_xung_ngoai();
      ktra_run() ; 
      ktra_stop() ;
                    
   }


}

