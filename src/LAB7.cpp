/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vishal/Documents/CTDProjects/LAB7/src/LAB7.ino"
/*
 * Project LAB7
 * Description:
 * Author:
 * Date:
 */
#include <blynk.h>
#include "oled-wing-adafruit.h"
void setup();
void loop();
#line 9 "c:/Users/Vishal/Documents/CTDProjects/LAB7/src/LAB7.ino"
SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;
uint64_t reading;
double voltage;
double temperature;
// setup() runs once, when the device is first turned on.
void setup()
{
	// Put initialization like pinMode and begin functions here.
	pinMode(A5, INPUT); // sets A5 as input to the TMP36
	display.setup();
	display.clearDisplay();
	display.display();
	Blynk.begin("D5wAwJ-jMX14ywmEQ_OIBj_OMNokPHlc", IPAddress(167, 172, 234, 162), 9090);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
	// The core of your code will likely live here.
	Blynk.run();
	display.loop();
	display.clearDisplay();
	reading = analogRead(A5);
	voltage = (reading * 3.3) / 4095.0;	 //converts the reading to a voltage value
	temperature = (voltage - 0.5) * 100; //converts the voltage value to temperature in celsius
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.print(temperature);
	display.println(" C");
	display.print(temperature * 1.8 + 32);
	display.println(" F");
	display.display();

	if (display.pressedA())
	{
		display.clearDisplay();
		Blynk.notify("Hey, got a push notification!");
		display.println("Push sent");
		display.display();
		delay(5000);
	}
}