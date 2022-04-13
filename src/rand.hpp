// Fontionnalités d'aléatoire utilisées par au moins 2 jeux

#include <random>

// Obtention d'un nb aléatoire entre 0 et une limite supérieure
inline int randInt(int upLimit){
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, upLimit);
    return distribution(generator);
}