//
// Created by mhuzz on 26/12/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {

    srand(time(0));
    int randNum = rand() % 100 + 1;
    int guessNum;
    int attempts = 7;

    while ( attempts > 0 ) {
        std::cout << "\nEnter your number: ";
        std::cin >> guessNum;

        if (guessNum < 1 || guessNum > 100) {
            std::cout << "\nEnter Number between 1-100";
            continue;

        }

        attempts--;

        if (guessNum == randNum) {
            std::cout << "\nYou entered the correct number";
            break;
        }
        else if (guessNum > randNum) {
            std::cout << "\nGuess Lower";
        }
        else {
            std::cout << "\nGuess Higher";
        }

        if (attempts > 0) {
            std::cout << "\nyou have "<< attempts << " remaining attempts";
        } else {
            std::cout << "\nGame Over! your number was: " << randNum;
        }
    }
    return 0;
}