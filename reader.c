#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    /*init strings for input and output names*/
    char* inputName;
    char* outputName;

    /*init of other variables*/
    int numStates;

    if (argc==3) /*both input name and output name provided*/
    {
        inputName = argv[1];
        outputName = argv[2];
    }
    else if (argc==2) /*only input name provided, use default output name*/
    {
        inputName = argv[1];
        outputName = "output.mif";
    }
    else /*improper usage, tell the user he/she is doing it wrong*/
    {
        printf("Usage: %s INPUT_FILE [OUTPUT_FILE]\n", argv[0]);
        return -1;
    }

    printf("Welcome to LED Cube Designer 1.0\n");

    /*open the given files*/
    FILE* fpi = fopen(inputName, "r");
    FILE* fpo = fopen(outputName, "w");

    fscanf(fpi, "%i", &numStates); /*get the number of states to be read*/
    if (numStates>64)
    {
        printf("Sorry, but a maximum of 64 states is allowed\n");
        return -1;
    }

    int ledArray[numStates][64];

    printf("Initialized array for %i states.\n", numStates);

    int temp;

    /*read the states into the ledArray*/
    for(int a=0; a<numStates; a++)
    {
        /*this will be repeated for every single state that we read*/
        /*printf("about to start state loop for the %ith time\n", a);*/
        for(int y=60; y>47; y-=4)
        {
            for(int x=0; x<49; x+=16)
            {
                for(int z=0; z<4; z++)
                {
                    fscanf(fpi, "%i", &temp);
                    /*printf("Read in %i,storing at (%i, %i)\n", temp, a, y-x+z);*/
                    ledArray[a][y-x+z]=temp;
                }
            }
        }
    }

    printf("Read design into array. Get that pen!\n");

    fprintf(fpo, "DEPTH = 32;\nWIDTH = 64;\nADDRESS_RADIX = HEX;\n");
    fprintf(fpo, "DATA_RADIX = BIN;\nCONTENT\nBEGIN\n");

    /*write the ledArray into the output file*/
    for(int s=0; s<numStates; s++)
    {
        if (s<16)
        {
            fprintf(fpo, "0%x : ", s);
        }
        else
        {
            fprintf(fpo, "%x : ", s);
        }
        /*this will be repeated for every single state that is in the array*/
        for(int t=0; t<64; t++)
        {
            fprintf(fpo, "%i", ledArray[s][t]);
        }
        fprintf(fpo, "\n");
    }
    fprintf(fpo, "END;\n");

    /*close the given files*/
    fclose(fpi);
    fclose(fpo);

    /*print a success message*/
    printf("Successfully Generated a MIF File.\n");

    return 0;
}
