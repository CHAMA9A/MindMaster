#include <iostream>
#include "mind.h"
#include <iostream>

#include <iostream>

// Add your function declarations here

int main() {
    // Constantes
    const int nombreCouleurs = 7; // Change this value according to your game
    const int nombrePositions = 4; // Change this value according to your game
    const int nombreEssais = 10; // Change this value according to your game

    std::cout << "Bienvenue dans Mastermind" << std::endl;

    // Tableaux pour stocker la combinaison secrète et la combinaison saisie
    int combiSecrete[nombrePositions];
    int combiSaisie[nombrePositions];

    // Boucle pour demander à l'utilisateur s'il veut rejouer
    char rejouer;
    do {
        // Appeler la fonction ChoisirCombinaison pour choisir la combinaison secrète
        ChoisirCombinaison(combiSecrete, nombrePositions, nombreCouleurs);

        // Boucle pour le fonctionnement du jeu
        for (int essai = 1; essai <= nombreEssais; ++essai) {
            std::cout << "Il vous reste " << nombreEssais - essai << " coups à jouer" << std::endl;

            // Demander au joueur de saisir la combinaison jouée
            SaisirCombinaison(combiSaisie, nombrePositions);

            // Tester la combinaison et afficher le résultat
            int nbPions, nbPionsPlaces, nbPionsMalPlaces;
            bool combinaisonCorrecte = TesterCombinaison(combiSecrete, combiSaisie, nbPions, nbPionsPlaces, nbPionsMalPlaces);

            std::cout << "Votre combinaison ";
            AfficherCombinaison(combiSaisie, nombrePositions);
            std::cout << "contient " << nbPionsPlaces << " pion bien places et " << nbPionsMalPlaces << " pion mal places." << std::endl;

            // Si le joueur a trouvé la bonne combinaison
            if (combinaisonCorrecte) {
                std::cout << "Bravo, vous avez gagné ! La combinaison était : ";
                AfficherCombinaison(combiSecrete, nombrePositions);
                break; // Sortir de la boucle du jeu
            }

            // Si le joueur n'a pas trouvé la bonne combinaison
            if (essai == nombreEssais) {
                std::cout << "Désolé, vous avez perdu ! La combinaison était : ";
                AfficherCombinaison(combiSecrete, nombrePositions);
            }
        }

        // Demander à l'utilisateur s'il veut rejouer
        std::cout << "Voulez-vous rejouer ? (o/n): ";
        std::cin >> rejouer;
    } while (rejouer == 'o' || rejouer == 'O');

    return 0;
}
