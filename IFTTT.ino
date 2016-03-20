# Fablab London - Internet of Things 

![Node MCU](http://www.seeedstudio.com/depot/images/113990105%201.jpg)

1. [Setting up the software toolchain](https://github.com/SmartSouth/fablablondon/wiki/IoT-Taster-Fablab-London#setting-up-the-software-toolchain)

2. [Social media and IoT: IFTTT](https://github.com/SmartSouth/fablablondon/wiki/IoT-Taster-Fablab-London#social-media-and-iot-ifttt)

3. [The anatomy of code](https://github.com/SmartSouth/fablablondon/wiki/IoT-Taster-Fablab-London#blynk_app)

4. [Blynk app](https://github.com/SmartSouth/fablablondon/wiki/IoT-Taster-Fablab-London#blynk_app)



5. [An online dashboard: io.adafruit.com](https://github.com/SmartSouth/fablablondon/wiki/IoT-Taster-Fablab-London#an-online-dashboard-ioadafruitcom)

## Setting up the software toolchain

1. Download the Arduino IDE from <https://www.arduino.cc/en/Main/Software>

2. Install the IDE and go to 'Settings' or 'Preferences' and copy-paste the following link to the '_Additional Board Manager URLs'_ field: http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. Open Boards Manager from Sketch > Include Library > Manage Libraries menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

4. Download and install the USB driver from [https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)

5. Connect the board with the USB cable.



## Social media and IoT: IFTTT

Copy and paster the following code to the Arduino IDE. 

`#include <ESP8266WiFi.h>`
 
`const char* ssid     = "heisenberg";`
`const char* password = "mrwhite13";`
 
`const char* host = "maker.ifttt.com";`
 
`void setup() {`
  `Serial.begin(115200);`
  `delay(100);`
 
  `// We start by connecting to a WiFi network`
 
  `Serial.println();`
  `Serial.println();`
  `Serial.print("Connecting to ");`
  `Serial.println(ssid);`
  
  `WiFi.begin(ssid, password);`
  
  `while (WiFi.status() != WL_CONNECTED) {`
    `delay(500);`
    `Serial.print(".");`
  `}`
 
  `Serial.println("");`
  `Serial.println("WiFi connected");  `
  `Serial.println("IP address: ");`
  `Serial.println(WiFi.localIP());`
`}`
 
`int value = 0;`
 
`void loop() {`
  `delay(5000);`
  `++value;`
 
  `Serial.print("connecting to ");`
  `Serial.println(host);`
  
  `// Use WiFiClient class to create TCP connections`
  `WiFiClient client;`
  `const int httpPort = 80;`
  `if (!client.connect(host, httpPort)) {`
    `Serial.println("connection failed");`
    `return;`
  `}`
  
  `// We now create a URI for the request`
  `String url = "trigger/{trigga}/with/key/rRB3V7RFkcBqqvNSPognn";`
  `Serial.print("Requesting URL: ");`
  `Serial.println(url);`
  
  `// This will send the request to the server`
`client.print(String("POST ") + url + " HTTP/1.1\r\n" +`
               `"Host: " + host + "\r\n" + `
               `"Connection: close\r\n\r\n");`

    `// Read all the lines of the reply from server and print them to Serial`
  `while(client.available()){`
    `String line = client.readStringUntil('\r');`
    `Serial.print(line);`
  `}`
  
  `Serial.println();`
  `Serial.println("closing connection");`
`}`

## The anatomy of code

## Blynk_app

1. Download and install the 'Blynk' app from your phones app store 

2. Register when prompted

## An online dashboard: io.adafruit.com
