#include<tv_kit_vdk_pic_all.c>
#include<tv_06_glcd.c>      
#include<graphics.c>    
#include<bai_631_glcd_kim_giay_tv.c>
usi8 giay_tam , giay_bin ; 

void main() {
   set_up_port();
   glcd_setup(glcd_text_mode);
   delay_ms(10);
   
   glcd_setup(glcd_graphic_mode);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();               
   
   glcd_ve_cac_vong_tron_so() ; 
   giay_bin=(giay_ds/16)*10+(giay_ds%16);
   glcd_ve_kim_giay(bks,giay_bin,0);
   giay_tam=0x60 ; 
   
   while(true) {
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds) {
         giay_tam=giay_ds;
         giay_bin=(giay_ds/16)*10+(giay_ds%16);
         glcd_ve_kim_giay(bks,giay_bin,1);
         
         gdram_vdk_to_gdram_glcd_all();
         glcd_dong_ho_so() ; 
      
      }
   
   }

}                                                                          
