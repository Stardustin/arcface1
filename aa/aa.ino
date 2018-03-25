#if 1
int i;
void setup()
{
	Serial.begin(9600);
	pinMode(7, OUTPUT);
}
void loop()
{
	String inString="";
	while (Serial.available()>0) {
			char inChar = Serial.read();
			inString += (char)inChar;
			delay(10);
	}
	if (inString.toDouble()> 0.5) {
		Serial.print("Input String:");
		Serial.println(inString);
		digitalWrite(7, HIGH);
		delay(200);
		digitalWrite(7, LOW);
		delay(200);
	}
	
}
#endif
