//
// Created by ybsxm on 12/11/2025.
//

#include "bunny.h"
int Bunny::row() {
    return current_row;
}

int Bunny::column() {
    return current_column;
}

void Bunny::move_right() {
    current_column += 1;
}

void Bunny::move_left() {
    current_column -= 1;
}

void Bunny::set_row(int row) {
    current_row = row;
}
void Bunny::set_column(int col) {
    current_column = col;
}
void Bunny::reset() {
    current_row = -1;
    current_column = 0;
}
void Bunny::playerCheck(int row, int column) {
    if ((row == current_row - 1 && column == current_column && current_column >=0) ||
        (row == current_row + 1 && column == current_column && current_column >=0) ||
        (row == current_row && column == current_column - 1 && current_column >=0) ) {
        current_column += 3;
    }else if (row == current_row && column == current_column + 1) {
        current_column -= 3;
    }
}