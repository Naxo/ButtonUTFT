#include <ColorRGB.h>

ColorRGB redColor(255,255,255);

void setup(void)
{
  Serial.begin(9600); 
  Serial.println("RGB test!");
}


void loop(void)
{ 
   Serial.println("R!");
   Serial.print(redColor.getR());
}
