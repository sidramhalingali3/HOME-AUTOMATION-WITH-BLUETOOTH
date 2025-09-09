String voice = "";

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT); // Light
  pinMode(9, OUTPUT); // Fan
}

void loop() {
  while (Serial.available()) {
    delay(3);  // small delay to ensure the full command is received
    char c = Serial.read();
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);  // echo the received voice command

    if (voice == "turn on light") {
      digitalWrite(13, HIGH);
    }
    else if (voice == "turn off light") {
      digitalWrite(13, LOW);
    }
    else if (voice == "turn on fan") {
      digitalWrite(9, HIGH);
    }
    else if (voice == "turn off fan") {
      digitalWrite(9, LOW);
    }
    else if (voice == "turn on all") {
      digitalWrite(13, HIGH);
      digitalWrite(9, HIGH);
    }
    else if (voice == "turn off all") {
      digitalWrite(13, LOW);
      digitalWrite(9, LOW);
    }

    // Clear the string after processing
    voice = "";
  }
}
