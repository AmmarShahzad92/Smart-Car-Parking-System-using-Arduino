# Smart Car Parking System using Arduino

This project implements a simple and effective smart car parking system using an Arduino board and an ultrasonic sensor. The system detects the presence of a car in a parking slot and indicates its status using three LEDs: Green for available, Yellow for partially occupied or approaching, and Red for occupied.

## Hardware Components

*   **Arduino Board:** The microcontroller used to run the system's logic.
*   **Ultrasonic Sensor (HC-SR04):** Used to measure the distance to detect the presence of a car.
*   **LEDs:**
    *   **Green LED:** Indicates that the parking slot is available.
    *   **Yellow LED:** Indicates a car is approaching or the slot is partially occupied.
    *   **Red LED:** Indicates that the parking slot is occupied.
*   **Jumper Wires**
*   **Breadboard**

## How it Works

The ultrasonic sensor continuously measures the distance to the nearest object. The Arduino board reads this distance and controls the LEDs based on the following logic:

*   If the measured distance is greater than 50 cm, it means the parking slot is empty, and the **Green LED** is turned on.
*   If the measured distance is between 25 cm and 50 cm, it could mean a car is in the process of parking or is not parked correctly. In this case, the **Yellow LED** is turned on as a warning.
*   If the measured distance is less than 25 cm, it means the parking slot is occupied by a car, and the **Red LED** is turned on.

The system provides a real-time visual indication of the parking slot's availability, making it easier for drivers to find an empty spot.

## Arduino Code

```ino
int trig = 8;
int echo = 9;
int Red = 5;
int Yellow = 6;
int Green = 7;
int distance;
long duration;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance : ");
  Serial.println(distance);

  if (distance > 50)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);
  }
  else if (distance > 25 && distance < 50)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);
  }
  else if (distance < 25)
  {
    digitalWrite(Red, HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);
  }
}
```

