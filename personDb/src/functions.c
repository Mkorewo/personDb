#include "functions.h"
#include "fileMenagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person{
    char name[50];
    char surname[50];
    char age[3];
};

/*
struct Zespol {



Person** arrPersons;

};
void dodajPerson(Person **arr);
void dodajDoZespo(Zespol*);
*/


void showUi(){
    printf(" __________________________________________________\n");
    printf("|                                                  |\n");
    printf("|                   WYBIERZ OPCJE:                 |\n");
    printf("|            1. Dodaj osobe                        |\n");
    printf("|            2. Usun osobe                         |\n");
    printf("|            3. Edytuj osobe                       |\n");
    printf("|            4. Wyswietl osoby                     |\n");
    printf("|            5. Wyjscie z programu                 |\n");
    printf("|__________________________________________________|\n");
}

void addData(char name[],char surname[],char age[]){
    struct Person person;

    strcpy(person.name,name);
    strcpy(person.surname,surname);
    strcpy(person.age,age);
    saveFile(person.name,person.surname,person.age);

}
void showData(){
    char *data = readFile();
    printf("%s",data);
    free(data);
}
void editData(){

    char *data = readFile();
    char *cols = strtok(data,"\n");
    int length = len();
    int i = 0;
    char *buf[length];
    char name[50],surname[50],age[3];
    buf[0] = cols;
    printf("Ktora osobe chcesz edytowac:\n");
    while(cols != NULL){

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
    printf("\nPodaj nazwisko osoby: ");
    scanf("%s", surname);
    printf("\npodaj wiek: ");
    scanf("%s", age);
    strcat(name,", ");
    strcat(name,surname);
    strcat(name,", ");
    strcat(name,age);

    buf[choice] = name;
    editFile(buf,length);
}
void delData(){
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
}
