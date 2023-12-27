signed int16 t0_tam,t0,t0_ud ;
int1 ud = 0 ;                         
int16 lt = 0xffff , lp = 0 ;                                                 
signed int16 g_han ;                             
void lcd_hienthi_up() {                        
   lcd_goto_xy(3,18);                    
   lcd_data("UP  ");                                               
                                             
}                                                         
void lcd_hienthi_dw() {
   lcd_goto_xy(3,18);             
   lcd_data("DW  ");                                  

}                      
void lcd_hienthi_run() {                        
   lcd_goto_xy(3,12);                    
   lcd_data("RUN  ");
                
}  
void lcd_hienthi_stop() {                        
   lcd_goto_xy(3,12);                    
   lcd_data("STOP  ");

}  
void tinh_t0_ud() {             
   if(ud == 0) t0_ud = t0 ;    
   else t0_ud = g_han - t0;           

}                         
void lcd_hienthi_t0_soto() {                         
   tinh_t0_ud() ;                       
   lcd_gm_ht_2so_to_xvn(t0_ud,1,14,cx_vn) ;      
}                                    
void lcd_hienthi_gh_soto() {                       
   lcd_hien_thi_so_to(g_han/10%10,1,4) ;    
   lcd_hien_thi_so_to(g_han%10,1,7) ;              
                                 
}
void hienthi_4led7doan() { 
   tinh_t0_ud() ;
   md4l7d_giaima_2so_vitri_vn(t0_ud,3,cx_vn);                                                         
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);             
   xuat_4led_7doan_4so();                                
}                 
void glcd_hthi_t0(usi8 addr){                                    
   unsigned int8 chuc, donvi ;      
   tinh_t0_ud() ;            
   chuc=t0_ud/10%10; donvi=t0_ud%10;
   
   glcd_command(addr);
   if(chuc==0) glcd_data(' ');
   else        glcd_data(chuc+0x30);
   glcd_data(donvi+0x30);

}
void phim_run() {
   if(phim_run_c2(250) == co_nhan){          
      setup_timer_0(t0_ext_l_to_h|t0_div_1) ;
      lp=0xffff;                  
      xuat_32led_don_2word(lt,lp);
      lcd_hienthi_run() ; 
      set_timer0(t0);                 
                                                        
   }                                                     
}  
void phim_stop() {               
   if(phim_stop_c2(250) == co_nhan){                               
      setup_timer_0(T0_OFF) ; 
      lp = 0; 
      xuat_32led_don_2word(0,lp);
      lcd_hienthi_stop() ; 
   }                                                           
}                              
void phim_ud() {
   if(phim_ud_c2(250) == co_nhan){
      t0 = g_han - t0 ;
      set_timer0(t0) ;                       
      ud = ~ud ;                          
      lt = ~lt ;     
      xuat_32led_don_2word(lt,lp);    
       
      if(ud) lcd_hienthi_dw() ; 
      else   lcd_hienthi_up() ;       
      
   }
}                                  
void dem_xung_ngoai_t0() {  
         t0 = get_timer0() ;                           
         if(t0_tam != t0) {           
         t0_tam = t0 ;           
         if(t0 >= g_han) {      
            set_timer0(0) ;     
            buzzer_on_off(300) ;              
         } 
         hienthi_4led7doan() ;     
         lcd_hienthi_t0_soto() ; 
         glcd_hthi_t0(glcd_addr_line2+7);
      }
                      
 }
                                   
