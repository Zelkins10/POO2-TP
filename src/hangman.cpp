#include "hangman.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <iostream>
#include <vector>

// Récupération du nb de mots dans le dictionnaire
int getNumberOfWordsInDict(std::ifstream& dictionaryTxtFile){
    int wordCount = 0;
    std::string line;
    
    while(std::getline(dictionaryTxtFile, line)){
        wordCount++;
    }
    
    return wordCount; 
}

// Obtention d'un mot aléatoire dans le dictionnaire
std::string getRandomWordInDict(std::ifstream& dictionaryTxtFile, int nbOfWords){

    int wordCount = 0;

    // Obtention d'un entier aléatoire entre 0 et le nb total de lignes dans le dictionnaire
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, nbOfWords);
    int randInt = distribution(generator);

    // Récupération du mot correspondant à l'entier aléatoire (numéro de ligne du dictionnaire)
    std::ifstream myDictionaryTxtFile("../assets/engmix.txt"); // PROBLEME : cette ligne ne devrait pas être répétée ici
    std::string line;
    while(std::getline(myDictionaryTxtFile, line)){
        wordCount++;
        if(wordCount == randInt){
            std::string randomWord = line;
            return randomWord;
        }
    }

    //default string pour debug
    std::string defaultWord = "word";
    return defaultWord;
}

// Déroulement du jeu
void hangmanGame(){

    // Lecture du dictionnaire (ancienne version de l'ouverture : cf commit sur git)
    std::ifstream myDictionaryTxtFile("../assets/engmix.txt");

    // Récupération du nb de mots dans le dictionnaire
    int nbOfWordsEngmix = getNumberOfWordsInDict(myDictionaryTxtFile);
    //std::cout << "le nb de mots dans le dico est : " << nbOfWordsEngmix << std::endl; //DEBUG
    
    // Récupération d'un mot aléatoire dans le dictionnaire
    std::string randomWord = getRandomWordInDict(myDictionaryTxtFile, nbOfWordsEngmix);
    //std::cout << randomWord << std::endl; //DEBUG (affichage du mot à trouver)


    // Création du mot partiellement découvert (combinaison de tirets et de lettres)
    int nbOfLetters = randomWord.length();
    std::vector<char> wordPartiallyDiscovered;
    for(int i=0; i < nbOfLetters; i++){
        wordPartiallyDiscovered.push_back('_');
    }


    // ---- Lancement du jeu ----

    // Variables utiles
    int nbOfLives = 11;
    char letter; // lettre entrée par le joueur à tester
    bool letterIsCorrect = false; // Booléen pour gérer une boucle du jeu
    int gameResult = 0; // 0 : partie non terminée ; 1 : gagné ; 2 : perdu // tester un enum à la place
    
    // BOUCLE PRINCIPALE DU JEU
    std::cout << "--- Hangman game ---" << std::endl;

    while(gameResult == 0){
        std::cout << std::endl << "You have " << nbOfLives << " lives" << std::endl;

        for(int i=0; i < nbOfLetters; i++){
            std::cout << wordPartiallyDiscovered[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Try a letter: ";
        std::cin >> letter;

        // Test de présence de la lettre entrée dans le mot à trouver
        int nbOfDiscoveredLetters = 0;
        for(int i=0; i < nbOfLetters; i++){

            if(randomWord[i] == letter){
                wordPartiallyDiscovered[i] = randomWord[i];
                
                letterIsCorrect = true;
            }
            if(wordPartiallyDiscovered[i] != '_'){
                nbOfDiscoveredLetters ++;
            }
        }

        // Evaluation de l'état de la tentative de lettre
        if(!letterIsCorrect){
            std::cout << "Nope!" << std::endl;
            nbOfLives--;
        }

        else if(letterIsCorrect){
            std::cout << "Correct!" << std::endl;
        }

        letterIsCorrect = false; // Réinitialisation de ce booléen

        // Evaluation de l'état de la partie
        if(nbOfLives == 0){
            gameResult = 2;
        }
        else if(nbOfDiscoveredLetters == nbOfLetters){
            gameResult = 1;
        }
    }

    // Résultat de la partie (et affichage du mot qu'il fallait trouver)
    std::cout << std::endl;

    if(gameResult == 1){
        std::cout << "Congrats, you won!" << std::endl;
    }
    else{
        std::cout << "You lost..." << std::endl;
    }
    std::cout << "The word was \"" << randomWord << "\"." << std::endl;

}