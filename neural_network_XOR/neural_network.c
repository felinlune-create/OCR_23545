//
// Created by imad on 21/10/2020.
//
//
//  NeuralNetwork


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "manage_nerones.h"





double sigmoid(double x) { return 1 / (1 + exp(-x)); }
double dSigmoid(double x) { return x * (1 - x); }
double initiation_poids() { return ((double)rand())/((double)RAND_MAX); }

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main() {
    printf("select if you want to save the weihgt a the end: s\nselect if you want to load the weihgt: l\nor nothing\n ");
    char choice = getchar();
    int save;
    int loadweight;
    if(choice == 'l')
         loadweight = 0;
    else
        loadweight = 1;
    if(choice == 's')
         save = 0;
    else
        save = 1;

    if(loadweight == 0)
        read_weight("test.txt");

    static const int numInputs = 2;
    static const int numHiddenNodes = 2;
    static const int numOutputs = 1;

    const double lr = 0.1f;

    double hiddenLayer[numHiddenNodes];
    double outputLayer[numOutputs];

    double hiddenLayerBias[numHiddenNodes];
    double outputLayerBias[numOutputs];

    double hiddenWeights[numInputs][numHiddenNodes];
    double outputWeights[numHiddenNodes][numOutputs];


    static const int numTrainingSets = 4;
    double training_inputs[numTrainingSets][numInputs];
    memset( training_inputs, 0, numTrainingSets*numInputs*sizeof(int) );
    double training_outputs[numTrainingSets][numOutputs];

    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<2;j++)
        {
            if(((j == 0) && (i == 1 )) || ((i == 2 )&&( j == 1)) || (i == 3))
                training_inputs[i][j] = 1.0f;
            else
                training_inputs[i][j] = 0.0f;

        }
    }


    memset( training_outputs, 0, numTrainingSets*numOutputs*sizeof(double) );

    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<1;j++)
        {
            if(i == 1 || i == 2)
                training_outputs[i][j] = 1.0f;
            else
                training_outputs[i][j] = 0.0f;

        }
    }
    //loadweight
    if(loadweight != 0) {
        for (int i = 0; i < numInputs; i++) {
            for (int j = 0; j < numHiddenNodes; j++) {
                hiddenWeights[i][j] = initiation_poids();
            }
        }
        for (int i = 0; i < numHiddenNodes; i++) {
            hiddenLayerBias[i] = initiation_poids();
            for (int j = 0; j < numOutputs; j++) {
                outputWeights[i][j] = initiation_poids();
            }
        }
        for (int i = 0; i < numOutputs; i++) {
            outputLayerBias[i] = initiation_poids();
        }
    }
    else
    {
        //utilsation des donnes charger
        for (int i = 0; i < numInputs; i++) {
            for (int j = 0; j < numHiddenNodes; j++) {
                hiddenWeights[i][j] = weight[j];
            }
        }
        for (int i = 0; i < numHiddenNodes; i++) {
            hiddenLayerBias[i] = bias[0];
            for (int j = 0; j < numOutputs; j++) {
                outputWeights[i][j] = weight[3+i];
            }
        }
        for (int i = 0; i < numOutputs; i++) {
            outputLayerBias[i] = bias[0];
        }
    }

    int trainingSetOrder[] = {0,1,2,3};

    for (int n=0; n < 10000; n++) {
        shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {

            int i = trainingSetOrder[x];



            for (int j=0; j<numHiddenNodes; j++) {
                double activation=hiddenLayerBias[j];
                for (int k=0; k<numInputs; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights[k][j];
                }
                hiddenLayer[j] = sigmoid(activation);
            }

            for (int j=0; j<numOutputs; j++) {
                double activation=outputLayerBias[j];
                for (int k=0; k<numHiddenNodes; k++) {
                    activation+=hiddenLayer[k]*outputWeights[k][j];
                }
                outputLayer[j] = sigmoid(activation);
            }


            printf("Input: %f %f Output: %f Expected Output %f\n",training_inputs[i][0],training_inputs[i][1],outputLayer[0],training_outputs[i][0]);
            // Backprop

            double deltaOutput[numOutputs];
            for (int j=0; j<numOutputs; j++) {
                double errorOutput = (training_outputs[i][j]-outputLayer[j]);
                deltaOutput[j] = errorOutput*dSigmoid(outputLayer[j]);
            }

            double deltaHidden[numHiddenNodes];
            for (int j=0; j<numHiddenNodes; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<numOutputs; k++) {
                    errorHidden+=deltaOutput[k]*outputWeights[j][k];
                }
                deltaHidden[j] = errorHidden*dSigmoid(hiddenLayer[j]);
            }

            for (int j=0; j<numOutputs; j++) {
                outputLayerBias[j] += deltaOutput[j]*lr;
                for (int k=0; k<numHiddenNodes; k++) {
                    outputWeights[k][j]+=hiddenLayer[k]*deltaOutput[j]*lr;
                }
            }

            for (int j=0; j<numHiddenNodes; j++) {
                hiddenLayerBias[j] += deltaHidden[j]*lr;
                for(int k=0; k<numInputs; k++) {
                    hiddenWeights[k][j]+=training_inputs[i][k]*deltaHidden[j]*lr;
                }
            }
        }
    }
    unsigned int indice_tab = 0;
    printf( "Final Hidden Weights\n[ ");
    for (int j=0; j<numHiddenNodes; j++) {
        printf( "[ ");
        for(int k=0; k<numInputs; k++) {
            printf("%lf ", hiddenWeights[k][j]);
            weight[indice_tab] = hiddenWeights[k][j];
            indice_tab++;
        }
        printf( "] ");
    }
    printf( "]\n");

    printf( "Final Hidden Biases\n[ ");
    for (int j=0; j<numHiddenNodes; j++) {
        printf("%f" ,hiddenLayerBias[j]);

    }
    printf( "]\n");
    printf( "Final Output Weights");
    for (int j=0; j<numOutputs; j++) {
        printf( "[ ");
        for (int k=0; k<numHiddenNodes; k++) {
            printf( "%f ",outputWeights[k][j]);
            weight[indice_tab] = outputWeights[k][j];
            indice_tab++;
        }
        printf( "]\n");
    }
    printf( "Final Output Biases\n[ ");
    for (int j=0; j<numOutputs; j++) {
        printf("%f --", outputLayerBias[j]);
        bias[0] = outputLayerBias[j];
    }
    printf( "]\n");
    if(save == 0){
        save_weight("test.txt");
        printf("poids save\n");
    }
    if(loadweight == 0) {
        for (unsigned int i = 0; i < 7; i++) {
            if (i == 6)
                printf("bias = %lf\n", bias[0]);
            else
                printf("%lf\n", weight[i]);
        }
    }
    return 0;
}

