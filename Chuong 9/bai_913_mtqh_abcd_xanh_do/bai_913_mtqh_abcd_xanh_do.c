#include<tv_kit_vdk_pic_all.c>                     
const unsigned char chuoi_hthi[] ={"abcd"} ; 
#include<tv_09_matran_led_quet_hang.c>           
                                
                                                
void main() {                                                            
   set_up_port();                                                                          
   lay_so_luong_ky_tu_chuoi();       
   lay_ma_ky_tu(slkt);                                                                
   while(true){    
         xoa_dl_48_cot();   
         sapxep_vitri_48byte_cot_xanh(0);  
         hien_thi_ma_tran_quet_hang(50);   
         
         xoa_dl_48_cot();   
         sapxep_vitri_48byte_cot_do(0);  
         hien_thi_ma_tran_quet_hang(50); 
                      
   }      
}                                                                   
