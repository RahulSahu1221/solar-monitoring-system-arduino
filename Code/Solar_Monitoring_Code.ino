// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

//Measuring Current Using ACS712 
int sensitivity = 185; // use 100 for 20A Module and 66 for 30A Module 
int adcvalue= 0; 
int offsetvoltage = 2500;  //Sensor Callibration
double Voltage = 0; //voltage measuring 
double ecurrent = 0;// Current measuring 
float power = 0;
float energy = 0;

float batteryVoltage = 0;
float batteryPercent = 30.0;

unsigned long previousMillis = 0;


void setup() 
{
  Serial.begin(9600);
  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
  lcd.print("  THE BRIGHT LIGHT    ");
  lcd.setCursor(0,1);
  lcd.print("  SOLAR MONITORING             ");
  previousMillis = millis();
} 

void loop()
{ 
  Serial.println(analogRead(A0));
  // Measure The Votage ***********************************
  // read the input on analog pin A1:
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float vol = (sensorValue * 5.0) / 1023.0;
  float voltage = vol * 5;
  
  // Battery Voltage Measurement (A2)

  int batteryADC = analogRead(A2);
  float batteryVol = (batteryADC * 5.0) / 1023.0;
  batteryVoltage = batteryVol * 5.0;

    // Measure The Current ***********************************
    adcvalue = analogRead(A0);//reading the value from the analog pin A0
    Voltage = (adcvalue / 1024.0) * 5000; // Gets you mV
    ecurrent = abs((Voltage - offsetvoltage) / sensitivity);
   
    power = voltage * ecurrent;
    unsigned long currentMillis = millis();
    energy += power * ((currentMillis - previousMillis) / 3600000.0);
    previousMillis = currentMillis;

    
    
    String chargeStatus;

    // Charging Status

    if(voltage > batteryVoltage + 1.0)
    {
      chargeStatus = "Charging";

      batteryPercent += (ecurrent * 0.1);   // SOC increases while charging

      if(batteryPercent > 100)
      {
        batteryPercent = 100;
      }
    }
    else
    {
      chargeStatus = "Standby";
    }

    batteryPercent = constrain(batteryPercent, 0, 100);
    
    // ================= SCREEN 1 =================

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("SOLAR MONITORING");

    lcd.setCursor(0,1);
    lcd.print("V=");
    lcd.print(voltage,1);
    lcd.print("V");

    lcd.setCursor(0,2);
    lcd.print("I=");
    lcd.print(ecurrent,1);
    lcd.print("A");

    delay(2000);


  // ================= SCREEN 2 =================

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("ENERGY GENERATED");

  lcd.setCursor(0,1);
  lcd.print("E=");
  lcd.print(energy,3);
  lcd.print("Wh");

  lcd.setCursor(0,2);
  lcd.print("P=");
  lcd.print(power,2);
  lcd.print("W");

  delay(2000);


  // ================= SCREEN 3 =================

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("BATTERY STATUS");

  lcd.setCursor(0,1);
  lcd.print("VB=");
  lcd.print(batteryVoltage,2);
  lcd.print("V");

  lcd.setCursor(0,2);
  lcd.print("SOC=");
  lcd.print(round(batteryPercent));
  lcd.print("% ");

  lcd.print("I=");
  lcd.print(ecurrent,1);
  lcd.print("A");

  lcd.setCursor(0,3);
  lcd.print(chargeStatus);

  delay(2000);
}
