#include "guessTheNumber.hpp"
#include "hangman.hpp"
#include "noughtsAndCrosses.hpp"
#include <iostream>

// includes pour [jeu suivant]
// [mettre les includes ici]

//includes pour debug
#include <experimental/filesystem>


int main(){
    
    // Choix du jeu à lancer

    char selectedGame; // Le jeu que l'utilisateur va choisir

    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1: Play GUESS THE NUMBER" << std::endl << "2: Play HANGMAN" << std::endl << "3: Play NOUGHTS AND CROSSES" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cin >> selectedGame;
    std::cout << std::endl;

    switch(selectedGame){
        case '1':
            guessTheNumberGame(); // GUESS THE NUMBER
            break;

        case '2':
            hangmanGame(); // HANGMAN
            break;

        case '3':
            noughtsAndCrossesGame(); // NOUGHTS AND CROSSES

        case 'q':
            break;
            
        default:
            std::cout << "Sorry, I don't know that command!" << std::endl;
    }

    return 0;
}