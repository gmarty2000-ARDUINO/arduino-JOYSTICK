#include "Joystick.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin numbers of the Joystick and set them in OUTPUT mode */
Joystick::Joystick(int pinX, int pinY, int pinZ) {
    this->pinX = pinX;
    this->pinY = pinY;
    this->pinZ = pinZ;

    pinMode(pinZ, INPUT);

    digitalWrite(this->pinZ, HIGH);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It prints the position of the X-Axis */
void Joystick::printX(String text, int begin, int end) {
    int rawValue = analogRead(this->pinX);
    int value = map(rawValue, 0, 1023, begin, end);

    Serial.print(text);
    Serial.print(value);
}

/* Method - It prints the position of the Y-Axis */
void Joystick::printY(String text, int begin, int end) {
    int rawValue = analogRead(this->pinY);
    int value = map(rawValue, 0, 1023, begin, end);

    Serial.print(text);
    Serial.print(value);
}

/* Method - It prints the state of the Z-Axis */
void Joystick::printZ(String text) {
    bool value = digitalRead(this->pinZ);

    Serial.print(text);
    Serial.print(value? "true" : "false");
}

/* ------------------------------ OTHER FUNCTIONS ------------------------------ */

/* Method - It prints the informations of the Joystick */
void Joystick::print(String text1, String text2, String text3, int begin, int end) {
    this->printX(text1, begin, end);
    this->printY(text2, begin, end);
    this->printZ(text3);
}

/* Method - It returns the Joystick informations */
String Joystick::toString() {
    String ret = String("Joystick: {");
    ret.concat("pinX=");
    ret.concat(this->pinX);
    ret.concat(", pinY=");
    ret.concat(this->pinY);
    ret.concat(", pinZ=");
    ret.concat(this->pinZ);
    ret.concat("}");
    
    return ret;
}
