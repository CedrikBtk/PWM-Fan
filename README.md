# PWM-Fan
Temperaturgesteuerte Lüftersteuerung - Lüfterdrehzahl mit Hilfe eines Arduinos.<br>
Zum Beispiel für HiFi-Verstärker ohne aktive Kühlung. So kann die Drehzahl des Lüfters je nach Belastung und Hitzeentwicklung automatisch angepasst werden.

## Benötigte Hardware
1x Arduino Nano
<br>
1x DHT11
<br>
1x 4-pin PWM-Lüfter (PC-Lüfter mit 4-Pin Anschluss)
<br>
1x Wiederstand 10kOhm
<br>
<h5>~ 30€ (ohne Lüfter unter 10€)</h5>


## Einrichtung

### Hardware

![alt text](https://user-images.githubusercontent.com/42981810/113414949-73c08c00-93be-11eb-847f-8e733497ba36.png)


### Software

```
#define DHTPIN <DHT11 Pin>

[...]

#define PIN_BLAU <PWM-Control Pin vom Lüfter>

[...]

if (temp <TEMPERATURBEREICH>){
  [...]
  1. Stufe:   dauer_low = 9;  dauer_high = 1;
  2. Stufe:   dauer_low = 8;  dauer_high = 2;
  3. Stufe:   dauer_low = 7;  dauer_high = 3;
  [...]
  10. Stufe (aus):  dauer_low = 10; dauer_high = 0;
}
```
