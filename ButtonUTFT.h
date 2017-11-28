#ifndef ButtonUTFT_h
#define ButtonUTFT_h

#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

#include "../UTFT/UTFT.h"

struct RGB {
  byte r;
  byte g;
  byte b;
};

class ButtonImage{
  public:
	ButtonImage();
    ButtonImage(UTFT *screen);
	void setScreen(UTFT *screen);
	void setInitPosition(int x1, int y1);
	void setImageSize(int x, int y);
	void print();
	boolean pushed(int x, int y);
	unsigned int *image; 
  private:
	int _x1;
	int _y1;
	int _xsize;
	int _ysize;
	UTFT *_screen;
};

class ButtonText{
  public:
	ButtonText();
    ButtonText(UTFT *screen);
    char *_text;
	int _intText;
	RGB _backgroundColor;
	RGB _frontColor;
	RGB _borderColor;
	RGB _fontColor;
	boolean _fontSize;
	void setScreen(UTFT *screen);
	void setPosition(int x1, int y1, int x2, int y2);
	void print();
	boolean pushed(int x, int y);
  private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;
	UTFT *_screen;
};

class Button{
  public:
	Button();
    Button(UTFT *screen);
	void setScreen(UTFT *screen);
	void setPosition(int x1, int y1, int x2, int y2);
	RGB _borderColor;
	void print();
	boolean pushed(int x, int y);
  private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;
	UTFT *_screen;
};

#endif