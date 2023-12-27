#include <tv_kit_vdk_pic_all.c> 
signed int8 g_han ;
unsigned int8 dem1, dem2 ; 
void b407_hienthi_4led7doan() {                 
   md4l7d_giaima_2so_vitri_vn(g_han,3,cx_vn);
   xuat_4led_7doan_4so();                                        
                               
}                                                          
void b407_up_dw_g_han() {                                 
     if(phim_up_c2(250) == co_nhan ) {
        dem1++ ;                 
        if(dem1 < 10) {     
           dl_4l7d[3] = ma7doan[dem1] ; 
        } else  {
             dem1 = 0 ;
             dl_4l7d[3] = ma7doan[dem1] ;
        }                                
        xuat_4led_7doan_4so() ;   
   }                                                        
     if(phim_dw_c2(250) == co_nhan ) {
        dem2++ ;                                       
        if(dem2 < 10) {            
           dl_4l7d[2] = ma7doan[dem2] ; 
        } else {
             dem2 = 0 ;
             dl_4l7d[2] = ma7doan[dem2] ;
        }                          
                      
        xuat_4led_7doan_4so() ;
   } 
}
                      
void main() {
   set_up_port() ;    
   g_han = 50 ; 
   b407_hienthi_4led7doan() ;
   dem1 = g_han%10 ;     
   dem2 = g_han/10%10 ;
   while(TRUE){                              
      b407_up_dw_g_han() ;   
   }     
}
