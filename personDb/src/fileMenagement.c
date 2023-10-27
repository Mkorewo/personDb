#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

FILE* file;
struct Person;

int len(){
    file = fopen("db.txt","r"); //r odczytuje
    if(file == NULL ) return 0;
    int length = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n') //jesli dotrze do nowej linii to inkrementuje length
            length = length + 1;
    fclose(file);
    return length;

}

char *readFile(){
    file = fopen("db.txt","r"); //r read
    if(file == NULL ) return NULL;
    fseek(file,0,SEEK_END); //ustawia ponter na koncu
    int length = (ftell(file)+1);
    fseek(file,0,SEEK_SET); //ustawia pointer na poczatku
    char *data = malloc(sizeof(char) * length);
    char c;
    int i = 0;
    while((c = fgetc(file)) != EOF){
        data[i] = c;
        i++;
    }
    data[i] = '\0';
    fclose(file);
    return data;
}
void editFile(char **data,int ln){
    file=fopen("db.txt","w"); //w nadpisuje
    for(int i = 0;i<ln; i++){
        fprintf(file,"%s\n",data[i]);
    }
    fclose(file);
}
void delDataFile(char **data,int ln,int del){
    file=fopen("db.txt","w"); //w napisuje
    for(int i = 0;i<ln; i++){
        if(i!=del){
            fprintf(file,"%s\n",data[i]);
        }

    }
    fclose(file);
}
void saveFile(char name[50],char surname[50],char age[3]){
    file=fopen("db.txt","a"); //a dopisuje
    fprintf(file,"%s, %s, %s\n",name,surname,age);
    //fputs("person", file);
    fclose(file);
}

