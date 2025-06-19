#include <stdio.h>

#include "actions.h"
#include "utils.h"
#include "structs.h"

void exibeMenuPrincipal();
void exibeMenuProdutos();
void exibeMenuClientes();
void exibeMenuVendas();

int main() {
    int opt = 0;

    Product products[10];
    int sizeProducts = 0;

    Client clients[10];
    int sizeClients = 0;

    Sale sales[10];
    int sizeSales = 0;

    SaledProducts saledProducts[100];
    int sizeSaledProducts = 0;

    do {
        exibeMenuPrincipal();
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                int optProdutos = 0;
                do {
                    exibeMenuProdutos();
                    scanf("%d", &optProdutos);

                    switch (optProdutos) {
                        case 1:
                            createProduct(products, &sizeProducts);
                            break;
                        case 2:
                            listProducts(products, sizeProducts);
                            break;
                        case 3:
                            updateProduct(products, sizeProducts);
                            break;
                        case 4:
                            deleteProduct(products, &sizeProducts);
                            break;
                    }
                } while (optProdutos != 0);
                break;
            }

            case 2: {
                int optClientes = 0;
                do {
                    exibeMenuClientes();
                    scanf("%d", &optClientes);

                    switch (optClientes) {
                        case 1:
                            createClient(clients, &sizeClients);
                            break;
                        case 2:
                            listClients(clients, sizeClients);
                            break;
                        case 3:
                            updateClient(clients, sizeClients);
                            break;
                        case 4:
                            deleteClient(clients, &sizeClients);
                            break;
                    }
                } while (optClientes != 0);
                break;
            }

            case 3: {
                int optVendas = 0;
                do {
                    exibeMenuVendas();
                    scanf("%d", &optVendas);

                    switch (optVendas) {
                        case 1:
                            makeSale(sales, &sizeSales, clients, sizeClients, products, sizeProducts, saledProducts, &sizeSaledProducts);
                            break;
                        case 2:
                            showSales(sales, sizeSales, clients, products, saledProducts, sizeSaledProducts);
                            break;
                    }
                } while (optVendas != 0);
                break;
            }
        }

    } while (opt != 999);

    return 0;
}

void exibeMenuPrincipal() {
    printDoubleLine();
    printf("Menu Principal - Escolha uma categoria:\n");
    printf(" 1 - Produtos\n");
    printf(" 2 - Clientes\n");
    printf(" 3 - Vendas\n");
    printf(" 999 - Sair do Sistema\n");
    printSingleLine();
}

void exibeMenuProdutos() {
    printDoubleLine();
    printf("Menu de Produtos:\n");
    printf(" 1 - Cadastrar Produto\n");
    printf(" 2 - Listar Produtos\n");
    printf(" 3 - Atualizar Produto\n");
    printf(" 4 - Deletar Produto\n");
    printf(" 0 - Voltar ao Menu Principal\n");
    printSingleLine();
}

void exibeMenuClientes() {
    printDoubleLine();
    printf("Menu de Clientes:\n");
    printf(" 1 - Cadastrar Cliente\n");
    printf(" 2 - Listar Clientes\n");
    printf(" 3 - Atualizar Cliente\n");
    printf(" 4 - Deletar Cliente\n");
    printf(" 0 - Voltar ao Menu Principal\n");
    printSingleLine();
}

void exibeMenuVendas() {
    printDoubleLine();
    printf("Menu de Vendas:\n");
    printf(" 1 - Realizar Venda\n");
    printf(" 2 - Listar Vendas\n");
    printf(" 0 - Voltar ao Menu Principal\n");
    printSingleLine();
}
