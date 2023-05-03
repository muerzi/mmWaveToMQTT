Hello everyone!

Today, I'm excited to present my project for implementing the mmWave Radar Sensor DFRobot SEN0395 with a Wemos D1 Mini, which can be integrated into ioBroker via MQTT. Until now, there has only been a Home Assistant implementation, as some of you may know. 
https://community.home-assistant.io/t/mmwave-presence-detection-esphome-style/382778

The DFRobot SEN0395 is a high-quality mmWave radar sensor that can be used to detect movements and objects in real-time. Together with a Wemos D1 Mini, we can wirelessly send the sensor's data to our ioBroker. A simple web interface can be used for configuration.

I printed the housing from here: https://www.thingiverse.com/thing:5914286 
Instructions for assembly can be found here: https://www.youtube.com/watch?v=VEqWlOeJ2YA&t=318s

You still need to install the library from here: https://github.com/muerzi/SEN0395_Lib

After loading the code the first time, make sure to adjust the values in the webpage.
You can see the IP on MQTT Objects or on your MQTT-Server


![webui](https://user-images.githubusercontent.com/4198159/235928922-823ddf83-8f1e-459a-bc8f-def098292541.png)

Sensitivity: Value 0-9 (0 low sensitivity - 9 high sensitivity)

Range: Range in meters

Delay: How long a presence should still be reported after no one is in the sensor's range. A value of 3 seconds has been found to work well.

LED: Whether the onboard LED of the sensor should blink.

![iobroker](https://user-images.githubusercontent.com/4198159/235928891-6e081a62-8aa8-4c9f-b7de-dde7bc7adc04.png)


It's now possible to update the device via OTA





Hallo zusammen!

Ich freue mich, euch heute meine Projekt zur Implementierung des mmWave Radar Sensors DFRobot SEN0395 und Wemos D1 Mini vorzustellen, die über MQTT in ioBroker eingebunden werden kann. Bisher gab es nur eine Home-Assistant-Implementierung, wie einige von euch sicher wissen.
https://community.home-assistant.io/t/mmwave-presence-detection-esphome-style/382778

Der DFRobot SEN0395 ist ein hochwertiger mmWave Radar Sensor, der zur Erfassung von Bewegungen und Objekten in Echtzeit eingesetzt werden kann. Zusammen mit einem Wemos D1 Mini, können wir die Daten des Sensors drahtlos an unseren ioBroker senden.
Zur Konfiguration kann eine einfache Weboberfläche genutzt werden. 

Als Gehäuße hab ich das gedruckt: https://www.thingiverse.com/thing:5914286
Anleitung zum Aufbau hier: https://www.youtube.com/watch?v=VEqWlOeJ2YA&t=318s

Es muss noch die Library von hier installiert werden: https://github.com/muerzi/SEN0395_Lib

Nachdem dem ersten Upload auf den Mikrocontroller, konfiguriere die Werte im Webinterface.
DIe IP findest du in den Objekten des MQTT Adapters bzw auf deinem MQTT Server

![webui](https://user-images.githubusercontent.com/4198159/235928922-823ddf83-8f1e-459a-bc8f-def098292541.png)

Sensitivity: Wert 0-9 (0 wenig sensibel - 9 sehr sensibel)

Range: Reichweite in meter

Delay: Verzögerung wie lange noch eine Präsenz gemeldet werden soll, nachdem keine Person mehr im Bereich des Sensor ist. Hier hat sich ein Wert von 3[sekunden] als gut erwiesen.

LED: ob die onboard LED des Sensors blinken soll


![iobroker](https://user-images.githubusercontent.com/4198159/235928891-6e081a62-8aa8-4c9f-b7de-dde7bc7adc04.png)

Es ist jetzt möglich, update über OTA zu installieren
