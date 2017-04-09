/*

Uses a flex sensor glove to map letters to different finger positions.

 created April 8th 2017
 by Marie Danenhower, Gina Dedes, Mahrukh Siddiqui
 */
const int Rt = A0;
const int R1 = A1;
const int R2 = A2;
const int R3 = A3;
const int R4 = A6;

int sensorValueT = 0,sensorValue1 = 0,sensorValue2 = 0,sensorValue3 = 0,sensorValue4 = 0;        // value read from the port
int outputValueT = 0, outputValue1 = 0,outputValue2 = 0,outputValue3 = 0,outputValue4 = 0;  // the amount of flex read from the sensors
String lastVT = "",lastV1 = "",lastV2 = "",lastV3 = "",lastV4 = "";   //for each finger, the last value read from the right side of the qwerty keyboard
String lastVTL = "",lastV1L = "",lastV2L = "",lastV3L = "",lastV4L = "";  //for each finger, the last value read from the left side of the qwerty keyboard


void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200); 
 
}

void loop() {


  // read the analog in value for each finger
  sensorValueT = analogRead(Rt);
  sensorValue1 = analogRead(R1);
  sensorValue2 = analogRead(R2);
  sensorValue3 = analogRead(R3);
  sensorValue4 = analogRead(R4);
  // map it to the range of the analog out
  outputValueT = map(sensorValueT, 0, 1023, 0, 255);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
  outputValue4 = map(sensorValue4, 0, 1023, 0, 255);


  //all the letters on the right hand
  if(outputValue4 > 195)    
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

  if(outputValue2 > 195)    
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
  if(outputValue3 < 175)    
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

  if(outputValue1 > 210)    
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
  
  if(outputValue4 < 175)    
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
  delay(10);
  
}
