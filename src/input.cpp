#include <string.h>
#include <iostream>
#include <string>
#include<array>
#include "global.hpp"
#include "input.hpp"
#include "net.hpp"

using std::cout;
using std::cin;
using std::cerr;

int length;
int board_size;
int points_req;
bool ishost;
unsigned short port;
std::string serverIp_str;
bool repeat = true;
void ishost_check() {

    char charishost;
    while (repeat) {
        cout << "will you be host or guest of this game?\n"
             << "(h/g): ";
        cin >> charishost;

        repeat = false;

        switch (charishost) {
        case 'h':
            ishost = true;
            break;
        case 'g':
            ishost = false;
            break;
        default:
            repeat = true;
        }
    }
}
void board_size_check() {
    repeat = true;

    while (repeat) {
        cout << "\nplease enter board size(for example: 3 for 3x3): ";

        cin >> board_size;
        if (cin.fail()) {
            cerr << "integer please\n";
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            if (board_size > 0) {
                repeat = false;
            } else {
                cerr << "positive integer please\n";
            }
        }
    }
}

void length_check() {
    repeat = true;

    while (repeat) {
        cout << "\nplease enter needed length(e.g. how many symbols need to be next to each other to get point): ";

        cin >> length;
        if (cin.fail()) {
            cerr << "integer please\n";
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            if (length > 0) {
                if (length > board_size) {
                    cerr << "length cannot be biger than board size";
                } else {
                    repeat = false;
                }
            } else {
                cerr << "positive integer please\n";
            }
        }
    }
}

void points_requied() {
    repeat = true;

    while (repeat) {
        cout << "\nhow many points will be requied to beat game: ";

        cin >> points_req;
        if (cin.fail()) {
            cerr << "integer please\n";
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            if (points_req > 0) {
                if (points_req * length < board_size * board_size) {
                    repeat = false;
                } else {
                    cerr << "too large number max number is " << (((board_size * board_size) / length) - 1) << "\n";
                }
            } else {
                cerr << "positive integer please\n";
            }
        }
    }
}


void port_check() {
    repeat = true;

    while (repeat) {
        cout << "\nplease enter port you want to use: ";

        cin >> port;
        if (cin.fail()) {
            cerr << "integer please (range: 1-65535)\n";
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            if (port > 0) {
                repeat = false;
            } else {
                cerr << "positive integer please\n";
            }
        }
    }
}

void ip_check() {
    repeat = true;

    while (repeat) {
        cout << "enter host ip or hostname: ";
        cin >> serverIp_str;
        if (serverIp_str == "") {
            cerr << "enter something!\n";
        } else {

            repeat = false;
        }
    }
}

std::array<int,2> choise_check() {
    int x_cord;
    int y_cord;
    char sure;
    while (true) {

        cout << "\nchoose x(e.g. horisontal) cordinates of you target square:";
        cin >> x_cord;
        if (x_cord < board_size && x_cord >= 0) {
            break;
        }

        cout << "\nchoose y(e.g. vertical) cordinates of you target square:";
        cin >> y_cord;
        if (y_cord < board_size && y_cord >= 0) {
            break;
        }

        cout << "\nare you sure [Y/n]";
        std::cin.get(sure);
        if (sure != 'n') {
            break;
        }
    }
    std::array<int,2> loc={x_cord,y_cord};
    return loc;
}