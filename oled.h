#ifndef _OELD_H
#define _OELD_H

#include "LPC11xx.h"
#define u8 uint8_t
#define u16 uint16_t

void OLED_Init(void);//OLED初始化
void OLED_CLS(void);//清屏
void OLED_P6x8Str(u8 x,u8 y,u8 ch[]);
void OLED_P8x16Str(u8 x,u8 y,u8 ch[]);
void OLED_P14x16Str(u8 x,u8 y,u8 ch[]);
void OLED_Print(u8 x, u8 y, u8 ch[]);
void OLED_PutPixel(u8 x,u8 y,u8 data1);
void OLED_Rectangle(u8 x1,u8 y1,u8 x2,u8 y2,u8 gif);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_WrDat(u8 data);
void Draw_BMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 bmp[]);//打印图片
void OLED_Fill(u8 dat);
void Dly_ms(u16 ms);
void OLED_PrintNum(u8 x,u8 y,u8 n);//打印一个数
void OLED_Img(uint8_t x,uint8_t y,uint8_t n);//打印固定图片

#endif
