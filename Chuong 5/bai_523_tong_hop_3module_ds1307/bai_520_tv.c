

#define tang 0
#define giam 1


unsigned int8      giay_tam, bdn; 
unsigned int8      gt_mod, tg_chinh ;
                          

#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}



unsigned int8 tang_or_giam_so_BCD(unsigned int8 x, sel)
{
   unsigned int8 y, dvi, chuc, v;
   chuc = (x>>4);
   dvi  = x&0x0f; 
   y    = chuc*10 + dvi;
   
   if(sel==0)
      y++;
   else 
      y--;
                                    
   chuc = y/10;
   dvi   = y%10;
   v    = (chuc<<4)|dvi;
   
   return(v);

}


void tat_2led_chinh()
{
   if(gt_mod==3)
   {
      dl_8l7dq[7] = 0xFF;
      dl_8l7dq[6] = 0xFF;
   }
   if(gt_mod==2)
   {
      dl_8l7dq[4] = 0xFF;
      dl_8l7dq[3] = 0xFF;
   }
   if(gt_mod==1)                       
   {
      dl_8l7dq[1] = 0xFF;
      dl_8l7dq[0] = 0xFF;
   }

}


void giai_ma_GPG()
{
      md8l7d_gma_so_bcd_vitri_vn(giay_ds, 0, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(phut_ds, 3, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(gio_ds, 6, kx_vn); 
      dl_8l7dq[5] = 0xff;
}


void xu_ly_chop_tat()
{
   if(gt_mod!=0)
   {
      if( (bdn==0) && (input(up)) && (input(dw)) )
         tat_2led_chinh();
      else if(bdn==5)
         giai_ma_GPG();   
   }

}


void phim_mod(unsigned int dl)
{
   if(phim_mode_c2(dl))
   {
      gt_mod++;
      if(gt_mod>3)
         gt_mod = 0;
      
      tg_chinh = 0; 
   }
}


void tang_giay()
{
   if(giay_ds==0x59)
      giay_ds = 0;
   else
      giay_ds = tang_or_giam_so_BCD(giay_ds, tang);
      
   ds1307_luu_vao_ds(0, giay_ds);
}



void tang_phut()
{
   if(phut_ds==0x59)
      phut_ds = 0;
   else
       phut_ds = tang_or_giam_so_BCD(phut_ds, tang);
      
   ds1307_luu_vao_ds(1, phut_ds);
}


void tang_gio()
{
   if(gio_ds==0x23)
      gio_ds = 0;
   else
      gio_ds = tang_or_giam_so_BCD(gio_ds, tang);
      
   ds1307_luu_vao_ds(2, gio_ds);
}


void chinh_tang_GPG()
{
      switch(gt_mod)
      {
         case 1:     tang_giay();   
                     break;        
         case 2:     tang_phut();
                     break;         
         case 3:     tang_gio();
                     break;        
                                      
         default: break;   
      }   
}


void phim_up(unsigned int dl)
{
   if(phim_up_c2(dl))
   {
      tg_chinh = 0;
      chinh_tang_GPG();
      giai_ma_GPG();
      hien_thi_8led_7doan_quet();
   }
}




void giam_giay()
{
   if(giay_ds==0)
      giay_ds = 0x59;
   else
      giay_ds = tang_or_giam_so_BCD(giay_ds, giam);
      
   ds1307_luu_vao_ds(0, giay_ds);
}


void giam_phut()
{
   if(phut_ds==0)
      phut_ds = 0x59;
   else
       phut_ds = tang_or_giam_so_BCD(phut_ds, giam);
      
   ds1307_luu_vao_ds(1, phut_ds);
}


void giam_gio()
{
   if(gio_ds==0)
      gio_ds = 23;
   else
      gio_ds = tang_or_giam_so_BCD(gio_ds, giam);
      
   ds1307_luu_vao_ds(2, gio_ds);
}


void chinh_giam_GPG()
{
      switch(gt_mod)
      {
         case 1:     giam_giay();
                     break;        
         case 2:     giam_phut();
                     break;        
         case 3:     giam_gio();
                  break;
                  
         default: break;   
      }   
}


void phim_dw(unsigned int dl)
{
   if(phim_dw_c2(dl))
   {
      tg_chinh = 0;
      chinh_giam_GPG();
      giai_ma_GPG();
      hien_thi_8led_7doan_quet();
   }
}




   

    
 

