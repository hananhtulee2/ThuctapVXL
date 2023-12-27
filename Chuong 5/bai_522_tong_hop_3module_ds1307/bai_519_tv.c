
unsigned int8      giay_tam; 
signed int8        i, gt_mod;


void giai_ma_GPG()
{
      md8l7d_gma_so_bcd_vitri_vn(giay_ds, 0, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(phut_ds, 3, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(gio_ds, 6, kx_vn);  
}


void giai_ma_NTN()
{
      md8l7d_gma_so_bcd_vitri_vn(nam_ds, 0, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(thang_ds, 3, kx_vn);
      md8l7d_gma_so_bcd_vitri_vn(ngay_ds, 6, kx_vn); 
}


void giai_ma_THU()
{
      dl_8l7dq[7] = 0x87;  // t
      dl_8l7dq[6] = 0x8b;  // h
      dl_8l7dq[5] = 0xc1;  // u
      dl_8l7dq[4] = 0xff;
      dl_8l7dq[3] = ma7doan[thu_ds];
      dl_8l7dq[2] = 0xff;
      dl_8l7dq[1] = 0xff;
      dl_8l7dq[0] = 0xff;
}


void chon_hien_thi_1trong3()
{
      if(gt_mod==0)
         giai_ma_GPG();
      if(gt_mod==1)
         giai_ma_NTN();
      if(gt_mod==2)
         giai_ma_THU();

}


void phim_chon_hienthi(unsigned int8 dl)
{
   if(phim_bt3_c2(dl))
     gt_mod++;
      if(gt_mod>2)
         gt_mod = 0;
      
      chon_hien_thi_1trong3();
         
}

