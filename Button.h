#include "Arduino.h"
#include <stdint.h>


class Button {
  public:
    /*
    Button is the default constructor function for the class button.
    The default case is an empty function as if we want the button to be available in the global
    scope, we can not run any functions or loops unless we call them from the setup() or loop() functions.

    The syntax ": input(input), gnd(gnd), pwr(pwr)" allows us to assign the variables in the parameters to 
    members of our object class.

    Example syntax is:

    Classname(type parameter1) : object_parameter(parameter1) {
      your constructor here...
    }

    Extending exercise:
      - There may be a situation where you don't want to define the pins until after you've entered the setup
      function. Create an overload constuctor that takes no parameters.
    */
    Button(uint8_t input, uint8_t gnd = 0, uint8_t pwr = 0)
    /*
    This syntax (uint8_t gnd = 0) allows for default parameters 
    i.e. if you do not specify power or ground it will not attempt to set the pins
    */ 
    : input(input), gnd(gnd), pwr(pwr) // Assigns constructor parameters to the variables defined in "private"
    {}

    /*
    init (for initialization) is a function that sets the pin modes for the button pins. This logic is not set
    in the constructor function as these functions cannot be called from the global scope. This allows you
    to create a button that is accessible in the global scope (so you can access it in setup, loop, and any other functions
    you may define) but it won't be ready to take input until after you've called my_button.init().

    Extending exercise:
        - There may be a situation where you want to define the pins while you're initializing the class.
        Create an overloading function definition that takes the input, gnd, and pwr parameters and
        sets them to your private members.
    */
    void init() {
      pinMode(input, INPUT);

      // If gnd is specified (and non-zero), set the specified pin to act as ground for the button input
      if (gnd) {
        pinMode(gnd, OUTPUT);
        digitalWrite(gnd, LOW);
      }

      // If pwr is specified (and non-zero), set the specified pin to act as power for the button input
      if (pwr) {
        pinMode(pwr, OUTPUT);
        digitalWrite(pwr, HIGH);
      }

    }

    /*
    buttonToggled is a function that checks to see whether button has changed from the off state to the on state
    (and returns true if this is the case). It relies on the private member "button_was_pressed" which keeps track
    of whether the button was pressed the last time this function was called.

    Extending function:
      - Add a default parameter which specifies whether it should return true when the button goes from the
      powered off state to the powered on state or whether it should return true when the button goes from the powered
      on state to the powered of state.
      - Bonus - Use an enum to distinguish between the states

      Research hints:
      "Rising and falling edge button detection"
      "Enums C++"
    */
    bool buttonToggled() {
      bool button_is_pressed = 
      digitalRead(input);

      bool button_toggled = !button_was_pressed 
                            && button_is_pressed;
      // 2. if the button was not pressed and now it ispressed note that thebutton has been toggled

      // 4. update whether the button was pressed
      button_was_pressed = button_is_pressed;

      // 5. return whether or not the button was toggled
      Serial.println("Returing" + String(button_toggled));

      return button_toggled;
    }


  private:
    uint8_t input; 
    uint8_t gnd; 
    uint8_t pwr;
    bool button_was_pressed = false;
};