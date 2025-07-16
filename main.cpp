#include <iostream>

class ScoreBoard
{
    private:
        int *donnees;
        unsigned int capacite; // capaciter totale
        unsigned int taille; // nombre d'elements actuel stocker

    public:
        // Méthode qui affiche la totalité des score present dans l'instance  @class Scoreboard
        void affichageScore();
        /*
        * parametre: @int, represente le nombre de scores à ajouté
        * Méthode qui ajoute un nombre définis de score à l'instance @class ScoreBoard
        */
        void ajoutScores(int);
        /*
        * parametre: @int, represente l'indexe du scores à supprimé
        * Méthode qui supprime un score définis par son indexe à l'instance @class ScoreBoard
        */
        void supprimeScores(int);

        // Initialiser le tableau
        void initialiser(int init = 10)
        {
            donnees = new int[init];
            capacite = init;
            taille = 0;
        }

        // Liberer la memoire
        void liberer()
        {
            delete[] donnees;
            donnees = nullptr;
            capacite = 0;
            taille = 0;
        }

        // Redimensionner le tableau
        void redimensionner(unsigned int nouvelleCapaciter)
        {
            int *newScoreBoard = new int[nouvelleCapaciter];

            for(int i = 0; i < taille; i++)
            {
                newScoreBoard[i] = donnees[i];
            }

            delete[] donnees;
            donnees = newScoreBoard;
            capacite = nouvelleCapaciter;
        }

        void ajoutScores(int nombre){
            int compteur = 0;

            if(taille >= capacite){
                redimensionner(capacite * 2);
            }

            while(compteur < nombre)
            {
                std::cout << "entrer le score %d: ",  compteur + 1;
                std::cin >> donnees[compteur];
                compteur++;
            }
            
        }

        
        void supprimeScores(int indice){
            if(taille >= capacite){
                std::cerr << "Erreur: Indice invalide";
            }

            for(int i = indice; i < taille - 1; i++){
                donnees[i] = donnees[i + 1];
            }

            taille--;

            if(taille < capacite / 4 && capacite > 10){
                redimensionner(capacite / 2);
            }
        }

        void affichageScore(){
            for(int i = 0; i < taille; i++){
                std::cout << "%d | %d\n", i + 1, donnees[i];
            }

        }




};


int main(){
    ScoreBoard playerScores;

    playerScores.initialiser();

    playerScores.ajoutScores(3);

    std::cout << "Scores\n";
    playerScores.affichageScore();

    return (0);
}