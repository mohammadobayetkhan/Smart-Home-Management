# Connections reference

## Bluetooth serial connection
The Arduino Mega uses hardware serial port 1:
- HC-05 TXD → Mega RX1 (pin 19)
- HC-05 RXD ← Mega TX1 (pin 18), through a voltage divider/level shifter
- HC-05 VCC → 5V (check module board specification)
- HC-05 GND → GND

## Relay control inputs
- IN1 → pin 8 (Light 1)
- IN2 → pin 9 (Light 2)
- IN3 → pin 10 (Light 3)
- IN4 → pin 11 (Fan)
- Relay VCC → 5V, as appropriate for the module
- Relay GND → GND

The sketch sets each relay output HIGH at startup to keep the active-LOW relays OFF.

## Command summary
- A/B: Light 1 ON/OFF
- C/D: Light 2 ON/OFF
- E/F: Light 3 ON/OFF
- G/H: Fan ON/OFF
- I/J: all ON/OFF
