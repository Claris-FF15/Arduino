  const int micpin = A1;
  const int led1 = 2;
  const int led2 = 4;
  const int led3 = 6;
  const int led4 = 8;
  const int num_led = 4;

  int mic;
  const int baseline = 50;

  int amplitude;
  const int max_amplitude = 200;

  const int delta = max_amplitude/(num_led+1);

  const int thresh1 = delta;
  const int  thresh2 = thresh1 + delta;
  const int thresh3 = thresh2 + delta;
  const int thresh4 = thresh3 + delta;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mic = analogRead(micpin);
  amplitude = abs(mic-baseline);
  Serial.println(amplitude);

  if (amplitude> thresh4){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if (amplitude> thresh3){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  else if (amplitude> thresh2){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else if (amplitude> thresh1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
