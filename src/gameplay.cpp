#include <iostream>
#include "gameplay.hpp"
#include "global.hpp"
using std::cout;
using std::cin;
using std::cerr;

void printBoard(const std::vector<std::vector<char>>& board) {
    cout << "\n ┌";
    for (int i = 0; i < board_size; i++) {
        if(i != board_size-1) {

            cout << i << "┬";
        } else {
            cout << i << "┐";
        }
        }
    cout << "\n";

    for (int y = 0; y < board_size; y++) {
        cout << y << "│";

        for (int x = 0; x < board_size; x++) {
            cout << board[x][y] << "│";
        }
        cout << "\n";




    }
    cout << " └";
    for (int i = 0; i < board_size; i++) {
    if(i != board_size-1) {

        cout << "─┴";
    } else {
        cout << "─┘";
    }
    }
}