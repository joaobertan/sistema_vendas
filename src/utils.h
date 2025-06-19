#ifndef UTILS_H
#define UTILS_H

#include "structs.h"

int warningLimit(char message[40], int size);
int warningEmpty(char message[40], int size);
int getIndexClient(Client clients[], int id);
int getLastIdClient(Client clients[], int size);
int getIndexProduct(Product products[], int id);
int getLastIdProduct(Product products[], int size);
int printDoubleLine();
int printSingleLine();
char* printCPFFormated(const char cpfOrigin[11]);

#endif //UTILS_H
