//
// Created by ybsxm on 12/11/2025.
//

#ifndef FARMING_SIMULATOR_BUNNY_H
#define FARMING_SIMULATOR_BUNNY_H


class Bunny {
private:
    int current_row = -100;
    int current_column = 0;

public:
    //Bunny();
    int row();
    int column();
    void move_right();
    void move_left();
    void set_row(int row);
    void set_column(int column);
    void reset();
    void playerCheck(int row, int column);
};


#endif //FARMING_SIMULATOR_BUNNY_H