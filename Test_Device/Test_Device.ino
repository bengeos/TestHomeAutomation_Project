
//defining analog inputs
const int A_INPUT_0= A0;
const int A_INPUT_1=A1;
const int A_INPUT_2=A2;
const int A_INPUT_3=A3;
const int A_INPUT_4=A4;
const int A_INPUT_5=A5;
//defining digital inputs
const int D_INPUT_0= 2;
const int D_INPUT_1= 3;
const int D_INPUT_2= 4;
const int D_INPUT_3= 5;
const int D_INPUT_4= 6;
const int D_INPUT_5= 7;
//defining digital outputs
const int D_OUTPUT_0= 8;
const int D_OUTPUT_1= 9;
const int D_OUTPUT_2= 10;
const int D_OUTPUT_3= 11;
const int D_OUTPUT_4= 12;
const int D_OUTPUT_5= 13;
//Out pins status
int OUTPUT_STATUS_0 = 0;
int OUTPUT_STATUS_1 = 0;
int OUTPUT_STATUS_2 = 0;
int OUTPUT_STATUS_3 = 0;
int OUTPUT_STATUS_4 = 0;
int OUTPUT_STATUS_5 = 0;
//
String serialData = "";
String recivedData = "";
bool serialComplete = false;


void setup() 
{
  //Digital Inputs
  pinMode(D_INPUT_0,INPUT);
  pinMode(D_INPUT_1,INPUT);
  pinMode(D_INPUT_2,INPUT);
  pinMode(D_INPUT_3,INPUT);
  pinMode(D_INPUT_4,INPUT);
  pinMode(D_INPUT_5,INPUT);
  //Digital output
  pinMode(D_OUTPUT_0,OUTPUT);
  pinMode(D_OUTPUT_1,OUTPUT);
  pinMode(D_OUTPUT_2,OUTPUT);
  pinMode(D_OUTPUT_3,OUTPUT);
  pinMode(D_OUTPUT_4,OUTPUT);
  pinMode(D_OUTPUT_5,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  serialEvent(); 
  if(serialComplete)
  {
     updateStatus();
     updateOutputPins();
     Serial.println(recivedData);
  }
  serialComplete=false;
  recivedData="";
  delay(1);
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    recivedData += inChar;
    
    if (inChar == '\\') {
      serialComplete = true;
    }
  }
}

void updateOutputPins()
{
    //OUTPUT1
    if(OUTPUT_STATUS_0==1)
    {
        digitalWrite(D_OUTPUT_0,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_0,LOW);
    }
    //OUTPUT2
    if(OUTPUT_STATUS_1==1)
    {
        digitalWrite(D_OUTPUT_1,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_1,LOW);
    }
    //OUTPUT3
     if(OUTPUT_STATUS_2==1)
    {
        digitalWrite(D_OUTPUT_2,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_2,LOW);
    }
    //OUTPUT4
     if(OUTPUT_STATUS_3==1)
    {
        digitalWrite(D_OUTPUT_3,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_3,LOW);
    }
    //OUTPUT5
     if(OUTPUT_STATUS_4==1)
    {
        digitalWrite(D_OUTPUT_4,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_4,LOW);
    }
    //OUTPUT6
     if(OUTPUT_STATUS_5==1)
    {
        digitalWrite(D_OUTPUT_5,HIGH);
    }
    else
    {
        digitalWrite(D_OUTPUT_5,LOW);
    }
}
void updateStatus()
{
    if(recivedData.substring(5).equals("ON"))
    {
        Serial.print("is on");
        if(recivedData.substring(0,5)=="PORT1")
        {
           OUTPUT_STATUS_0=1;
        }
        else if(recivedData.substring(0,5)=="PORT2")
        {
          OUTPUT_STATUS_1=1;
        }
        else if(recivedData.substring(0,5)=="PORT3")
        {
          OUTPUT_STATUS_2=1;
        }
        else if(recivedData.substring(0,5)=="PORT4")
        {
          OUTPUT_STATUS_3=1;
        }
        else if(recivedData.substring(0,5)=="PORT5")
        {
          OUTPUT_STATUS_4=1;
        }
        else if(recivedData.substring(0,5)=="PORT6")
        {
          OUTPUT_STATUS_5=1;
          Serial.print("Port 6 is on");
        }
    }
    else if(recivedData.substring(5).equals("OFF"))
    {
        Serial.print("is off");
         if(recivedData.substring(0,5)=="PORT1")
        {
           OUTPUT_STATUS_0=0;
        }
        else if(recivedData.substring(0,5)=="PORT2")
        {
          OUTPUT_STATUS_1=0;
        }
        else if(recivedData.substring(0,5)=="PORT3")
        {
          OUTPUT_STATUS_2=0;
        }
        else if(recivedData.substring(0,5)=="PORT4")
        {
          OUTPUT_STATUS_3=0;
        }
        else if(recivedData.substring(0,5)=="PORT5")
        {
          OUTPUT_STATUS_4=0;
        }
        else if(recivedData.substring(0,5)=="PORT6")
        {
          OUTPUT_STATUS_5=0;
        }
    }
  
}
