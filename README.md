# Low budget Halloween glowing eyes

An ESP32-based LED project that creates spooky, randomly animated eyes using 8x8 WS2812 LED matrices.

Each 8×8 LED matrix represents one pair of eyes.
Multiple matrices can be connected in a single daisy-chained LED "strip" and operate independently, each running its own randomly selected animation.

- **multiple independent matrices** – configure the amount of 64 pixel matrices
- **random effect selection** – weight and select each matrix effect independently
- **single data line** – all eyes connect via one data connection with a single ESP32 

### effects

- red glow – fade-inand-out standard eyes
- Knight Rider – red scanning animation for variation
- white strobe

## hardware

- ESP32 development board, ESP32C3 with one data pin is enough
- WS2812 / WS2812B LED matrices (64 LED, 8×8 LED matrix)
- 5V USB power supply (tested with a 10 W adapter for eight matrices)

All matrices are connected in series using a single data line and forwarding VCC and GND.

### wiring

     ESP32                   Matrix 1                 Matrix 2
    +--------+              +----------+             +----------+
    |        |              |          |             |          |
    | GPIO 1 |------------->| DIN  OUT |------------>| DIN  OUT |--> ...
    |        |              |          |             |          |
    |  5V    |------------->| 5V    5V |------------>| 5V    5V |--> ...
    |  GND   |------------->| GND  GND |------------>| GND  GND |--> ...
    |        |              |          |             |          |
    +--------+              +----------+             +----------+

## configuration

All main settings are defined in `config.h`, e.g. LED matrix count, delays, and durations.

### matrix configuration

```cpp
#define LEDS_PER_MATRIX 64
#define MATRIX_COUNT 2
#define LEDS_COUNT (LEDS_PER_MATRIX * MATRIX_COUNT)
#define LEDS_PIN 1
```

### effect probabilities (in percent)

```cpp
constexpr uint8_t GLOW_WEIGHT = 90;
constexpr uint8_t KNIGHT_WEIGHT = 9;
constexpr uint8_t STROBE_WEIGHT = 1;
```

## software requirements

- Arduino IDE
- ESP32 Arduino Core
- `ESP32_WS2812_Lib` library

Install the required library and select the appropriate ESP32 board in the Arduino IDE.

Open `halloween-low-budget-glowing-eyes.ino` to compile and upload the project.

## project structure

```text
HalloweenEyes/
├── halloween-low-budget-glowing-eyes.ino
├── config.h
├── LedMatrix.h
├── LedMatrix.cpp
├── Effect.h
├── GlowEffect.h
├── GlowEffect.cpp
├── KnightRiderEffect.h
├── KnightRiderEffect.cpp
├── WhiteStrobeEffect.h
└── WhiteStrobeEffect.cpp
```

### software structure

- `HalloweenEyes.ino` – Main program and effect scheduling
- `config.h` – Central configuration
- `LedMatrix` – WS2812 hardware abstraction
- `Effect` – Common interface for all effects
- `GlowEffect` – Red glow animation
- `KnightRiderEffect` – Two-row scanning animation
- `WhiteStrobeEffect` – White strobe animation

Each matrix has its own controller and effect instances. Effect state is kept local to that matrix, so animations do not interfere with each other.

## extending the project

To add another effect:

1. Create a new class inheriting from `Effect`.
2. Implement `start()` and `update()`.
3. Add an instance to the matrix controller.
4. Include it in the weighted random effect selection.

The architecture is designed to make adding new effects straightforward.
that matches your intended use and distribution.