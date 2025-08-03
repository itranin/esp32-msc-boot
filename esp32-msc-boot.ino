/*
    Preloader for ESP32-READER
    ---------------------------
    Arduino options:
    - Board: ESP32S3 Dev Module
    - JTAG: Disabled
    - PSRAM: Disabled
    - Flash Mode: QIO 80MHz
    - Flash Size: 8MB (64Mb)
    - Arduino Runs on: Core 1 (default)
    - Events Run On: Core 0 (default)
    - USB Mode: USB-OTG (TynyUSB)
    - USB CDC On Boot: Enabled
    - USB DFU On Boot: Disabled
    - Upload Mode: Uart0/Hardware CDC
    - Partition Scheme: 8M with spiffs (3MB APP/1.5MB SPIFFS)
    - CPU Frequency: 240MHz (WiFi)
    - Upload Speed: 921600
    - Debug Level: None
    - Erase All Flash Before Sketch Upload: Disabled
*/

#define RGB_LED		48
#define PWR_EN		2

int LEDS[3][3] = {{255, 0, 0},   // Red
                  {255, 255, 0}, // Yellow
                  {0, 255, 0}};  // Green

void setup()
{
    pinMode(RGB_LED,  OUTPUT);
    pinMode(PWR_EN,   OUTPUT);
    digitalWrite(PWR_EN, HIGH);
}

void loop()
{
    static int led_index = 0;
    neopixelWrite(RGB_LED, LEDS[led_index][0], LEDS[led_index][1], LEDS[led_index][2]);
    if (++led_index >= 3) led_index = 0;
    delay(1000); // Change color every second
    neopixelWrite(RGB_LED, 0, 0, 0); // Turn off the LED
    delay(500); // Wait before the next color change
}
