* Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YOUR-AUTHENTICATION-TOKEN";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "heisenberg", "mrwhite13");
}

void loop()
{
  Blynk.run();
}
