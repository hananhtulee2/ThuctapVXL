#include <tv_kit_vdk_pic_all.c>                                
const unsigned char hang2[] = {0x00 ,0x0a,0x15 , 0x11,0x11,0x0a,0x04,0x00 } ;    
signed int8 i ;

void main() {
   set_up_port(); 
   lcd_setup() ;
   lcd_goto_xy(0,0); 
   lcd_data("Hien thi trai tim") ;  
   lcd_command(0x40) ;             
   for(i = 0 ; i<8 ; i++ )   lcd_data(hang2[i]); 
   lcd_goto_xy(1,10);  lcd_data(0) ;              
   while(true) ;

}
