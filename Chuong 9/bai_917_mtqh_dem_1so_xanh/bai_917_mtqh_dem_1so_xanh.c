#include<tv_kit_vdk_pic_all.c>                     
const unsigned char chuoi_hthi[] ={"*1234!** Let make sign better ****"} ; 
#include<tv_09_matran_led_quet_hang.c>                                      
unsigned int8 i ;                              

void main() {                                                            
   set_up_port();                                                                          
   xoa_dl_hienthi();       
                                                                   
   while(true){  
         for(i=0;i<10;i++)     {
            lay_ma_1_so_matran(i,3);  
            xoa_dl_48_cot(); 
            sapxep_vitri_48byte_cot_xanh(0);
            hien_thi_ma_tran_quet_hang(100)  ;
         }                                  
      
                   
                      
   }      
}                                                                   
