#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    float price;
    double amountSold;
} product;

typedef struct
{
    int id;
    double totalSales;
} seller;

int main()
{

    system("clear");

    FILE *productsFile = fopen("files/produtos.txt", "r");
    FILE *sellersFile = fopen("files/vendedores.txt", "r");
    FILE *salesFile = fopen("files/vendas.txt", "r");
    FILE *totalsFile = fopen("files/totais.txt", "w");

    int productsLines, sellersLines, salesLines;

    fscanf(productsFile, "%d", &productsLines);
    fscanf(sellersFile, "%d", &sellersLines);
    fscanf(salesFile, "%d", &salesLines);

    product products[productsLines];
    seller sellers[sellersLines];

    int id;
    int counter = 0;
    double price;
    char name[15];

    fprintf(totalsFile, "Catálogo de produtos:\n");
    while (fscanf(productsFile, "%i%lf%s", &id, &price, name) != -1)
    {
        fprintf(totalsFile, "[%d] %d %.2f %s\n", counter, id, price, name);
        products[counter].id = id;
        products[counter].price = price;
        products[counter].amountSold = 0;
        counter += 1;
    }

    counter = 0;

    fprintf(totalsFile, "\nLista de vendedores:\n");
    while (fscanf(sellersFile, "%i%s", &id, name) != -1)
    {
        fprintf(totalsFile, "[%d] %d %s\n", counter, id, name);
        sellers[counter].id = id;
        sellers[counter].totalSales = 0;
        counter += 1;
    }

    counter = 0;

    int sellerID, productID, quantity;
    double total = 0;

    fprintf(totalsFile, "\nLog de Vendas:\n");
    while (fscanf(salesFile, "%d%d%d", &sellerID, &productID, &quantity) != -1)
    {
        fprintf(totalsFile, "[%d] %d %d %d\n", counter, sellerID, productID, quantity);
        for (int i = 0; i < productsLines; i++)
        {
            if (products[i].id == productID)
            {
                total += products[i].price * quantity;
                products[i].amountSold += quantity * products[i].price;
            }
        }

        for (int i = 0; i < sellersLines; i++)
        {
            if (sellers[i].id == sellerID)
            {
                for (int j = 0; j < productsLines; j++)
                {
                    if (products[j].id == productID)
                    {
                        sellers[i].totalSales += products[j].price * quantity;
                    }
                }
            }
        }
        counter++;
    }

    fprintf(totalsFile, "\nTotal geral vendido: %.2f\n", total);

    rewind(productsFile);
    fscanf(productsFile, "%d", &productsLines);
    counter = 0;

    fprintf(totalsFile, "\nTotal de vendas de cada produto:\n");
    while (fscanf(productsFile, "%d%lf%s", &id, &price, name) != -1)
    {
        fprintf(totalsFile, "Produto %d (%s): R$%.2lf\n", id, name, products[counter].amountSold);
        counter++;
    }

    rewind(sellersFile);
    fscanf(sellersFile, "%d", &sellersLines);
    counter = 0;

    fprintf(totalsFile, "\nTotal de vendas de cada vendedor:\n");
    while (fscanf(sellersFile, "%d%s", &id, name) != -1)
    {
        fprintf(totalsFile, "Vendedor %d (%s): R$%.2lf\n", id, name, sellers[counter].totalSales);
        counter++;
    }

    return 0;
}
