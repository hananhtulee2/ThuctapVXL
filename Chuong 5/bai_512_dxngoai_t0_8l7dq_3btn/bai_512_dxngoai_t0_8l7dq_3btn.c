#include <tv_kit_vdk_pic_all.c>    
signed int8 t0_tam,t0;                 
signed int16 g_han = 60 ;                
signed int16 min = 0 ,max = 60 , min_tam = 0 ;   
int1 run_stop = 0  ;                              
void giai_ma_8_led_quet() {                          
   md8l7d_gma_2so_vitri_vn(t0,3,kx_vn);      
   md8l7d_gma_2so_vitri_vn(min_tam,0,kx_vn); 
   md8l7d_gma_2so_vitri_vn(g_han,6,kx_vn);       
   hien_thi_8led_7doan_quet();         
}                                                                  
void b406_up_dw_g_han(){                              
   if(phim_up_c2(10) == co_nhan ) {                    
      if(min < 20 ) min++ ;             
      else  min = 0 ;                                         
      giai_ma_8_led_quet() ; 
                                                    
   }                              
    if(phim_dw_c2(10) == co_nhan ){    
         if(max > 40 ) max-- ;          
         else  max = 60 ;              
         g_han = max  ;        
         giai_ma_8_led_quet();                                                                                   
   }                             
}                                                    
void ktra_phim() {                               
   if(phim_stop_c1(1,0) == co_nhan){  
      run_stop = ~run_stop ;                
   }                                            
}                         
void ktra_run_stop() {
   if( run_stop == 0 ){
      setup_timer_0(T0_OFF) ;                
      xuat_32led_don_2word(0x00,0x00);    
   } if (run_stop == 1) {                                    
         setup_timer_0(t0_ext_l_to_h|t0_div_1) ;
          //set_timer0(min_tam);                   
          xuat_32led_don_2word(0x00,0xff);  
          }
}                              
void b411_dem_xung_ngoai() {      
     if(min_tam != min){         
      min_tam = min ; 
      set_timer0(min_tam);       
      }                           
      t0 = get_timer0() ;                                        
      if(t0_tam != t0) {                         
         t0_tam = t0 ;                    
         if(t0 >= g_han) {     
            set_timer0(0) ;          
            buzzer_on_off(300) ;            
         }                                
         giai_ma_8_led_quet();                                   
      }
   }                                 
                                                                              
void main() {                                           
   set_up_port() ;                                                       
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0) ;                               
   t0_tam = 1 ;                    
   //g_han = 50 ;                              
   while(TRUE) {        
      b406_up_dw_g_han(); 
      ktra_phim() ;
      ktra_run_stop() ; 
      b411_dem_xung_ngoai();              
      giai_ma_8_led_quet() ;    
   }                                             
                                                      
}
