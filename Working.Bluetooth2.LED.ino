#include "BluetoothA2DPSink.h"
#include <Adafruit_NeoPixel.h>

BluetoothA2DPSink a2dp_sink;

#define LED_PIN   5
#define NUM_LEDS  20
#define STATUS_LED 4

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialize Status LED
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, HIGH);

  // Start Bluetooth FIRST
  a2dp_sink.start("ESP32 Speaker");

  delay(2000);   // Let BT stabilize

  // Now initialize LEDs
  strip.begin();
  strip.setBrightness(60);   // LOW brightness (important!)
  strip.show();

  uint32_t blue = strip.Color(0, 120, 255);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, blue);
  }

  strip.show();
}

void loop() {}