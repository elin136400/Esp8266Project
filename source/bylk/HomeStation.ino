            #include <ESP8266WiFi.h>
            #include <BlynkSimpleEsp8266.h>
                //#include <SimpleTimer.h>
                // You should get Auth Token in the Blynk App.
                // Go to the Project Settings (nut icon).
              char auth[] = "632f99110911484c8a04af6b0b257935";
              const int btnPin = 5;
              
               // SimpleTimer timer;
            void notifyOnButtonPress()
            {
              // Invert state, since button is "Active LOW"
              int isButtonPressed = !digitalRead(5);
              if (isButtonPressed) {
                Serial.println("Button is pressed.");

                Blynk.notify("Yaaay... button is pressed!");
              }
            }

            void setup()
            {
              Serial.begin(115200);
              Blynk.begin(auth, "121", "nicaicai");
              
              // Attach pin 2 interrupt to our handler
              pinMode(btnPin, INPUT_PULLUP);

              while (Blynk.connect() == false) {
                // Wait until connected
              }
            pinMode(5, INPUT_PULLUP);
              // Attach pin 2 interrupt to our handler
              attachInterrupt(digitalPinToInterrupt(5), notifyOnButtonPress, CHANGE);

            }

            // V3 LED Widget represents the physical button state


            BLYNK_WRITE(V5)
            {
              // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
              // this method will be triggered every day
              // until you remove widget or stop project or
              // clean stop/start fields of widget
              Serial.print("Got a value: ");
              Serial.println(param.asStr());
            }
            void loop()
            {
             Blynk.run();


            }
