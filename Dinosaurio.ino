#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- CARACTERES ---
byte DINO_PARADO_P1[8] = {B00000, B00000, B00100, B00100, B00111, B00111, B00011, B00010}; 
byte DINO_PARADO_P2[8] = {B01110, B01011, B01111, B11000, B11110, B11010, B10000, B10000};
byte DINO_PIE_DERE_P1[8] = {B00000, B00000, B00100, B00100, B00111, B00111, B00011, B00010};
byte DINO_PIE_DERE_P2[8] = {B01110, B01011, B01111, B11000, B11110, B11010, B10000, B00000};
byte DINO_PIE_IZQU_P1[8] = {B00000, B00000, B00100, B00100, B00111, B00111, B00011, B00000};
byte DINO_PIE_IZQU_P2[8] = {B01110, B01011, B01111, B11000, B11110, B11010, B10000, B10000};
byte RAMA[8] = {B00100, B00100, B00100, B10100, B10100, B11100, B00100, B00100};
byte AVE[8] = {B00000, B10000, B11000, B11100, B11110, B11111, B00000, B00000};

// --- VARIABLES ---
int col_dino = 1;
int fila_dino = 1; // 1 = Suelo, 0 = Salto
int col_obs = 15;
int fila_obs = 1;
int puntos = 0;
int velocidad = 100;
unsigned long t_mov = 0, t_anim = 0;
bool flag_anim = true;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(2, INPUT);
  
  lcd.createChar(0, DINO_PARADO_P1);
  lcd.createChar(1, DINO_PARADO_P2);
  lcd.createChar(2, DINO_PIE_DERE_P1);
  lcd.createChar(3, DINO_PIE_DERE_P2);
  lcd.createChar(4, DINO_PIE_IZQU_P1);
  lcd.createChar(5, DINO_PIE_IZQU_P2);
  lcd.createChar(6, RAMA);
  lcd.createChar(7, AVE);

  lcd.clear();
  lcd.setCursor(3,0); lcd.print("LISTO?");
  delay(1000);
  lcd.clear();
}

void loop() {
  // 1. Animación de las patas (Dino corriendo)
  if (millis() - t_anim > 150) {
    flag_anim = !flag_anim;
    t_anim = millis();
  }

  // 2. Movimiento del obstáculo
  if (millis() - t_mov > velocidad) {
    lcd.setCursor(col_obs, fila_obs); lcd.print(" "); // Limpia rastro
    col_obs--;
    
    if (col_obs < 0) {
      col_obs = 15;
      fila_obs = random(0, 2); // Aparece arriba o abajo
      puntos++;
      if(velocidad > 40) velocidad -= 2; // Aumenta dificultad
    }
    t_mov = millis();
  }

  // 3. Salto con el botón (Pin 2)
  if (digitalRead(2) == HIGH) {
    fila_dino = 0; // Salta
  } else {
    fila_dino = 1; // Suelo
  }

  // 4. Dibujar Dino y Obstáculo
  dibujarEscena();

  // 5. DETECCIÓN DE COLISIÓN (El corazón del Game Over)
  // Si el obstáculo llega a la columna del dino (1) y están en la misma fila
  if (col_obs == col_dino && fila_obs == fila_dino) {
    gameOver();
  }
}

void dibujarEscena() {
  // Limpiar posiciones anteriores de forma selectiva para evitar parpadeo
  lcd.setCursor(col_dino, 0); lcd.print(" ");
  lcd.setCursor(col_dino, 1); lcd.print(" ");

  // Dibujar Dino
  lcd.setCursor(col_dino, fila_dino);
  if (fila_dino == 0) { // En el aire
    lcd.write(byte(0)); 
  } else { // En el suelo corriendo
    lcd.write(flag_anim ? byte(2) : byte(4));
  }

  // Dibujar Obstáculo
  lcd.setCursor(col_obs, fila_obs);
  lcd.write(fila_obs == 1 ? byte(6) : byte(7));

  // Puntos
  lcd.setCursor(13, 0);
  lcd.print(puntos);
}

void gameOver() {
  lcd.clear();
  lcd.setCursor(3, 0); lcd.print("GAME OVER!");
  lcd.setCursor(4, 1); lcd.print("Score: "); lcd.print(puntos);
  delay(3000);
  
  // Reiniciar valores
  puntos = 0;
  col_obs = 15;
  velocidad = 100;
  lcd.clear();
}
