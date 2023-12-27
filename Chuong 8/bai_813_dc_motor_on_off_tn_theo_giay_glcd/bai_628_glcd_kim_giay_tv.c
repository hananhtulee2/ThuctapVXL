#define xt 96
#define yt 32
#define bks 32
void glcd_ve_kim(usi8 bk, usi16 tg, int1 tt)
{
   signed int16 x_ve,y_ve,tg45;
   float xtinh,ytinh,goc;
   
   glcd_command(glcd_graphic_mode);
   if(tt) glcd_line(xt,yt,x_ve,y_ve,tat);
   tg45 = tg+45;
   if(tg45>60) tg45=tg45-60;
   goc = tg45*6;
   xtinh = bk*cos((goc*3.14)/180);
   ytinh = bk*sin((goc*3.14)/180);
   x_ve = xt + (signed int16) (xtinh);
   y_ve = yt + (signed int16) (ytinh);
   glcd_line(xt,yt,x_ve,y_ve, sang);
   glcd_circle( xt,yt,4,co_fill, sang);
   glcd_circle(xt, yt, 2, no_fill, tat);
}

void glcd_ve_vong_tron_ht_so(usi8 second)
{
   unsigned char glcd_text1[]={"clock:"}, glcd_12[]="12";
   unsigned char glcd_3[]="3", glcd_6[], glcd_9[]="9";
   
   glcd_setup(glcd_graphic_mode);
   glcd_mau_nen(0);
   glcd_text57(0,0,glcd_text1, 1 ,1);
   
   glcd_text57(xt-5,yt-28,glcd_12, 1, 1);
   glcd_text57(xt-3,yt+22,glcd_6, 1, 1);
   glcd_text57(xt-28,yt-3,glcd_9, 1, 1);
   glcd_text57(xt+24,yt-3,glcd_3, 1, 1);
   glcd_circle(xt, yt, bks+8,no_fill,sang);
   //glcd_circle(xt, yt, bks, no_fill, sang);
   glcd_ve_kim(bks,second,0);
}

void glcd_dong_ho_so(usi8 second)
{
   const signed int8 maglcd[]={"0123456789"};
   glcd_command(glcd_text_mode);
   glcd_command(glcd_addr_line1+3);
   glcd_data(maglcd[second/10]);
   glcd_data(maglcd[second%10]);
}
   

