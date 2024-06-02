#include<iostream>
#include"global.hpp"
#include"input.hpp"

using std::cout;
using std::cin;
using std::cerr;

int length;
int board_size;
bool ishost;
unsigned short port;
bool repeat = true;
void ishost_check() {

char charishost;
while (repeat) {
  cout << "will you be host or guest of this game?\n" << "(h/g): ";
  cin >> charishost;

  repeat = false;

  switch(charishost) {
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
    if(cin.fail()) {
        cerr << "integer please\n";
        cin.clear();
        cin.ignore(256,'\n');
        } else {
            if(board_size > 0) {
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
        if(cin.fail()) {
            cerr << "integer please\n";
            cin.clear();
            cin.ignore(256,'\n');
        } else {
            if(length > 0) {
                if(length > board_size) {
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

void port_check() {
    repeat = true;

    while (repeat) {
        cout << "\nplease enter port you want to use: ";

        cin >> port;
        if(cin.fail()) {
            cerr << "integer please (range: 1-65535)\n";
            cin.clear();
            cin.ignore(256,'\n');
            } else {
                if(port > 0) {
                    repeat = false;
                } else {
                    cerr << "positive integer please\n";
                }
            }
        }
}

void ip_check() {
    repeat = true;
    std::string serverIp_temp;

    while(repeat) {
        cout << "enter host ip or hostname: ";
        cin >> serverIp_temp;
        if(serverIp_temp == "") {
            cerr << "enter something!\n";
        } else {

            repeat = false;
            const char *serverIp = serverIp_temp.c_str();
        }
    }
}