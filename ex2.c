#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_C 50
#define MAX_N 50
#define MAX_E 50
#define MAX_T 12

struct Contato{
    int id;
    char nome[MAX_N];
    char email[MAX_E];
    char telefone[MAX_T];
};

struct Contato agenda[MAX_C], contato, novoC;
int tcontato = 0, i, ta, arroba, pont, enc, o;
char emailBusca[MAX_E],nomeBusca[MAX_N], ddd[4], inc;

int gerarId() {
    return tcontato + 1;
}

int validarEmail(const char* email) {
     ta = strlen(email);
     arroba = -1, pont = -1;
    
    if (ta < 5){
        return 0;
    }

    for (i = 0; i < ta; i++) {
        if (email[i] == '@') {
            arroba = i;
            break;
        }
    }
    
    if (arroba == -1 || arroba == 0 || arroba >= ta - 4)
        return 0;

    for (i = arroba + 1; i < ta; i++) {
        if (email[i] == '.') {
            pont = i;
            break;
        }
    }
    
    if (pont == -1 || pont == arroba + 1 || pont >= ta - 1)
        return 0;

    return 1;
}

int Telefone(const char* telefone) {
    int ta = strlen(telefone);
    int i;
    
    if (ta != 11){
        return 0;
    }

    for (i = 0; i < ta; i++) {
        if (!isdigit(telefone[i])){
            return 0;
        }
    }

    return 1;
}

void Cadastro(){
    if (tcontato >= MAX_C) {
        printf("A agenda de contatos esta cheia!\n");
        return;
    }


    printf("Nome: ");
    fgets(novoC.nome, MAX_N, stdin);
    novoC.nome[strcspn(novoC.nome, "\n")] = '\0';

    if (strlen(novoC.nome) == 0) {
        printf("O nome nao pode ser vazio!\n");
        return;
    }

    printf("E-mail: ");
    fgets(novoC.email, MAX_E, stdin);
    novoC.email[strcspn(novoC.email, "\n")] = '\0';

    if (!validarEmail(novoC.email)) {
        printf("O email inserido nao e valido!\n");
        return;
    }

    printf("Telefone: ");
    fgets(novoC.telefone, MAX_T, stdin);
    novoC.telefone[strcspn(novoC.telefone, "\n")] = '\0';

    if (!Telefone(novoC.telefone)) {
        printf("O telefone inserido nao e valido!\n");
        return;
    }

    novoC.id = gerarId();
    agenda[tcontato++] = novoC;

    printf("Contato cadastrado com sucesso!\n");
}

void listarContatos() {

    if (tcontato == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("Lista de contatos:\n");
    for (i = 0; i < tcontato; i++) {
        contato = agenda[i];
        printf(" ID: %d\n", contato.id);
        printf(" Nome: %s\n", contato.nome);
        printf(" Email: %s\n", contato.email);
        printf(" Telefone: %s\n\n", contato.telefone);
    }
}

void buscaNome(){
    enc = 0;

    printf("Digite o nome para buscar: ");
    fgets(nomeBusca, MAX_N, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remove o caractere '\n' da string

    for (i = 0; i < tcontato; i++) {
        contato = agenda[i];
        if (strcmp(contato.nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("ID: %d\n", contato.id);
            printf("Nome: %s\n", contato.nome);
            printf("Email: %s\n", contato.email);
            printf("Telefone: %s\n", contato.telefone);
            enc = 1;
            break;
        }
    }

    if (!enc)
        printf("Nenhum contato encontrado com esse nome.\n");
}

void buscaEmail(){

    printf("Digite o email para buscar: ");
    fgets(emailBusca, MAX_E, stdin);
    emailBusca[strcspn(emailBusca, "\n")] = '\0'; // Remove o caractere '\n' da string

    for (i = 0; i < tcontato; i++) {
        contato = agenda[i];
        if (strcmp(contato.email, emailBusca) == 0) {
            printf("Contato encontrado:\n");
            printf(" ID: %d\n", contato.id);
            printf(" Nome: %s\n", contato.nome);
            printf(" Email: %s\n", contato.email);
            printf(" Telefone: %s\n", contato.telefone);
            enc = 1;
            break;
        }
    }

    if (!enc)
        printf("Nenhum contato encontrado com esse email.\n");
}

void buscaInicial(){
    enc = 0;

    printf("Digite a inc para buscar contatos: ");
    scanf(" %c", &inc);

    printf("Contatos encontrados com a inc '%c':\n", inc);
    for (i = 0; i < tcontato; i++) {
        contato = agenda[i];
        if (toupper(contato.nome[0]) == toupper(inc)) {
            printf(" ID: %d\n", contato.id);
            printf(" Nome: %s\n", contato.nome);
            printf(" Email: %s\n", contato.email);
            printf(" Telefone: %s\n\n", contato.telefone);
            enc = 1;
        }
    }

    if (!enc){
        printf("Nenhum contato encontrado com essa inc.\n");
    }
}

void DDD(){
    enc = 0;

    printf("Digite o DDD para listar contatos: ");
    fgets(ddd, 4, stdin);

    printf("Contatos com DDD %s:\n", ddd);
    for (i = 0; i < tcontato; i++) {
        contato = agenda[i];
        if (strncmp(contato.telefone, ddd, 2) == 0) {
            printf(" ID: %d\n", contato.id);
            printf(" Nome: %s\n", contato.nome);
            printf(" Email: %s\n", contato.email);
            printf(" Telefone: %s\n\n", contato.telefone);
            enc = 1;
        }
    }

    if (!enc){
        printf("Nenhum contato encontrado com esse DDD.\n");
    }
}

int main() {

    do {
         printf("\n---- Agenda de Contatos ----\n");
        printf("\n 1 - Cadastrar novo contatoa\n");
        printf("\n 2 - Listar todos os contatos cadastrados\n");
        printf("\n 3 - Apresentar a quantidade de contatos cadastrados\n");
        printf("\n 4 - Buscar um contatos por nome\n");
        printf("\n 5 - Buscar contatos por e-mail\n");
        printf("\n 6 - Buscar contatos por inicial\n");
        printf("\n 7 - Listar todos os contatos de um mesmo DDD\n");
        printf("\n 8 - Sair\n");

        printf("\n escolha uma opcao: ");
        scanf("%i", &o);

        getchar();

        switch (o){
            case 1:
                system("cls");
                Cadastro();
                break;
            case 2:
                system("cls");
                listarContatos();
                break;
            case 3:
            system("cls");
                printf("Total de contatos cadastrados: %d\n", tcontato);
                break;
            case 4:
                system("cls");
                buscaNome();
                break;
            case 5:
                system("cls");
                buscaEmail();
                break;
            case 6:
                system("cls");
                buscaInicial();
                break;
            case 7:
                system("cls");
                DDD();
                break;
            case 8:
                system("cls");
                printf("Encerrando o programa...\n");
                break;
            default:
                system("cls");
                printf("o invalida! Digite um numero de 1 a 8.\n");
                break;
        }

        printf("\n");
    } while (o != 8);

    return 0;
}