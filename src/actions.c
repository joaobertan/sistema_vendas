#include <stdio.h>
#include <string.h>

#include "actions.h"
#include "utils.h"
#include "structs.h"

void createProduct(Product products[], int *size) {
    if (warningLimit("Limite de produtos atingido!", *size)) return;

    printSingleLine();
    printf("Digite a descrição do produto:\n");
    scanf("%s", products[*size].descr);

    printf("Digite o preço do produto:\n");
    scanf("%f", &products[*size].price);

    products[*size].id = getLastIdProduct(products, *size) + 1;

    printf("Produto cadastrado com sucesso!\n");

    (*size)++;
}

void createClient(Client clients[], int *size) {
    if (warningLimit("Limite de clientes atingido!", *size)) return;

    printSingleLine();
    printf("Digite o nome do cliente:\n");
    scanf("%s", clients[*size].name);

    printf("Digite o cpf do cliente (sem pontos):\n");
    scanf("%s", clients[*size].cpf);

    clients[*size].id = getLastIdClient(clients, *size) + 1;

	printf("Cliente cadastrado com sucesso!\n");

	(*size)++;
}

void makeSale(Sale sales[], int *size, Client clients[], int sizeClients, Product products[], int sizeProducts, SaledProducts saledProducts[], int *sizeSaledProducts) {
    if (warningLimit("Limite de vendas atingido!", *size)) return;

    int id_client, id_product, n_products, qtd;

    for (int i = 0; i < 10; i++) {
        sales[*size].saled_products_id[i] = 0;
    }

    listClients(clients, sizeClients);
    printSingleLine();
    printf("Selecione um cliente:\n");
    scanf("%d", &id_client);

    n_products = 0;
    do {
        listProducts(products, sizeProducts);
        printf("999 - Sair\n");
        printf("Selecione o produto:\n");

        scanf("%d", &id_product);

        if (id_product == 999) break;

        printf("Digite a quantidade:\n");
        scanf("%d", &qtd);

        saledProducts[*sizeSaledProducts].id = *sizeSaledProducts + 1;
        saledProducts[*sizeSaledProducts].id_product = id_product;
        saledProducts[*sizeSaledProducts].qtd_products = qtd;
        saledProducts[*sizeSaledProducts].id_sale = *size + 1;

        int indexProduct = getIndexProduct(products, id_product);
        saledProducts[*sizeSaledProducts].price = products[indexProduct].price;

        sales[*size].saled_products_id[n_products] = saledProducts[*sizeSaledProducts].id;

        (*sizeSaledProducts)++;
        n_products++;

        if (n_products >= 10) break;

    } while (id_product != 999);

    sales[*size].id_cliente = id_client;
    sales[*size].id = *size + 1;
    (*size)++;

    printf("Venda cadastrada com sucesso!\n");
}

void showSales(Sale sales[], int size, Client clients[], Product products[], SaledProducts saledProducts[], int sizeSaledProducts) {
    int clientIndex, saledProductIndex, productIndex;
    float total;

    if (warningEmpty("Nenhuma venda cadastrada ainda.", size)) return;

    printSingleLine();
    for (int i = 0; i < size; i++) {
        printf("Venda código %d\n", sales[i].id);

        clientIndex = getIndexClient(clients, sales[i].id_cliente);
        printf("Cliente: %d - %s\n", sales[i].id_cliente, clients[clientIndex].name);

        printf("Produtos:\n");
        total = 0;

        for (int j = 0; j < 10; j++) {
            int saledProductId = sales[i].saled_products_id[j];
            if (saledProductId <= 0) break;

            for (int k = 0; k < sizeSaledProducts; k++) {
                if (saledProducts[k].id == saledProductId) {
                    saledProductIndex = k;

                    productIndex = getIndexProduct(products, saledProducts[saledProductIndex].id_product);
                    float subtotal = saledProducts[saledProductIndex].qtd_products * saledProducts[saledProductIndex].price;

                    printf("%d - %s - Qtd: %d - Preço Unit: R$%.2f - Subtotal: R$%.2f\n",
                           saledProducts[saledProductIndex].id,
                           products[productIndex].descr,
                           saledProducts[saledProductIndex].qtd_products,
                           saledProducts[saledProductIndex].price,
                           subtotal
                    );

                    total += subtotal;
                    break;
                }
            }
        }

        printf("Total da venda: R$%.2f\n", total);
        printSingleLine();
    }
}


void listProducts(Product products[], int size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", size)) return;

    printSingleLine();
    printf("\nLista de Produtos Cadastrados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s: R$%.2f\n", products[i].id, products[i].descr, products[i].price);
    }
}

void listClients(Client clients[], int size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", size)) return;

    printSingleLine();
    printf("Lista de clientes Cadastrados:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s - %s\n", clients[i].id, clients[i].name, printCPFFormated(clients[i].cpf));
    }
}

void deleteProduct(Product products[], int *size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", *size)) return;

    int idToDelete, indexToDelete;

    listProducts(products, *size);
    printf("Digite o código para excluir:\n");
    scanf("%d", &idToDelete);
    indexToDelete = getIndexProduct(products, idToDelete);

    for(int i = indexToDelete; i < *size - 1; i++) {
        products[i] = products[i + 1];
    };

    (*size)--;
}

void deleteClient(Client clients[], int *size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", *size)) return;

    int idToDelete, indexToDelete;

    listClients(clients, *size);
    printf("Digite o código para excluir:\n");
    scanf("%d", &idToDelete);
    indexToDelete = getIndexClient(clients, idToDelete);

    for(int i = indexToDelete; i < *size - 1; i++) {
        clients[i] = clients[i + 1];
    };

    (*size)--;
}

void updateProduct(Product products[], int size) {
    if (warningEmpty("Nenhum produto cadastrado ainda.", size)) return;

    int idToUpdate, indexToUpdate;
    char newDescr[20];
	float newPrice;

    listProducts(products, size);
    printf("Digite o código para atualizar:\n");
    scanf("%d", &idToUpdate);
    indexToUpdate = getIndexProduct(products, idToUpdate);
    printf("Digite a descrição do produto:\n");
    scanf("%s", newDescr);
    printf("Digite o preço do produto:\n");
    scanf("%f", &newPrice);
    strcpy(products[indexToUpdate].descr, newDescr);
    products[indexToUpdate].price = newPrice;
}

void updateClient(Client clients[], int size) {
    if (warningEmpty("Nenhum cliente cadastrado ainda.", size)) return;

    int idToUpdate, indexToUpdate;
    char newName[20];

    listClients(clients, size);
    printf("Digite o código para atualizar:\n");
    scanf("%d", &idToUpdate);
    indexToUpdate = getIndexClient(clients, idToUpdate);
    printf("Digite o nome do cliente:\n");
    scanf("%s", newName);
    strcpy(clients[indexToUpdate].name, newName);
}