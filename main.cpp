#include <iostream>

// Classe qui contient l'ensemble des scores 
class ScoreBoard
{
    private:
        int *data;
        unsigned int capacite; // capaciter totale
        unsigned int taille; // nombreScores d'elements actuel stocker

    public:
        // Initialiser le tableau
        void initialiser(int init = 10)
        {
            data = new int[init];
            capacite = init;
            taille = 0;
        }

        // Liberer la memoire
        void liberer()
        {
            delete[] data;
            data = NULL;
            capacite = 0;
            taille = 0;
        }

        // Redimensionner le tableau
        void redimensionner(unsigned int nouvelleCapaciter)
        {
            int *newScoreBoard = new int[nouvelleCapaciter];

            for(unsigned int i = 0; i < taille; i++)
            {
                newScoreBoard[i] = data[i];
            }

            delete[] data;
            data = newScoreBoard;
            capacite = nouvelleCapaciter;
        }
        /*
        * parametre: @int, represente le nombreScores de scores à ajouté
        * Méthode qui ajoute un nombreScores définis de score à l'instance @class ScoreBoard
        */
        void ajoutScores(unsigned int nombreScores){
            unsigned int compteur = 0;

            if(taille >= capacite){
                redimensionner(capacite * 2);
            }

            while(compteur < nombreScores)
            {
                std::cout << "entrer le score "<< compteur + 1 << ": ";
                std::cin >> data[compteur];
                compteur++;
            }
             
            taille = nombreScores;
        }
       
        /*
        * parametre: @int, represente l'indexe du scores à supprimé
        * Méthode qui supprime un score définis par son indexe à l'instance @class ScoreBoard
        */
        void supprimeScores(unsigned int indice){
            if(taille >= capacite || indice > taille ){
                std::cerr << "Erreur: Indice invalide\n";
            }else{
                for(unsigned int i = indice; i < taille - 1; i++){
                    data[i] = data[i + 1];
                }

                taille--;

                if(taille < capacite / 4 && capacite > 10){
                    redimensionner(capacite / 2);
                }
            }

            
        }
        // Méthode qui affiche la totalité des score present dans l'instance  @class Scoreboard
        void affichageScore(){
            if(taille == 0){
                std::cout <<"Tableau vide...\nVeillez a le remplir au prealable\n";
            }else{
                std::cout << "Scores:\n";
                for(unsigned int i = 0; i < taille; i++){
                    std::cout <<"Score_" << i + 1 << ": " << data[i] << "\n";
                }
            }
            
        }

        // Affiche le score le plus elevé 
        void highScore()
        {
            if(taille != 0)
            {
                unsigned int max = 0;

                std::cout << "Meilleur Score\n";

                for(unsigned int i = 0; i < taille; i++){
                    if(max < data[i]) max = data[i]; 
                }

                std::cout <<"Plus grand Score " << max << "\n";
            }else{
                std::cout <<"Tableau vide...\nVeillez a le remplir au prealable\n";
            }
            
        }
};

unsigned int afficheMenu();


int main(){
    unsigned int choix;
    ScoreBoard playerScores;

    playerScores.initialiser();

    while (choix <= 4){
        choix = afficheMenu();

        switch (choix)
        {
        case 1:
            playerScores.affichageScore();
            break;
        case 2:
            unsigned int nombreScore;

            std::cout << "Combien de Scores voullez vous inserer ?\n";
            std::cin >> nombreScore;
            playerScores.ajoutScores(nombreScore);
            break;
        case 3:
            unsigned int indice;

            std::cout << "Supprimer Score\n";
            std::cout << "Indice: ";
            std::cin >> indice;
            playerScores.supprimeScores(indice - 1);
            break;
        case 4:
            playerScores.highScore();
            break;
    
        default:
            break;
        }
    }
 
    playerScores.liberer();

    return (0);
}

unsigned int afficheMenu(){
    unsigned int option;

    std::cout << "1. Afficher Scores\n";
    std::cout << "2. Inserer Scores\n";
    std::cout << "3. Supprimer Score\n";
    std::cout << "4. Plus grand Scores \n";
    std::cout << "99. Quitter\n";

    std::cin >> option;

    return (option);
}