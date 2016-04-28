/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tail.c
 * Author: rockuo
 *
 * Created on 6. dubna 2016, 19:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define lineSize  511
/*
 * 
 */

typedef struct{char line[lineSize];} line;


int fileTailF(int size, line *tail, char *input){
    int c=0;
    char newLine[lineSize] = {'\0'};
    int i = 0;
    bool errorCaled = false;
    bool saveChar = true;
    FILE *file = fopen(input, "r");
    if (file == NULL)
        return 1;
    while((c = fgetc(file))!=EOF){
        if(c!='\n')
        {
            if(!saveChar)
                continue;
            if(i!=(lineSize-1))
            {
                newLine[i] = c;
                i++;
                continue;
            }
            newLine[i] = '\0';\
            saveChar= false;
            if(!errorCaled)
            {
                errorCaled = true;
                fprintf( stderr, "řádek smí obsahovat poute 510 znaků\n" );
            }
            continue;
        }
        else{
            saveChar = true;
        }
        i=0;
        for(int k =0;k<size-1;k++)
        {
            strcpy(tail[k].line,tail[k+1].line);
        }
       
        strcpy(tail[size-1].line,newLine); 
        for(int k=0;k<lineSize;k++)
            newLine[k]='\0';
       
    }
    fclose(file);
    return 0;
}

int tailF(int size, line *tail){
    int c=0;
    char newLine[lineSize] = {'\0'};
    int i = 0;
    bool errorCaled = false;
    bool saveChar = true;
    while((c = getchar())!=EOF){
        if(c!='\n')
        {
            if(!saveChar)
                continue;
            if(i!=(lineSize-1))
            {
                newLine[i] = c;
                i++;
                continue;
            }
            newLine[i] = '\0';\
            saveChar= false;
            if(!errorCaled)
            {
                errorCaled = true;
                fprintf( stderr, "Řádek smí obsahovat poute 510 znaků\n" );
            }
            continue;
        }
        else{
            saveChar = true;
        }
        i=0;
        for(int k =0;k<size-1;k++)
        {
            strcpy(tail[k].line,tail[k+1].line);
        }
       
        strcpy(tail[size-1].line,newLine); 
        for(int k=0;k<lineSize;k++)
            newLine[k]='\0';
       
    }
    return 0;
}

int main(int argc, char** argv) {
    int size=10;
    bool isStdin=true;
    int inputOn = -1;
    if(argc>1)
    {
        if(argc>4)
        {
            fprintf( stderr, "Chybný počet argumentů\n" );
            return (EXIT_FAILURE);
        }
        for(int i=1;i<argc;i++)
        {
            if(strcmp(argv[i],"-n")==0)
            {
                if(argc==(i+1)){
                    fprintf( stderr, "Chybný počet argumentů\n" );
                    return (EXIT_FAILURE);
                }
                int err =sscanf (argv[i+1],"%d",&size);
                if(err!=1)
                {
                    fprintf( stderr, "Chybný formát argumentů\n" );
                    return (EXIT_FAILURE);
                }
                i++;
            }else
            {
                isStdin = false;
                inputOn=i;
            }
            
        }
        
    }
    line *tail = malloc(size*sizeof(line));
    for(int i=0;i<size;i++)
    {
        strcpy(tail[i].line,"\0");
        printf("%s",tail[i].line);
    }
    if(isStdin)
    {
        tailF(size,tail);
    }else
    {
        int isFailure =fileTailF(size,tail, argv[inputOn]);
        if(isFailure==1)
        {
            fprintf( stderr, "Neexistující soubor\n" );
            return (EXIT_FAILURE);
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%s\n",tail[i].line);
    }
    free(tail);
    return (EXIT_SUCCESS);
}


