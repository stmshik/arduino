#include <WindowLib.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
//#include <Arduino.h>

		void Window::OpenWindow(WindowSetings *SetingsCorner, int NumberWindow)// открыть окно
		{
			//SetingsCorner[NumberWindow].motor_PinPlus;
			//SetingsCorner[NumberWindow].motor_PinMinus;		
			
			  Adafruit_MCP23017 mcp;// создание объекта для работы с микрой мср23017
			  mcp.begin();      // use default address 0

			  mcp.pinMode(SetingsCorner[NumberWindow].motor_PinPlus, OUTPUT);
			  mcp.pinMode(SetingsCorner[NumberWindow].motor_PinMinus, OUTPUT);
			  
			  
			  mcp.digitalWrite(SetingsCorner[NumberWindow].motor_PinPlus, HIGH);
			  mcp.digitalWrite(SetingsCorner[NumberWindow].motor_PinMinus, LOW);
			  
			 // mcp.pinMode(0, OUTPUT);
			 // mcp.pinMode(1, OUTPUT);
			  
			  
			 // mcp.digitalWrite(0, HIGH);
			  //mcp.digitalWrite(1, LOW);
			  SetingsCorner[NumberWindow].StatusWindow=1;// установка статуса открытия окна в положение "открыто"
			  
			 // mcp.pullUp(0, HIGH);  // turn on a 100K pullup internally
				
				
				/*pinMode (12,OUTPUT); //
				pinMode (11, OUTPUT);
				pinMode(10,OUTPUT);
				pinMode(9,OUTPUT);
			  digitalWrite(12,HIGH);
			  digitalWrite(11,LOW);
			  digitalWrite(10,HIGH);
			  digitalWrite(9,LOW);*/
			  
			  
			  delay(SetingsCorner[NumberWindow].corner*1000);
						
		}
		
		void Window::CloseWindow(WindowSetings *SetingsCorner, int NumberWindow)// закрыть окно
		{
			Adafruit_MCP23017 mcp;// создание объекта для работы с микрой мср23017
			  mcp.begin();      // use default address 0

			  mcp.pinMode(SetingsCorner[NumberWindow].motor_PinPlus, OUTPUT);
			  mcp.pinMode(SetingsCorner[NumberWindow].motor_PinMinus, OUTPUT);
			  
			  
			  mcp.digitalWrite(SetingsCorner[NumberWindow].motor_PinPlus, HIGH);
			  mcp.digitalWrite(SetingsCorner[NumberWindow].motor_PinMinus, LOW);
			  
			 // mcp.pinMode(0, OUTPUT);
			 // mcp.pinMode(1, OUTPUT);
			  
			  
			 // mcp.digitalWrite(0, HIGH);
			  //mcp.digitalWrite(1, LOW);
			  SetingsCorner[NumberWindow].StatusWindow=0;// установка статуса открытия окна в положение "открыто"
			  delay(SetingsCorner[NumberWindow].corner*1000);
			  
			
		}
		void Window::ChangeCorner(WindowSetings *SetingsCorner, int NumberWindow, int NewCorner)// изменение угла открытия окноа
		{
			SetingsCorner[NumberWindow].corner=NewCorner;
		}
		