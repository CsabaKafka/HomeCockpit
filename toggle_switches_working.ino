/*
 * Pins:      Cockpit Function           Bits&Droids Function
 * PIN = 2    ToggleMasterBattery1       sendToggleMasterBattery1
 * PIN = 3    AvionicsMaster1Off/On
 * PIN = 4    ToggleExternalPower
 * PIN = 5    ToggleStarter1
 * PIN = 6    ToggleStarter2
 * PIN = 7    ToggleStarterAutoStart
 */

#include <BitsAndDroidsFlightConnector.h>

const byte Battery = 2;
bool BatteryState = false;
const byte AvionicsMaster = 3;
bool AvionicsMasterState = false;
const byte ExternalPower = 4;
bool ExternalPowerState = false;
const byte Starter1 = 5;
bool Starter1State = false;
const byte Starter2 = 6;
bool Starter2State = false;
const byte AutoStart = 7;
bool AutoStartState = false;

BitsAndDroidsFlightConnector connector(false);

void setup() {
  Serial.begin(115200);
  pinMode(Battery, INPUT_PULLUP);
  pinMode(AvionicsMaster, INPUT_PULLUP);
  pinMode(ExternalPower, INPUT_PULLUP);
  pinMode(Starter1, INPUT_PULLUP);
  pinMode(Starter2, INPUT_PULLUP);
  pinMode(AutoStart, INPUT_PULLUP);
}

void loop() {
//------------------------------------------------------------------------------------
//Battery
  if(digitalRead(Battery) == LOW){
    if(!BatteryState){
      Serial.println(connector.sendToggleMasterBattery1()); //-->Bits&Droids Function
      BatteryState = true;
    }
  }
  else{
     if(BatteryState){
      Serial.println(connector.sendToggleMasterBattery1());
      BatteryState = false;
    }
  }
//------------------------------------------------------------------------------------
//Avionics
  if(digitalRead(AvionicsMaster) == LOW){
    if(!AvionicsMasterState){
      Serial.println(connector.sendAvionicsMaster1Off());
      AvionicsMasterState = true;
    }
  }
  else{
     if(AvionicsMasterState){
      Serial.println(connector.sendAvionicsMaster1On());
      AvionicsMasterState = false;
    }
  }
//------------------------------------------------------------------------------------
//ExternalPower
  if(digitalRead(ExternalPower) == LOW){
    if(!ExternalPowerState){
      Serial.println(connector.sendToggleExternalPower());
      ExternalPowerState = true;
    }
  }
  else{
     if(ExternalPowerState){
      Serial.println(connector.sendToggleExternalPower());
      ExternalPowerState = false;
    }
  }
//------------------------------------------------------------------------------------
//Starter1
  if(digitalRead(Starter1) == LOW){
    if(!Starter1State){
      Serial.println(connector.sendToggleStarter1());
      Starter1State = true;
    }
  }
  else{
     if(Starter1State){
      Serial.println(connector.sendToggleStarter1());
      Starter1State = false;
    }
  }
//Starter2
  if(digitalRead(Starter2) == LOW){
    if(!Starter2State){
      Serial.println(connector.sendToggleStarter2());
      Starter2State = true;
    }
  }
  else{
     if(Starter2State){
      Serial.println(connector.sendToggleStarter2());
      Starter2State = false;
    }
  }
//------------------------------------------------------------------------------------
//AutoStart
  if(digitalRead(AutoStart) == LOW){
    if(!AutoStartState){
      Serial.println(connector.sendMagneto1Both());
      AutoStartState = true;
    }
  }
  else{
     if(AutoStartState){
      Serial.println(connector.sendMagneto1Off());
      AutoStartState = false;
    }
  }
  
}
