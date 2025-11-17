// #include "Arduino.h"
// /*Change all the ? in the code, add code in ???, modify getPosition() */

// // L298N Driver Pin

// #define MOTOR_ENA 27 // Replace the ? with the GPIO pin you selected to connect ENA
// #define MOTOR_IN1 25 // Replace the ? with the GPIO pin you selected to connect IN2
// #define MOTOR_IN2 26 // Replace the ? with the GPIO pin you selected to connect IN2

// // Encoder Pin
// #define ENCODER_PINA 34 // Replace the ? with the GPIO pin you selected to connect encoder A
// #define ENCODER_PINB 35 // Replace the ? with the GPIO pin you selected to connect encoder B

// // Encoder Counter
// volatile long encoderCount = 0;
// volatile double position = 0;

// // Serial Monitor command for rotation direction
// String command;

// // interruppt
// void IRAM_ATTR encoderInterrupt()
// {
//   if (digitalRead(ENCODER_PINA) != digitalRead(ENCODER_PINB))
//   {
//     encoderCount++;
//   }
//   else
//   {
//     encoderCount--;
//   }
// }

// // To get the current position
// /*Modify this function*/
// double getPosition()
// {
//   // Calculate the current position based on encoder count
//   position = float(encoderCount) * 360.0 / 912.0; // Replace 1000.0 with the actual counts per revolution

//   if (position < 0)
//   {
//     position = position + 360; // Ensure position is positive
//   }

//   return position;
// }

// // Serial Display Function
// void getState()
// {
//   Serial.print("Count: ");
//   Serial.println(encoderCount);
//   Serial.print("Position: ");
//   Serial.println(getPosition());
//   delay(50);
// }

// void setup()
// {

//   /* pin mode for pins connected with L298N driver  */
//   pinMode(MOTOR_ENA, OUTPUT);
//   pinMode(MOTOR_IN1, OUTPUT);
//   pinMode(MOTOR_IN2, OUTPUT);

//   // encoder A pin mode for interrupt
//   pinMode(ENCODER_PINA, INPUT_PULLUP);
//   attachInterrupt(digitalPinToInterrupt(ENCODER_PINA), encoderInterrupt, CHANGE);

//   pinMode(ENCODER_PINA, INPUT);
//   pinMode(ENCODER_PINB, INPUT);
//   /* set up baud rate  */
//   Serial.begin(115200);
// }

// void loop()
// {
//   if (Serial.available() > 0)
//   {
//     command = Serial.readStringUntil('\n'); // Read the incoming command
//     command.trim();                         // Remove any leading or trailing whitespace
//     if (command == "F")
//     {
//       /*Forward rotation direction*/
//       digitalWrite(MOTOR_IN1, HIGH);
//       digitalWrite(MOTOR_IN2, LOW);
//       /*Set a speed for your motor*/
//       analogWrite(MOTOR_ENA, 255);
//     }
//     else if (command == "B")
//     {
//       /*Backward rotation direction*/
//       digitalWrite(MOTOR_IN1, LOW);
//       digitalWrite(MOTOR_IN2, HIGH);
//       /*Set a speed for your motor*/
//       analogWrite(MOTOR_ENA, 255);
//     }
//   }

//   // print the encoderCount and Position
//   getState();

//   /* Reset encoder count*/
//   if (position > 360 || position < 0)
//   {
//     encoderCount = 0;
//   }
// }
