#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int eyeHeight = 48;
int y = 6;
int x = 30;
int eyeCloseness = 40;

int n = 0;

String currentEmotion = "Happy";
bool testing = true;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String currentBlinkState = "Close";
String currentEyeDirection = "Center";
bool currentEyeDirectionMovementToLeft = false;
bool currentEyeDirectionMovementToRight = false;
bool currentEyeDirectionMovementToCenter = false;
bool blinking = true;

bool lookLeft(bool currentEyeDirectionMovementToLeft) {
  if (x > 2 && currentEyeDirectionMovementToLeft == true){
    x = x-4;
    //Serial.println(x);
    return true;
  } else {
    return false;
  }
}

bool lookRight(bool currentEyeDirectionMovementToRight) {
  if (x < 54 && currentEyeDirectionMovementToRight == true){
    x = x+4;
    //Serial.println(x);
    return true;
  } else {
    return false;
  }
}

bool lookCenter(bool currentEyeDirectionMovementToCenter) {
  if (currentEyeDirectionMovementToCenter == true) {
    if (x > 30) {
      x = x-4;
      return true;
    } else {
      if (x < 30){
        x = x+4;
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}

String blinkClose(String currentBlinkState) {
  if (eyeHeight > 1 && currentBlinkState == "Close") {
    eyeHeight = eyeHeight - 4;
    y = y + 2;
    currentBlinkState = "Close";
  } else {
    currentBlinkState = "Open";
  }

  return currentBlinkState;
}

String blinkOpen(String currentBlinkState) {
  if (eyeHeight < 48 && currentBlinkState == "Open") {
    eyeHeight = eyeHeight + 4;
    y = y - 2;
    currentBlinkState = "Open";
  } else {
    currentBlinkState = "Close";
  }

  return currentBlinkState;
}

void blink() {
  if (blinking == true){
    if (currentBlinkState == "Close") {
      currentBlinkState = blinkClose(currentBlinkState);
    } else {
      currentBlinkState = blinkOpen(currentBlinkState);
    }
  } 
  if (eyeHeight == 48 && currentBlinkState == "Open"){
    blinking = false;
  }
}

String playAnimation(String animation){
  if (animation == "Happy"){
    y=6;
    int bounceCounter = 0;
    String bounceDirection = "down";
    while (bounceCounter <= 3){
      //bounce
      if (bounceDirection == "down"){
        y=y+2;
        if (y>=14) {
          bounceDirection = "up";
        }
      } else if (bounceDirection == "up"){
        y=y-2;
        if (y<=6){
          bounceDirection = "down";
          bounceCounter++;
        }
      }
      //draw
      display.clearDisplay();
      display.fillRoundRect(x, y+4, 30, 24, 10, SSD1306_WHITE);
      display.fillRoundRect(x+40, y+4, 30, 24, 10, SSD1306_WHITE);
      display.fillRoundRect(x, y+12, 30, 24, 10, SSD1306_BLACK);
      display.fillRoundRect(x+40, y+12, 30, 24, 10, SSD1306_BLACK);
      display.display();
      delay(1);
    }
  }
  return "Default";
  y=6;
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  
  if (currentEmotion == "Default"){
    if (n == 100){
      blinking = true;
      n=0;
    }
    if (random(1, 1000) == 1) {
      currentEyeDirectionMovementToLeft = true;
    }
    if (random(1, 1000) == 999){
      currentEyeDirectionMovementToRight = true;
    }
    if (random(1, 500) == 250){
      currentEyeDirectionMovementToCenter = true;
    }
    n = n+1;
    currentEyeDirectionMovementToLeft = lookLeft(currentEyeDirectionMovementToLeft);
    currentEyeDirectionMovementToRight = lookRight(currentEyeDirectionMovementToRight);
    currentEyeDirectionMovementToCenter = lookCenter(currentEyeDirectionMovementToCenter);
    blink();
    display.clearDisplay();
    display.fillRoundRect(x, y, 30, eyeHeight, 10, SSD1306_WHITE);
    display.fillRoundRect(x+40, y, 30, eyeHeight, 10, SSD1306_WHITE);
    display.display();
    delay(1);
  } else if(currentEmotion == "Happy"){
    currentEmotion = playAnimation("Happy");
  }
}
