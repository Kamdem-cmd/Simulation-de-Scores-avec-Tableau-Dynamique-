#include "header.h"

unsigned int afficheMenu(){
    unsigned int option;

    std::cout << "\nMENU\n";
    std::cout << "1. Afficher Scores\n";
    std::cout << "2. Inserer Scores\n";
    std::cout << "3. Supprimer Score\n";
    std::cout << "4. Plus grand Scores \n";
    std::cout << "99. Quitter\n";

    std::cin >> option;

    return (option);
}