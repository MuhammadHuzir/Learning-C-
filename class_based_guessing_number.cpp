//
// Created by mhuzz on 26/12/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

class guessGame {

    private:
        int randNum;
        int attempts;

    public:
        guessGame() {
            srand(time(0));
            randNum = rand() % 100 + 1;
            attempts = 7;
        }
        void play() {
            int guessNum;

            while ( attempts > 0 ) {
                std::cout << "\nEnter your number: ";
                std::cin >> guessNum;

                attempts--;

                if (guessNum == randNum) {
                    std::cout << "\nYou entered the correct number";
                    return;
                }
                else if (guessNum > randNum) {
                    std::cout << "\nGuess Lower";
                }
                else {
                    std::cout << "\nGuess Higher";
                }

                std::cout << "\nyou have "<< attempts << " remaining attempts";
            }
            std::cout << "\nGame Over! your number was: " << randNum;
        }
};
int main() {
    guessGame game;
    game.play();
    return 0;
}