//
// Created by imad on 24/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "manage_nerones.h"
#include "neural_network.h"

double weight[6];
double bias[1];


void save_weight(char path[]) {
    FILE *file1;
    file1 = fopen(path, "wb");
    //first the hidden weight
    for(int i = 0;i<6;i++)
    {
        fprintf(file1,"%lf\n",weight[i]);
    }
    fprintf(file1,"%lf\n",bias[0]);
    fclose(file1);
}

void read_weight(char path[]){
    printf("l1\n");
    FILE *myFile;
    myFile = fopen(path, "r");

    for (unsigned int i = 0; i < 7; i++)
    {
        if(i == 6)
            fscanf(myFile, "%lf", &bias[0]);
        else
            fscanf(myFile, "%lf", &weight[i]);
    }
    printf("l2\n");
    fclose(myFile);
    printf("l3\n");

}