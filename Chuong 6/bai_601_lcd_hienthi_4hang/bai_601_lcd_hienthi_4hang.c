 #include<tv_kit_vdk_pic_all.c> 
 unsigned char hang0[] ={"1hien thi lcd 20x4** "};
 unsigned char hang1[] = {"2 nguyen dinh phu ***"};
 unsigned char hang2[] ={"3 bo thi nghiem vdk "} ; 
 unsigned char hang3[] = {"0123456789abcdefghij"}; 
 //signed int8 i ;             
 
 void main() {                                   
   set_up_port();
   lcd_setup() ;                             
                            
   //lcd_goto_xy(0,0);                
   lcd_puts(0,0,hang0) ;                                                                       
                        
   //lcd_goto_xy(1,0);          
   lcd_puts(1,0hang1) ; 
                         
   //lcd_goto_xy(2,0);                      
   lcd_puts(2,0,hang2) ;
            
   //lcd_goto_xy(3,0);         
   lcd_puts(3,0,hang3) ;      
    
   while(true) ;              
                  
 }
