#include <string>
x`
#include "beet.h"

std::string Beet::symbol() {
    if (age == 0) {
        return "v";
    } else if (age == 1){
        return "V";
    }
    return "W";
}
void Beet::end_day() {
    if (watered == true) {
        age += 2;
    }else
    {
        age += 1;
    }
}
void Beet:: water() {
    watered = true;
}

int Beet::get_age() {
    return age;
}

