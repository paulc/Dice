const struct dicePins { int centre,leftDiag,rightDiag,middle; } \
  l = { 9,8,7,6 }, 
  r = { 13,12,11,10 };

const int buttonPin = 2;    
int buttonState;

void setDicePins(const struct dicePins d) {
  pinMode(d.centre, OUTPUT);
  pinMode(d.leftDiag, OUTPUT);
  pinMode(d.rightDiag, OUTPUT);
  pinMode(d.middle, OUTPUT);  
}

void clear(const struct dicePins d) {
  digitalWrite(d.centre,LOW);
  digitalWrite(d.leftDiag,LOW);
  digitalWrite(d.rightDiag,LOW);
  digitalWrite(d.middle,LOW);
}

void display(const struct dicePins d, int n) {
  switch (n) {
    case 1: digitalWrite(d.centre,HIGH);
            break;
    case 2: digitalWrite(d.rightDiag,HIGH);
            break;
    case 3: digitalWrite(d.leftDiag,HIGH);
            digitalWrite(d.centre,HIGH);
            break;    
    case 4: digitalWrite(d.rightDiag,HIGH);
            digitalWrite(d.leftDiag,HIGH);
            break;    
    case 5: digitalWrite(d.rightDiag,HIGH);
            digitalWrite(d.leftDiag,HIGH);
            digitalWrite(d.centre,HIGH);
            break;
    case 6: digitalWrite(d.rightDiag,HIGH);
            digitalWrite(d.leftDiag,HIGH);
            digitalWrite(d.middle,HIGH);
            break;
  }       
}

void test() {
  for(;;) {
    clear(l);
    clear(r);
    delay(250);
    display(l,random(1,7)); 
    display(r,random(1,7));
    delay(1000);    
  }
}

void setup() {
  pinMode(buttonPin, INPUT);
  setDicePins(l);
  setDicePins(r);
  clear(l);
  clear(r);
  if (digitalRead(buttonPin) == HIGH) {
    test();
  }
}

void loop() {
      buttonState = digitalRead(buttonPin);
      if (buttonState == LOW) {
        delay(50);
      } else {
        clear(l);
        clear(r);
        delay(25);
        display(l,random(1,7)); 
        display(r,random(1,7));
        delay(25);
      }
}
