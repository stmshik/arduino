#include <TroykaDHT.h>// библиотека датчика температуры и влажности
#include <WindowLib.h> // собственная библиотека
// new change ssh

int GetTemp_DHT11();// прототип функции
bool SignalOpenCloze(int TempDHT11, int TempMax, int TempMin);// прототип функции

unsigned long timing;//для корректной работы датчика температуры.

int Temp_Max=27;//температура открытия окон
int Temp_Min=20;//температура закрытия окон

int Temp_Dht11=0;
bool sig;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   int sizeWinObject=3; // размер массива 
   WindowSetings WindowObject[]={ // создание обЪекта с настройками окна
	    {0,30},
		{1,30},
		{2,30},
		{3,30}
   }

}//end setup

void loop()
{
  // put your main code here, to run repeatedly:

    if (millis() - timing > 5000)//5 секунд
    {  
        timing = millis();
        Temp_Dht11=GetTemp_DHT11();
        Serial.println (Temp_Dht11);//получение температуры  тип полученного значения int   
     
    }
        sig=SignalOpenCloze(Temp_Dht11,Temp_Max,Temp_Min);// получение сигнала на открытие или закрытие 
        Serial.println(sig);

        
       // delay(1000);
}// end loop

//-------------------------------------пользовательские функции------------------------------

bool SignalOpenCloze(int TempDHT11, int TempMax, int TempMin)
{
  if (TempDHT11>=TempMax) return 1; // открыть
  if (TempDHT11 <=TempMin) return 0;// закрыть  
}// End SignalOpenCloze
  
int GetTemp_DHT11()
  {
          DHT dht(5, DHT11);// обЪект датчика температуры, влажности подключенному к 5 цифровому пину.
          dht.read();// считывание данных с датчика
                 // проверяем состояние данных    
                switch(dht.getState())
                {
                  // всё OK
                  case DHT_OK:
                    // выводим показания влажности и температуры            
                   return int( dht.getTemperatureC());// Температура с датчика
                     //dht.getHumidity(); //Влажность с датчика
                    
                    break;
                  // ошибка контрольной суммы
                  case DHT_ERROR_CHECKSUM:
                    Serial.println("Checksum error");
                    break;
              //     превышение времени ожидания
                  case DHT_ERROR_TIMEOUT:
                    Serial.println("Time out error");
                    break;
                  // данных нет, датчик не реагирует или отсутствует
                  case DHT_ERROR_NO_REPLY:
                    Serial.println("Sensor not connected");     
                    break;
                }     

  }    //end GetTemp_DHT11
  
