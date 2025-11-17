#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
  if (age == 0) {
    return "v";
  } else if (age == 1){
    return "V";
  }
  return "W";
}
void Carrot::end_day() {
  if (watered == true) {
    age += 2;
  }else
  {
    age += 1;
  }
}
void Carrot:: water() {
  watered = true;
}

int Carrot::get_age() {
  return age;
}

