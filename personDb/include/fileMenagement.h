#ifndef FILEMENAGEMENT_H
#define FILEMENAGEMENT_H

int len();
char *readFile();
void editFile(char **data,int ln);
void delDataFile(char **data,int ln,int del);
void saveFile(char name[50],char surname[50],char age[3]);//temp

#endif // FILEMENAGEMENT_H
