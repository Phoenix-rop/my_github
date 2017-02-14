
#include <SoftwareSerial.h>
int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 6;
int LED5 = 9;
int LED6 = 10;
int LED7 = 12;

int LDR1 = A0;
int LDR2 = A1;
int LDR3 = A2;

int sensorLDR1 =0;
int sensorLDR2 =0;
int sensorLDR3 =0;
String Order; 

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  //Serial.println("Liveing Room : Led 1,2,3,4");
  sensorLDR1 = analogRead(LDR1);
  //Serial.println(sensorLDR1);
  //delay(1000);
  //Serial.println("Bed Room : Led 5,6");
  sensorLDR2 = analogRead(LDR2);
  //Serial.println(sensorLDR2);
  //delay(1000);
  //Serial.println("Bath Room : Led 7");
  sensorLDR3 = analogRead(LDR3);
  //Serial.println(sensorLDR3);
  //delay(1000);
  
  if(Serial.available()>0){
  Order = Serial.readString();
  }

  //Auto
  if(Order == "AUTO"){
    if(sensorLDR1 < 50){
      Serial.println("Ligth in Liveing Room : ON");
      digitalWrite(LED1, HIGH);Serial.print("LED1ON");
      digitalWrite(LED2, HIGH);Serial.print("LED2ON");
      digitalWrite(LED3, HIGH);Serial.print("LED3ON");
      digitalWrite(LED4, HIGH);Serial.print("LED4ON");
      delay(100);
    }else{
      Serial.println("Ligth in Liveing Room : OFF");
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
   }
    //Auto
    if(sensorLDR2 < 100){
      Serial.println("Ligth in Bed Room : ON");
      digitalWrite(LED5, HIGH);Serial.print("LED5ON");
      digitalWrite(LED6, HIGH);Serial.print("LED6ON");
      delay(100);
    }else{
      Serial.println("Ligth in Bed Room : OFF");
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
    }
    //Auto
    if(sensorLDR3 < 850){
      Serial.println("Ligth in Bath Room : ON");
      digitalWrite(LED7, HIGH);Serial.print("LED7ON");
      delay(100);
    }else{
      Serial.println("Ligth in Bath Room : OFF");
      digitalWrite(LED7, LOW);
    }
  } else if(Order == "ONLED1"){digitalWrite(LED1, HIGH);
  }else if(Order == "ONLED2"){digitalWrite(LED2, HIGH);
  }else if(Order == "ONLED3"){digitalWrite(LED3, HIGH);
  }else if(Order == "ONLED4"){digitalWrite(LED4, HIGH);
  }else if(Order == "ONLED5"){digitalWrite(LED5, HIGH);
  }else if(Order == "ONLED6"){digitalWrite(LED6, HIGH);
  }else if(Order == "ONLED7"){digitalWrite(LED7, HIGH);
  }else if(Order == "OFFLED1"){digitalWrite(LED1, LOW);
  }else if(Order == "OFFLED2"){digitalWrite(LED2, LOW);
  }else if(Order == "OFFLED3"){digitalWrite(LED3, LOW);
  }else if(Order == "OFFLED4"){digitalWrite(LED4, LOW);
  }else if(Order == "OFFLED5"){digitalWrite(LED5, LOW);
  }else if(Order == "OFFLED6"){digitalWrite(LED6, LOW);
  }else if(Order == "OFFLED7"){digitalWrite(LED7, LOW);
  }else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
  }
  
    
    
  
  
  // put your main code here, to run repeatedly:

}
