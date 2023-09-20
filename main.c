#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    float price;
} product;

typedef struct
{
    int id;
} seller;

int main()
{
    FILE *productsFile = fopen("files/produtos.txt", "r");
    FILE *sellersFile = fopen("files/vendedores.txt", "r");
    FILE *salesFile = fopen("files/vendas.txt", "r");

    int productsLines;
    int sellersLines;

    fscanf(productsFile, "%d", &productsLines);
    fscanf(sellersFile, "%d", &sellersLines);

    product products[productsLines];
    seller sellers[sellersLines];

    int id;
    int counter = 0;
    double price;
    char name[20];

    while (fscanf(productsFile, "%i%lf%s", &id, &price, name) != -1)
    {
        products[counter].id = id;
        products[counter].price = price;
        counter += 1;
    }

    counter = 0;

    while (fscanf(sellersFile, "%i%s", &id, name) != -1)
    {
        sellers[counter].id = id;
        counter += 1;
    }

    return 0;
}
