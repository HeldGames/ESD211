long x;
int pin[] = { 4, 5, 6, 7, 8, 9, 10, 11 };
int f = 100;
int T = 1*1000 / f;
long lasttime = 0;


void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(pin[i], OUTPUT);
  }
}


void loop() {
  if ((millis() - lasttime) > T) {
    lasttime += T;
    x = analogRead(A0);
    int y = map(x, 0, 1023, 0, 255);
    for (int i = 0; i < 7; i++) {
      digitalWrite(pin[i], bitRead(y, i + 1));  //i+1 fordi bits åbentbart bliver læst fra 1 og ikke 0
    }
  }
}
