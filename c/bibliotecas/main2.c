#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    float valor;
    char c;
    char tp;
}Venda;

Venda vendas[100], novaV, vP, vendaMax;
int nV, o, i;
char tp, c;
float l, total;
bool enc = false;

void novaVenda(){

    nV = 0;

    if (nV == 100){
        printf("Limite de vendas alcancado\n");
        return;
    }

    printf("Valor total da venda: ");
    scanf("%f", &novaV.valor);

    printf("Categoria dos produtos vendidos A , B e C: \n");
    scanf("%c", &novaV.c);

    printf("Tipo de pagamento D - debito, C - credito ou P - PIX: \n");
    scanf("%c", &novaV.tp);

    vendas[nV++] = novaV;

    printf("Venda cadastrada !!!!\n");

    system("cls");
    
}

void listarVendas(){
    if (nV == 0){
        printf("Nenhuma venda realizada\n");
        return;
    }

    printf("Lista de venda: \n");
    for(i = 0; i < nV; i++){
        printf("Venda %i: \n", i++);
        printf(" Valor: %.2f\n", vendas[i].valor);
        printf(" Categoria: %c\n", vendas[i].c);
        printf(" Tipo de pagamento: %c\n", vendas[i].tp);
        printf("\n");
    }

    system("cls");
    
}

void listarVendasC(){
    printf("Informe a categoria A, B ou C: ");
    scanf("%c", &c);

    printf("Vendas da Categoria %c: \n", c);

    for(i = 0; i < nV; i++){
        if (vendas[i].c == c){
            printf("Vendas %i: \n", i++);
            printf(" Valor: %.2f\n",vendas[i].valor);
            printf(" Tipo de pagamento: %c\n", vendas[i].tp);
            printf("\n");
            enc = true;
        }

        if (!enc){
            printf("Nenhuma venda encotrada para %c\n", c);
        }

        system("cls");
        
    }
}

void totalVendasP(){

    total = 0;

    printf("Informe o tipo de pagamento D - debito, C - credito ou P - Pix: ");
    scanf("%c", &tp);

    for(i = 0; i < nV; i++){
        if(vendas[i].tp == tp){
            total += vendas[i].valor;
        }
    }

    printf("Total de vendas para o tipo de pagamento %c: %.2f\n", tp, total);

    system("cls");

}

void lucrTotal(){

    l = 0;

    for(i = 0; i < nV; i++){
        l += vendas[i].valor;
    }

    printf("Lucro total das vendas: %.2f\n", l);

    system("cls");

}

void maiorVenda(){
    if (nV == 0){
        printf("Nenhuma venda realizada\n");
        return;
    }

    vendaMax = vendas[0];

    for(i = 0; i < nV; i++){
        if(vendas[i].valor > vendaMax.valor){
            vendaMax = vendas[i];
        }
    }

    printf("Maior venda realizada: \n");
    printf(" Valor: %.2f\n", vendaMax.valor);
    printf(" Categoria: %c\n", vendaMax.c);
    printf(" Tipo de pagamento: %c\n", vendaMax.tp);

    system("cls");
    
}

void menorVP(){
    if( nV == 0){
        printf("Nenhuma venda realizada\n");
        return;
    }

    for(i = 0; i < nV; i++){
        if(vendas[i].tp == 'P'){
            if(!enc || vendas[i].valor < vP.valor){
                vP = vendas[i];
                enc = true;
            }
        }
    }

    if(enc){
        printf("Menor venda realizada via PIX:\n");
        printf(" Valor: %.2f\n", vP.valor);
        printf(" Categoria: %c\n", vP.c);
    }

    else{
        printf("nenhuma venda realizada via PIX\n");
    }

    system("cls");
}

int main(){

    do{
        
        printf(" 1 - Cadastrar nova venda\n");
        printf(" 2 - Listar todas as vendas realizadas\n");
        printf(" 3 - Listar vendas por categoria\n");
        printf(" 4 - Apresentar o total de vendas realizadas, dado um tipo de pagamento selecionado\n");
        printf(" 5 - Apresentar o lucro total das vendas\n");
        printf(" 6 - Apresentar os dados da maior venda realizada\n");
        printf(" 7 - Apresentar os dados da menor venda realizada via PIX\n");
        printf(" 8 - Sair\n");

        printf("escolha uma opcao: ");
        scanf("%i", &o);

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
            listarVendasC();
            break;

        case 4:
            system("cls");
            totalVendasP();
            break;

        case 5:
            system("cls");
            lucrTotal();
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
            printf("encerrando o programa......");
            break;
        
        default:
            system("cls");
            printf("Erro, tente novamente.....");
        }
    } while (o =! 8);
    

    return 0;
}