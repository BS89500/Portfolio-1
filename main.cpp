#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"
#include "src/lettuce.h"
#include "src/spinach.h"
#include "src/brussel_sprouts.h"
#include "src/beet.h"
#include "src/bunny.h"


//test
int main() {
  Player player;
  Bunny bunny;
  Farm farm(8, 8, &player, &bunny);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;
  int dayCounter = 1;
  std::cout << "Press Q to exit the game." << std::endl;
  std::cout << "Use W,A,S,D to move your character around" << std::endl;
  std::cout << "Press 'C' to plant a carrot." << std::endl;
  std::cout << "Press 'X' to plant a brussel sprout." << std::endl;
  std::cout << "Press 'B' to plant a beet." << std::endl;
  std::cout << "Press 'N' to plant lettuce." << std::endl;
  std::cout << "Press 'M' to plant spinach." << std::endl;
  std::cout << "Press 'V' to harvest a grown plant." << std::endl;
  std::cout << "Press 'E' to pass the day." << std::endl;
  std::cout << "Press 'Z' to water plants." << std::endl;
  std::cout << "Days Passed: " << dayCounter << std::endl ;

  while(game_in_progress) {
    //ansi_clear(); broken
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "d" && player.column() < farm.number_of_columns() - 1) {
      //bunny.playerCheck(player.row(), player.column());
      player.move_right();
      bunny.playerCheck(player.row(), player.column());

    } else if(player_input == "s" && player.row() < farm.number_of_rows() - 1) {
      //bunny.playerCheck(player.row(), player.column());
      player.move_down();
      bunny.playerCheck(player.row(), player.column());
    } else if(player_input == "w" && player.row() > 0) {
      //bunny.playerCheck(player.row(), player.column());
      player.move_up();
      bunny.playerCheck(player.row(), player.column());

    } else if(player_input == "a" && player.column() > 0) {
      //bunny.playerCheck(player.row(), player.column());
      player.move_left();
      bunny.playerCheck(player.row(), player.column());
    }

    else if(player_input == "c") {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    } else if(player_input == "b") {
      Beet *beet = new Beet();
      farm.plant(player.row(), player.column(), beet);
    } else if(player_input == "n") {
      Lettuce *lettuce = new Lettuce();
      farm.plant(player.row(), player.column(), lettuce);
    } else if(player_input == "m") {
      Spinach *spinach = new Spinach();
      farm.plant(player.row(), player.column(), spinach);
    } else if(player_input == "x") {
      BrusselSprouts *brussel_sprouts = new BrusselSprouts();
      farm.plant(player.row(), player.column(), brussel_sprouts);
    } else if (player_input == "v") {
        if (farm.isHarvestable(player.row(), player.column())) {
          farm.harvest(player.row(), player.column());
        }
    } else if(player_input == "e") {
      farm.end_day();
      dayCounter++;
      std::cout << "Days Passed: " << dayCounter << std::endl ;
    } else if (player_input == "z") {
      farm.water(player.row(), player.column());
    }
  }
}