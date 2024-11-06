// Define pin numbers
const int ledPin = 13;      // GPIO number connected to the LED
const int buttonPin = 14;   // GPIO number connected to the button

void setup() {
  pinMode(ledPin, OUTPUT);     // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP); // Initialize the button pin as an input with an internal pull-up resistor (connected to ground = 0/LOW, not connected to ground 1/HIGH)
  Serial.begin(9600);          // Initialize serial communication at 9600 bits per second
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the state of the button

  if (buttonState == LOW) {  // Check if the button is pressed
    digitalWrite(ledPin, HIGH);  // Turn LED on
    Serial.println("LED on: Button pressed");  // Print message to the serial monitor
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off
    Serial.println("LED off: Button not pressed");  // Print message to the serial monitor
  }
}
