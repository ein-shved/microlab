#include <PT2322.h>
#include <MicroLab.h>
#include <Wire.h>

AH500 ah500;
void setup () {
#if 0
    DDRD =  B11111111;
    PORTD = B00000000;
    Serial.begin(9600);
    Wire.begin();
    Wire.setClock(10000);


    Wire.beginTransmission(PT2322);
    Wire.write(0xff);
    byte res = Wire.endTransmission();
    if (res) {
        Serial.print("Reset failure: ");
        Serial.println(res);
    } else {
        Serial.println("Reset succeed");
    }

    Wire.beginTransmission(PT2322);
    Wire.write(B11000111);
    res = Wire.endTransmission();
    if (res) {
        Serial.print("Input channel selection failure: ");
        Serial.println(res);
    } else {
        Serial.println("Input channel selection succeed");
    }
    
    Wire.beginTransmission(PT2322);
    Wire.write(B11100100);
    Wire.write(B11010010);
    res = Wire.endTransmission();
    if (res) {
        Serial.print("Volume control failure: ");
        Serial.println(res);
    } else {
        Serial.println("Volume control succeed");
    }
#endif
    Serial.begin(9600);
    Wire.begin();
    Serial.println("Initializing A-H500");
    if (ah500.init()) {
        Serial.println("Failed to initialize A-H500");
        return;
    } else {
        Serial.println("A-H500 initialization complete");
    }

    ah500.standBy(false);
    ah500.select6ch();
    ah500.muteOff();
    ah500.masterVolume(45);

}

void loop() {
 
}
