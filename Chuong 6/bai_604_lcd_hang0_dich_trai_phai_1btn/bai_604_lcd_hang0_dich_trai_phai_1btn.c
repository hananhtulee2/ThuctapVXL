#include<tv_kit_vdk_pic_all.c>        
signed int8 i,tt ; 
unsigned char  tam ; 
unsigned char hang0[] = {"     HAN ANH TU     "} ;
unsigned char hang1[] = {"BT0 DICH PHAI HANG 1"} ; 
unsigned char hang2[] = {"      DH SPKT       "} ;
unsigned char hang3[] = {"HOC NUA, HOC MAI ,HL"} ;  
signed int8 bdn ;      
#int_timer3
void timer3_interrup() {
   bdn++ ;                                 
   set_timer3(3036) ;
}
void hang0_dich_trai(){
   tam = hang0[0] ; 
   for(i = 0 ; i<=19;i++){
       hang0[i] = hang0[i+1] ;
   }  hang0[19] = tam ; 

}              
void hang0_dich_phai(){
   tam = hang0[19] ; 
   for(i=19;i>=0;i--){
      hang0[i] = hang0[i-1] ; 
                     
   }  hang0[0] = tam ;     

}               
void kiem_tra_dich_h0(){    
   if(tt == 1){      
      hang0_dich_trai() ;         
      lcd_puts(0,0,hang0);     
   } else if(tt == 3) {          
      hang0_dich_phai() ; 
      lcd_puts(0,0,hang0) ;  
   }
}
void phim_dich()  {   
   if(phim_bt0_c2(10)) {      
      tt++  ;                
      if ( tt >= 4 ) {tt = 0 ;}    
      xuat_32led_don_1dw(0xff);
   }                       
                                
}                                                      
void main() {      
   set_up_port();         
   enable_interrupts(global) ;
   enable_interrupts(int_timer3) ;  
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);       
   bdn = 0 ;  
   
   lcd_setup() ;
   lcd_puts(0,0,hang0) ; 
   lcd_puts(1,0,hang1) ; 
   lcd_puts(2,0,hang2) ;
   lcd_puts(3,0,hang3) ;  
   tt = 0 ;                    
   while(true) {  
      if(bdn<10)  {                                
         phim_dich() ;                              
         delay_ms(10)     ;
      } else    {    
           bdn = 0 ;              
           kiem_tra_dich_h0() ;     
      
      
      } 
   
   }
 
 }
