#include <tv_kit_vdk_pic_all.c>         
signed int16 t0_tam,t0,t0_ud ;
int1 ud = 0 ;                         
int16 lt = 0xffff , lp = 0 ;                         
signed int16 g_han ;                             
unsigned char hang0[] = {"DEM SAN PHAM DUNG T0"} ;      
unsigned char hang1[] = {"GH: "} ;                
unsigned char hang2[] = {"GT: "} ;     
unsigned char hang3[] = {"TRANG THAI DEM: "} ; 
void hienthi_UP() {                        
   lcd_goto_xy(3,16);                    
   lcd_data("UP  ");

}
void hienthi_DOWN() {
   lcd_goto_xy(3,16);
   lcd_data("DOWN");

}
void tinh_t0_ud() {
   if(ud == 0) t0_ud = t0 ;    
   else t0_ud = g_han - t0;           

}               
void lcd_hienthi_t0() {                         
   tinh_t0_ud() ;                       
   lcd_gm_ht_2so_to_xvn(t0_ud,1,14,cx_vn) ;      
}                                    
void lcd_hienthi_gh() {                       
   lcd_hien_thi_so_to(g_han/10%10,1,4) ;    
   lcd_hien_thi_so_to(g_han%10,1,7) ;              
                                 
}
void b411_hienthi_4led7doan() { 
   tinh_t0_ud() ;
   md4l7d_giaima_2so_vitri_vn(t0_ud,3,cx_vn);                                                         
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
void ktra_ud() {
   if(phim_ud_c2(250) == co_nhan){
      t0 = g_han - t0 ;
      set_timer0(t0) ;                       
      ud = ~ud ;         
      lt = ~lt ;     
      xuat_32led_don_2word(lt,lp);    
       
      
   }
}
void b411_dem_xung_ngoai() {  
         t0 = get_timer0() ;                           
         if(t0_tam != t0) {           
         t0_tam = t0 ;          
         //b411_hienthi_4led7doan() ; 
         if(t0 >= g_han) {      
            set_timer0(0) ;     
            buzzer_on_off(300) ;              
         } 
         b411_hienthi_4led7doan() ;     
         lcd_hienthi_t0() ;  
      }
                      
 }
                                   
void main() {                                         
   set_up_port(); 
   lcd_setup();                     
   lcd_puts(0,0,hang0);   
   lcd_puts(1,0,hang1);        
   lcd_puts(1,11,hang2);  
   lcd_puts(3,0,hang3) ; 
   setup_timer_0(t0_ext_l_to_h|t0_div_1) ; 
   set_timer0(0);              
   t0_tam = 1 ;         
   g_han = 50 ;   
   xuat_32led_don_2word(lt,lp);
   lcd_hienthi_gh() ; 
   while(TRUE) {   
      if(ud==0)   hienthi_UP();
      else hienthi_DOWN();
      b411_dem_xung_ngoai(); 
      ktra_run() ; 
      ktra_stop() ; 
      ktra_ud() ;
                    
   }


}

