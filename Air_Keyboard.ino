/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
//const int analogInPin = A6;  // Analog input pin that the potentiometer is attached to
//the fingers on the right hand.
const int Rt = A0;
const int R1 = A1;
const int R2 = A2;
const int R3 = A3;
const int R4 = A6;
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValueT = 0,sensorValue1 = 0,sensorValue2 = 0,sensorValue3 = 0,sensorValue4 = 0;        // value read from the pot
int outputValueT = 0, outputValue1 = 0,outputValue2 = 0,outputValue3 = 0,outputValue4 = 0;  // value output to the PWM (analog out)
String lastVT = "",lastV1 = "",lastV2 = "",lastV3 = "",lastV4 = "";
String lastVTL = "",lastV1L = "",lastV2L = "",lastV3L = "",lastV4L = "";


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200); //for bluetooth 
 
}

void loop() {


  // read the analog in value:
  sensorValueT = analogRead(Rt);
  sensorValue1 = analogRead(R1);
  sensorValue2 = analogRead(R2);
  sensorValue3 = analogRead(R3);
  sensorValue4 = analogRead(R4);
  // map it to the range of the analog out:
  outputValueT = map(sensorValueT, 0, 1023, 0, 255);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
  outputValue4 = map(sensorValue4, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(Rt, outputValueT);
  //analogWrite(R2, outputValue2);
  //analogWrite(R4, outputValue4);


  //all the letters on the right hand
  if(outputValue4 > 195)    //DONE
  {
    if(!lastV4.equals("P"))
    {
      Serial.print("P");
      lastV4 = "P";
    }
    
  }
  else
  {
      lastV4 = "";
    
  }

  if(outputValue1 < 185) 
  {
    if(!lastV1.equals("M"))
    {
      Serial.print("M");
      lastV1 = "M";
    }
    
  }
  else
  {
      lastV1 = "";
    
  }

  if(outputValue2 > 195)    //DONE
  {
    if(!lastV2.equals("I"))
    {
      Serial.print("I");
      lastV2 = "I";
    }
    
  }
  else
  {
      lastV2 = "";
    
  }


  //all the letters on the left hand
  if(outputValue3 < 175)    //DONE
  {
    if(!lastV3L.equals("C"))
    {
      Serial.print("C");
      lastV3L = "C";
    }
    
  }
  else
  {
      lastV3L = "";
    
  }

  if(outputValue2 < 175) 
  {
    if(!lastV2L.equals("B"))
    {
      Serial.print("B");
      lastV2L = "B";
    }
    
  }
  else
  {
      lastV2L = "";
    
  }

  if(outputValue1 > 210)    //DONE
  {
    if(!lastV1L.equals("A"))
    {
      Serial.print("A");
      lastV1L = "A";
    }
    
  }
  else
  {
      lastV1L = "";
    
  }

  if(outputValue4 < 175)    //DONE
  {
    if(!lastV4L.equals("T"))
    {
      Serial.print("T");
      lastV4L = "T";
    }
    
  }
  else
  {
      lastV4L = "";
    
  }
  
 
//  // print the results to the serial monitor:
//  Serial.print("sensor = ");
//  Serial.print(sensorValue);
//  Serial.print("\t output = ");
//  Serial.println(outputValue);

//  // wait 2 milliseconds before the next loop
//  // for the analog-to-digital converter to settle
//  // after the last reading:
  delay(10);
  
}
