#pragma once
#include <Arduino.h>
#include <Adafruit_MCP23017.h> 

struct WindowSetings  // структура с настройками окна
{
	int idWindow; //номер окна
	int corner;// угол открытия окна
	bool StatusWindow; // закрыты или открыты окна на канале
	int motor_PinPlus;//номер плюсового пина для мотора 
	int motor_PinMinus;//номер минусового пина для мотора 
};






class Window 
{
		
	
	public:
		void OpenWindow(WindowSetings *SetingsCorner, int NumberWindow ); // открыть окно
		void CloseWindow(WindowSetings *SetingsCorner, int NumberWindow);// закрыть окно
		void ChangeCorner(WindowSetings *SetingsCorner, int NumberWindow, int NewCorner);// изменение угла открытия
		
};