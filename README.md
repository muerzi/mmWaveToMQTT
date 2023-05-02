Hallo zusammen!

Ich freue mich, euch heute meine Projekt zur Implementierung des mmWave Radar Sensors DFRobot SEN0395 und Wemos D1 Mini vorzustellen, die über MQTT in ioBroker eingebunden werden kann. Bisher gab es nur eine Home-Assistant-Implementierung, wie einige von euch sicher wissen.
https://community.home-assistant.io/t/mmwave-presence-detection-esphome-style/382778

Der DFRobot SEN0395 ist ein hochwertiger mmWave Radar Sensor, der zur Erfassung von Bewegungen und Objekten in Echtzeit eingesetzt werden kann. Zusammen mit einem Wemos D1 Mini, können wir die Daten des Sensors drahtlos an unseren ioBroker senden.
Zur Konfiguration kann eine einfache Weboberfläche genutzt werden. 

Als Gehäuße hab ich das gedruckt: https://www.thingiverse.com/thing:5914286
Anleitung zum Aufbau hier: https://www.youtube.com/watch?v=VEqWlOeJ2YA&t=318s

Es muss noch die Library von hier installiert werden: https://github.com/muerzi/SEN0395_Lib
