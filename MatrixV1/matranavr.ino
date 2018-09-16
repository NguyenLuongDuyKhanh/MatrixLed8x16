/***************************************************
 Simple AVR sketch to blink an LED (or similar)
 connected to PB2 (Arduino pin D2)
 Note that the compiled sketch is significantly
 smaller than the original Arduino blink sketch.
 A detailed explanation about debugging, port and
 pin definitions can be watched here:
 https://www.youtube.com/watch?v=plJf0r7IcWc
***************************************************/ 


#include <avr/io.h>
#include <util/delay.h>

#define clockpin1 PB2
#define latchpin1 PB3

#define datapin1 PB0
#define datapin2 PB1

#define COn 0
#define COff 1
#define ROn 1
#define ROff 0

//byte TODOS[] = {11111111,11111111,11111111,11111111,11111111,11111111,11111111,11111111};
//byte EX[] = {00000000,00010000,00010000,00010000,00010000,00000000,00010000,00000000};
//byte A[] = {0b00000000,0b00011000,0b00100100,0b00100100,0b00111100,0b00100100,0b00100100,0b00000000};
//byte B[] = {0b01111000,0b01001000,0b01001000,0b01110000,0b01001000,0b01000100,0b01000100,0b01111100};
//byte C[] = {0b00000000,0b00011110,0b00100000,0b01000000,0b01000000,0b01000000,0b00100000,0b00011110};
//byte D[] = {0b00000000,0b00111000,0b00100100,0b00100010,0b00100010,0b00100100,0b00111000,0b00000000};
//byte E[] = {0b00000000,0b00111100,0b00100000,0b00111000,0b00100000,0b00100000,0b00111100,0b00000000};
//byte F[] = {0b00000000,0b00111100,0b00100000,0b00111000,0b00100000,0b00100000,0b00100000,0b00000000};
//byte G[] = {0b00000000,0b00111110,0b00100000,0b00100000,0b00101110,0b00100010,0b00111110,0b00000000};
//byte H[] = {0b00000000,0b00100100,0b00100100,0b00111100,0b00100100,0b00100100,0b00100100,0b00000000};
//byte I[] = {0b00000000,0b00111000,0b00010000,0b00010000,0b00010000,0b00010000,0b00111000,0b00000000};
//byte J[] = {0b00000000,0b00011100,0b00001000,0b00001000,0b00001000,0b00101000,0b00111000,0b00000000};
//byte K[] = {0b00000000,0b00100100,0b00101000,0b00110000,0b00101000,0b00100100,0b00100100,0b00000000};
//byte L[] = {0b00000000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00111100,0b00000000};
//byte M[] = {0b00000000,0b00000000,0b01000100,0b10101010,0b10010010,0b10000010,0b10000010,0b00000000};
//byte N[] = {0b00000000,0b00100010,0b00110010,0b00101010,0b00100110,0b00100010,0b00000000,0b00000000};
//byte O[] = {0b00000000,0b00111100,0b01000010,0b01000010,0b01000010,0b01000010,0b00111100,0b00000000};
//byte P[] = {0b00000000,0b00111000,0b00100100,0b00100100,0b00111000,0b00100000,0b00100000,0b00000000};
//byte Q[] = {0b00000000,0b00111100,0b01000010,0b01000010,0b01000010,0b01000110,0b00111110,0b00000001};
//byte R[] = {0b00000000,0b00111000,0b00100100,0b00100100,0b00111000,0b00100100,0b00100100,0b00000000};
//byte S[] = {0b00000000,0b00111100,0b00100000,0b00111100,0b00000100,0b00000100,0b00111100,0b00000000};
//byte T[] = {0b00000000,0b01111100,0b00010000,0b00010000,0b00010000,0b00010000,0b00010000,0b00000000};
//byte U[] = {0b00000000,0b01000010,0b01000010,0b01000010,0b01000010,0b00100100,0b00011000,0b00000000};
//byte V[] = {0b00000000,0b00100010,0b00100010,0b00100010,0b00010100,0b00010100,0b00001000,0b00000000};
//byte W[] = {0b00000000,0b10000010,0b10010010,0b01010100,0b01010100,0b00101000,0b00000000,0b00000000};
//byte X[] = {0b00000000,0b01000010,0b00100100,0b00011000,0b00011000,0b00100100,0b01000010,0b00000000};
//byte y[] = {0b00000000,0b01000100,0b00101000,0b00010000,0b00010000,0b00010000,0b00010000,0b00000000};
//byte Z[] = {0b00000000,0b00111100,0b00000100,0b00001000,0b00010000,0b00100000,0b00111100,0b00000000};


byte LT[] = {0b00000000,0b10010011,0b10010100,0b11010100,0b10110111,0b10010100,0b10010100,0b00000000,
             0b00000000,0b00100010,0b10110110,0b10101010,0b10100010,0b10100010,0b10100010,0b00000000};
      
byte buff1[]={0b00101001,0b00101001};
byte buff2[]={0b11010011,0b11010011};

void printscreen();
void turnr(uint8_t r, bool rstt);
void turnc(uint8_t c, bool cstt);

void resetbuff();
void runtime();

void _delay(word time = 1) { // Xây dựng lại hàm delay
  for (word i = 1; i<=time;i++) {
    delayMicroseconds(250);
  }
}
int main()
{       
  DDRB |= 1<<clockpin1;
  DDRB |= 1<<latchpin1;
  DDRB |= 1<<datapin1;
  DDRB |= 1<<datapin2;
  TCCR0B |=  _BV(CS02)  ;
  int count=10;
  while(1)
  {     
    //for(int h=0;h<100;h++)
    {
    for(int i=1;i<8;i++) //hang
    {
      resetbuff();
      for(int j=0;j<16;j++)//cot
      {
        if(j<=7)
        {
          if(LT[i]>>(7-j) & 1==1)
          {
            turnc(j+1,COn);
          }else turnc(j+1,COff);
        }else 
        
        if(j>7)
        {
          if(LT[i+8]>>(15-j) & 1==1)
          {
            turnc(j+1,COn);
          }else turnc(j+1,COff);
        }
        
      }
      turnr(i+1,ROn);
      printscreen();
    }
    }
    runtime();
    delayMicroseconds(5000);
    //_delay(1);
  }   
  return 0;
}

//int timer = 150;



void runtime()
{
  _delay_ms(10);
  bool a;
        for(byte j=0;j<8;j++)
      {
//        a = LT[j]>>7;
//        LT[j]=(LT[j]<<1) | (LT[j+8]>>7);
//        LT[j+8]=LT[j+8]<<1 | (LT[j+16]>>7);
//        LT[j+16]=LT[j+16]<<1 | a;
        a = LT[j]>>7;
        LT[j]=(LT[j]<<1) | (LT[j+8]>>7);
        LT[j+8]=LT[j+8]<<1 | a;

        //LT[j+8]=LT[j+8]<<1 | (LT[j+16]>>7);
        //LT[j+16]=LT[j+16]<<1 | a;
      }
}

//
//void SetPinHigh(volatile byte *port, byte pin)
//{
//  *port |= (1 << pin);
//}
//
//void SetPinLow(volatile byte *port, byte pin)
//{
//  *port &= ~(1 << pin);
//}

void SetPinHigh(byte pin)
{
  PORTB |= (1 << pin);
}

void SetPinLow(byte pin)
{
  PORTB &= ~(1 << pin);
}

void resetbuff()
{     
    for(uint8_t i=1;i<=8;i++)
    {
      turnr(i,ROff);
    }
    //for(uint8_t i=1;i<=16;i++)
    {
      //turnc(i,COff);
    }
}

void printscreen()
{
  SetPinLow(latchpin1);
  for(uint8_t i=0;i<=15;i++)
  {
    SetPinLow(clockpin1);
    {
      if(i<=7)
      {
        if(((buff1[0] >> (7-i)) & 1)==1)
        {
            SetPinHigh(datapin1);
        }else
        {
            SetPinLow(datapin1);
        }

        if(((buff2[0] >> (7-i)) & 1)==1)
        {
                SetPinHigh(datapin2);
        }else
        {
                SetPinLow(datapin2);
        }
      }else if(i>7)
      {
        if(((buff1[1] >> (15-i)) & 1)==1)
        {
            SetPinHigh(datapin1);
        }else
        {
            SetPinLow(datapin1);
        }

        if(((buff2[1] >> (15-i)) & 1)==1)
        {
                SetPinHigh(datapin2);
        }else
        {
                SetPinLow(datapin2);
        }
      }
    }
    SetPinHigh(clockpin1);
  }
  SetPinHigh(latchpin1);
}

void turnc(uint8_t c, bool cstt)
{
   switch(c)
  {
    case 1:
    {
      if(cstt==0)
      {
        buff1[1]&=0b11101111;
      }else if (cstt==1)
      {
        buff1[1]|=0b00010000;
      }
      //buff1[11]=cstt;
      break;
    }
    case 2:
    {
      if(cstt==0)
      {
        buff2[1]&=0b11111011;
      }else if (cstt==1)
      {
        buff2[1]|=0b00000100;
      }
      //buff2[13]=cstt;
      break;
    case 3:
    {
      if(cstt==0)
      {
        buff2[1]&=0b11110111;
      }else if (cstt==1)
      {
        buff2[1]|=0b00001000;
      }
      //buff2[12]=cstt;
      break;
    }
    }
    case 4:
    {
      if(cstt==0)
      {
        buff1[1]&=0b11111101;
      }else if (cstt==1)
      {
        buff1[1]|=0b00000010;
      }
      //buff1[14]=cstt;
      break;
    }
    case 5:
    {
      if(cstt==0)
      {
        buff2[1]&=0b11011111;
      }else if (cstt==1)
      {
        buff2[1]|=0b00100000;
      }
      //buff2[10]=cstt;
      break;
    }
    case 6:
    {
      if(cstt==0)
      {
        buff1[1]&=0b11111011;
      }else if (cstt==1)
      {
        buff1[1]|=0b00000100;
      }
      //buff1[13]=cstt;
      break;
    }
    case 7:
    {
      if(cstt==0)
      {
        buff1[1]&=0b10111111;
      }else if (cstt==1)
      {
        buff1[1]|=0b01000000;
      }
      //buff1[9]=cstt;
      break;
    }
    case 8:
    {
      if(cstt==0)
      {
        buff1[1]&=0b01111111;
      }else if (cstt==1)
      {
        buff1[1]|=0b10000000;
      }
      //buff1[8]=cstt;
      break;
    }
    case 9:
    {
      if(cstt==0)
      {
        buff1[0]&=0b11101111;
      }else if (cstt==1)
      {
        buff1[0]|=0b00010000;
      }
      //buff1[3]=cstt;
      break;
      
    }
    case 10:
    {
      if(cstt==0)
      {
        buff2[0]&=0b11111011;
      }else if (cstt==1)
      {
        buff2[0]|=0b00000100;
      }
      //buff2[5]=cstt;
      break;
    }
    case 11:
    {
      if(cstt==0)
      {
        buff2[0]&=0b11110111;
      }else if (cstt==1)
      {
        buff2[0]|=0b00001000;
      }
      //buff2[4]=cstt;
      break;
    }
      
    case 12:
    {
      if(cstt==0)
      {
        buff1[0]&=0b11111101;
      }else if (cstt==1)
      {
        buff1[0]|=0b00000010;
      }
      //buff1[6]=cstt;
      break;
      
    }
    case 13:
    {
      if(cstt==0)
      {
        buff2[0]&=0b11011111;
      }else if (cstt==1)
      {
        buff2[0]|=0b00100000;
      }
      //buff2[4]=cstt;
      break;
    }
    case 14:
    {
      if(cstt==0)
      {
        buff1[0]&=0b11111011;
      }else if (cstt==1)
      {
        buff1[0]|=0b00000100;
      }
      //buff1[5]=cstt;
      break;
      
    }
    case 15:
    {
       if(cstt==0)
      {
        buff1[0]&=0b10111111;
      }else if (cstt==1)
      {
        buff1[0]|=0b01000000;
      }
      //buff1[1]=cstt;
      break;
      
    }
    case 16:
    {
      if(cstt==0)
      {
        buff1[0]&=0b01111111;
      }else if (cstt==1)
      {
        buff1[0]|=0b10000000;
      }
      //buff1[1]=cstt;
      break;
      
    }
  }
}

void turnr(uint8_t r, bool rstt)
{
  switch(r)
  {
    case 1:
    {
      if(rstt==0)
      {
        buff1[0]&=0b11111110;
        buff1[1]&=0b11111110;
      }else if (rstt==1)
      {
        buff1[0]|=0b00000001;
        buff1[1]|=0b00000001;
      }
      break;
    }
    case 2:
    {
          if(rstt==0)
      {
        buff1[0]&=0b11011111;
        buff1[1]&=0b11011111;
      }else if (rstt==1)
      {
        buff1[0]|=0b00100000;
        buff1[1]|=0b00100000;
      }
      break;
    }
    case 3:
    {
       if(rstt==0)
      {
        buff2[0]&=0b01111111;
        buff2[1]&=0b01111111;
      }else if (rstt==1)
      {
        buff2[0]|=0b10000000;
        buff2[1]|=0b10000000;
      }
      //buff2[0]=rstt;
      //buff2[8]=rstt;
      break;
    }
    case 4:
    {
          if(rstt==0)
      {
        buff1[0]&=0b11110111;
        buff1[1]&=0b11110111;
      }else if (rstt==1)
      {
        buff1[0]|=0b00001000;
        buff1[1]|=0b00001000;
      }
      //buff1[4]=rstt;
      //buff1[12]=rstt;
      break;
    }
    case 5:
    {
          if(rstt==0)
      {
        buff2[0]&=0b11111110;
        buff2[1]&=0b11111110;
      }else if (rstt==1)
      {
        buff2[0]|=0b00000001;
        buff2[1]|=0b00000001;
      }
      //buff2[7]=rstt;
      //buff2[15]=rstt;
      break;
    }
    case 6:
    {
          if(rstt==0)
      {
        buff2[0]&=0b10111111;
        buff2[1]&=0b10111111;
      }else if (rstt==1)
      {
        buff2[0]|=0b01000000;
        buff2[1]|=0b01000000;
      }
      break;
    }
    case 7:
    {
          if(rstt==0)
      {
        buff2[0]&=0b11111101;
        buff2[1]&=0b11111101;
      }else if (rstt==1)
      {
        buff2[0]|=0b00000010;
        buff2[1]|=0b00000010;
      }
      break;
    }
    case 8:
    {
      if(rstt==0)
      {
        buff2[0]&=0b11101111;
        buff2[1]&=0b11101111;
      }else if (rstt==1)
      {
        buff2[0]|=0b00010000;
        buff2[1]|=0b00010000;
      }
      break;
    }
  }
}
