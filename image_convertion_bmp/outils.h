#ifndef OUTILS_H_INCLUDED
#define OUTILS_H_INCLUDED



void gris (){

    int choixImage;

    printf("Choisissez une image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage);

    FILE* fichier = NULL, *t = NULL;
    unsigned char a[270054];

    switch (choixImage)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }
    FILE * resultat = fopen("result.bmp", "wb");

    unsigned char header[HEADER];
    fread(header, sizeof(unsigned char), HEADER, fichier);
    fwrite(header, sizeof(unsigned char), HEADER, resultat);

    //initialisation de la longueur et hauteur
    int L = *(int*)&header[18];
    int H = abs(*(int*)&header[22]);

    unsigned char pixel[3];//Image en gris clair
    for (int y = 0 ; y < H ; ++y) {
        for (int x = 0 ; x < L ; ++x) {
            fread(pixel, 3, 1, fichier); // On lit le pixel d'origine
            unsigned char gris = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11; // On definit le gris
            memset(pixel, gris, sizeof(pixel)); // On alloue la zone mémoire
            fwrite(&pixel, 3, 1, resultat); // On écrit le pixel modifié
        }
    }
}


void negative (){

    int choixImage;

    printf("Choisissez une image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage);

    FILE* fichier = NULL, *t = NULL;
    unsigned char a[270054];

    switch (choixImage)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }
    FILE * resultat = fopen("result.bmp", "wb");

    unsigned char header[HEADER];
    fread(header, sizeof(unsigned char), HEADER, fichier);
    fwrite(header, sizeof(unsigned char), HEADER, resultat);

    //initialisation de la longueur et hauteur
    int L = *(int*)&header[18];
    int H = abs(*(int*)&header[22]);

    unsigned char pixel[3];//Image en couleurs négatives
    for (int y = 0 ; y < H ; ++y) {
        for (int x = 0 ; x < L ; ++x) {
            fread(pixel, 3, 1, fichier); // On lit le pixel d'origine
           //On met l'inverse du rouge
            pixel[0]=-pixel[0];
            pixel[1]=-pixel[1];
            pixel[2]=-pixel[2];

            fwrite(&pixel, 3, 1, resultat); // On écrit le pixel modifié
        }
    }
}

void monochrome (){

    int choixImage;

    printf("Choisissez une image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage);

    FILE* fichier = NULL, *t = NULL;
    unsigned char a[270054];

    switch (choixImage)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }

    FILE * resultat = fopen("result.bmp", "wb");

    unsigned char header[HEADER];
    fread(header, sizeof(unsigned char), HEADER, fichier);
    fwrite(header, sizeof(unsigned char), HEADER, resultat);

    //initialisation de la longueur et hauteur
    int L = *(int*)&header[18];
    int H = abs(*(int*)&header[22]);

    unsigned char pixel[3];//Image en monochrome
            for (int y = 0 ; y < H ; ++y) {
                for (int x = 0 ; x < L ; ++x) {
                    fread(pixel, 3, 1, fichier); // On lit le pixel d'origine
                    pixel[0]=pixel[1]=pixel[2];
                    unsigned char monochrome = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11; // On definit le gris
                    memset(pixel, monochrome, sizeof(pixel)); // On alloue la zone mémoire
                    //On met defini le noir et le blanc
                    if (pixel[0]<127){
                        pixel[0]=0;
                    }else if (pixel[0]>127){
                        pixel[0]=255;
                    }

                    if (pixel[1]<127){
                        pixel[1]=0;
                    }else if (pixel[0]>127){
                        pixel[1]=255;
                    }

                    if (pixel[2]<127){
                        pixel[2]=0;
                    }else if (pixel[0]>127){
                        pixel[2]=255;
                    }

                    fwrite(&pixel, 3, 1, resultat);
        }
    }
}

void superposition (){

    int choixImage;

    printf("Choisissez une image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage);

    FILE* fichier = NULL, *t = NULL;
    FILE* fichier2  = NULL;
    unsigned char a[270054];

    switch (choixImage)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }

    int choixImage2;

    printf("Choisissez une dexième image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage2);

    switch (choixImage2)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }

    FILE * resultat = fopen("result.bmp", "wb");

    unsigned char header[HEADER];
    fread(header, sizeof(unsigned char), HEADER, fichier);
    fread(header, sizeof(unsigned char), HEADER, fichier2);
    fwrite(header, sizeof(unsigned char), HEADER, resultat);

    //initialisation de la longueur et hauteur
    int L = *(int*)&header[18];
    int H = abs(*(int*)&header[22]);

    unsigned char pixel[3];//Superposition
    unsigned char pixel_2[3];
        for (int y = 0 ; y < H ; ++y) {
            for (int x = 0 ; x < L ; ++x) {
                fread(pixel, 3, 1, fichier); // On lit le pixel d'origine
                fread(pixel_2, 3, 1, fichier2);

                pixel[0] = (pixel[0]+pixel_2[0])/2;
                pixel[1] = (pixel[1]+pixel_2[1])/2;
                pixel[2] = (pixel[2]+pixel_2[2])/2;

                fwrite(&pixel, 3, 1, resultat); // On écrit le pixel modifié
        }
    }

}

void contour (){

 int choixImage;

    printf("Choisissez une image :\n\n");
    printf("1.test1.bmp\n");
    printf("2.test2.bmp\n");
    printf("3.test3.bmp\n");
    printf("4.test4.bmp\n");
    printf("\nVotre choix ?\n");
    scanf("%d", &choixImage);

    FILE* fichier = NULL, *t = NULL;
    unsigned char a[270054];

    switch (choixImage)
    {
    case 1:
        fichier = fopen("test1.bmp", "rb");
        break;
    case 2:
        fichier = fopen("test2.bmp", "rb");
        break;
    case 3:
       fichier = fopen("test3.bmp", "rb");
        break;
    case 4:
       fichier = fopen("test4.bmp", "rb");
        break;
    default:
        affichageMenu();
        break;
    }
    FILE * resultat = fopen("result.bmp", "wb");

    unsigned char header[HEADER];
    fread(header, sizeof(unsigned char), HEADER, fichier);
    fwrite(header, sizeof(unsigned char), HEADER, resultat);

    //initialisation de la longueur et hauteur
    int L = *(int*)&header[18];
    int H = abs(*(int*)&header[22]);

    unsigned char pixel[3];//Image en gris clair
    for (int y = 0 ; y < H ; ++y) {
        for (int x = 0 ; x < L ; ++x) {
            fread(pixel, 3, 1, fichier); // On lit le pixel d'origine
            unsigned char gris = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11; // On definit le gris
            memset(pixel, gris, sizeof(pixel)); // On alloue la zone mémoire

            if (pixel[0]>(pixel[0]++)+200){
                pixel[0]=0;
            }else if (pixel[0]<(pixel[0]++)-200){
                pixel[0]=0;
            }else{
                pixel[0]=255;
            }

            if (pixel[1]>(pixel[1]++)+200){
                pixel[1]=0;
            }else if (pixel[1]<(pixel[1]++)-200){
                pixel[1]=0;
            }else{
                pixel[1]=255;
            }

            if (pixel[2]>(pixel[2]++)+200){
                pixel[2]=0;
            }else if (pixel[2]<(pixel[2]++)-200){
                pixel[2]=0;
            }else{
                pixel[2]=255;
            }

            fwrite(&pixel, 3, 1, resultat); // On écrit le pixel modifié

        }
    }
}

#endif // OUTILS_H_INCLUDED
