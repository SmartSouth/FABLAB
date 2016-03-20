int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);     // This is a comment
}

void loop() {
  digitalWrite(LedPin, LOW);   
                                    
  delay(1000);                    
  digitalWrite(ledPin, HIGH); 
  delay(1000); 
  digitalWrite(ledPin, LOW);                      
}
