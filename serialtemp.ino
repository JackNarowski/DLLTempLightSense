
#define aref_voltage 5

int tempsense = A2;
int tempinput = 0;
int lightsense = A1;
int lightinput = 0;

void setup() {
  pinMode(tempsense, INPUT);
  pinMode(lightsense, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  temp();
  
  light();
  
  delay(5000);
}

void temp() {
  tempinput = analogRead(tempsense);
  Serial.print("Temp Sense = "); Serial.println(tempinput);
  
  int Vo;
  float R1 = 10000;
  float logR2, R2, T;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

  R2 = R1 * (1023.0 / (float)tempinput - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 
}



void light(){
  lightinput = analogRead(lightsense);
  Serial.print("Light Sense = ");
  Serial.println(lightinput);

}
