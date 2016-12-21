#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 60

Adafruit_NeoPixel stripRGB  = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripRGBW = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  
  stripRGB.begin();
  stripRGBW.begin();
  
  Serial.println("Testing: RGB Strip");
  getPixelTest(stripRGB, 0xFF000000);
  getPixelTest(stripRGB, 0xDD00DD00);
  getPixelTest(stripRGB, 0xAAAA0000);

  Serial.println("Testing: RGBW Strip");
  getPixelTest(stripRGBW, 0xFF000000);
  getPixelTest(stripRGBW, 0xDD00DD00);
  getPixelTest(stripRGBW, 0xAAAA0000);

}

void getPixelTest(Adafruit_NeoPixel &strip, uint32_t colorSet){
  char msg[16];

  for(int i = 0; i < 4; i++){
    Serial.print("\nInput Color: ");
    printColor(colorSet);
    
    for(int k = 255; k>=0; k--){
      strip.setBrightness(k);
      strip.setPixelColor(0, colorSet);
      sprintf(msg, "Bright %3u : ", k);
      Serial.print(msg);
      printColor(strip.getPixelColor(0));
     }
     
    colorSet = (colorSet >> 8); // advance color    
    
  }
  Serial.println();
}

void printColor(uint32_t c){
  char    msg[32];
  uint8_t w, r, g, b;

  w = (uint8_t)(c >> 24);
  r = (uint8_t)(c >> 16);
  g = (uint8_t)(c >> 8);
  b = (uint8_t)(c);

  sprintf(msg, "W%3u R%3u G%3u B%3u", w, r, g, b);
  Serial.println(msg);  
}

void loop(){
  
}

