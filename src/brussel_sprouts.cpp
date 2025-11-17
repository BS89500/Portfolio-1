#include <string>

#include "brussel_sprouts.h"

std::string BrusselSprouts::symbol() {
    if (age == 0) {
        return "v";
    } else if (age == 1){
        return "V";
    }
    return "W";
}
void BrusselSprouts::end_day() {
    if (watered == true) {
        age += 2;
    }else
    {
        age += 1;
    }
}
void BrusselSprouts:: water() {
    watered = true;
}

int BrusselSprouts::get_age() {
    return age;
}

