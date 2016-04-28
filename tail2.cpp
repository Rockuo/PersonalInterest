/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tail.cpp
 * Author: rcd C
 *
 * Created on 9. dubna 2016, 13:57
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int tailF(int size, string *tail){
    for (string line; getline(cin, line);) {
        for(int k =0;k<size-1;k++)
        {
            tail[k]=tail[k+1];
        }
       
        tail[size-1]=line;
    }
    
    
    return 0;
}

int fileTailF(int size, string *tail, string filename){
    ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        for (string line; getline(file, line);) {
            for(int k =0;k<size-1;k++)
            {
                tail[k]=tail[k+1];
            }

            tail[size-1]=line;
        }
    }
    else{
        return 1;
    }
    file.close();
    return 0;
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    bool isStdIn = true;
    int inputOn = 0;
    int size = 10;
    string arg;
    if(argc>1)
    {
        if(argc>4)
        {
            fprintf( stderr, "Chybný počet argumentů\n" );
            return (EXIT_FAILURE);
        }
        for(int i=1;i<argc;i++)
        {
            arg = argv[i];
            if(arg.compare("-n")==0)
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
                isStdIn = false;
                inputOn=i;
            }
        }
        
    }
    string *tail = new string[size];
    if(isStdIn){
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
    for (int i=0 ; i<size;i++) {
        cout << tail[i] << endl;
        
    }
    return 0;
}

