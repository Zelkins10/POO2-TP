#include <iostream>
#include <random>

#include "rand.hpp"
    
void guessTheNumberGame(){
    // GUESS THE NUMBER
    std::cout << "--- Guess the number game ---" << std::endl;

    const int GAME_MAX_NUMBER = 100;
    int randIntToGuess = randInt(GAME_MAX_NUMBER);

    int userGuess = 101;

    while(userGuess != randIntToGuess){

        std::cout << "Enter a number between 0 and 100: ";
        std::cin >> userGuess;
        std::cout << std::endl;

        if(userGuess < randIntToGuess){
            std::cout << "Greater" << std::endl;
        }
        
        else if(userGuess > randIntToGuess){
            std::cout << "Smaller" << std::endl;
        }
    }
    
    if(userGuess == randIntToGuess){
        std::cout << "Congrats, you won!" << std::endl;
    }
}