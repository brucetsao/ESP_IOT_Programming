#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

int rotatetext = 1;

void setup()   {
  Serial.begin(9600);

  //Initialize Display
  display.begin();

  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(57);

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello world!");
  display.display();
  delay(2000);
  display.clearDisplay();


  // Display Inverted Text
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.setCursor(0,0);
  display.println("Hello world!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Scaling Font Size
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.setTextSize(2);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display Numbers
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(123456789);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Specifying Base For Numbers
  display.setCursor(0,0);
  display.print("0x"); display.print(0xFF, HEX); 
  display.print("(HEX) = ");
  display.print(0xFF, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display ASCII Characters
  display.setCursor(0,0);
  display.setTextSize(2);
  display.write(3);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Text Rotation
  while(1)
  {
  display.clearDisplay();
  display.setRotation(rotatetext);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Text Rotation");
  display.display();
  delay(1000);
  display.clearDisplay();
  rotatetext++;
  }
}
