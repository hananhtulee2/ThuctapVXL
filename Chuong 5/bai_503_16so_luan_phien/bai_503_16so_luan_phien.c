#include <tv_kit_vdk_pic_all.c> 
signed int16 i ; 
void lay_ma_8so_0_7() {
   dl_8l7dq[0] = ma7doan[0]  ;    
   dl_8l7dq[1] = ma7doan[1]  ;
   dl_8l7dq[2] = ma7doan[2]  ;                        
   dl_8l7dq[3] = ma7doan[3]  ;                                    
   dl_8l7dq[4] = ma7doan[4]  ;
   dl_8l7dq[5] = ma7doan[5]  ;      
   dl_8l7dq[6] = ma7doan[6]  ;                  
   dl_8l7dq[7] = ma7doan[7]  ;    
}
void hien_thi_8so_0_7_1s() { 
   lay_ma_8so_0_7();                
   for(i = 0 ; i<100 ; i++ ) {     
       hien_thi_8led_7doan_quet(); 
   } 
}
void lay_ma_8so_8_f(){ 
   dl_8l7dq[0] = ma7doan[8]  ;    
   dl_8l7dq[1] = ma7doan[9]  ;
   dl_8l7dq[2] = ma7doan[10]  ;                        
   dl_8l7dq[3] = ma7doan[11]  ;                                    
   dl_8l7dq[4] = ma7doan[12]  ;
   dl_8l7dq[5] = ma7doan[13]  ;      
   dl_8l7dq[6] = ma7doan[14]  ;                  
   dl_8l7dq[7] = ma7doan[15]  ;
}                            
void hien_thi_8so_8_f_1s() { 
   lay_ma_8so_8_f() ; 
   for(i = 0 ; i<100 ; i++ ) {     
       hien_thi_8led_7doan_quet(); 
   }
}
void main() {
   set_up_port() ;                     
                          
   while(TRUE) { 
       hien_thi_8so_0_7_1s() ; 
       hien_thi_8so_8_f_1s() ;
      
   }                                             
                                                      
}
