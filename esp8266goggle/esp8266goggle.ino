#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>


const char* ssid = "Akai-B-48";
const char* password = "cepikharies";
int timeBlink;
int act=0;
int refresh=0;
int lastAct;
String decodedMsg="ITB Insight 2017";

ESP8266WebServer server(80);

IPAddress    apIP(192, 168, 0, 1);


int pinCS = D1; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 3;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "Arduino";
int wait = 40; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels


                                                        

String mainIndex=
"<div style=\"width:100vw\">"
"<a style=\"font-size:8em;\" href=\"/blink\">blink normally</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/heart\">heart eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/happy\">happy eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/kawaii\">kawaii eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/dizzy\">dizzy eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/angry\">angry eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/sad\">sad eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/exclamation\">exclamation eye</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/winkr\">wink right</a>"
"<br>"
"<a style=\"font-size:8em;\" href=\"/winkl\">wink left</a>"
"<br>"
"<form style=\"font-size:5em;\" action=\"/submit\" method=\"POST\">"
"<br>Enter any text: <input style=\"font-size:3em;\" type='text' name='msgfromuser' size=100> <br> <input style=\"font-size:3em;\" type='submit' value='Submit'></form>"
"</div>";


#include "dizzy.h"
#include "eyecollection.h"
#include "zing.h"
#include "handle.h"

void writeKawaii(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,kawaiiLeft,8,8,HIGH);
  matrix.drawBitmap(8,0,kawaiiRight,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  act=0;
}

void writeSad(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,slantedLeft,8,8,HIGH);
  matrix.drawBitmap(8,0,slantedRight,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  act=0;
}

void writeAngry(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,slantedRight,8,8,HIGH);
  matrix.drawBitmap(8,0,slantedLeft,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  act=0;
}


void writeLove(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,lovesign,8,8,HIGH);
  matrix.drawBitmap(8,0,lovesign,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  act=0;
}

void writeWinkLeft(){
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,0+i,6,8-2*i,2,HIGH);
  matrix.fillRoundRect(9,0,6,8,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(20,40));
  }
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,3-i,6,2+2*i,2,HIGH);
  matrix.fillRoundRect(9,0,6,8,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(15,40));
  }
  act=0;
}

void writeWinkRight(){
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,0,6,8,2,HIGH);
  matrix.fillRoundRect(9,0+i,6,8-2*i,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(15,40));
  }
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,0,6,8,2,HIGH);
  matrix.fillRoundRect(9,3-i,6,2+2*i,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(15,40));
  }
  act=0;
}

void roundEyeBlinking(){
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,0+i,6,8-2*i,2,HIGH);
  matrix.fillRoundRect(9,0+i,6,8-2*i,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(15,40));
  }
  for(int i=0;i<4;i++){
  matrix.fillScreen(LOW);
  matrix.fillRoundRect(1,3-i,6,2+2*i,2,HIGH);
  matrix.fillRoundRect(9,3-i,6,2+2*i,2,HIGH);
  matrix.write();
  server.handleClient();
  delay(random(15,40));
  }
  act=0;
}

void writeHappyEye(){
  for(int j=0;j<2;j++){
  for(int i=2;i>=0;i--){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,i,happyEye,8,6,HIGH);
  matrix.drawBitmap(8,i,happyEye,8,6,HIGH);
  server.handleClient();
  delay(50);
  
  matrix.write();
  } 
  for(int i=0;i<=2;i++){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,i,happyEye,8,6,HIGH);
  matrix.drawBitmap(8,i,happyEye,8,6,HIGH);
  server.handleClient();
  matrix.write();
  delay(50);
  }
  }
  act=0;
}

void writeDizzy(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy1,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy7,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy2,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy8,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy3,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy9,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy4,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzyA,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy5,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzyB,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy6,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy1,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy7,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy2,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy8,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy3,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzy9,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy4,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzyA,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy5,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,dizzyB,8,8,HIGH);
  matrix.drawBitmap(8,0,dizzy6,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(65);
}

void writeZing(){
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing1,8,8,HIGH);
  matrix.drawBitmap(8,0,zing1,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing2,8,8,HIGH);
  matrix.drawBitmap(8,0,zing2,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing3,8,8,HIGH);
  matrix.drawBitmap(8,0,zing3,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing4,8,8,HIGH);
  matrix.drawBitmap(8,0,zing4,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing5,8,8,HIGH);
  matrix.drawBitmap(8,0,zing5,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing6,8,8,HIGH);
  matrix.drawBitmap(8,0,zing6,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing7,8,8,HIGH);
  matrix.drawBitmap(8,0,zing7,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing8,8,8,HIGH);
  matrix.drawBitmap(8,0,zing8,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zing9,8,8,HIGH);
  matrix.drawBitmap(8,0,zing9,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zingA,8,8,HIGH);
  matrix.drawBitmap(8,0,zingA,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0,0,zingB,8,8,HIGH);
  matrix.drawBitmap(8,0,zingB,8,8,HIGH);
  matrix.write(); // Send bitmap to display
  server.handleClient();
  delay(30);
  act=0;
}

void writeUserText(){
  matrix.setPosition(0, 0, 0); 
  matrix.setPosition(1, 2 ,0); 
  matrix.setPosition(2, 1 ,0); 
  for ( int i = 0 ; i < width * decodedMsg.length() + matrix.width() - 1 - spacer; i++ ) {
    server.handleClient();                        // checks for incoming messages
    if (refresh==1) i=0;
    else if(refresh==2){
      refresh=0;
      matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
      matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
      matrix.setPosition(2, 2, 0); // The second display is at <1, 0>
      break;
    }
    refresh=0;
    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically
 
    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < decodedMsg.length() ) {
        matrix.drawChar(x, y, decodedMsg[letter], HIGH, LOW, 1);
        }

      letter--;
      x -= width;
    }
    matrix.write();
    delay(wait);
  }
  matrix.setPosition(0, 0, 0); 
  matrix.setPosition(1, 1 ,0); 
  matrix.setPosition(2, 2 ,0); 
}

void setup() {
  Serial.begin(9600);
  Serial.println("");
  WiFi.mode(WIFI_AP);           //Only Access point
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid, password);  //Start HOTspot removing password will disable security
 
  IPAddress myIP = WiFi.softAPIP(); //Get IP address
  Serial.print("HotSpt IP:");
  Serial.println(myIP);
 
  server.on("/", handleRoot);      //Which routine to handle at root location
  server.on("/blink", handleBlink);
  server.on("/heart", handleHeart);
  server.on("/happy", handleHappy);
  server.on("/kawaii", handleKawaii);
  server.on("/dizzy", handleDizzy);
  server.on("/submit", handleSubmit);
  server.on("/angry", handleAngry);
  server.on("/sad", handleSad);
  server.on("/exclamation", handleZing);
  server.on("/winkr", handleWinkR);
  server.on("/winkl", handleWinkL);
 
  server.begin();                  //Start server
  Serial.println("HTTP server started"); 
  matrix.setRotation(1);
  matrix.setIntensity(8); // Use a value between 0 and 15 for brightness
  

  // Adjust to your own needs
  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
  matrix.setPosition(2, 2, 0); // The second display is at <1, 0>
  roundEyeBlinking();
  timeBlink=random(500,5000);
  act=1;
  lastAct=1;
}

int currTime=0;

void loop() {
  if(act==0)server.handleClient();
  else if(act==1){
    roundEyeBlinking();
    server.handleClient();
  }
  else if(act==2){
    writeLove();
    server.handleClient();
  }
  else if(act==3){
    writeHappyEye();
    server.handleClient();
  }
  else if(act==4){
    writeKawaii();
    server.handleClient();
  }
  else if(act==5){
    writeDizzy();
    server.handleClient();
  }
  else if(act==6){
    writeUserText();
    server.handleClient();
  }
  else if(act==7){
    writeAngry();
    server.handleClient();
  }
  else if(act==8){
    writeSad();
    server.handleClient();
  }
  else if(act==9){
    writeZing();
    server.handleClient();
  }

  else if(act==10){
    writeWinkRight();
    delay(25);
    writeWinkRight();
    server.handleClient();
  }

  else if(act==11){
    writeWinkLeft();
    delay(25);
    writeWinkLeft();
    server.handleClient();
  }
  if((millis()-currTime)>timeBlink){
    if(lastAct==1){
      act=1; 
    }
    else if(lastAct==3){
      act=3;
    }
    else if(lastAct==6){
      act=6;
    }
    timeBlink=random(500,5000);
    currTime=millis();
  }
}

