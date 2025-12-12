#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player), bunny(nullptr) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
}

Farm::Farm(int rows, int columns, Player *player, Bunny *bunny_): rows(rows), columns(columns), player(player), bunny(bunny_){
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
}


int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}

std::string Farm::get_symbol(int row, int column) {
  if (bunny != nullptr && bunny->row() == row && bunny->column() == column) {
    return "Y";
  }
  if(player->row() == row && player->column() == column) {
    return "@";
  }
  else {
    return plots.at(row).at(column)->symbol();
  }

}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  if (current_plot->symbol() == ".") {
    plots.at(row).at(column) = plot;
    delete current_plot;
  }

}

void Farm::harvest(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  plots.at(row).at(column) = new Soil();
  delete current_plot;
}
bool Farm::isHarvestable(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  if (current_plot->symbol() == "V" || current_plot->symbol() == "W" || current_plot->symbol() == "B"
   || current_plot->symbol() == "O" || current_plot->symbol() == "L" || current_plot->symbol() == "S") {
    return true;
  }
  return false;
}

void Farm::end_day() {
  for (int i = 0; i < rows; i++) {
    for (int j =0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
  if (bunny != nullptr) {
    int random = rand() % 10 + 1;
    if (bunnySpawned == true) {
      if (bunny->column() + 1 == player->column() && bunny->row() == player->row()){
        bunnyMove(-3);
      }else if ((bunny->column() + 1 == player->column() && bunny->row() + 1 == player->row()) ||
        (bunny->column() + 1 == player->column() && bunny->row() - 1 == player->row())){
        bunnyMove(3);
      }else{
        bunnyMove(1);
      }
    }
    if (random > 5 && bunnySpawned == false) {
      spawnBunnies();
    }
  }
}

void Farm::spawnBunnies() {
  if (bunny != nullptr) {
    int randRow = rand() % rows;
    bunnySpawned = true;
    if (bunny->column() == player->column() && player->row() == randRow) {
      bunny->set_row(randRow - 1);
    }
    else {
      bunny->set_row(randRow);
    }
    harvest(bunny->row(), bunny->column());

  }

}

void Farm::bunnyMove(int move) {
  if (bunny != nullptr) {
    for (int i = 0; i < abs(move); i++) {
      if (move > 0) {
        bunny->move_right();
      }
      else {
        bunny->move_left();
      }
    }
    if (bunny->column() >= 0 && bunny->column() <= number_of_columns() - 1) {
      harvest(bunny->row(), bunny->column());
    }
    if (bunny->column() > number_of_columns() - 1 || bunny->column() < 0) {
      bunnySpawned = false;
      bunny->reset();
    }
  }

}

void Farm::water(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  current_plot->water();
}