#include <TFT_eSPI.h>

#define BTN           WIO_5S_PRESS
#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define SCREEN_BG  TFT_BLACK
#define ROTATION   3
#define TEXT_SIZE  2
#define TEXT_COLOR TFT_WHITE

const String MSG[3] {
  "Fire!",
  "Lightning!",
  "Rumble!"
};

TFT_eSPI tft;
long n;
bool p = HIGH;

void displayText(String txt, int x, int y) {
  tft.fillScreen(SCREEN_BG);
  tft.drawString(txt,x,y);
}

void setup() {
  tft.begin();
  tft.setRotation(ROTATION);
  tft.fillScreen(SCREEN_BG);
  tft.setTextSize(TEXT_SIZE);
  tft.setTextColor(TEXT_COLOR);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    if (p == HIGH) {
      n = random(0,3);
      displayText(MSG[n],1,0);
    }
    p = LOW;
  } else {
    p = HIGH;
  }
}
