#include <Servo.h>

Servo myServo;  // Create servo object
const int quickPositions[3] = {0, 90, 180}; // Positions for quick mode
int mode = 0;  // 0 for sweep mode, 1 for quick mode

void setup() {
  myServo.attach(D2); // Attach the servo on GPIO pin D2
}

void loop() {
  if (mode == 0) {
    sweepServo();
    mode = 1;  // Switch to quick mode after sweep
  } else {
    quickMode();
    mode = 0;  // Switch back to sweep mode after quick movements
  }
}

void sweepServo() {
  for (int pos = 0; pos <= 180; pos++) { // Sweeps from 0 degrees to 180 degrees
    myServo.write(pos); // Tell servo to go to position in variable 'pos'
    delay(15);          // Waits 15ms for the servo to reach the position
  }
  delay(5000); // Extra delay after sweeping before switching modes
}

void quickMode() {
  for (int i = 0; i < 3; i++) {
    myServo.write(quickPositions[i]); // Move servo to the next position
    delay(3000); // Wait 3 seconds at each position
  }
}
