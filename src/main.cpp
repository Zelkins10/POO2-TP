#include "guessTheNumber.hpp"
#include "hangman.hpp"
#include <iostream>

// includes pour [jeu suivant]
// [mettre les includes ici]

//includes pour debug
#include <experimental/filesystem>


int main(){
    
    // Choix du jeu à lancer

    char selectedGame; // Le jeu que l'utilisateur va choisir

    std::cout << "Games available:" << std::endl << "GUESS THE NUMBER" << std::endl << "HANGMAN" << std::endl;
    std::cout << "Which one would you like to play? (g/h) ";
    std::cin >> selectedGame;
    std::cout << std::endl;

    switch(selectedGame){
        case 'g':
            guessTheNumberGame(); // GUESS THE NUMBER
            break;

        case 'h':
            hangmanGame(); // HANGMAN
            break;
    }

    return 0;
}