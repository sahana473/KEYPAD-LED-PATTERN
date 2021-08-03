/* Problem Statement:
 *  This program is to generate first five LED patterns as shown in the following video when Keypad key is pressed.
 *  https://www.facebook.com/watch/?v=437404777682929 
 *  
 * Hardware Component :  
 * Arduino Uno 
 * Led Bargraph
 * 4x3 Matrix keypad
 *   
 * Hardware connection:
 * D5,D4,D3,D2 of Arduino Uno pins are connected to A, B, C, D row pin of keypad
 * D6,D7,D8 of Arduino Uno pins are connected to 3 , 2, 1 column pin of keypad
 * D9-D12 of Arduino Uno pins are connected to 6,5,4,3 of Led Bargraph
 * D0,D1 of Arduino Uno pins are connected to TXD,RXD pin of Serial Monitor
 * 
 * Author : Sahana B G
 * Date: 30 Apr 2021
 * 
 */
// Include the header file:
#include <Keypad.h>

// Pins for declaring first and last pins of Arduino
const unsigned int FIRSTPIN = 9;
const unsigned int LASTPIN = 12;

// Buzzer Pin
const unsigned int BUZZER = 13;

// Keypad initialization
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

// Keypad declaration
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);

  // Configure D4-D13 pins to OUTPUT mode
  for(int i=FIRSTPIN;i<=LASTPIN;i++)
  {
   pinMode(i,OUTPUT);
  }
  pinMode(BUZZER,OUTPUT);

}
  
void loop()
{
  // Read the key value
  char key = keypad.getKey();

  // If key is pressed 
  if(key)
  {
    
  // Display in Serial monitor  
  Serial.println(key);
  
  switch (key)
  {
    case '1' :pattern1();break;
    case '2' :pattern2();break;
    case '3' :pattern3();break;
    case '4' :pattern4();break;
    case '5' :pattern5();break;
    case '*' :digitalWrite(BUZZER,HIGH);break;
  }
  }
}

void pattern1()
{
  // Generate pattern no 1 
  for(int i=FIRSTPIN;i<=LASTPIN;i++)
  {
   digitalWrite(i,HIGH);
   delay(100);
   digitalWrite(i,LOW);
  }
  
  for(int i=LASTPIN;i>=FIRSTPIN;i--)
  {
   digitalWrite(i,HIGH);
   delay(500);
   digitalWrite(i,LOW);
  }
}
void  pattern2()
{
  for(int i=FIRSTPIN;i<=LASTPIN;i++)
  {
   digitalWrite(i,HIGH);
   digitalWrite(i+1,HIGH);
   digitalWrite(i+2,HIGH);
   delay(1000);
   digitalWrite(i,LOW);
   digitalWrite(i+1,LOW);
   digitalWrite(i+2,LOW);
  }
  for(int i=LASTPIN;i>=FIRSTPIN;i--)
  {
   digitalWrite(i,HIGH);
   digitalWrite(i-1,HIGH);
   digitalWrite(i-2,HIGH);
   delay(100);
   digitalWrite(i,LOW);
   digitalWrite(i-1,LOW);
   digitalWrite(i-2,LOW);
  }
}

void pattern3()
{
  // Generate pattern no 3
   for(int i=FIRSTPIN;i<=LASTPIN;i++)
   {
    digitalWrite(i,HIGH);
    delay(100);
   }
   for(int i=LASTPIN;i>=FIRSTPIN;i--)
   {
    digitalWrite(i,LOW);
    delay(100);
   }
}

void pattern4()
{
  // Generate pattern no 4
 for(int i=FIRSTPIN;i<=LASTPIN;i++)
 {
  for(int j=1;j<=i-3 ;j++){ 
    digitalWrite(i,HIGH);
    delay(100);    
    digitalWrite(i,LOW);
    delay(100);
  }
 }
}

void pattern5()
{
  // Generate pattern no 5
  int totalLEDPins = LASTPIN-FIRSTPIN+1; // This variable stores total number of led pin connected to ardunio
  int loopCount = totalLEDPins/2; // This variable stores half of the led pins which is required by the pattern
  for(int i=0;i<loopCount;i++)
  {
   digitalWrite(i+FIRSTPIN,HIGH);
   digitalWrite(LASTPIN-i,HIGH);
   delay(1000);
    }
 }
