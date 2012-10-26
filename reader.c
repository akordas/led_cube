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
        outputName = "output.txt";
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
    int ledArray[numStates][64];

    printf("Initialized array for %i states.\n", numStates);

    int temp;

    /*read the states into the ledArray*/
    for(int a=0; a<numStates; a++)
    {
        /*this will be repeated for every single state that we read
        for (int b=0; b<64; b++)
        {
            ledArray[a][b]=0;
        }
        */
        /*
        for(int x=4; x<17; x+=4)
        {
            for(int n=0; n<4; n++)
            {
                for(int y=(64-x-(16*n)); y<(64-(16*n)); y++)
                {
                    fscanf(fpi, "%i", &temp);
                    printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
                    ledArray[a][y]=temp;
                }
            }
        }
        */
        for(int y=60;y<64;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=44;y<48;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=28;y<32;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=12;y<16;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=56;y<60;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=40;y<44;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=24;y<28;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=8;y<12;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=52;y<56;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=36;y<40;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=20;y<24;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=4;y<8;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=48;y<52;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=32;y<36;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=16;y<20;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }
        for(int y=0;y<4;y++)
        {
            fscanf(fpi, "%i", &temp);
            printf("Read in %i , storing at (%i, %i)\n", temp, a, y);
            ledArray[a][y]=temp;
        }

    }

    printf("Read design into array. Get that pen!\n");

    /*write the ledArray into the output file*/
    for(int s=0; s<numStates; s++)
    {
        /*this will be repeated for every single state that is in the array*/
        for(int t=0; t<64; t++)
        {
            fprintf(fpo, "%i", ledArray[s][t]);
        }
        fprintf(fpo, "\n");
    }

    /*close the given files*/
    fclose(fpi);
    fclose(fpo);

    /*print a success message*/
    printf("Created a file, one line per ROM line. Now copy and paste!\n");

    return 0;
}
