Hello everyone!

Today, I'm excited to present my project for implementing the mmWave Radar Sensor DFRobot SEN0395 with a Wemos D1 Mini, which can be integrated into ioBroker via MQTT. Until now, there has only been a Home Assistant implementation, as some of you may know. 
https://community.home-assistant.io/t/mmwave-presence-detection-esphome-style/382778

The DFRobot SEN0395 is a high-quality mmWave radar sensor that can be used to detect movements and objects in real-time. Together with a Wemos D1 Mini, we can wirelessly send the sensor's data to our ioBroker. A simple web interface can be used for configuration.

I printed the housing from here: https://www.thingiverse.com/thing:5914286 
Instructions for assembly can be found here: https://www.youtube.com/watch?v=VEqWlOeJ2YA&t=318s

You still need to install the library from here: https://github.com/muerzi/SEN0395_Lib

After loading the code the first time, make sure to adjust the values in the webpage.

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

Es ist jetzt möglich, update über OTA zu installieren
