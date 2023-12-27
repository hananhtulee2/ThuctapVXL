#include<tv_kit_vdk_pic_all.c>                                                             
unsigned int8 t0 , t0_tam ,g_han ; 
unsigned char hang0[] = {"DEM SAN PHAM DUNG T0"} ; 
unsigned char hang1[] = {"GIA TRI DEM: "} ; 
unsigned char hang2[] = {"GIOI HAN DEM: "} ; 
void lcd_hienthi_t0() {
   lcd_goto_xy(1,18);
   lcd_data(t0/10%10+0x30) ;
   lcd_data(t0%10+0x30) ;         
}
void lcd_hienthi_gh() {
   lcd_goto_xy(2,18);
   lcd_data(g_han/10%10+0x30) ; 
   lcd_data(g_han%10+0x30) ;

}  
void hienthi_4led7doan(){    
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn)  ;
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();      
   

}
void dem_xung_ngoai_t0() {
   t0 = get_timer0() ;  
   if(t0_tam != t0 ) {
     t0_tam = t0 ; 
     if(t0 >= g_han) {
        set_timer0(0) ;
        buzzer_on_off(300);                  
     }  
      hienthi_4led7doan() ;    
      lcd_hienthi_t0() ;
   }

}    
void main() {
   set_up_port();                            
   lcd_setup();                     
   //lcd_goto_xy(0,0)   ;
   lcd_puts(0,0,hang0);   
   //lcd_goto_xy(1,0);
   lcd_puts(1,0,hang1);        
   //lcd_goto_xy(2,0);
   lcd_puts(2,0,hang2);  
                      
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0) ;
   t0_tam = 1 ;     
   g_han = 50 ;                                                                                     
   lcd_hienthi_gh() ; 
   while(true) {
       dem_xung_ngoai_t0();
   
   }
       
   }
