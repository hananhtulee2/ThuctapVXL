#include<tv_kit_vdk_pic_all.c>
const unsigned char chuoi_hthi[] ={"*Hay-Lam-Cuoc-Song-Tot-Dep-Hon*"} ; 
#include<tv_09_matran_led_quet_cot.c>  
unsigned int16 i;                                                                      
void lay_ma_ky_tu(unsigned int8 slkt_x) {                                                     
   unsigned int8 kytu,i,n,j ;       
   n=0;                              
   for(i=0;i<slkt_x;i++){ 
      kytu=chuoi_hthi[i];                 
      for(j=0;j<6;j++,n++){
         dl_hthi[n] = hieu_chinh_4bit_cao(mt_kytu[kytu][j]);
                                    
      }
   
   }                

}
void main() {                                                            
   set_up_port();                                                                          
   xoa_dl_hienthi();                        
   while(true){  
      for(i=0;i<10;i++){
         lay_ma_1_so_matran(i,3);
         quet_4kytu_mau_do(50,0);
      
      }
   }      
}
