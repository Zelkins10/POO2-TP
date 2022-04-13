#include "hangman.hpp"

#include "rand.hpp"

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
    
    // Réinitialisation des flags eof et fail pour la lecture du dictionnaire
    dictionaryTxtFile.clear();
    dictionaryTxtFile.seekg(0);

    return wordCount; 
}

// Obtention d'un mot aléatoire dans le dictionnaire
std::string getRandomWordInDict(std::ifstream& dictionaryTxtFile, int nbOfWords){

    int wordCount = 0;

    // Obtention d'un entier aléatoire entre 0 et le nb total de lignes dans le dictionnaire
    int randIntInDict = randInt(nbOfWords);

    // Récupération du mot correspondant à l'entier aléatoire (numéro de ligne du dictionnaire)
    std::string line;
    while(std::getline(dictionaryTxtFile, line)){
        wordCount++;
        if(wordCount == randIntInDict){
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

    // Lecture du dictionnaire
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

    enum class GameState {Ongoing, Won, Lost};
    GameState gameState = GameState::Ongoing; // état de la partie
    
    // BOUCLE PRINCIPALE DU JEU
    std::cout << "--- Hangman game ---" << std::endl;

    while(gameState == GameState::Ongoing){
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
            gameState = GameState::Lost;
        }
        else if(nbOfDiscoveredLetters == nbOfLetters){
            gameState = GameState::Won;
        }
    }

    // Résultat de la partie (et affichage du mot qu'il fallait trouver)
    std::cout << std::endl;

    if(gameState == GameState::Won){
        std::cout << "Congrats, you won!" << std::endl;
    }
    else{
        std::cout << "You lost..." << std::endl;
    }
    std::cout << "The word was \"" << randomWord << "\"." << std::endl;

}