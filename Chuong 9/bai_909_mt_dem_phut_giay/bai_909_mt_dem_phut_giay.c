#include<tv_kit_vdk_pic_all.c>
const unsigned char chuoi_hthi[] ={"*Hay-Lam-Cuoc-Song-Tot-Dep-Hon*"} ; 
#include<tv_09_matran_led_quet_cot.c>  
unsigned int16 i,j;     
signed int8 giay,bdn,phut ; 
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
#int_timer3      
void interrupt_timer3(){
   bdn++;          
   set_timer3(3036)     ;

}                     
void tang_giay_phut() {
   bdn = bdn -10; giay++ ;
   if(giay==60) { 
      giay = 0 ; phut++;           
      if(phut==60) {                          
         phut = 0 ;                

      } } lay_ma_1_so_matran(phut%10,1);     
         lay_ma_1_so_matran(phut/10%10,0)  ; 
   
      lay_ma_1_so_matran(giay%10,3);
      lay_ma_1_so_matran(giay/10%10,2);   
  
                      
}                 
void main() {                                                            
   set_up_port();                                                                          
   xoa_dl_hienthi();  
   setup_timer_3(t3_internal|t3_div_by_8);     
   set_timer3(3036) ;                 
   enable_interrupts(global);       
   enable_interrupts(int_timer3); 
   giay = 0;bdn=0; phut=0;       
   while(true){                                               
      if(bdn<10) quet_4kytu_mau_do(10,0);     
      else tang_giay_phut() ; 
     
   }      
}                                      
