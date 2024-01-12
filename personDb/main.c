#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    char choice;
    char name[50];
    char surname[50];
    char age[3];
    showUi();
    do{
        scanf("%c", &choice);
        switch(choice){
            case '1':
                printf("\n");
                printf("Podaj imie osoby: ");
                scanf("%s", name);

                printf("\n");
                printf("Podaj nazwisko osoby: ");
                scanf("%s", surname);

                printf("\n");
                printf("podaj wiek: ");
                scanf("%s", age);

                addData(name,surname,age);
                system("cls");
                showUi();
                break;
            case '2':
                delData();
                system("cls");
                showUi();
                break;
            case '3':
                editData();
                system("cls");
                showUi();
                break;
            case '4':
                system("cls");
                showData();
                showUi();
                break;
            case '5':
                system("cls");
                u_sMgmt();
                showUi();
                break;

        }


    }while(choice!='6');
    return 0;
}
