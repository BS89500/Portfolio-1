#pragma once

#include <string>

class Plot {
    protected:

  public:
    virtual std::string symbol() = 0;
    virtual void end_day() = 0;
};
