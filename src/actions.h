#ifndef ACTIONS_H
#define ACTIONS_H

#include "structs.h"

void createProduct(Product products[], int *size);
void createClient(Client clients[], int *size);
void makeSale(Sale sales[], int *size, Client clients[], int sizeClients, Product products[], int sizeProducts, SaledProducts saledProducts[], int *sizeSaledProducts);
void showSales(Sale sales[], int size, Client clients[], Product products[], SaledProducts saledProducts[], int sizeSaledProducts);
void listProducts(Product products[], int size);
void listClients(Client clients[], int size);
void deleteProduct(Product products[], int *size);
void deleteClient(Client clients[], int *size);
void updateProduct(Product products[], int size);
void updateClient(Client clients[], int size);

#endif //ACTIONS_H
