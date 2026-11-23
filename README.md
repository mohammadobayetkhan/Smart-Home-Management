# Smart Home Management System

A simple Bluetooth-controlled home automation project using an **Arduino Mega 2560**, **HC-05 Bluetooth module**, and a **4-channel relay module**. It controls three lights and one fan (or another suitable load) from a phone using Bluetooth commands.

## Features
- Control three lights individually.
- Control a fan individually.
- Turn all four channels ON or OFF together.
- Bluetooth control using an Android Bluetooth terminal/controller app.
- Serial Monitor displays received Bluetooth commands.

## Components
- Arduino Mega 2560
- HC-05 Bluetooth module
- 4-channel relay module (active LOW)
- Three light loads
- One fan/motor load (compatible with relay ratings)
- Jumper wires and breadboard (for low-voltage signal wiring)
- Android phone with a Bluetooth controller/terminal app

## Wiring

### HC-05 to Arduino Mega 2560 (Serial1)
| HC-05 | Arduino Mega |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | RX1, pin 19 |
| RXD | TX1, pin 18 (use a voltage divider to reduce Mega's 5V TX signal to a suitable 3.3V level) |

### Relay module
| Relay channel | Arduino Mega pin | Load |
|---|---:|---|
| IN1 | 8 | Light 1 |
| IN2 | 9 | Light 2 |
| IN3 | 10 | Light 3 |
| IN4 | 11 | Fan |
| VCC | 5V | Relay module power (verify module requirements) |
| GND | GND | Common ground for control side |

The relay module used in this project is **active LOW**: LOW switches a relay ON and HIGH switches it OFF.

## Bluetooth commands
Send one uppercase letter at a time from the Bluetooth app:

| Command | Action |
|---|---|
| A | Light 1 ON |
| B | Light 1 OFF |
| C | Light 2 ON |
| D | Light 2 OFF |
| E | Light 3 ON |
| F | Light 3 OFF |
| G | Fan ON |
| H | Fan OFF |
| I | All ON |
| J | All OFF |

## Upload and use
1. Open `Arduino/SmartHomeManagement.ino` in Arduino IDE.
2. Select **Arduino Mega 2560** and the correct COM port.
3. Upload the sketch.
4. Pair the phone with the HC-05 (the module's pairing PIN is often `1234` or `0000`, but it may differ).
5. Open a Bluetooth controller/terminal app and connect to HC-05.
6. Send the command letters listed above.

## Safety
- **Mains voltage can cause electric shock, fire, or death.** Do not wire or handle mains-powered loads while energized.
- Mains connections should be installed and checked by a qualified person. Use suitable enclosure, insulation, wire gauge, relay ratings, and protective devices.
- Never place exposed mains connections on a breadboard.
- This repository documents the control wiring and code; it is not a mains-wiring guide.
- For HC-05 RXD, use a voltage divider or appropriate level shifter on the Arduino Mega TX1 signal.

## Project structure
```
SmartHomeManagement/
├── Arduino/
│   └── SmartHomeManagement.ino
├── docs/
│   └── CONNECTIONS.md
├── README.md
└── LICENSE
```

## Project status
Completed and tested as a Bluetooth-controlled prototype.
