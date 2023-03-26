#define HEADER 54
#define PIXEL_SIZE 50
#define SIZE_MAT 270054

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outils.h"

int affichageMenu();

int main(){

    int choixMenu;
    FILE * fichier = fopen("test1.bmp", "rb");
    FILE * fichier2 = fopen("test2.bmp", "rb");
    FILE * resultat = fopen("result.bmp", "wb");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir l'image.\n");
        return 0;
    } else if (resultat == NULL) {
        printf("Impossible de creer l'image.\n");
        return 0;
    }else{
        affichageMenu();
    }

        fclose(resultat);
        fclose(fichier);
        fclose(fichier2);
        return 0;
}


void gris ();
void negative ();
void monochrome ();
void superposition ();
void contour ();


int affichageMenu(void){

    int choixMenu;

    printf("---Menu---\n\n");
    printf("1.Passage en niveau de gris\n");
    printf("2.Inversion des couleurs\n");
    printf("3.Image monochrome\n");
    printf("4.Extraction de contours\n");
    printf("5.Superposition de 2 images de meme taille\n");
    printf("\nVotre choix?\n\n");
    scanf("%d", &choixMenu);

    if (choixMenu == 1){
        gris ();
    }else if (choixMenu == 2){
        negative ();
    }else if (choixMenu == 3){
        monochrome ();
    }else if (choixMenu == 4){
        contour ();
    }else if (choixMenu == 5){
        superposition ();
    }else{
        affichageMenu();
    }
    return choixMenu;
}


