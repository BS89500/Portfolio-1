#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"


//test
int main() {
  Player player;
  Farm farm(8, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;
  int dayCounter = 1;
  std::cout << "Press Q to exit the game." << std::endl;
  std::cout << "Use W,A,S,D to move your character around" << std::endl;
  std::cout << "Press 'C' to plant a carrot." << std::endl;
  std::cout << "Days Passed: " << dayCounter << std::endl ;
  while(game_in_progress) {
    //ansi_clear(); broken
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "d" && player.column() < farm.number_of_columns() - 1) {
      player.move_right();
    } else if(player_input == "s" && player.row() < farm.number_of_rows() - 1) {
      player.move_down();
    } else if(player_input == "w" && player.row() > 0) {
      player.move_up();
    } else if(player_input == "a" && player.column() > 0) {
      player.move_left();
    } else if(player_input == "c") {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    } else if (player_input == "v") {
      if (farm.isHarvestable(player.row(), player.column())) {
        farm.harvest(player.row(), player.column());
      }
    } else if(player_input == "e") {
      farm.end_day();
      dayCounter++;
      std::cout << "Days Passed: " << dayCounter << std::endl ;
    }
  }
}
