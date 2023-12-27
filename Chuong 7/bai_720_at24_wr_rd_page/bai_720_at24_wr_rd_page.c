#include <tv_kit_vdk_pic_all.c>
unsigned int8 i,dt_doc,page;

void at24cxx_ghi_data_page(usi8 x,usi16 pagex)
{
   usi16 addr_mem;
   usi8 addr_l,addr_h,dt_ghi;
   
   if(pagex>511)  pagex=0;
   addr_mem = (pagex)*64;
   at24_khoi_tao_ghi(addr_mem);
   for(i=0;i<64;i++)
   {
      dt_ghi=i+100;
      i2c_write(dt_ghi);
      xuat_32led_don_4byte(addr_h,addr_l|i,0,dt_ghi);
      md4l7d_giaima_3so_vitri_vn(dt_ghi,3,kx_vn);
      xuat_4led_7doan_4so();
      delay_ms(x);
   }
   i2c_stop();
}
void at24cxx_doc_data_page(usi8 x,usi16 pagex)
{
   usi16 addr_mem;
   
   if(pagex>511)  pagex=0;
   addr_mem = (pagex)*64;
   at24_khoi_tao_doc(addr_mem);
   for(i=0;i<64;i++)
   {
      dt_doc=i2c_read();
      md4l7d_giaima_3so_vitri_vn(dt_doc,3,kx_vn);
      xuat_4led_7doan_4so();
      xuat_32led_don_4byte(0,i,0,dt_doc);
      delay_ms(x);
   }
   dt_doc=i2c_read(0);
   i2c_stop();
}

void main()
{
   set_up_port();
   at24_reset();
   page=0;
   at24cxx_ghi_data_page(100,page);
   at24cxx_doc_data_page(10,page);
   while(true)
   {
      at24cxx_doc_data_page(200,page);
      delay_ms(500);
   }
}
