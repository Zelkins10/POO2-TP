#include "guessTheNumber.hpp"

// includes pour hangman
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <iostream>
#include <vector>

//includes pour debug
#include <experimental/filesystem>

// Récupération du nb de mots dans le dictionnaire
int getNumberOfWordsInDict(std::ifstream& dictionaryTxtFile){
    int wordCount = 0;
    std::string line;
    
    while(std::getline(dictionaryTxtFile, line)){
        wordCount++;
    }
    
    return wordCount; 
}

std::string getRandomWordInDict(std::ifstream& dictionaryTxtFile, int nbOfWords){

    std::string line;
    int wordCount = 0;

    // Obtention d'un entier aléatoire entre 0 et le nb total de lignes dans le dictionnaire
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, nbOfWords);
    int randInt = distribution(generator);

    // Récupération du mot correspondant à l'entier aléatoire (numéro de ligne du dictionnaire)
    std::ifstream myDictionaryTxtFile("./assets/engmix.txt"); // PROBLEME : cette ligne ne devrait pas être répétée ici
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

int main(){
    //guessTheNumberGame();

    // HANGMAN

    // Lecture du dictionnaire (ancienne version de l'ouverture : cf commit sur git)
    std::ifstream myDictionaryTxtFile("./assets/engmix.txt");

    // Récupération du nb de mots dans le dictionnaire
    int nbOfWordsEngmix = getNumberOfWordsInDict(myDictionaryTxtFile);
    //std::cout << "le nb de mots dans le dico est : " << nbOfWordsEngmix << std::endl; //DEBUG
    
    // Récupération d'un mot aléatoire dans le dictionnaire
    std::string randomWord = getRandomWordInDict(myDictionaryTxtFile, nbOfWordsEngmix);
    std::cout << randomWord << std::endl; //DEBUG


    // Création du mot partiellement découvert (combinaison de tirets et de lettres)
    int nbOfLetters = randomWord.length();
    std::vector<char> wordPartiallyDiscovered;
    for(int i=0; i < nbOfLetters; i++){
        wordPartiallyDiscovered.push_back('_');
    }


    // Lancement du jeu
    int nbOfLives = 8;
    
    // BOUCLE PRINCIPALE DU JEU

    std::cout << "--- Hangman game ---" << std::endl;

    while(nbOfLives > 0){
        std::cout << "You have " << nbOfLives << " lives." << std::endl;

        for(int i=0; i < nbOfLetters; i++){
            std::cout << wordPartiallyDiscovered[i] << " ";
        }

        nbOfLives--; //DEBUG uniquement, doit être retiré

    }
    

    return 0;
}