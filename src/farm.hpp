#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"
#include "bunny.h"
class Farm {
  private:
    int rows;
    int columns;
    Player *player;
    Bunny *bunny = nullptr;
    std::vector<std::vector<Plot *>> plots;
    bool bunnySpawned = false;
  public:
    Farm(int rows, int columns, Player *player);
    Farm(int rows, int columns, Player *player, Bunny *bunny);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void plant(int row, int column, Plot *plot);
    void harvest(int row, int column);
    bool isHarvestable(int row, int column);
    void end_day();
    void water(int row, int column);
    void spawnBunnies();
    void bunnyMove(int move);
};
