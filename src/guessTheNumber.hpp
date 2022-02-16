#include <iostream>
#include <random>    
    
void guessTheNumberGame(){
    // GUESS THE NUMBER
    std::cout << "--- Guess the number game ---" << std::endl;

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 100);
    int randIntToGuess = distribution(generator);

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