/*
  Smart Home Management System
  Arduino Mega 2560 + HC-05 Bluetooth + 4-channel relay

  Commands:
  A/B = Light 1 ON/OFF
  C/D = Light 2 ON/OFF
  E/F = Light 3 ON/OFF
  G/H = Fan ON/OFF
  I/J = All ON/OFF

  Relay module is active LOW (LOW = ON, HIGH = OFF).
*/

void setup()
{
  Serial.begin(9600);   // Serial Monitor
  Serial1.begin(9600);  // HC-05 on Mega RX1/TX1

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // Start with all relays OFF
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  Serial.println("Smart Home Ready");
}

void loop()
{
  if (Serial1.available())
  {
    char data = Serial1.read();

    Serial.print("Received: ");
    Serial.println(data);

    switch (data)
    {
      case 'A': digitalWrite(8, LOW);  break; // Light 1 ON
      case 'B': digitalWrite(8, HIGH); break; // Light 1 OFF
      case 'C': digitalWrite(9, LOW);  break; // Light 2 ON
      case 'D': digitalWrite(9, HIGH); break; // Light 2 OFF
      case 'E': digitalWrite(10, LOW); break; // Light 3 ON
      case 'F': digitalWrite(10, HIGH); break; // Light 3 OFF
      case 'G': digitalWrite(11, LOW); break; // Fan ON
      case 'H': digitalWrite(11, HIGH); break; // Fan OFF

      case 'I': // ALL ON
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        break;

      case 'J': // ALL OFF
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        break;
    }
  }
}
