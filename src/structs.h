#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int id;
    char descr[20];
    float price;
} Product;

typedef struct {
    int id;
    char name[20];
    char cpf[11];
} Client;

typedef struct {
    int id;
    int saled_products_id[10];
    int id_cliente;
} Sale;

typedef struct {
    int id;
    int id_sale;
    int id_product;
    int qtd_products;
    float price;
} SaledProducts;

#endif //STRUCTS_H
