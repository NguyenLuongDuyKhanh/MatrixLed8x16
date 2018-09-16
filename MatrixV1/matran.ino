#define clockpin1 2
#define clockpin2 4

#define latchpin1 3
#define latchpin2 5

#define datapin1 0
#define datapin2 1

//#define clockpin1 A3
//#define clockpin2 A2
//
//#define latchpin1 A1
//#define latchpin2 A0
//
//#define datapin1 A5
//#define datapin2 A4

#define R1 7
#define R2 2
#define R3 0
#define R4 4
#define R5 7
#define R6 1
#define R7 6
#define R8 3
#define R9 15
#define R10 10
#define R11 8
#define R12 12
#define R13 15
#define R14 9
#define R15 14
#define R16 11
//C8,C7,R2,C1,R4,C6,C4,R1,C16,C15,R10,C9,R12,C14,C12,R9
//R3,R6,C5,R8,C3,C2,R7,R5,R11,R14,C13,R16,C11,C10,R15,R13
#define C1 3
#define C2 5
#define C3 4
#define C4 6
#define C5 2
#define C6 5
#define C7 1
#define C8 0
#define C9 11
#define C10 13
#define C11 12
#define C12 14
#define C13 10
#define C14 13
#define C15 9
#define C16 8

byte TODOS[] = {11111111,11111111,11111111,11111111,11111111,11111111,11111111,11111111};
byte EX[] = {00000000,00010000,00010000,00010000,00010000,00000000,00010000,00000000};
byte A[] = {00000000,00011000,00100100,00100100,00111100,00100100,00100100,00000000};
byte B[] = {01111000,01001000,01001000,01110000,01001000,01000100,01000100,01111100};
byte C[] = {00000000,00011110,00100000,01000000,01000000,01000000,00100000,00011110};
byte D[] = {00000000,00111000,00100100,00100010,00100010,00100100,00111000,00000000};
byte E[] = {00000000,00111100,00100000,00111000,00100000,00100000,00111100,00000000};
byte F[] = {00000000,00111100,00100000,00111000,00100000,00100000,00100000,00000000};
byte G[] = {00000000,00111110,00100000,00100000,00101110,00100010,00111110,00000000};
byte H[] = {00000000,00100100,00100100,00111100,00100100,00100100,00100100,00000000};
byte I[] = {00000000,00111000,00010000,00010000,00010000,00010000,00111000,00000000};
byte J[] = {00000000,00011100,00001000,00001000,00001000,00101000,00111000,00000000};
byte K[] = {00000000,00100100,00101000,00110000,00101000,00100100,00100100,00000000};
byte L[] = {00000000,00100000,00100000,00100000,00100000,00100000,00111100,00000000};
byte M[] = {00000000,00000000,01000100,10101010,10010010,10000010,10000010,00000000};
byte N[] = {00000000,00100010,00110010,00101010,00100110,00100010,00000000,00000000};
byte O[] = {00000000,00111100,01000010,01000010,01000010,01000010,00111100,00000000};
byte P[] = {00000000,00111000,00100100,00100100,00111000,00100000,00100000,00000000};
byte Q[] = {00000000,00111100,01000010,01000010,01000010,01000110,00111110,00000001};
byte R[] = {00000000,00111000,00100100,00100100,00111000,00100100,00100100,00000000};
byte S[] = {00000000,00111100,00100000,00111100,00000100,00000100,00111100,00000000};
byte T[] = {00000000,01111100,00010000,00010000,00010000,00010000,00010000,00000000};
byte U[] = {00000000,01000010,01000010,01000010,01000010,00100100,00011000,00000000};
byte V[] = {00000000,00100010,00100010,00100010,00010100,00010100,00001000,00000000};
byte W[] = {00000000,10000010,10010010,01010100,01010100,00101000,00000000,00000000};
byte X[] = {00000000,01000010,00100100,00011000,00011000,00100100,01000010,00000000};
byte y[] = {00000000,01000100,00101000,00010000,00010000,00010000,00010000,00000000};
byte Z[] = {00000000,00111100,00000100,00001000,00010000,00100000,00111100,00000000};

bool ic1[]={0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1};
          //C8,C7,R2,C1,R4,C6,C4,R1,C16,C15,R10,C9,R12,C14,C12,R9
bool ic2[]={1,1,0,1,0,0,1,1,1,1,0,1,0,0,1,1};
          //R3,R6,C5,R8,C3,C2,R7,R5,R11,R14,C13,R16,C11,C10,R15,R13


//bool ic1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//bool ic2[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup()
{
  // cài đặt timer
  //TCCR0B |=  _BV(CS02)  ;  
  
  pinMode(clockpin1,OUTPUT);
  //pinMode(clockpin2,OUTPUT);
  pinMode(latchpin1,OUTPUT);
  pinMode(latchpin2,OUTPUT);
  pinMode(datapin1,OUTPUT);
  pinMode(datapin2,OUTPUT);
}

int timer = 150;

void _delay(word time = 1) { // Xâby dựng lại hàm delaby
  for (word i = 1; i<=time;i++) {
    delayMicroseconds(timer);
  }
}


void on(int R,int C)
{
  
}

void printscreen(bool ic1[],bool ic2[])
{
  digitalWrite(latchpin1,LOW);
  digitalWrite(latchpin2,LOW);

  for(int i=0;i<16;i++)
  {
    digitalWrite(clockpin1,LOW);
    //digitalWrite(clockpin2,LOW);
    digitalWrite(datapin1,ic1[i]);
    digitalWrite(datapin2,ic2[i]);
    digitalWrite(clockpin1,HIGH); 
    digitalWrite(clockpin2,HIGH); 
  }
  digitalWrite(latchpin1,HIGH);
  digitalWrite(latchpin2,HIGH);
    delay(1000);
  digitalWrite(latchpin1,LOW);
  digitalWrite(latchpin2,LOW);
  for(int i=0;i<16;i++)
  {
    digitalWrite(clockpin1,LOW);
    //digitalWrite(clockpin2,LOW);
    digitalWrite(datapin1,~ic1[i]);
    digitalWrite(datapin2,~ic2[i]);
    digitalWrite(clockpin1,HIGH); 
    //digitalWrite(clockpin2,HIGH); 
  }
    digitalWrite(latchpin1,HIGH);
    digitalWrite(latchpin2,HIGH);
  delay(1000);
}

void updatebuff()
{
  for(int i=0;i<16;i++);
}

void loop()
{
  printscreen(ic1,ic2);
}

