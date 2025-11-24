#include <string>

#include "spinach.h"

std::string Spinach::symbol() {
    if (age == 0) {
        return "~";
    } else if (age == 2){
        return "s";
    }
    else if (age == 7){
        return "S";
    }
    return "W";
}
void Spinach::end_day() {
    if (watered == true) {
        age += 2;
    } else{
        age += 1;
    }
}
void Spinach:: water() {
    watered = true;
}

int Spinach::get_age() {
    return age;
}

