# SISTEMAS-EMBEBIDOS-PARCIAL-SALA

🎮 Proyectos con Arduino – LCD y OLED

Este repositorio contiene el desarrollo de múltiples prácticas realizadas con Arduino enfocadas en sistemas embebidos, interacción con pantallas y lógica de programación en tiempo real.

📌 Contenido del proyecto

Se implementaron tres funcionalidades principales:

Juego tipo Dino (LCD 16x2 con I2C)
Mensaje animado en pantalla OLED: "Vamos por el 5"
Mensaje animado en pantalla OLED: "Tenga un buen día"
🦖 1. Juego tipo Dino en LCD
🧠 Descripción

Se desarrolló un videojuego inspirado en el clásico juego del dinosaurio de Chrome, utilizando una pantalla LCD 16x2 con comunicación I2C.

El jugador controla un dinosaurio que debe esquivar obstáculos (ramas y aves) mediante un botón. A medida que avanza el juego, la velocidad aumenta, incrementando la dificultad.

⚙️ Características
Animación del dinosaurio (efecto de movimiento de patas)
Generación aleatoria de obstáculos
Sistema de puntuación incremental
Detección de colisiones
Incremento progresivo de dificultad
Reinicio automático tras "Game Over"
🔌 Componentes utilizados
Arduino UNO
Pantalla LCD 16x2 con módulo I2C
Pulsador (botón)
Resistencias
Cables de conexión
🔄 Lógica del sistema

El sistema se basa en el uso de millis() para controlar:

Animaciones
Movimiento de obstáculos
Velocidad del juego

Esto permite evitar el uso de delay() y lograr una ejecución más fluida.

📺 2. Mensaje OLED: "Vamos por el 5"
🧠 Descripción

Programa que muestra un mensaje motivacional en una pantalla OLED SSD1306, con desplazamiento automático del texto.

⚙️ Características
Uso de librerías Adafruit_GFX y Adafruit_SSD1306
Texto en múltiples tamaños
Scroll horizontal automático
Inicialización por dirección I2C (0x3C)
📌 Funcionalidad
Muestra:
"SISTEMAS EMBEBIDOS"
"VAMOS POR EL 5"
Animación:
Scroll de izquierda a derecha
Scroll de derecha a izquierda
🌞 3. Mensaje OLED: "Tenga un buen día"
🧠 Descripción

Similar al proyecto anterior, este programa despliega un mensaje positivo en la pantalla OLED con animación de desplazamiento.

⚙️ Características
Visualización de texto decorativo
Scroll automático continuo
Configuración de tipografía y tamaño
🧰 Librerías utilizadas
Wire.h
LiquidCrystal_I2C.h
Adafruit_GFX.h
Adafruit_SSD1306.h
SPI.h
🔌 Conexiones
LCD I2C
VCC → 5V
GND → GND
SDA → A4
SCL → A5
OLED SSD1306
VCC → 5V
GND → GND
SDA → A4
SCL → A5
Botón (Juego Dino)
Pin digital 2
Configurado como entrada
