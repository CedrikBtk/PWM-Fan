# PWM-Fan
Temperaturgesteuerte Lüfterdrehzahl<br>
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


### Software

```
#define DHTPIN <DHT11 Pin>

[...]

#define PIN_BLAU <PWM-Control Pin vom Lüfter>

[...]

if (temp <TEMPERATURBEREICH>){
  [...]
}
```
