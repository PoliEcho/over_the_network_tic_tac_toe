#include <cstddef>
#include<iostream>
#include"global.hpp"
#include"net.hpp"
#include"input.hpp"


using std::cout;
using std::cin;
using std::cerr;

int main() {

    cout << R"( ___       __   _______   ___       ________  ________  _____ ______   _______           _________  ________
|\  \     |\  \|\  ___ \ |\  \     |\   ____\|\   __  \|\   _ \  _   \|\  ___ \         |\___   ___\\   __  \                                                              
\ \  \    \ \  \ \   __/|\ \  \    \ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|        \|___ \  \_\ \  \|\  \                                                             
 \ \  \  __\ \  \ \  \_|/_\ \  \    \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \_|/__           \ \  \ \ \  \\\  \                                                            
  \ \  \|\__\_\  \ \  \_|\ \ \  \____\ \  \____\ \  \\\  \ \  \    \ \  \ \  \_|\ \           \ \  \ \ \  \\\  \                                                           
   \ \____________\ \_______\ \_______\ \_______\ \_______\ \__\    \ \__\ \_______\           \ \__\ \ \_______\                                                          
    \|____________|\|_______|\|_______|\|_______|\|_______|\|__|     \|__|\|_______|            \|__|  \|_______|                                                          



 ________  ___      ___ _______   ________          _________  ___  ___  _______           ________   _______  _________  ___       __   ________  ________  ___  __       
|\   __  \|\  \    /  /|\  ___ \ |\   __  \        |\___   ___\\  \|\  \|\  ___ \         |\   ___  \|\  ___ \|\___   ___\\  \     |\  \|\   __  \|\   __  \|\  \|\  \     
\ \  \|\  \ \  \  /  / | \   __/|\ \  \|\  \       \|___ \  \_\ \  \\\  \ \   __/|        \ \  \\ \  \ \   __/\|___ \  \_\ \  \    \ \  \ \  \|\  \ \  \|\  \ \  \/  /|_   
 \ \  \\\  \ \  \/  / / \ \  \_|/_\ \   _  _\           \ \  \ \ \   __  \ \  \_|/__       \ \  \\ \  \ \  \_|/__  \ \  \ \ \  \  __\ \  \ \  \\\  \ \   _  _\ \   ___  \  
  \ \  \\\  \ \    / /   \ \  \_|\ \ \  \\  \|           \ \  \ \ \  \ \  \ \  \_|\ \       \ \  \\ \  \ \  \_|\ \  \ \  \ \ \  \|\__\_\  \ \  \\\  \ \  \\  \\ \  \\ \  \ 
   \ \_______\ \__/ /     \ \_______\ \__\\ _\            \ \__\ \ \__\ \__\ \_______\       \ \__\\ \__\ \_______\  \ \__\ \ \____________\ \_______\ \__\\ _\\ \__\\ \__\
    \|_______|\|__|/       \|_______|\|__|\|__|            \|__|  \|__|\|__|\|_______|        \|__| \|__|\|_______|   \|__|  \|____________|\|_______|\|__|\|__|\|__| \|__|



 _________  ___  ________               _________  ________  ________               _________  ________  _______                                                           
|\___   ___\\  \|\   ____\             |\___   ___\\   __  \|\   ____\             |\___   ___\\   __  \|\  ___ \                                                          
\|___ \  \_\ \  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \   __/|                                                         
     \ \  \ \ \  \ \  \    |\____________\  \ \  \ \ \   __  \ \  \    |\____________\  \ \  \ \ \  \\\  \ \  \_|/__                                                       
      \ \  \ \ \  \ \  \___\|____________|   \ \  \ \ \  \ \  \ \  \___\|____________|   \ \  \ \ \  \\\  \ \  \_|\ \                                                      
       \ \__\ \ \__\ \_______\                \ \__\ \ \__\ \__\ \_______\                \ \__\ \ \_______\ \_______\                                                     
        \|__|  \|__|\|_______|                 \|__|  \|__|\|__|\|_______|                 \|__|  \|_______|\|_______| 
)" << '\n';

    int board_size;

    ishost_check();



    if(ishost) {
        board_size_check();
    } else {
        ip_check();
    }
    port_check();

    {
        int init_net_status = init_net();
        if(init_net_status != 0){
            cerr << "failed to initialize network\n";
            return 2;
        }
    }


    char board[board_size*board_size];


    int ncord = 0;
    for (int i = 0; i < sizeof(board); i++) {
        board[ncord] = '_';
        ncord++;
    }

    if(ishost) {
        
    }


    return 0;
    }
