#include <Arduino.h>

#define LED_1 2
#define LED_2 4
#define LED_3 6

#define BUTTON_INPUT_1 10
#define BUTTON_GND_1 11
#define BUTTON_PWR_1 12

void setup() {
  // put your setup code here, to run once:

  pinMode(BUTTON_GND_1, OUTPUT);
  pinMode(BUTTON_PWR_1, OUTPUT);

  digitalWrite(BUTTON_GND_1, LOW); // Sets pin as GND for BUTTON 1
  digitalWrite(BUTTON_PWR_1, HIGH); // Sets pin as PWR for BUTTON 1

  pinMode(BUTTON_INPUT_1, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

}

bool button_was_pressed = false;

bool buttonToggled() {
  bool button_is_pressed = 
  digitalRead(BUTTON_INPUT_1);

  bool button_toggled = !button_was_pressed 
                        && button_is_pressed;
  // 2. if the button was not pressed and now it ispressed note that thebutton has been toggled

  // 4. update whether the button was pressed
  button_was_pressed = button_is_pressed;

  // 5. return whether or not the button was toggled
  return button_toggled;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(buttonToggled()) {
    digitalWrite(LED_1, HIGH); 
    digitalWrite(LED_2, HIGH); 
    digitalWrite(LED_3, HIGH); 
    return;
  }

  digitalWrite(LED_1, LOW); 
  digitalWrite(LED_2, LOW); 
  digitalWrite(LED_3, LOW); 
}


