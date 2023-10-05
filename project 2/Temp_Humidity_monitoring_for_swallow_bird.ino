#include "DHT.h"
#define DHT11PIN 5
DHT dht(DHT11PIN, DHT11);

#define BLYNK_TEMPLATE_ID "TMPLzQLt4Jre"
#define BLYNK_DEVICE_NAME "DHT11 Monitoring"
#define BLYNK_AUTH_TOKEN "DHI47vZsrzQqCsd1hiPMGN12y_hCqY_l"
#include <BlynkSimpleEsp32.h>
//masuk ke jaringan wifi

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Nira";
char pass[] = "satudua345";

void setup() {
  Serial.begin(115200);
/* Start the DHT11 Sensor */
  dht.begin();
 //blynk
  Blynk.begin(auth, ssid, pass);

}

void loop() {
 float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);
  delay(1000);
Blynk.virtualWrite(V1, temp);
Blynk.virtualWrite(V2, humi);

  Blynk.run();
}
