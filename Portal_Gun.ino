#include <Adafruit_NeoPixel.h>

// pin definitions 
#define PIN 13 // led strip pin 
#define NUMPIXELS 13 // number of leds in strip
#define ROTARY_PIN_A 3 // rotary encoder A pin 
#define ROTARY_PIN_B 4 // rotary encoder B pin 
#define BUTTON_PIN 5 // push button pin

// set ws2812b led strip with neopixel library
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// portal states
bool activatebluePortal = false;
bool activateorangePortal = false;

void setLEDColor(uint8_t r, uint8_t g, uint8_t b); // set colours in rgb values 
void activatePortal(int portal); // set active portals (blue or orange)

void setup() {

  pixels.begin(); // initialise the NeoPixel library

  pinMode(ROTARY_PIN_A, INPUT); // rotary pin A setup 
  pinMode(ROTARY_PIN_B, INPUT); // rotary pin B setup 
  pinMode(BUTTON_PIN, INPUT_PULLUP); // button pin set up; input pulled 'high' by default
  Serial.begin(9600); // initiates arduino and ide communication channel with a baud rate of 9600 -> debugging
}

void loop() {

  // read rotary encoder  
  int rotaryA = digitalRead(ROTARY_PIN_A); // reads pin A to return an active/inactive state
  int rotaryB = digitalRead(ROTARY_PIN_B); // reads pin B to return an active/inactive state
  int state = 0; // control state

  // determine portal states depending on rotary encoder readings
  if (rotaryA == HIGH && rotaryB == LOW) {
    state = 1; // blue state
  } else if (rotaryA == LOW && rotaryB == HIGH) {
    state = 2; // orange state
  } else {
    state = 0; // no state
  }

  // activate portal depending on rotary encoder state; else, turn off leds
  if (state == 1) {
    activatePortal(1); // if blue state is initiated -> activate blue portal 
  } else if (state == 2) {
    activatePortal(2); // if orange state is initiated -> activate orange portal 
  } else {
    setLEDColor(0,0,0); // no state -> shut off leds
  }

  // read button states; open portal if blue and orange portals have been activated; else, trigger error
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (activatebluePortal && activateorangePortal) {
      setLEDColor(255,255,255); // open portal (steady white)
    } else {
        triggerErrorState(); // trigger error state
    }
  }
}

// activate chosen portal and change led states
void activatePortal(int portal) {
  if (portal == 1) { // if value of portal is equal to 1 ->
    activatebluePortal = true; // activate blue portal
    activateorangePortal = false; // deactivate orange portal
    setLEDColor(0, 0, 255); // set leds to blue
  } else if (portal == 2) { // if value of portal is equal to 2 ->
    activatebluePortal = false; // deactivate blue portal
    activateorangePortal = true; // activate orange portal
    setLEDColor(255, 100, 0); // set leds to orange 
  }
}

// set led strip colour
void setLEDColor(uint8_t r, uint8_t g, uint8_t b) { // set function within rbg values, but does not return a value
  for(int i = 0; i < NUMPIXELS; i++) { // loop moves to next led each time it runs and increases by 1; loop is run as long as i < 16
    pixels.setPixelColor(i, pixels.Color(r, g, b)); // set led pixel colour
  }
  pixels.show(); // update strip colour based on previous input
}

// trigger error state (blinking white)
void triggerErrorState() { // creates an error state, but does not return a value
  for (int i = 0; i < 5; i++) { // i increases by 1 each loop; loop is run as long as i < 5
    setLEDColor(255, 255, 255); // set leds to white
    delay(500); // blink on for 0.05 seconds
    setLEDColor(0, 0, 0); // shut off leds
    delay(500); // blink off for 0.05 seconds
  }
}
