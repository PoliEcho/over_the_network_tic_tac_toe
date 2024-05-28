#include<iostream>
#include"global.hpp"
#include"input.hpp"

using std::cout;
using std::cin;

int board_size;
bool ishost;
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
      cout << "integer please\n";
      cin.clear();
      cin.ignore(256,'\n');
    } else {
        if(board_size > 0) {
          repeat = false;
    } else {
        cout << "positive integer please\n";
    }


  
}
}
}