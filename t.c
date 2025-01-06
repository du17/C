#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    float valor;
    char c;
    char tp;
}Venda;

Venda vendas[MAX], novaV, vP, vendaMax;
int nV, o, i;
char tp, c;
float l, total;
bool enc = false;


void novaVenda(){

    nV = 0;

    if (nV == MAX){
        printf("Limite de vendas alcançado.\n");
        return;
    }

    printf("Valor total da venda: ");
    scanf("%f", &novaV.valor);

    printf("Categoria dos produtos vendidos (A, B ou C): ");
    scanf(" %c", &novaV.c);

    printf("Tipo de pagamento (D - debito, C - credito ou P - pix): ");
    scanf(" %c", &novaV.tp);

    vendas[nV++] = novaV;

    printf("Venda cadastrada com sucesso.\n");

    system("cls");
}

void listarVendas(){
    if (nV == 0){
        printf("Nenhuma venda realizada.\n");
        return;
    }

    printf("Lista de vendas:\n");
    for (i = 0; i < nV; i++){
        printf("Venda %d:\n", i + 1);
        printf("  Valor: %.2f\n", vendas[i].valor);
        printf("  Categoria: %c\n", vendas[i].c);
        printf("  Tipo de pagamento: %c\n", vendas[i].tp);
        printf("\n");
    }

    system("cls");
}

void listarVendac(){
    printf("Informe a Categoria (A, B ou C): ");
    scanf(" %c", &c);

    printf("Vendas da Categoria %c:\n", c);

    for (int i = 0; i < nV; i++){
        if (vendas[i].c == c){
            printf("Venda %d:\n", i + 1);
            printf("  Valor: %.2f\n", vendas[i].valor);
            printf("  Tipo de pagamento: %c\n", vendas[i].tp);
            printf("\n");
            enc = true;
        }
    }

    if (!enc){
        printf("Nenhuma venda encontrada para a categoria %c.\n", c);
    }

    system("cls");
}

void totalVendasP(){

    total = 0;

    printf("Informe o tipo de pagamento (D - debito, C - credito ou P - pix): ");
    scanf(" %c", &tp);


    for (int i = 0; i < nV; i++){
        if (vendas[i].tp == tp){
            total += vendas[i].valor;
        }
    }

    printf("Total de vendas para o tipo de pagamento %c: %.2f\n", tp, total);

    system("cls");
}

void lucroTotal(){

    l = 0;

    for (int i = 0; i < nV; i++){
        l += vendas[i].valor;
    }

    printf("Lucro total das vendas: %.2f\n", l);

    system("cls");
}

void maiorVenda() {
    if (nV == 0){
        printf("Nenhuma venda realizada.\n");
        return;
    }

    vendaMax = vendas[0];

    for (int i = 1; i < nV; i++){
        if (vendas[i].valor > vendaMax.valor){
            vendaMax = vendas[i];
        }
    }

    printf("Maior venda realizada:\n");
    printf("  Valor: %.2f\n", vendaMax.valor);
    printf("  Categoria: %c\n", vendaMax.c);
    printf("  Tipo de pagamento: %c\n", vendaMax.tp);

    system("cls");
}

void menorVP(){
    if (nV == 0){
        printf("Nenhuma venda realizada.\n");
        return;
    }

    for (int i = 0; i < nV; i++){
        if (vendas[i].tp == 'P'){
            if (!enc || vendas[i].valor < vP.valor){
                vP = vendas[i];
                enc = true;
            }
        }
    }

    if (enc){
        printf("Menor venda realizada via PIX:\n");
        printf("  Valor: %.2f\n", vP.valor);
        printf("  Categoria: %c\n", vP.c);
    } 
    
    else{
        printf("Nenhuma venda realizada via PIX.\n");
    }

    system("cls");
}

int main(){

    do{

        printf("1. Cadastrar nova venda\n");
        printf("2. Listar todas as vendas realizadas\n");
        printf("3. Listar vendas por categoria\n");
        printf("4. Apresentar o total de vendas realizadas, dado um tipo de pagamento selecionado\n");
        printf("5. Apresentar o lucro total das vendas\n");
        printf("6. Apresentar os dados da maior venda realizada\n");
        printf("7. Apresentar os dados da menor venda realizada via PIX\n");
        printf("8. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &o);

        switch (o){
            case 1:
                system("cls");
                novaVenda();
                break;
            case 2:
                system("cls");
                listarVendas();
                break;
            case 3:
                system("cls");
                listarVendac();
                break;
            case 4:
                system("cls");
                totalVendasP();
                break;
            case 5:
                system("cls");
                lucroTotal();
                break;
            case 6:
                system("cls");
                maiorVenda();
                break;
            case 7:
                system("cls");
                menorVP();
                break;
            case 8:
                system("cls");
                printf("Encerrando o programa.\n");
                break;
            default:
                system("cls");
                printf("Erro, opcao invalida\n");
        }

    }while (o != 8);

    return 0;
}