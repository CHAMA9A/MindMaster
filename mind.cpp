#include <iostream>
#include <algorithm> // for std::shuffle
#include <ctime>     // for std::time
#include <random>
#include <vector>
#include "mind.h"

bool TesterCombinaison(int combiCache[], int combiSaisie[], int& nbPions, int& nbPionsPlaces, int& nbPionsMalPlaces) {
    // Initialisation des compteurs
    nbPions = nbPionsPlaces = nbPionsMalPlaces = 0;

    // Vérification des pions bien placés
    for (int i = 0; i < 4; ++i) {
        if (combiSaisie[i] == combiCache[i]) {
            ++nbPionsPlaces;
        }
    }

    // Vérification des pions mal placés
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (combiSaisie[i] == combiCache[j] && combiSaisie[i] != combiCache[i]) {
                ++nbPionsMalPlaces;
                break;
            }
        }
    }

    // Calcul du nombre total de pions bien placés et mal placés
    nbPions = nbPionsPlaces + nbPionsMalPlaces;

    // La combinaison est correcte si tous les pions sont bien placés
    return nbPionsPlaces == 4;

}

void AfficherCombinaison(int combi[], int nbPions) {
    std::cout << "Combinaison : ";
    for (int i = 0; i < nbPions; ++i) {
        std::cout << combi[i] << " ";
    }
    std::cout << std::endl;
}

// Fonction pour saisir la combinaison
void SaisirCombinaison(int combi[], int nbPions) {
    std::cout << "Entrez votre combinaison : ";

    // Boucle pour saisir chaque élément de la combinaison
    for (int i = 0; i < nbPions; ++i) {
        std::cin >> combi[i];
    }
}



int GetNombreAleatoire(int min, int max) {
    // Initialisation du générateur de nombres aléatoires
    srand(time(nullptr));

    // Calcul d'une valeur aléatoire entre min et max
    int nombreAleatoire = rand() % (max - min + 1) + min;
    return nombreAleatoire;
}


void ChoisirCombinaison(int combi[], int nbPions, int maxCouleur) {
    // Créer un tableau avec les différentes couleurs possibles
    int couleursDisponibles[maxCouleur];
    for (int i = 0; i < maxCouleur; ++i) {
        couleursDisponibles[i] = i + 1;
    }

    // Mélanger le tableau pour obtenir une combinaison aléatoire de différentes couleurs
    shuffle(couleursDisponibles, couleursDisponibles + maxCouleur, std::mt19937(std::random_device()()));

    // Prendre les premiers nbPions éléments du tableau mélangé comme combinaison secrète
    for (int i = 0; i < nbPions; ++i) {
        combi[i] = couleursDisponibles[i];
    }
}
