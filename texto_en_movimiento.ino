#define __DEBUG__
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//SCL=A5  SDA=A4
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
#ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
#endif

  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true)
      ;
  }

  // Limpir buffer
  display.clearDisplay();

  // Tamaño del texto
  display.setTextSize(1);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(1, 1);
  //Activar página de código 437
  display.cp437(true);
  // Escribir texto
  display.println("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(1, 32);
  display.cp437(true);
  display.println(" TENGA UN BUEN DIA ");
  display.display();
  delay(100);

  // Mover texto de izquierda a derecha
  display.startscrollright(0x00, 0x0F);
  delay(20000);
  display.stopscroll();

  // Mover texto de derecha a izquierda
  display.startscrollleft(0x00, 0x0F);
  delay(10800);
  display.stopscroll();
}

void loop() {}
