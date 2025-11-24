#include <string>

#include "lettuce.h"

std::string Lettuce::symbol() {
    if (age >= 0 && age <2) {
        return "~";
    } else if (age >= 2 && age < 4) {
        return "l";
    }
    else if (age >= 4){
        return "L";
    }
}
void Lettuce::end_day() {
    if (watered == true) {
        age += 2;
    }else
    {
        age += 1;
    }
}
void Lettuce:: water() {
    watered = true;
}

int Lettuce::get_age() {
    return age;
}