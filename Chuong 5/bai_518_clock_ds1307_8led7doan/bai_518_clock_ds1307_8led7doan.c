#include<tv_kit_vdk_pic_all.c>      
usi8 giay_tam ; 
void giai_ma_8led_quet() {
   md8l7d_gma_so_bcd_vitri_vn(giay_ds,0,cx_vn); 
   md8l7d_gma_so_bcd_vitri_vn(phut_ds,3,cx_vn);
   md8l7d_gma_so_bcd_vitri_vn(gio_ds,6,cx_vn);
                                      
                              
}                                                                  
void main() {                    
   set_up_port();
   ds1307_kiem_tra_ma();           
   while(TRUE) {
      for(int8 i = 0;i<5;i++) hien_thi_8led_7doan_quet() ; 
      ds1307_doc_time(8) ;
      if(giay_tam != giay_ds) {
         giay_tam = giay_ds ; 
         giai_ma_8led_quet() ; 
      }
   }

}
