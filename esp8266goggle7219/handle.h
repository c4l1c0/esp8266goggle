void handleRoot() {
  //server.send(200, "text/html", mainIndex);
}
void handleBlink() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=1;
  lastAct=1;
}
void handleHeart() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=2;
  lastAct=2;
}
void handleHappy() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=3;
  lastAct=3;
}
void handleKawaii() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=4;
  lastAct=4;
}
void handleDizzy() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=5;
  lastAct=5;
}
void handleAngry() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=7;
  lastAct=7;
}
void handleSad() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=8;
  lastAct=8;
}

void handleZing() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=9;
  lastAct=9;
}
void handleWinkR() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=10;
  lastAct=10;
}
void handleWinkL() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=11;
  lastAct=11;
}

void handleFFT() {
  //server.send(200, "text/html", mainIndex);
  refresh=2;
  act=12;
  lastAct=12;
}

void handleSubmit(){
  //server.send(200, "text/html", mainIndex); 
  File file = SPIFFS.open("/index.html", "r");
  size_t sent = server.streamFile(file, "text/html");
  file.close();  
  
  String msg=server.arg("msgfromuser");
  Serial.println(msg);
  refresh=1;
  decodedMsg = msg;
  decodedMsg.replace("+", " ");      
  decodedMsg.replace("%21", "!");  
  decodedMsg.replace("%22", "");  
  decodedMsg.replace("%23", "#");
  decodedMsg.replace("%24", "$");
  decodedMsg.replace("%25", "%");  
  decodedMsg.replace("%26", "&");
  decodedMsg.replace("%27", "'");  
  decodedMsg.replace("%28", "(");
  decodedMsg.replace("%29", ")");
  decodedMsg.replace("%2A", "*");
  decodedMsg.replace("%2B", "+");  
  decodedMsg.replace("%2C", ",");  
  decodedMsg.replace("%2F", "/");   
  decodedMsg.replace("%3A", ":");    
  decodedMsg.replace("%3B", ";");  
  decodedMsg.replace("%3C", "<");  
  decodedMsg.replace("%3D", "=");  
  decodedMsg.replace("%3E", ">");
  decodedMsg.replace("%3F", "?");  
  decodedMsg.replace("%40", "@"); 
  act=6;
  lastAct=6;
}
