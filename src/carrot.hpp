#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot {
private:
    int age = 0;
    bool watered = false;
  public:
    std::string symbol() override;
    void end_day() override;
    int get_age();
    void water();
};
