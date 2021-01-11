/*
  NodeMCU for P4.75 by rizapn@gmail.com
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "font.h"
#include <ArduinoOTA.h>
#include <asyncHTTPrequest.h>
#include <Ticker.h>

Ticker ticker,ticker2;
asyncHTTPrequest webClient;
//WiFiClient webClient;
//WiFiServer server(80);

ESP8266WebServer server(80);

/*
#define P_RX  3
#define P_TX  1         // ok-for-output
#define P_A   D1
#define P_B   D2
#define P_C   D8
#define P_D   D6
#define P_R1  D3
#define P_G1  D7
#define P_OE  D4        // GPIO02
#define P_LAT D0
#define P_CLK D5
*/

/* WEMOS D1 MINI PINOUT */
#define P_A   D8
#define P_B   D7
#define P_C   D6
#define P_D   D5
#define P_R1  D1
#define P_G1  D0
#define P_OE  D2        // GPIO02
#define P_LAT D3
#define P_CLK D4

#define WIDTH0      64
#define HEIGHT0     16
#define GRAY_LEVEL  4
#define WIDTH       64
#define HEIGHT      16
#define NW WIDTH/WIDTH0
#define NH HEIGHT/HEIGHT0
#define BUFSIZE WIDTH*HEIGHT
#define SHIFT   WIDTH0*HEIGHT0

uint8_t displaybuf[BUFSIZE];

#define MAX_TEXT   16
#define MAX_PRG    100
#define MAX_SCREEN 10
#define MAX_SCRPRG 16
#define PRG_ITEM   20
#define MAX_PARS   255
#define MAX_UPDATE 24

byte brightness = 10*NH;
byte SCREEN_PAUSE = 0;

/*  byte1 : type (clock1/clock2/scrolling/static)
 *  byte2 : x
 *  byte3 : y
 *  byte4 : xl
 *  byte5 : yu
 *  byte6 : xr
 *  byte7 : yd
 *  byte8 : font_id
 *  byte9 : color
 *  byte10 : bgcolor
 *  byte11 : textbuf-id
 *  byte12 : textbuf-ofs
 *  byte13 : textbuf-len
 *  byte14 : num
 *  byte15 : delay
 */

char textbuf[MAX_TEXT][255];            // buffer of all text used by program
byte prgbuf[MAX_PRG][PRG_ITEM];         // buffer of each-program
byte scrbuf[MAX_SCREEN][MAX_SCRPRG];    // buffer of screen (containing max 8 program)
uint16_t scrdelay[MAX_SCREEN];          // delay for screen
uint16_t curpos[MAX_TEXT];              // current-pos for running-text
uint16_t txtwidth[MAX_TEXT];            // text width
//byte txtdelay[MAX_TEXT];                // running-text delay
byte txtcloop[MAX_TEXT];                // current-loop counter for running-text
//byte rotdelay[MAX_TEXT];                // text-rotation delay
uint16_t rotdelay0[MAX_TEXT];               // text-rotation current-delay counter
byte rotcurr[MAX_TEXT];                 // text-rotation current-id
byte updtime[2*MAX_UPDATE];             // auto-update time

byte hh,ss;
byte mm = 99;
byte fmt_jam = 1;
char jam[10];
byte clr_jam = 0;
byte LAST_SCR = MAX_SCREEN+1;
byte CURR_SCR = 0;
uint16_t screentime = 0;
byte wifiok = 0;

byte siap = 0;

const char* ssid = "TAMU";
const char* pwd = "081294340345";
const char stBusy[4] = {'-','\\','|','/'};
byte bloop = 0;
byte bldelay = 0;

long waktu0 = 0;
byte dot = 1;
String scWeb;

char myIP[16];          // 255.255.255.255

void begin() {
  pinMode(P_A,OUTPUT);
  pinMode(P_B,OUTPUT);
  pinMode(P_C,OUTPUT);
  pinMode(P_D,OUTPUT);
  pinMode(P_R1,OUTPUT);
  pinMode(P_G1,OUTPUT);
  pinMode(P_OE,OUTPUT);
  pinMode(P_LAT,OUTPUT);
  pinMode(P_CLK,OUTPUT);
  memset(textbuf,0,sizeof(textbuf));
  memset(prgbuf,0,sizeof(prgbuf));
  memset(scrbuf,0,sizeof(scrbuf));
  memset(curpos,0,sizeof(curpos));
  memset(txtwidth,0,sizeof(txtwidth));
  memset(txtcloop,0,sizeof(txtcloop));
  memset(rotdelay0,0,sizeof(rotdelay0));
  memset(rotcurr,0,sizeof(rotcurr));
  memset(updtime,99,sizeof(updtime));
}

void clearDsp() {
  memset(displaybuf,0,sizeof(displaybuf));
}

void fillArea(int xl, int yu, int xr, int yd, byte color) {
  for (int y=yu; y<=yd; y++)
    for (int x=xl; x<=xr; x++)
      displaybuf[x+y*WIDTH] = color;
}

byte getHMS(byte xtmp) {
  unsigned long tmp1 = waktu0+millis()/1000;
  ss = tmp1%60;
  tmp1 /= 60;
  mm = tmp1%60;
  tmp1 /= 60;
  hh = tmp1%24;
  if (fmt_jam==2 && ss!=xtmp) sprintf(jam,"%02d:%02d:%02d ",hh,mm,ss);
  else if (fmt_jam==1 && mm!=xtmp) {
    sprintf(jam,"%02d_M:_M%02d",hh,mm);
    char color = 'A'+clr_jam;
    jam[3] = color;
    jam[6] = color;
  }
  else return (1+ss);
  return 0;
}

void setPrg(byte prgid, char dt[PRG_ITEM]) {
  if (prgid<=0 || prgid>MAX_PRG) return;
  prgid--;
  memset(prgbuf[prgid],0,sizeof(prgbuf[0]));
  memcpy(prgbuf[prgid],dt,PRG_ITEM);
}

void setText(byte textid, byte pos, byte len, String str) {
  if (textid>=MAX_TEXT) return;
  if (len+pos>255) len = 255-pos;
  memset(&textbuf[textid][pos],0,len);
  str.toCharArray(&textbuf[textid][pos],len);
}

void setText(byte textid, byte pos, byte len, char txt[]) {
  if (textid>=MAX_TEXT) return;
  if (len+pos>255) len = 255-pos;
  memset(&textbuf[textid][pos],0,len);
  memcpy(&textbuf[textid][pos],txt,len);
}

void setScreen(byte scrid, uint16_t wd, char prg[]) {
  if (scrid>=MAX_SCREEN) return;
  memset(scrbuf[scrid],0,MAX_SCRPRG);
  scrdelay[scrid] = wd;
  memcpy(scrbuf[scrid],prg,MAX_SCRPRG);
}

String stPanel = "rpnPANEL v1.0";

void wait4wifi() {
  if (WiFi.status() != WL_CONNECTED) return;
  ticker2.detach();
  clearDsp();
  wifiok = 1;
  server.on("/",GetMessage);
  server.begin();
  printString("Wifi Connected.",0,0,0,0,WIDTH-1,8,0,0b1100,0);
  printString(WiFi.localIP().toString().c_str(),0,0,0,5,WIDTH-1,10,0,0b1010,0);
  Serial.println(WiFi.localIP());
  printString(stPanel,0,0,0,11,WIDTH-1,15,0,0b0011,0);
  webClient.onReadyStateChange(getWebResponse);
  scWeb = "init.php";
  ticker.attach(2,webCmds);
  siap = 1;
}

void setup() {
  begin();
  Serial.begin(115200);
  digitalWrite(P_OE, HIGH);
  printString("Trying wifi ...",0,0,0,0,WIDTH-8,8,0,0b1010,0);
  WiFi.begin(ssid, pwd);
  ticker2.attach(2,wait4wifi);
/*  
  long tx = millis();
  while (WiFi.status() != WL_CONNECTED && millis()-tx<30000) dspBusy(0);
  dspBusy(' ');
  clearDsp();
  if (WiFi.status() != WL_CONNECTED) {
    printString(stPanel,0,0,0,2,63,14,1,3,0);
  }
  else {
    wifiok = 1;
    printString("Wifi Connected.",0,0,0,0,WIDTH-1,8,0,0b1100,0);
    printString(WiFi.localIP().toString().c_str(),0,0,0,5,WIDTH-1,10,0,0b1010,0);
    Serial.println(WiFi.localIP());
    printString(stPanel,0,0,0,11,WIDTH-1,15,0,0b0011,0);
    webClient.onReadyStateChange(getWebResponse);
    scWeb = "init.php";
    ticker.attach(2,webCmds);
    server.on("/",GetMessage);
    server.begin();
  }
  siap = 1;
*/
  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  
  Serial.println("READY ...");
}

void GetMessage() {
  String cmd;
  if (server.args()>0) {
    cmd = server.arg(0);
    doCmds(cmd,0);
  }
  server.sendHeader("access-control-allow-credentials", "false");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  String up = "";
  byte c;
  for (byte i=0; i<sizeof(updtime); i++) {
    c = updtime[i];
    if (c>=99) break;
    up += String(c, DEC)+",";
  }
  server.send(200,"text/plain",cmd+"\r\n"+up+"\r\n");
}

void getWebResponse(void* optParm, asyncHTTPrequest* request, int readyState) {
  if (readyState!=4) return;
  String html = request->responseText();
  doCmds(html,'=');
  ticker.detach();
}

void webCmds() {
  if (webClient.readyState()==0 || webClient.readyState()==4) {
    String url = "http://192.168.53.53/LED/"+scWeb;
    char tmp[255];
    memset(tmp,0,255);
    url.toCharArray(tmp,255);
    webClient.open("GET", tmp);
    webClient.send();
  }
}

/*
void webCmds(String url) {
  if (!webClient.connect(host, 80)) return;
  webClient.print("GET /LED/"+url+"\r\n");
  byte rept = 0;
  while (!webClient.available() && rept<30) {
    //dspBusy(0);
    myDelay(100);
    rept++;
  }
  //dspBusy(' ');
  webClient.setSync(true);
  byte i = 0;
  String line = webClient.readStringUntil('~');
  webClient.stop();
  doCmds(line,'=');
}
*/

void myDelay(int ms) {
  long tm = millis();
  while (millis()-tm<ms) {
    display(); 
    delay(10);
  }
}

void display() {
  uint8_t c = 0;
  uint8_t r,g;
  int pos;
  int apos;
  uint8_t *ptr0, *ptr;
  for (uint8_t lx=1; lx<GRAY_LEVEL; lx++) {
    ptr0 = displaybuf;
    for (uint8_t y=0; y<HEIGHT0; y++) {
      digitalWrite(P_A,y&1);
      digitalWrite(P_B,y&2);
      digitalWrite(P_C,y&4);
      digitalWrite(P_D,y&8);
      int8_t yy = NH;
      while (yy>0) {
        yy--;
        ptr = ptr0+yy*SHIFT;
        for (uint8_t x=0; x<WIDTH; x++) {
          r = *ptr & 0b11;
          g = (*ptr>>2) & 0b11;
          if (r<lx) r = 0;
          if (g<lx) g = 0;
          digitalWrite(P_R1, r);
          digitalWrite(P_G1, g);
          digitalWrite(P_CLK, HIGH);
          digitalWrite(P_CLK, LOW);
          ptr++;
        }
      }
      digitalWrite(P_LAT, LOW);
      digitalWrite(P_LAT, HIGH);
      digitalWrite(P_LAT, LOW);
      digitalWrite(P_OE, LOW);                // display ON
      unsigned long start_time=micros();
      while ((micros()-start_time)<brightness)
        asm volatile (" nop ");
      digitalWrite(P_OE, HIGH);               // display OFF
      ptr0 += WIDTH0;
    }
  }
}

void dspScreen(byte flag) {
  if (scrdelay[CURR_SCR]==0 || SCREEN_PAUSE==1) return;
  byte i,j,prg;
  i = 0;
  char tmp[20];
  while (i<MAX_SCRPRG) {
    prg = scrbuf[CURR_SCR][i];
    //if (LAST_SCR!=CURR_SCR) { Serial.print(i); Serial.print(":"); Serial.print(prg); Serial.print(","); }
    if (prg==0) break;
    if (prg>MAX_PRG) {
      if (CURR_SCR!=LAST_SCR) clearDsp(); 
      i++;
      continue;
    }
    byte* buf = prgbuf[prg-1];
    if (buf[0]==1 || buf[0]==2) {                       // clock
      fmt_jam = buf[0];
      clr_jam = buf[8];
      byte xss = getHMS(mm);
      if (flag==1) {
        if (xss==0) dot = 1; else dot = 1-dot;
        if (fmt_jam==1) {
          jam[3] = 'A'+(clr_jam*dot);
          jam[6] = 'A'+clr_jam;
        }
        printString(jam,buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],clr_jam,buf[9]);
      }
    }
    else if (buf[0]==4) {                               // running-text : pars,id,ofs,len,
      byte rid = buf[10];
      byte r = 0;
      uint16_t cr = curpos[rid];
      if (txtwidth[rid]==0) {
        //Serial.println((String)&textbuf[rid][buf[11]]);
        txtwidth[rid] = (buf[5]-buf[3])+strLength(&textbuf[rid][buf[11]],buf[7]);
        //txtdelay[rid] = buf[1];
        txtcloop[rid] = 0;
        curpos[rid] = 0;
        r = 1;
      }
      else {
        txtcloop[rid]++;
        //if (txtcloop[rid]>=txtdelay[rid]) {
        if (txtcloop[rid]>=buf[1]) {                // text delay
          r = 1;
          txtcloop[rid] = 0;
          cr++;
          if (cr>txtwidth[rid]) cr = 0;
          curpos[rid] = cr;
        }
      }
      if (r==1) printString(&textbuf[rid][buf[11]],(buf[5]-buf[3])-cr,buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9]);
    }
    else if (buf[0]==6) {     // rotated-text : pars,id,ofs,len,rid,num,delay
      byte rid = buf[13];
      byte r = 0;
      byte cr = rotcurr[rid];
      if (LAST_SCR!=CURR_SCR) {
        rotcurr[rid] = 0;
        rotdelay0[rid] = 0;
        r = 1;
      }
      else {
        rotdelay0[rid]++;
        if ((rotdelay0[rid]>>4)>=buf[15]) {          // rotation delay
          r = 1;
          rotdelay0[rid] = 0;
          cr++;
          if (cr>=buf[14]) cr = 0;    // current rotation-id
          rotcurr[rid] = cr;
        }
      }
      if (r==1) {
        memset(tmp,' ',sizeof(tmp));
        memcpy(tmp,&textbuf[buf[10]][buf[11]+cr*buf[12]],buf[12]);
        printString(tmp,buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9]);
      }
    }
    else if (LAST_SCR!=CURR_SCR) {
      if (buf[0]==3) {         // static-text
        memset(tmp,' ',sizeof(tmp));
        memcpy(tmp,&textbuf[buf[10]][buf[11]],buf[12]);
        fillArea(buf[3],buf[4],buf[5],buf[6],buf[9]);
        printString(tmp,buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9]);
      }
      else if (buf[0]==5) {     // clear-screen
        fillArea(buf[1],buf[2],buf[3],buf[4],buf[5]);
      }
    }
    i++;    
  }
  //if (LAST_SCR!=CURR_SCR) { Serial.println(CURR_SCR); }
  LAST_SCR = CURR_SCR;
}

word getLong(String str, word i, word sl, long* x) {
  String tmp = "";
  while (i<sl) {
    char c = str.charAt(i);
    if (c==',') { i++; break; }
    tmp += c;
    i++;
  }
  *x = tmp.toInt();
  return i;
}

char pars[MAX_PARS];

word getPars(String str, word* j, word w, byte mx) {
  memset(pars,0,sizeof(pars));
  word i = *j;
  long i0;
  byte i2 = 0;
  while (i2<mx && i<w) {
    i = getLong(str,i,w,&i0);
    //Serial.print(i0); Serial.print(",");
    pars[i2] = i0&0xFF;
    i2++;
  }
  *j = i;
  return i2;
}

void doCmd(String str) {
  word w = str.length();
  if (w<3) return;
  long i0,l2;
  long idx = 0;
  byte i2 = 0;
  word i = 2;
  char cmd = str.charAt(0);
  str[0] = '0'; str[1] = '0';
  switch (cmd) {
    case 'b':                         // setbrightness b:val
      i0 = str.toInt();
      brightness = i0&0xFF;
      break;
    case 'T':                         // modify-waktu0-tickcount T:tickcount
      i0 = str.toInt();
      if (i0>0) waktu0 = i0-millis()/1000;
      //Serial.println(i0);
      break;
    case 't':                         // modify long-text-buffer t:id,pos,len,TEXT
      //Serial.println("SetText:");
      getPars(str,&i,w,3);
      setText(pars[0],pars[1],pars[2],(String)&str[i]);
      //Serial.println(String(&str[i]));
      break;
    case 'F':                         // fillarea F:xl,yu,xr,yd,clr
      //Serial.print("FillArea:");
      getPars(str,&i,w,5);
      fillArea(pars[0],pars[1],pars[2],pars[3],pars[4]);
      //Serial.println();
      break;
    case 'P':                         // setprg P:id,params
      i = getLong(str,i,w,&idx);
      if (idx<=0 || idx>MAX_PRG) break;
      //Serial.print("setPrg:");
      getPars(str,&i,w,PRG_ITEM);
      setPrg(idx,pars);
      //Serial.println(idx);
      break;
    case 'p':                         // screen-pause p:[0/1]
      //Serial.print("setPause:");
      i = getLong(str,i,w,&i0);
      SCREEN_PAUSE = i0;
      //Serial.println(i0);
      break;
    case 'S':                         // setScreen S:id,delay,params
      i = getLong(str,i,w,&idx);
      if (idx>=MAX_SCREEN) break;
      //Serial.print("setScreen:");
      i = getLong(str,i,w,&i0);
      if (i>=w) {
        scrdelay[idx] = i0;
        //Serial.print(i0);
      }
      else {
        getPars(str,&i,w,MAX_SCREEN);
        setScreen(idx,i0,pars);
      }
      //Serial.println(idx);
      break;
    case 'D':                         // displayText D:x,y,xl,yu,xr,yd,fid,clr,bgclr,text
      getPars(str,&i,w,9);
      //Serial.print("dspText:");
      printString(&str[i],pars[0],pars[1],pars[2],pars[3],pars[4],pars[5],pars[6],pars[7],pars[8]);
      //Serial.println(&str[i]);
      break;
    case 'R':                         // restart R:12,34,56
      getPars(str,&i,w,3);
      if (pars[0]==12 && pars[1]==34 && pars[2]==56) ESP.restart();
      break;
    case 'U':                         // update U:hh1,mm1,hh2,mm2,hh3,mm3 dst
      byte s = sizeof(updtime);
      i2 = getPars(str,&i,w,s);
      memset(updtime,99,s);
      if (i2>s) i2 = s;
      memcpy(updtime,pars,i2);
      break;      
  }
}

void doCmds(String str, char flag) {
  //Serial.println(str);
  word w = str.length();
  word i = 0;
  char c;
  char cp;
  if (flag==0) cp = 1; else cp = 0;
  String tmp = "";
  while (i<w) {
    c = str.charAt(i);
    if (cp==1) {
      if (c=='|' || c=='~' || i+1==w) {           // new-command
        //Serial.println(tmp);
        doCmd(tmp);
        tmp = "";
      }
      else tmp += c;
    }
    else if (c==flag) cp = 1;
    i++;
  }
}

void cekUpdate() {              // cek for auto-update array
  byte i = 0;
  byte uhh,umm;
  while (i<MAX_UPDATE) {
    uhh = updtime[i];
    umm = updtime[i+1];
    if (uhh>=24 || umm>=60 || uhh>hh) break;
    if (hh==uhh) {
      if (mm<umm) break;
      if (mm==umm) {
        scWeb = "update.php";
        ticker.attach(2,webCmds);
        break;
      }
    }
    i += 2;
  }
}

void busyProgress() {
  bldelay++;
  if (bldelay>8) {
    bldelay = 0;
    printChar(stBusy[bloop],0,0,0,60,0,63,7,0,3,0);
    bloop++; if (bloop>=sizeof(stBusy)) bloop = 0;
  }
}

byte lss = 99;

void loop() {
  ArduinoOTA.handle();
  if (wifiok>0) server.handleClient();
  else busyProgress();
  if (siap>0) {
    byte d = 0;
    byte xss = getHMS(mm);
    if (xss!=lss) {
      if (ss==0) cekUpdate();
      lss = xss;
      d = 1;
      screentime++;
      if (screentime>scrdelay[CURR_SCR]) {
        CURR_SCR++;
        if (CURR_SCR>=MAX_SCREEN || scrbuf[CURR_SCR][0]==0) CURR_SCR = 0;
        screentime = 0;
      }
    }
    dspScreen(d);
  }
  display();
}

uint16_t strLength(String string, char fid) {
  return printString(string,0,0,0,0,0,0,fid,0,0);
}

uint16_t printString(String string, int x, int y, int xl, int yu, int xr, int yd, char fid, uint8_t color, uint8_t bgcolor) {
  int wl = 0;
  uint8_t clr = color;
  uint8_t bgc = bgcolor;
  char fd = fid;
  byte spc = 1;
  int slen = string.length();
  int i = 0;
  while (i<slen) {
    char c = string.charAt(i);
    while (c=='_') {
      i++;
      //string++;
      //c = *string;
      c = string.charAt(i);
      if (c>='A' && c<='P') clr = c-'A';              // change color
      else if (c>='a' && c<='p') bgc = c-'a';         // change bgcolor
      else if (c>='0' && c<='9') {
        fd = c-'0';                                   // change font-id
        if (fd>=MAX_FONT) fd = 0;
      }
      //string++;
      //c = *string;
      i++;
      c = string.charAt(i);
    }
    byte wc = printChar(c,spc,x+wl,y,xl,yu,xr,yd,fd,clr,bgc);
    wl += wc+spc;
    //string++;
    i++;
  }
  return wl;
}

/*
      x0,y0 - x1,y1     : display area
*/
uint8_t printChar(char c, byte spc, int x, int y, int xl,int yu, int xr,int yd, char fid, uint8_t color, uint8_t bgcolor) {
  uint8_t *font = (uint8_t*)xfont[fid];
  uint8_t c0 = pgm_read_byte_near(font);       // first char in the table
  uint8_t w = pgm_read_byte_near(font+1);      // width
  uint8_t h = pgm_read_byte_near(font+2);      // height
  uint8_t b = pgm_read_byte_near(font+3);      // byte-per-char
  uint8_t b2 = pgm_read_byte_near(font+4);      // byte-per-data
  font += b*(c-c0)+5;
  if (w==0) { w = pgm_read_byte_near(font); font++; }
  if (xr<=xl) return w;
  if (x+w<0 || y+h<0 || x+xl>xr || y+yu>yd) return w;       // out-of-print-area
  x += xl;
  y += yu;
  int pos = x+y*WIDTH;                                  // first index in displaybuf
  word cx = 0;                                      // font data 16 bit
  for (byte x2=0; x2<w+spc; x2++) {
    cx = pgm_read_byte_near(font)<<8;
    if (b2>1) cx |= pgm_read_byte_near(font+1);
    int pos1 = pos+x2;
    byte fx = h;
    int y2 = y;
    if (x2>=w) cx = 0;
    if (x>=xl)
    while (fx>0) {
      if (y2>yd) break;
      if (y2>=yu && pos1>=0 && pos1<BUFSIZE) {
        if (cx&0x8000) displaybuf[pos1] = color; else displaybuf[pos1] = bgcolor;
      }
      pos1 += WIDTH;
      cx <<= 1;
      fx--;
      y2++;
    }
    font += b2;
    x++;
    if (x>xr) break;
  }
  return w;
}
