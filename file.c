#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "1234" // Mot de passe
#define FILENAME "resultat.txt"

// Fonction pour vérifier le mot de passe
void authentification() {
    char entree[20];
    do {
        printf("\nEntrez le mot de passe : ");
        scanf("%s", entree);

        if (strcmp(entree, PASSWORD) != 0) {
            printf("Mot de passe incorrect. Réessayez.\n");
        }
    } while (strcmp(entree, PASSWORD) != 0);

    printf("Accès autorisé.\n");
}

// Fonction pour sauvegarder le dernier résultat
void sauvegarder_resultat(const char *resultat) {
    FILE *fichier = fopen(FILENAME, "w");
    if (fichier != NULL) {
        fprintf(fichier, "%s", resultat);
        fclose(fichier);
    }
}

// Fonction pour afficher le dernier résultat
void afficher_dernier_resultat() {
    char buffer[100];
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier != NULL) {
        if (fgets(buffer, sizeof(buffer), fichier) != NULL) {
            printf("Dernier résultat : %s\n", buffer);
        }
        fclose(fichier);
    } else {
        printf("Aucun résultat précédent trouvé.\n");
    }
}

// Conversion binaire vers décimal
void binaire_vers_decimal() {
    char binaire[33];
    int decimal = 0;

    printf("Entrez un nombre binaire : ");
    scanf("%s", binaire);

    for (int i = 0; binaire[i] != '\0'; i++) {
        decimal = decimal * 2 + (binaire[i] - '0');
    }

    printf("Décimal : %d\n", decimal);

    char resultat[50];
    sprintf(resultat, "Binaire -> Décimal : %d", decimal);
    sauvegarder_resultat(resultat);
}

// Conversion décimal vers hexadécimal
void decimal_vers_hexadecimal() {
    int decimal;
    printf("Entrez un nombre décimal : ");
    scanf("%d", &decimal);

    printf("Hexadécimal : %X\n", decimal);

    char resultat[50];
    sprintf(resultat, "Décimal -> Hexadécimal : %X", decimal);
    sauvegarder_resultat(resultat);
}

// Conversion de la monnaie (USD <-> FC)
void conversion_monnaie() {
    float montant;
    int choix;
    const float taux = 2500.0; // Exemple de taux USD -> FC

    printf("1. USD -> FC\n2. FC -> USD\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Entrez le montant en USD : ");
        scanf("%f", &montant);
        printf("%.2f USD = %.2f FC\n", montant, montant * taux);

        char resultat[50];
        sprintf(resultat, "USD -> FC : %.2f", montant * taux);
        sauvegarder_resultat(resultat);

    } else if (choix == 2) {
        printf("Entrez le montant en FC : ");
        scanf("%f", &montant);
        printf("%.2f FC = %.2f USD\n", montant, montant / taux);

        char resultat[50];
        sprintf(resultat, "FC -> USD : %.2f", montant / taux);
        sauvegarder_resultat(resultat);

    } else {
        printf("Option invalide.\n");
    }
}

// Menu principal
void menu() {
    int choix;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Décodage binaire -> décimal\n");
        printf("2. Conversion décimal -> hexadécimal\n");
        printf("3. Conversion de la monnaie (USD <-> FC)\n");
        printf("4. Afficher le dernier résultat\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: binaire_vers_decimal(); break;
            case 2: decimal_vers_hexadecimal(); break;
            case 3: conversion_monnaie(); break;
            case 4: afficher_dernier_resultat(); break;
            case 5: printf("Au revoir !\n"); break;
            default: printf("Option invalide.\n");
        }
    } while (choix != 5);
}

// Fonction principale
int main() {
    authentification();
    menu();
    return 0;
}