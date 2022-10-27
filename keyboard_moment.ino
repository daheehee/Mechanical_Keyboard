
#include <SoftwareSerial.h>
#include "keycode.h"
#include <Keyboard.h>
#include "PCF8575.h"


PCF8575 pcf8575(0x20); 


// GPIO corresponding to HID keycode (not Ancii Character)
int Key[7] =
{ 0,0,0,0,0,0,0};
int command[4] =
{ KEY_LEFT_GUI,KEY_LEFT_ALT,KEY_LEFT_CTRL,KEY_LEFT_SHIFT};
int modifier[3] =
{ 99,118,97};


 int inputKeycodes[7] [17] = {
{ KEY_ESC, 0, KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F10,KEY_F11,KEY_F12,100000,100001,100002},
{ 96, 49,50 ,51 ,52,53,54,55,56,57,48,45,61,KEY_BACKSPACE,0,0,0},
{ KEY_TAB, 113,119 ,101 ,114,116,121,117,105,111,112,91,93,92,100007,100008,100009},
{ KEY_CAPS_LOCK, 97,115,100,102,103,104,106,107,108,59,39,0,KEY_RETURN,0,0,0},
{ KEY_LEFT_SHIFT, 122,120,99,118,98,110,109,44,46,47,0,KEY_LEFT_SHIFT,0,0,0,0},
{ KEY_LEFT_CTRL, KEY_LEFT_ALT,KEY_LEFT_GUI,0,0,32,0,0,0,0,KEY_LEFT_GUI,KEY_LEFT_ALT,KEY_LEFT_CTRL,10010,0,0,0}};

void setup() {
delay(500);

Serial.begin(115200);
  
Keyboard.begin();

//pinmode 
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(14, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(16, INPUT_PULLUP);
pcf8575.pinMode(P6, OUTPUT);
pcf8575.pinMode(P7,OUTPUT);
pcf8575.pinMode(P5,OUTPUT);
pcf8575.pinMode(P4,OUTPUT);
pcf8575.pinMode(P3,OUTPUT);
pcf8575.pinMode(P2,OUTPUT);
pcf8575.pinMode(P1,OUTPUT);
pcf8575.pinMode(P0,OUTPUT);
pcf8575.pinMode(P10,OUTPUT);
pcf8575.pinMode(P11,OUTPUT);
pcf8575.pinMode(P12,OUTPUT);
pcf8575.pinMode(P13,OUTPUT);
pcf8575.pinMode(P14,OUTPUT);
pcf8575.pinMode(P15,OUTPUT);
pcf8575.pinMode(P9,OUTPUT);
pcf8575.pinMode(P8,OUTPUT);

  pcf8575.begin();
}

void loop() {
for (int p = 0; p <= 15; p++) {
for (int i = 0; i <= 15; i++) {
   pcf8575.digitalWrite(i,HIGH);
   if (i==p){
    pcf8575.digitalWrite(i,LOW);
   }
}

  //row 123
 if ( digitalRead(16) == LOW )
      {
        if (p == 14){
        Keyboard.press(command[0]);
        Keyboard.press(modifier[0]);
        }
        else if (p == 15){
        Keyboard.press(command[0]);
        Keyboard.press(modifier[1]);
        }
        else if (p == 16){
        Keyboard.press(command[0]);
        Keyboard.press(modifier[2]);
        }
        else{
          Key[1] = inputKeycodes[1][p];
        }
       
        
      }else
      {
        Key[1] = 0;
      }

   while ( digitalRead(16)== LOW)
      {
        // Send keyboard report
        Keyboard.press(Key[1]);
        
      }   
Keyboard.releaseAll();

//row qwe
if ( digitalRead(5) == LOW )
      {
        Key[2] = inputKeycodes[2][p];
      }else
      {
        Key[2] = 0;
      }
   while ( digitalRead(5)== LOW)
      {
        // Send keyboard report
        Keyboard.press(Key[2]);
        
      }   
Keyboard.releaseAll();   

//row alt, control, window
 if ( digitalRead(9) == LOW )
      {
        Key[4] = inputKeycodes[5][p];
      }else
      {
        Key[4] = 0;
      }
      // Only send if it is not the same cs previous reportfffffffffffffffffffffffffffffffnncl;ccc
   while ( digitalRead(9)== LOW)
      {
        // Send keyboard report
        Keyboard.press(Key[4]);

      
      }   
Keyboard.releaseAll();

//row asd
if ( digitalRead(7) == LOW )
      {
        Key[3] = inputKeycodes[3][p];
      }else
      {
        Key[3] = 0;
      }
      // Only send if it is not thesame as previous reportfffffffffffffffffffffffffffffffnn
      while ( digitalRead(7)== LOW)
      {
        // Send keyboard report
        Keyboard.press(Key[3]);

        
      }   

Keyboard.releaseAll();

//row zxc
 if ( digitalRead(8) == LOW )
      {
        Key[5] = inputKeycodes[4][p];
      }else
      {
        Key[5] = 0;
      }
      while ( digitalRead(8)== LOW)
      {
        // Send keyboard report
        Keyboard.press(Key[5]);

        
      }   
Keyboard.releaseAll();

}
}
