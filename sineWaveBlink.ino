float slope, count, interval, currentSin;
int minFreq, maxFreq;

void setup() {
  Serial.begin(9600);
  minFreq = 2;
  maxFreq = 50;
  slope = (maxFreq - minFreq) / 2;
  pinMode(LED_BUILTIN, OUTPUT);
  interval = 0.08;
  count = -interval;
}

float newSinValue(){    
  count += interval;
  return sin(2*PI*count/3)+1;
}

void loop() {  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000/(slope*(currentSin = newSinValue()) + minFreq));
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000/(slope*currentSin + minFreq));
}
