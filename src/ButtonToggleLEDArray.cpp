// Get our Button class from Button.h
#include "Button.h" 

// Define which pins we are using as LED outputs.
/*
Extending exercise:
  - Add these LEDs to an array
  - Use for-loops and array access for pinMode(s), and digitalWrite(s)
  - Create a LED class which allows you to set an optional gnd pin, similar
  to our Button class
*/
#define LED_1 2
#define LED_2 4
#define LED_3 6


// Define which pins are being used to define a button
#define BUTTON_INPUT_1 10
#define BUTTON_GND_1 11
#define BUTTON_PWR_1 12


// Construct a new button called led_button and define
// the input, gnd, and power pins
Button led_button(BUTTON_INPUT_1, BUTTON_GND_1, BUTTON_PWR_1);

void setup() {
  // Initialize the led_button
  // (Sets the pin modes for the associated pins)
  led_button.init();

  // Set the pinMode to output for all of your LEDs
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

// This led_state variable keeps track of whether
// the LEDs should be ON (true) or OFF (false)

/*
Extending exercise:
  - Create a pair of macros called ON and OFF to more easily understand the
  state of the LEDs
*/
bool led_state = false;

void loop() {
  // "Ask" the button if it has been toggled
  if (led_button.buttonToggled())
    led_state = !led_state; // If it has, change the led_state

  // If the led_state is true (ON)
  if(led_state) {
    // Turn the LEDs ON
    digitalWrite(LED_1, HIGH); 
    digitalWrite(LED_2, HIGH); 
    digitalWrite(LED_3, HIGH); 
    return; // and stop running this loop
  }

  // Otherwise (implicitly, since the function never reaches this point
  // when led_state is true (ON)).
  // Turn the LEDs OFF
  digitalWrite(LED_1, LOW); 
  digitalWrite(LED_2, LOW); 
  digitalWrite(LED_3, LOW); 
}


