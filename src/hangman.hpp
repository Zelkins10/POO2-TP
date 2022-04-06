#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

// Récupération du nb de mots dans le dictionnaire
int getNumberOfWordsInDict(std::ifstream& );

// Obtention d'un mot aléatoire dans le dictionnaire
std::string getRandomWordInDict(std::ifstream&, int);

// Déroulement du jeu
void hangmanGame();