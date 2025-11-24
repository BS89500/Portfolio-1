#include <string>

#include "spinach.h"

std::string Spinach::symbol() {
    if (age >= 0 && age < 2) {
        return "~";
    } else if (age >= 2 && age < 5){
        return "s";
    }
    else if (age >= 5){
        return "S";
    }
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

