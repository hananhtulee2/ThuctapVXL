#include <tv_kit_vdk_pic_all.c>
#include <bai_721_dht11_tv.c>

void main()
{
    set_up_port();
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
    lcd_goto_xy(0,1);
    lcd_data("HUMI");
    lcd_goto_xy(0,8);
    lcd_data("DHT11");
    lcd_goto_xy(0,15);
    lcd_data("TEMP");
    lcd_goto_xy(1,7);
    lcd_data("CHECK");
    lcd_goto_xy(2,9);
    lcd_data("SUM");
    while(true)
    {
       dht11_read_temp_humi();
       dht11_hthi_lcd_nd_da(1,0);
       dht11_hthi_lcd_5byte(3,0);
       delay_ms(200); 
    }
}
