#include <iostream>
#include "gameplay.hpp"
#include "global.hpp"
#include "color.hpp"
using std::cout;
using std::cin;
using std::cerr;

int points_my;
int points_en;

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

void print_gameinfo() {
    cout << "\npoint info:\nyou: " << BLUE << points_my << RESET << "\nenemy: " << RED << points_en << RESET << "\n";
}

void check_if_point(const std::vector<std::vector<char>> &board) {
    points_my = 0;
    points_en  = 0;
    char char_we_are_checking;

    //flag to set if brake; is called
    bool broken = false;

    //initializes pointer to nowhere
    int *points_ptr = nullptr;

        for (int p = 0; p < 2; p++){
    switch (p) {
    case 0:
            char_we_are_checking = char_my;
        points_ptr = &points_my;
            break;

        case 1:
        char_we_are_checking = char_en;
            points_ptr = &points_en;
        break;

        default:
            cerr << "\nunexpected iteration number(" << RED << p << RESET << ") at function: check_if_point\nexiting...\n";
                    exit(3);
            }

            //horizontal check
            for (int i = 0; i < board_size; i++) {
                for (int j = 0; j < board_size-(length-1);  j++) {
                    for (int k = 0; k < length; k++) {
                        if(board[i][j+k] != char_we_are_checking) {
                            broken = true;
                            break;
                        }
                        if(!broken){
                            ++*points_ptr;
                        }
                }
                }
                    }

            //vertical check
            for (int i = 0; i < board_size; i++) {
                    for (int j = 0; j < board_size-(length-1);  j++) {
                for (int k = 0; k < length; k++) {
                        if(board[j+k][i] != char_we_are_checking) {
                    broken = true;
                            break;
                    }
                        if(!broken){
                    ++*points_ptr;
                            }
                        }
                }}

                    for(int i = 0; i < (board_size*2-1)-((length-1)*2); i++) {
                        
            }
                }}