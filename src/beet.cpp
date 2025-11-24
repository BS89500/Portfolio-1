#include <string>
#include "beet.h"

std::string Beet::symbol() {
    if (age >= 0 && age < 2) {
        return "~";
    } else if (age >= 2 && age <7){
        return "b";
    }else if (age >= 7){
        return "B";
    }
}
void Beet::end_day(){
    if (watered == true) {
        age += 2;
    }
    else{
        age += 1;
    }
}
void Beet:: water() {
    watered = true;
}

int Beet::get_age() {
    return age;
}