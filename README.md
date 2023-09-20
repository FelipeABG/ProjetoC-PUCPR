# Programação Imperativa – Trabalho 1
## Prof. Alcides Calsavara – PUCPR

Uma loja possui um catálogo de produtos e uma lista de vendedores, sendo que:

- Cada produto é caracterizado por:
  - Um código (valor inteiro)
  - Um preço (valor real)
  - Uma descrição (uma string) – basta uma palavra

- Cada vendedor é caracterizado por:
  - Um código (valor inteiro)
  - Um nome (uma string) – basta uma palavra

Todas as vendas da loja em cada dia são registradas em um arquivo de “log”, sendo que cada linha do arquivo contém o seguinte:

- O código do vendedor que fez a venda
- O código do produto vendido
- O número de unidades vendidas do produto

Por exemplo, a linha com o conteúdo `54 89 4` indica a venda de 4 unidades do produto 89 pelo vendedor 54.

A loja tem interesse de, ao final do dia, saber o valor total geral vendido, bem como o valor total vendido por cada produto e, ainda, o valor total vendido por cada vendedor.

Escreva um programa na Linguagem C que:

1. Armazene em memória o log de vendas a partir de dados lidos de um arquivo texto denominado `vendas.txt`.
2. Armazene em memória o catálogo de produtos a partir de dados lidos de um arquivo texto denominado `produtos.txt`.
3. Armazene em memória a lista de vendedores a partir de dados lidos de um arquivo texto denominado `vendedores.txt`.
4. Calcule o total geral das vendas do dia, bem como o total vendido por produto e o total vendido por cada vendedor.
5. Grave todos os dados lidos e os totais calculados em um arquivo texto denominado `totais.txt`.

Os arquivos de entrada devem ter exatamente a forma mostrada no exemplo a seguir. Deve-se observar que a primeira linha de cada arquivo informa a quantidade de linhas restantes no arquivo, isto é, a quantidade de linhas efetivamente de dados. Cada linha de dados de um arquivo tem a seguinte forma:

- Arquivo `vendas.txt`:
  - código-do-vendedor código-do-produto unidades-vendidas

- Arquivo `produtos.txt`:
  - código-do-produto preço-do-produto descrição-do-produto

- Arquivo `vendedores.txt`:
  - código-do-vendedor nome-do-vendedor

Cada equipe de estudantes deverá criar os seus próprios arquivos de entrada, sendo o volume mínimo de dados de acordo com a seguinte tabela:

Arquivo | Número mínimo de linhas com dados
--- | ---
vendas.txt | 20
produtos.txt | 10
vendedores.txt | 5

Sugere-se usar os arquivos de entrada mostrados no exemplo a seguir para fins de validação do programa.

Na apresentação e defesa do programa, deverão ser usados os arquivos criados pela equipe de estudantes.

