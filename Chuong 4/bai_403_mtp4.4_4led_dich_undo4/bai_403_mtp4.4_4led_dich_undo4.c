#include <tv_kit_vdk_pic_all.c>  
unsigned int8 mp ; 
unsigned int8 m4led[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f} ;
signed int8 i ;
unsigned int8 dud   ;                                        
                                             
                                  
void hienthi_4led7doan() {                   
   for(i = 0 ; i <= 4 ; i++) {
      dl_4l7d[i] = m4led[i+4] ;           
   }                                         
   xuat_4led_7doan_4so()  ;
}                   
void xoa_mang_4led(){ 
   for(i = 0 ; i < 7 ; i++){
      m4led[i] = 0xff ;        
   }
   m4led[7] = 0x7f ;    
}
void bai_403_xuly_phimnhan(){     
   mp = key_4x4_dw();               
   if(mp < 10){                   
      for(i = 0 ; i<7;i++){                                 
         m4led[i] = m4led[i+1];                                                                           
      }                                   
       m4led[7] = ma7doan[mp] ;   
       if(dud < 4) dud++ ;    
       hienthi_4led7doan();  
       delay_ms(100) ;            
   }else if(mp == 0x0B ) {
       if (dud > 0) {          
         for(i = 7 ; i > 0 ; i--){      
            m4led[i] = m4led[i-1] ;
         }                                                            
         dud-- ;
         
       }                       
       hienthi_4led7doan() ;     
       buzzer_on_off(100);   
   }else if(mp == 0x0C) {
       dud = 0 ;                     
       xoa_mang_4led();   
       hienthi_4led7doan() ;
   }

}                      
void main(){                    
   set_up_port() ;
   dud = 0 ;             
   hienthi_4led7doan() ;             
   while(TRUE){                
     bai_403_xuly_phimnhan() ;
     
   }
}
