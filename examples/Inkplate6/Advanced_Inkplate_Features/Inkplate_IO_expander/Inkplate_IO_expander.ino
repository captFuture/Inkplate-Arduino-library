/*
   Inkplate_IO_expander example for Soldered Inkplate 6
   For this example you will need only a micro USB cable, Inkplate6, 330 Ohm resistor and LED diode.
   Select "Inkplate 6(ESP32)" or "Soldered Inkplate6" from Tools -> Board menu.
   Don't have "Inkplate 6(ESP32)" option? Follow our tutorial and add it:
   https://e-radionica.com/en/blog/add-inkplate-6-to-arduino-ide/

   Connect resistor to P1-7 pin (GPB7 pin on older Inkplates with MCP23017) on IO Expander 2 header at bottom on the
   backside (component side) of Inkplate. You will have to connect one side of 330 Ohm resistor to P1-7 (GPB7), then
   other side to anode of LED and finally, cathode pin of LED to GND.

   This example will show you how you can manipulate with I/Os of external IO Expander.
   On this expander all pins are free to use, nothing is connected by the default.

   Want to learn more about Inkplate? Visit www.inkplate.io
   Looking to get support? Write on our forums: http://forum.e-radionica.com/en/
   5 December 2022 by Soldered Electronics.
*/

// Next 3 lines are a precaution, you can ignore those, and the example would also work without them
#if !defined(ARDUINO_ESP32_DEV) && !defined(ARDUINO_INKPLATE6V2)
#error "Wrong board selection for this example, please select Inkplate 6 or Soldered Inkplate6 in the boards menu."
#endif

#include "Inkplate.h" //Include Inkplate library to the sketch

// We are going to use pin P1-7 (or GPB7 on older Inkplates).
// Remember! GPA0 = 0, GPA1 = 1, ..., GPA7 = 7, GPB0 = 8, GBP1 = 9, ..., GPB7 = 15.
// And also P0-0 = GPA0, P0-1 = GPA1, ..., P0-7 = GPA7, P1-0 = GPB0, P1-1 = GPB1, ..., P1-7 = GPB7.
#define LED_PIN IO_PIN_B7

Inkplate display(INKPLATE_1BIT); // Create an object on Inkplate library and also set library into 1-bit mode (BW)

void setup()
{
    display.begin(); // Init Inkplate library (you should call this function ONLY ONCE)
    display.clearDisplay();
    display.display();
    display.pinModeIO(LED_PIN,
                      OUTPUT); // Set P1-7 (or GPB7) to output. On that pin, we sholud connect LED with current limiting
                               // resistor If we do not specify which IO expander we want to use, by the default
                               // external IO expander will be used of the one with header named IO Expander 2.
}

void loop()
{
    display.digitalWriteIO(LED_PIN, LOW);  // Set output to low (LED does not light up)
    delay(1000);                           // Wait for one second
    display.digitalWriteIO(LED_PIN, HIGH); // Set output to high (LED lights up)
    delay(1000);                           // Wait for one second
}
