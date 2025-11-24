#include <string>

#include "brussel_sprouts.h"

std::string BrusselSprouts::symbol() {
    if (age == 0) {
        return "~";
    } else if (age == 5){
        return "o";
    } else if (age == 15) {
        return "O";
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

