#include "functions.h"
#include "fileMenagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Person{ // utworzenie structa do obslugi osoby
    char name[50];
    char surname[50];
    char age[3];

};
struct U_S{
struct Person person;
char tax[3];
};

void showUi(){ // funkcja sluzaca do wyswietlenia interfejsu uzytkownika
    printf(" __________________________________________________\n");
    printf("|                                                  |\n");
    printf("|                   WYBIERZ OPCJE:                 |\n");
    printf("|            1. Dodaj osobe                        |\n");
    printf("|            2. Usun osobe                         |\n");
    printf("|            3. Edytuj osobe                       |\n");
    printf("|            4. Wyswietl osoby                     |\n");
    printf("|            5. Oblicz podatki                     |\n");
    printf("|            6. Wyjscie z programu                 |\n");
    printf("|__________________________________________________|\n");
}

void addData(char name[],char surname[],char age[]){ // funkcja sluzaca do dodania osoby do bazy, przyjmuje 3 tablice charow wypelnionych odpowiednimi danymi
    struct Person person; // deklaracja nowego structa typu Person

    strcpy(person.name,name);
    strcpy(person.surname,surname);   // 31-33: inicjalizacja structa typu Person
    strcpy(person.age,age);
    saveFile(person.name,person.surname,person.age); // wywylonie funkcji saveFile() z przekazaniem danych z structa

}
void showData(){ // funkcja sluzaca wyswietleniu danych
    char *data = readFile(); // deklaracja i inicjalizacja zmiennej data danymi po wywolaniu funkcji readFile()
    printf("%s",data); // wyswietlenie danych
    free(data); // uwolnienie przydzielonej pamieci data (readFile() zwraca dane z przydzielona pamiecia)
}
void editData(){ // funkcja sluzaca do edycji danych wybranego wierszu przez uzytkownika nowymi danymi wybranymi przez niego

    char *data = readFile();
    char *cols = strtok(data,"\n"); // wypelnienie pierwszego wiersza z wczytanego pliku
    int length = len(); // deklaracja i inicjalizacja zmiennej length danymi pop wywolaniu funkcji len()
    int i = 0;
    char *buf[length]; // utworzenie bufforu do edycji danych
    char name[150],surname[50],age[3];
    buf[0] = cols;
    printf("Ktora osobe chcesz edytowac:\n");
    while(cols != NULL){ // petla do zapelnienia bufforu wiersz po wierszu danymi

        buf[i] = cols;
        printf("%d. %s\n",(i+1),buf[i]);
        cols = strtok(NULL,"\n");
        i++;
    }
    int choice;
    scanf("%d",&choice);
    choice--;
    printf("\nPodaj imie osoby: ");
    scanf("%s", name);
    printf("\nPodaj nazwisko osoby: "); //60-67 wczytanie nowych danych od uzytkownika
    scanf("%s", surname);
    printf("\npodaj wiek: ");
    scanf("%s", age);
    strcat(name,", ");
    strcat(name,surname); // 68-71 sklejenie nowych danych w jeden wiersz
    strcat(name,", ");
    strcat(name,age);

    buf[choice] = name;
    editFile(buf,length); //73-74 nadpisanie podanego wszesniej wiersza nowym wierszem oraz przekazanie calego buffora finkcji editFile()
    free(data);
}
void delData(){ // funkcja do usuniecia wybranego wiersza; funkcja dziala na podobnej zasadzie co funkcja editData() z taka roznica ze zamiast do byforu wczytan nowy wiersz, pomija wybrany wiersz przy zapisie
    char *data = readFile();
    char *cols = strtok(data,"\n");
    int length = len();
    int i = 0;
    char *buf[length];
    int choice;
    buf[0] = cols;
    printf("Ktora osobe chcesz usunac:\n");
    while(cols != NULL){

        buf[i] = cols;
        printf("%d. %s\n",(i+1),buf[i]);
        cols = strtok(NULL,"\n");
        i++;
    }
    scanf("%d",&choice);
    choice--;
    delDataFile(buf,length,choice);
    free(data);
}

void u_sMgmt(){ // funkcja sluzy do obliczenia podatku dla osob z pliku db.txt oraz zapisanie wyniku w pliku tax.txt
    char *data = readFile();
    int length = len();
    char *cols = strtok(data,"\n");
    struct U_S us[length];
    int i = 0;
    bool a = true;
    char *buf[length];
    while(cols != NULL){

        buf[i] = cols;


        sscanf(buf[i], "%[^,], %[^,], %s", &us[i].person.name, &us[i].person.surname, &us[i].person.age);
        if(atoi(us[i].person.age)<26){
            strcpy(&us[i].tax,"0%");
        }
        else{
            strcpy(&us[i].tax,"32%");
        }

        saveTax(&us[i].person.name,&us[i].person.surname,&us[i].person.age,a);
        a=false;
        printf("%s %s podatek w wysoksci: %s\n", &us[i].person.name, &us[i].person.surname,&us[i].tax);
        cols = strtok(NULL,"\n");
        i++;
    }



    free(data);
}
