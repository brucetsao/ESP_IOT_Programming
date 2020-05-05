/*************************************************************
 *                   PORT EXPANDER
 *                   =============
 *
 * In this project an MCP23017 Port Expander chip is used to 
 * add 16 more I/O ports to the ESP32 Devkitc. This chip is
 * interfaced to a processor via teh I2C bus (SDA and SCL lines).
 * 10K pull-up resistors are used at these lines. In order to
 * test the hardware and teh software, an LED is connected to
 * port GPA0 (pin 21) of the MCP23017 chip. The program flashes
 * the LED every second.
 *
 *
 * File:   Expander
 * Date:   July 2017
 * Author: Dogan Ibrahim
 *************************************************************/
#include <Wire.h>                           // Include I2C library
const byte slave_addr=0x20;                 // MCP23017 I2C address
const byte IODIRA=0x00;                     // IODIRA address
const byte GPIOA=0x12;                      // GPIOA address

//
// This function configures the MCP23017 chip such that Port pin
// GPA0 is an output pin. PortDir is the address of the port
// direction register (IODIRA or IODIRB), and Data is the
// direction data such that 0 sets the corresponding port pin to
// output, and 1 sets the corresponding port pin to input
//
void Configure(char PortDir, char Data)
 {
    Wire.beginTransmission(slave_addr);
    Wire.write(PortDir);
    Wire.write(Data);
    Wire.endTransmission();
 }


//
// This function sends data to the specified port. The port can be
// GPIOA or GPIOB and data is a byte
//
void Send(char Port, char Data)
{
  Wire.beginTransmission(slave_addr);
  Wire.write(Port);
  Wire.write(Data);
  Wire.endTransmission();
}

//
// Initialize teh I2C bus, configure port GPIOA as an output port
//
void setup()
{
   Wire.begin();
   Configure(IODIRA, 0xFE);
}


//
// Main program initializes the I2C, configures the GPIOA port
// and flashes the LED connected to port pin GPA0 every second
//
void loop()
{
   Send(GPIOA, 0);                            // LED OFF
   delay(1000);                               // Wait 1 second
   Send(GPIOA, 1);                            // LED ON
   delay(1000);                               // Wait 1 second
}

