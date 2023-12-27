#include<tv_kit_vdk_pic_all.c> 
#define solan 100
const unsigned char chuoi_hthi[] ={"*1234!** Let make sign better ****"} ; 
#include<tv_09_matran_led_quet_hang.c>                                      
#include<bai_701_lm35a_tv.c>                                             
void main() {                                                            
   set_up_port();                                                                          
   xoa_dl_hienthi();                       
   while(true){                            
       adc_lm35a_doc_xuly(solan) ;
       lay_ma_1_so_matran(lm35a_ng%10,3);              
       lay_ma_1_so_matran(lm35a_ng/10%10,2);
       xoa_dl_48_cot();                           
       sapxep_vitri_48byte_cot_xanh(0);
       hien_thi_ma_tran_quet_hang(100)  ;            
                      
   }      
}                                                                   
