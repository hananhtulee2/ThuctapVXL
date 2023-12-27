#include<tv_kit_vdk_pic_all.c>
#include<tv_06_glcd.c>

void main() {
   set_up_port();
   glcd_setup(glcd_text_mode);
   delay_ms(10);
   
   glcd_setup(glcd_graphic_mode);
   glcd_mau_nen(0);    
    
   glcd_xuat_anh(64,64,0,0);
   glcd_xuat_anh(64,64,64,0); 
   gdram_vdk_to_gdram_glcd_all()  ; 
   
   glcd_command(glcd_text_mode);         
   glcd_command(glcd_addr_line0);
   glcd_data("UTE    UTE   UTE");
   while(true);             
   

}
