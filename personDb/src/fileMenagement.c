#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


FILE* file;
struct Person;

int len(){ // funkcja sluzaca do pobrania ilosci wierrszy
    file = fopen("db.txt","r"); // otwarcie pliku w trybie r - read: odczytaj
    if(file == NULL ) return 0;
    int length = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n') //jesli dotrze do nowej linii to inkrementuje length
            length = length + 1;
    fclose(file); // zamkniecie pliku na ktorym dzialala funkcja
    return length; // zwrocenie wartosci length

}

char *readFile(){ // funkcja sluzaca do wczytania danych i przekazanie jej do zmiennej data
    file = fopen("db.txt","r"); //r read
    if(file == NULL ) return NULL;
    fseek(file,0,SEEK_END); //ustawia pointer na koncu
    int length = (ftell(file)+1);
    fseek(file,0,SEEK_SET); //ustawia pointer na poczatku
    char *data = malloc(sizeof(char) * length); // przypisanie pamieci dla zmiennej data
    char c;
    int i = 0;
    while((c = fgetc(file)) != EOF){ // petla ktora zapisuje char po char do zmiennej data
        data[i] = c;
        i++;
    }
    data[i] = '\0'; // ustawienie wartosci NULL na koncu
    fclose(file);
    return data; // zwrocenie zmiennej data
}
void editFile(char **data,int ln){ // funkcja sluzaca do edycji pliku; dziala na zasadzie nadpisanie calego pliku nowymi danymi wszytanymi przez funkcje
    file=fopen("db.txt","w"); // otwarcie pliku w trybie w - write: nadpisz
    for(int i = 0;i<ln; i++){
        fprintf(file,"%s\n",data[i]);
    }
    fclose(file);
}
void delDataFile(char **data,int ln,int del){ // funkcja do usuniecia z bazy; dziala na podobnej zasadzie co editFile tylko ,ze nadpisuje danymi poza podanym wierszem
    file=fopen("db.txt","w"); // w napisuje
    for(int i = 0;i<ln; i++){
        if(i!=del){
            fprintf(file,"%s\n",data[i]);
        }

    }
    fclose(file);
}
void saveFile(char name[50],char surname[50],char age[3]){ // funkcja sluzaca do dodania wiersza do pliku
    file=fopen("db.txt","a"); // // otwarcie pliku w trybie a - append: dopisz na koncu
    fprintf(file,"%s, %s, %s\n",name,surname,age);
    fclose(file);
}
void saveTax(char name[50],char surname[50],char tax[3],bool a){
    file=fopen("tax.txt","a");

    if(a==true){
        file=fopen("tax.txt","w");
        fprintf(file,"%s","");
        fprintf(file,"%s %s podatek w wysoksci: %s\n",name,surname,tax);
    }
    else{
        fprintf(file,"%s %s podatek w wysoksci: %s\n",name,surname,tax);
    }

    fclose(file);
}
