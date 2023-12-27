signed int8 gio,phut,giay,bdn,gt_mod,tg_chinh = 0 ; 
#int_timer3                                                                            
void interrupt_timer3() {
   bdn++ ;                                                                                   
   set_timer3(3036);                                   
} 
void giai_ma_8led_quet() {
   md8l7d_gma_2so_vitri_vn(giay,0,kx_vn)   ;                                          
   md8l7d_gma_2so_vitri_vn(phut,3,kx_vn)   ;
   md8l7d_gma_2so_vitri_vn(gio,6,kx_vn)    ;
   if(gt_mod == 1) dl_8l7dq[6] = dl_8l7dq[6] & 0x7f ;  
   if(gt_mod == 2) dl_8l7dq[3] = dl_8l7dq[3] & 0x7f ;
   if(gt_mod == 3) dl_8l7dq[0] = dl_8l7dq[0] & 0x7f ;

}  
void tat_2led_chinh() {
   if(gt_mod == 1) 
   {                  
      dl_8l7dq[1] =0xff ; dl_8l7dq[0] = 0xff ; 
   }
   if(gt_mod == 2) {
      dl_8l7dq[4] = 0xff ; dl_8l7dq[3] =0xff ;       
   }                                   
   if(gt_mod ==3) {                          
      dl_8l7dq[7] =0xff ; dl_8l7dq[6] = 0xff ;
   }
   

}
void phim_mod(usi8 dl) {
   if(phim_mode_c2(dl)){
      gt_mod++ ; 
      if(gt_mod >= 4) gt_mod = 0 ; 
      tg_chinh = 0 ; 
   }                                    
}                        
                            
void phim_up(usi8 dl) {
   if(phim_up_c2(dl)){        
      tg_chinh = 0 ;      
      switch(gt_mod){                          
         case 1 : if(giay == 59) giay = 0 ; 
                  else           giay++ ;   
                  break ;
         case 2 : if(phut == 59) phut = 0 ; 
                  else           phut++ ; 
                  break ; 
         case 3 : if(gio == 23)  gio = 0; 
                  else           gio++ ;
                  break ; 
         default: break ; 
      
      }
      giai_ma_8led_quet() ; 
      hien_thi_8led_7doan_quet() ; 
   }
   
                                        
}
void phim_dw(usi8 dl) {
   if(phim_dw_c2(dl)){
      tg_chinh = 0 ; 
      switch(gt_mod) {
         case 1 : if(giay == 0 ) giay =59 ;
                  else           giay-- ;
                  break ; 
         case 2 : if(phut == 0 ) phut = 59  ;                                          
                  else           phut-- ;    
                  break ; 
         case 3 : if(gio == 0 )  gio = 23 ; 
                  else           gio-- ;
                  break ; 
         default : break ;
      
                         
      }
        giai_ma_8led_quet() ; 
        hien_thi_8led_7doan_quet(); 
   }

}
void tang_giay_phut_gio() {
   bdn = bdn - 10 ;                   
   if(tg_chinh < 20 ) tg_chinh++ ;            
   else               gt_mod = 0 ;             
   giay++ ;                       
   if(giay == 60 ) {
      giay = 0 ; phut++ ; 
      if(phut == 60 ) {
         phut = 0 ; gio++ ; 
         if(gio == 24) gio = 0 ; 
      }
   
   }
     giai_ma_8led_quet() ; 
                                
}
void xu_ly_choptat() {
   if(gt_mod != 0 ) {
      if((bdn ==0) &&(input(up))&&(input(dw))) tat_2led_chinh() ; 
      else if(bdn == 5)  giai_ma_8led_quet() ; 
   
   }

} 
