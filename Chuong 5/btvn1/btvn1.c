#include <tv_kit_vdk_pic_all.c> 
unsigned int16 i,j,n,v ;                                                                                                           
unsigned int8 chuoidich[24] ={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,ma7doan[5],ma7doan[1],ma7doan[2],ma7doan[1],ma7doan[6],ma7doan[1],ma7doan[1]ma7doan[2],0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff} ;
                                                                                                                                                
void copy_8byte_hthi(usi8 k) {               
     for(i = k, n = 0 ; i < k+8 ; i++ , n++ ) {                                                    
        dl_8l7dq[n] = chuoidich[i] ;                   
     }                                            
}                                                                
void main() {                                          
   set_up_port() ;                      
                                                         
   while(TRUE) {                                 
        for ( j = 0 ; j<=16 ; j++ ) {           
            copy_8byte_hthi(j) ; 
            for (v = 0 ;v<=20; v++ ) {
               hien_thi_8led_7doan_quet()   ;  
                                  
            }          
        }                              
      
   }                                             
                                                      
}                                                                                                
