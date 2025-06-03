#include <TFT_eSPI.h>

#define BTN           WIO_5S_PRESS
#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define SCREEN_BG    TFT_BLACK
#define ROTATION     3
#define TEXT_SIZE    2
#define TEXT_COLOR   TFT_WHITE
#define LINE_SPACING 25

#define MSG_SIZE 10
const String MSG[MSG_SIZE] = {
  "Perds 3 microcoins",
  "Perds 2 microcoins",
  "Passe ton tour",
  "Va sur la case Dark Web",
  "Donne 2 microcoins au\njoueur en possedant le\nmoins",
  "Chaque joueur te donne 1\nmicrocoin",
  "Reponds a une question\n \nBonne reponse : gagne 2\nmicrocoins\n \nMauvaise reponse : donne 1\nmicrocoin a chaque joueur",
  "Gagne 2 microcoins",
  "Gagne 3 microcoins",
  "Cite 3 reseaux sociaux\npour gagner 5 microcoins"
};

TFT_eSPI tft;
long n;
bool p = HIGH;

void displayText(String txt, int x, int y) {
  int i = txt.indexOf('\n');

  tft.fillScreen(SCREEN_BG);

  if (i == -1) {
    tft.drawString(txt, x,y);
    return;
  }

  do {
    tft.drawString(txt.substring(0,i), x,y);
    txt = txt.substring(i+1);
    i = txt.indexOf('\n');
    y += LINE_SPACING;
  } while (i != -1);

  tft.drawString(txt, x,y);
}

void setup() {
  Serial.begin(9600);

  tft.begin();
  tft.setRotation(ROTATION);
  tft.fillScreen(SCREEN_BG);
  tft.setTextSize(TEXT_SIZE);
  tft.setTextColor(TEXT_COLOR);

  randomSeed(analogRead(0));

  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    if (p == HIGH) {
      n = random(0,MSG_SIZE);
      displayText(".", 1,0);
      delay(300);
      displayText("..", 1,0);
      delay(300);
      displayText("...", 1,0);
      delay(800);
      displayText(MSG[n], 1,0);
    }
    p = LOW;
  } else {
    p = HIGH;
  }
}
