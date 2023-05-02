#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include "DFRobot_mmWave_Radar.h"
#include <PubSubClient.h>
#include <SoftwareSerial.h>

/********************************************
          USER DEFINED VARIABLES HERE
********************************************/
//Wifi
const char* ssid = 		"yourSSID";
const char* password = 	"yourPassword";

//SEN0395 Sensor
#define SEN0395_RX  D1
#define SEN0395_TX  D2
#define GPIORADAR   D0

//Default Values for Sensor
int sensitivity = 5;
int range = 2;
int delayTime = 3;
bool led = true;

//MQTT
const char* mqtt_server = 	  "yourMQTTServer";   				//change IP here
String clientId =             "mmWaveBuero";					//Client Name
const char* topic_praesenz =  "mmWave/Buero/praesenz";			//Topic1
const char* topic_IP =        "mmWave/Buero/IP";				//Topic2
const char* topic_name =      "mmWave/Buero/Name";				//Topic3

SoftwareSerial mySerial(SEN0395_RX, SEN0395_TX);  //RX,TX
DFRobot_mmWave_Radar sensor(&mySerial);

WiFiClient espClient;
PubSubClient client(espClient);

ESP8266WebServer server(80);  // create web server on port 80

void handleButton() {  // function to handle button press
  sensitivity = server.arg("sensitivity").toInt();
  Serial.print("Sensitivity: ");
  Serial.println(sensitivity);
  range = server.arg("range").toInt();
  Serial.print("Range: ");
  Serial.println(range);
  delayTime = server.arg("delayTime").toInt();
  Serial.print("Delay: ");
  Serial.println(delayTime);
  led = server.arg("led") == "on";
  Serial.print("LED: ");
  Serial.println(led);

  // store values in EEPROM
  EEPROM.begin(512);
  EEPROM.put(0, sensitivity);
  EEPROM.put(4, range);
  EEPROM.put(8, delayTime);
  EEPROM.put(12, led);
  EEPROM.commit();
  EEPROM.end();

  sensor.DetRangeCfg(0, range);
  sensor.OutputLatency(0, delayTime);
  sensor.setSensitivity(sensitivity);

  if (led == true) {
    sensor.enableLED();
  } else {
    sensor.disableLED();
  }

  Serial.println("Sensor configured");

  server.sendHeader("Location", "/");
  server.send(302);
}

void handleRoot() {  // function to handle root URL
  String html = "<form action='/button' method='GET'>\n";
  html += "Sensitivity: <input type='text' name='sensitivity' value='" + String(sensitivity) + "'><br>\n";
  html += "Range: <input type='text' name='range' value='" + String(range) + "'><br>\n";
  html += "Delay: <input type='text' name='delayTime' value='" + String(delayTime) + "'><br>\n";
  html += "LED: <input type='checkbox' name='led' value='on'";
  if (led) {
    html += " checked";
  }
  html += "><br>\n";
  html += "<input type='submit' value='Save'>\n";
  html += "</form>\n";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(GPIORADAR, INPUT);

  // load values from EEPROM
  EEPROM.begin(512);
  EEPROM.get(0, sensitivity);
  EEPROM.get(4, range);
  EEPROM.get(8, delayTime);
  EEPROM.get(12, led);
  EEPROM.end();

  WiFi.begin(ssid, password);  // connect to WiFi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  mySerial.begin(115200);
  //initial config Sensor with Values from EEPROM
  sensor.DetRangeCfg(0, range);
  sensor.OutputLatency(0, delayTime);
  sensor.setSensitivity(sensitivity);

  if (led == true) {
    sensor.enableLED();
  } else {
    sensor.disableLED();
  }

  Serial.println("Sensor configured");
  Serial.println("Program Start");

  server.on("/", handleRoot);          // handle root URL
  server.on("/button", handleButton);  // handle button press
  server.begin();                      // start server

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) { reconnect(); }
  client.loop();

  server.handleClient();  // handle incoming client requests
  int radarValue = digitalRead(GPIORADAR);
  if (radarValue == HIGH) {
    Serial.println("Person detected");
    client.publish(topic_praesenz, "1");
  } else {
    Serial.println("No person detected");
    client.publish(topic_praesenz, "0");
  }
  delay(500);  // wait half a second before checking again
}

void callback(char* topic, byte* payload, unsigned int length) {
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientId.c_str())) {  // convert clientId to C string
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(topic_IP, WiFi.localIP().toString().c_str());  //Publish our IP
      client.publish(topic_name, clientId.c_str());                 //Publish our Name
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}