#include <stdio.h>

#include "utils.h"
#include "structs.h"

int warningLimit(char message[40], int size) {
    if (size >= 10) {
        printf("%s\n",message);
        return 1;
    }

    return 0;
}

int warningEmpty(char message[40], int size) {
    if (size == 0) {
        printf("%s\n",message);
        return 1;
    }

    return 0;
}

int getIndexClient(Client clients[], int id) {
    for (int i = 0; i < 10; i++) {
        if (clients[i].id == id) return i;
    }

    return -1;
}

int getLastIdClient(Client clients[], int size) {
    if (size == 0) return 0;
    return clients[size - 1].id;
}

int getIndexProduct(Product products[], int id) {
    for (int i = 0; i < 10; i++) {
        if (products[i].id == id) return i;
    }

    return -1;
}

int getLastIdProduct(Product products[], int size) {
    if (size == 0) return 0;
    return products[size - 1].id;
}

int printDoubleLine() {
    for (int i = 0; i < 15; i++) {
        printf("=");
    }
    printf("\n");
    return 0;
}

int printSingleLine() {
    for (int i = 0; i < 15; i++) {
        printf("-");
    }
    printf("\n");
    return 0;
}

char* printCPFFormated(const char cpfOrigin[11]) {
    static char cpfFormated[15];

    sprintf(cpfFormated, "%.3s.%.3s.%.3s-%.2s",
            cpfOrigin,
            cpfOrigin + 3,
            cpfOrigin + 6,
            cpfOrigin + 9);

    return cpfFormated;
}
