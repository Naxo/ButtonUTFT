#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif
#include "ButtonUTFT.h"
#include "../UTFT/UTFT.h"

//Declare which fonts to be utilized
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

/***************************** ButtonImage *******************************************/
ButtonImage::ButtonImage(UTFT *screen){
	_screen = screen;
}

ButtonImage::ButtonImage(){
}

void ButtonImage::setScreen(UTFT *screen){
	_screen = screen;
}

void ButtonImage::setInitPosition(int x1, int y1){
	_x1 = x1; _y1 = y1;;
}

void ButtonImage::setImageSize(int x, int y){
	_xsize = x; _ysize = y;
}

void ButtonImage::print(){
	_screen -> drawBitmap(_x1, _y1, _xsize, _ysize, image, 1);
}

boolean ButtonImage::pushed(int x, int y){
  return ((x>=_x1) && (x<= (_x1 + _xsize)) && (y>=_y1) && (y<= (_y1+ _ysize)));
}

/***************************** ButtonText *******************************************/
ButtonText::ButtonText(UTFT *screen){
	_screen = screen;
}

ButtonText::ButtonText(){
}

void ButtonText::setScreen(UTFT *screen){
	_screen = screen;
}

void ButtonText::setPosition(int x1, int y1, int x2, int y2){
	_x1 = x1; _y1 = y1; _x2 = x2; _y2 = y2;
}

void ButtonText::print(){
	
	int length = strlen(_text);
	int xSize, ySize;
	
	_screen -> setColor(_frontColor.r, _frontColor.g, _frontColor.b); 
	_screen -> fillRoundRect (_x1, _y1, _x2, _y2);
	_screen -> setColor(_borderColor.r,_borderColor.g, _borderColor.b);
	_screen -> drawRoundRect (_x1, _y1, _x2, _y2);
 
	_screen -> setBackColor(_backgroundColor.r, _backgroundColor.g, _backgroundColor.b);
	_screen -> setColor(_fontColor.r,_fontColor.g, _fontColor.b);
	
	if (_fontSize){
		_screen -> setFont(BigFont); 
		xSize = _x1+(((_x2 - _x1+1)-(length*16))/2);
		ySize = _y1+(((_y2 - _y1+1)-16)/2);
		
		if(_text)
			_screen -> print(_text,  xSize, ySize);
		else
			_screen -> printNumI(_intText, xSize, ySize);
		
	}else {
		_screen -> setFont(SmallFont); 
		xSize= _x1+(((_x2 - _x1)-(length*8))/2);
		ySize = _y1+(((_y2 - _y1-1)-8)/2);
		if(_intText)
			_screen -> printNumI(_intText, xSize, ySize);
		else
			_screen -> print(_text, xSize, ySize);
   }
}

boolean ButtonText::pushed(int x, int y){
  return ((x>=_x1) && (x<=_x2) && (y>=_y1) && (y<=_y2));
}

/***************************** Button **********************************************/
Button::Button(UTFT *screen){
	_screen = screen;
}

Button::Button(){
}

void Button::setPosition(int x1, int y1, int x2, int y2){
	_x1 = x1; _y1 = y1; _x2 = x2; _y2 = y2;
}

void Button::print(){
	_screen -> setColor(_borderColor.r,_borderColor.g, _borderColor.b);
    _screen -> drawRoundRect (_x1, _y1, _x2, _y2);
}

boolean Button::pushed(int x, int y){
  return ((x>=_x1) && (x<=_x2) && (y>=_y1) && (y<=_y2));
}