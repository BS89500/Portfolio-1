#include <string>
#include "beet.h"

std::string Beet::symbol() {
    if (age == 0) {
        return "~";
    } else if (age == 2){
        return "b";
    }else if (age == 7){
        return "B";
    }
    return "W";
}
void Beet::end_day(){
    if (watered == true) {
        age += 1;
    }
}
void Beet:: water() {
    watered = true;
}

int Beet::get_age() {
    return age;
}