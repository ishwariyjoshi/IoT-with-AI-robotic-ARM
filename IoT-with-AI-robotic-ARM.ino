#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"
#include <Servo.h>

Servo servo;
Servo servoone;
Servo servotwo;
Servo servothree;
Servo servofour;

#define nodeone D5
#define nodetwo D6
#define nodethree D7
#define nodefour D4

#define WIFI_SSID "speechbee"//change your Wifi name
#define WIFI_PASS "speechbee"//Change your Wifi Password
#define SERIAL_BAUDRATE                 115200

fauxmoESP fauxmo;
// -----------------------------------------------------------------------------
// Wifi Setup
// -----------------------------------------------------------------------------

void wifiSetup() {

  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);

  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  // Connected!
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}
// -----------------------------------------------------------------------------
// Device Callback
// -----------------------------------------------------------------------------
void callback(uint8_t device_id, const char * device_name, bool state) {
  Serial.print("Device "); Serial.print(device_name);
  Serial.print(" state: ");
  if (state) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
  //Switching action on detection of device name

  //nodesixing action on detection of device name
  if ( (strcmp(device_name, "nodeone") == 0) )
  {
    // adjust the nodefive immediately!
    if (state)
    {
      digitalWrite(nodeone, LOW);
    }

    else
    {
      digitalWrite(nodeone, HIGH);
    }
  }

  //nodesixing action on detection of device name
  if ( (strcmp(device_name, "nodetwo") == 0) )
  {
    // adjust the nodefive immediately!
    if (state)
    {
      digitalWrite(nodetwo, LOW);
    }

    else
    {
      digitalWrite(nodetwo, HIGH);
    }
  }

  //nodesixing action on detection of device name
  if ( (strcmp(device_name, "nodethree") == 0) )
  {
    // adjust the nodefive immediately!
    if (state)
    {
      digitalWrite(nodethree, LOW);
    }

    else
    {
      digitalWrite(nodethree, HIGH);
    }
  }

  //nodesixing action on detection of device name
  if ( (strcmp(device_name, "nodefour") == 0) )
  {
    // adjust the nodefive immediately!
    if (state)
    {
      digitalWrite(nodefour, LOW);
    }

    else
    {
      digitalWrite(nodefour, HIGH);
    }
  }



  if ( (strcmp(device_name, "servo") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      servo.write (0);
    } else {
      servo.write (180);
    }
  }


  if ( (strcmp(device_name, "servoone") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      servoone.write (0);
    } else {
      servoone.write (180);
    }
  }


  if ( (strcmp(device_name, "servotwo") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      servotwo.write (0);
    } else {
      servotwo.write (180);
    }
  }


  if ( (strcmp(device_name, "servothree") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      servothree.write (0);
    } else {
      servothree.write (180);
    }
  }


  if ( (strcmp(device_name, "servofour") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      servofour.write (0);
    } else {
      servofour.write (180);
    }
  }



}

void setup() {
  //Initialize pins to Low on device start

  pinMode(nodeone, OUTPUT);
  digitalWrite(nodeone, HIGH);

  pinMode(nodetwo, OUTPUT);
  digitalWrite(nodetwo, HIGH);

  pinMode(nodethree, OUTPUT);
  digitalWrite(nodethree, HIGH);

  pinMode(nodefour, OUTPUT);
  digitalWrite(nodefour, HIGH);


  servo.attach(16);
  servoone.attach(5);
  servotwo.attach(4);
  servothree.attach(0);
  servofour.attach(15);

  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("FauxMo demo sketch");
  Serial.println("After connection, ask Alexa/Echo to 'turn <devicename> on' or 'off'");

  // Wifi
  wifiSetup();

  // Device Names for Simulated Wemo switches
  fauxmo.addDevice("nodeone");
  fauxmo.addDevice("nodetwo");
  fauxmo.addDevice("nodethree");
  fauxmo.addDevice("nodefour");

  fauxmo.addDevice("servo");
  fauxmo.addDevice("servoone");
  fauxmo.addDevice("servotwo");
  fauxmo.addDevice("servothree");
  fauxmo.addDevice("servofour");
  fauxmo.onMessage(callback);
}

void loop() {
  fauxmo.handle();
}
