#include<tv_kit_vdk_pic_all.c> 
#define solan 100
const unsigned char chuoi_hthi[] ={"*1234!** Let make sign better ****"} ; 
#include<tv_09_matran_led_quet_hang.c>                                      
#include<bai_701_lm35a_tv.c>    
unsigned int16 t0, t0_tam, g_han ;    

void b411_dem_xung_ngoai() {
         t0 = get_timer0() ;                           
         if(t0_tam != t0) {           
         t0_tam = t0 ;          
         //b411_hienthi_4led7doan() ;  
         if(t0 > g_han-1) {      
            set_timer0(0) ;               
            buzzer_on_off(300) ;              
         }         
                           
 }  
 }
void main() {
   set_up_port();                                                                          
   xoa_dl_hienthi();
   setup_timer_0(t0_ext_l_to_h|t0_div_1) ; 
   set_timer0(0); 
   g_han = 15 ;   
   t0_tam = 1;
   while(true){                            
       adc_lm35a_doc_xuly(solan) ;         
       lay_ma_1_so_matran(lm35a_ng%10,3);              
       lay_ma_1_so_matran(lm35a_ng/10%10,2);
       xoa_dl_48_cot();                           
       sapxep_vitri_48byte_cot_xanh(0);
       hien_thi_ma_tran_quet_hang(100)  ;    
       
       b411_dem_xung_ngoai();                   
       lay_ma_1_so_matran(t0%10,1);        
       lay_ma_1_so_matran(t0/10%10,0);
       xoa_dl_48_cot();                           
       sapxep_vitri_48byte_cot_xanh(0);
       hien_thi_ma_tran_quet_hang(100)  ;
                      
   }      
}                                                                   
