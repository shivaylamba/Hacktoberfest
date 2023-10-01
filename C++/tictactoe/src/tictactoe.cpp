#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

#include <board.hpp>

int main()
{
    srand(std::time(nullptr));

    Board playground;

    playground.drawBoard();

    while(true) {
        
        int pos{0};

        while(((pos < 1) || (pos > 9))) {
            std::cout << "Enter position to fill 'X': ";
            std::cin >> pos;
            
            if(playground.getSymbol(pos) != ' ') {
                std::cout << "Position already occupied" << std::endl;
                pos = 0;
            }
        }

        playground.setSymbol(pos, 'X');
        playground.drawBoard();

        if(playground.isDraw()) {
            std::cout << "Draw" << std::endl;
            exit(EXIT_SUCCESS);
        }

        if(playground.isXWinning()) {
            std::cout << "You Win" << std::endl;
            exit(EXIT_SUCCESS);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        playground.playComputer();
        playground.drawBoard();

        if(playground.isDraw()) {
            std::cout << "Draw" << std::endl;
            exit(EXIT_SUCCESS);
        }

        if(playground.isOWinning()) {
            std::cout << "You Lost" << std::endl;
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}