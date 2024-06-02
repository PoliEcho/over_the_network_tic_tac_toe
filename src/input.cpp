#include<iostream>
#include"global.hpp"
#include"input.hpp"

using std::cout;
using std::cin;
using std::cerr;

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

void port_check() {
    repeat = true;

    while (repeat) {
        cout << "\nplease enter port you want to host on: ";

        cin >> port;
        if(cin.fail()) {
            cerr << "integer please (range: 1-65535)\n";
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

void ip_check() {
    repeat = true;
    char *serverIp;
    while(repeat) {
        cout << "enter host ip or hostname: ";
        cin >> serverIp;
        if(serverIp[0] == '\0') {
            cerr << "enter something!\n";
        } else {
            repeat = false;
        }
    }
}