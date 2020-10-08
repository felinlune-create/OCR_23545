/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: sortie du projet 
 *        Version:  1.0
 *        Created:  05/10/2020 20:00:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


/*
*  !!!!!!!!!!!!!!!!!!!!!!!!!  ne vas plus marcher car les fichier en question on été modifier.!!!!!!!!!!!!!!!!!!
*/
#include <stdlib.h>
#include "image_lib.h"
#include <stdio.h>
#include <string.h> // Penser à inclure string.h pour strchr()
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL) 
    {
        positionEntree = strchr(chaine, '\n'); 
        if (positionEntree != NULL) 
        {
            *positionEntree = '\0'; 
        }
        return 1; 
    }
    else
    {
        return 0; 
    }
}


int main()
{
	char path[20];
	printf("entrer le chemin de l'image");
	lire(path,20);
	affiche(path);
	return 0;
}
