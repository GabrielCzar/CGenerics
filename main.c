#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome_completo[100];
    char primeiro_nome[100];
    int numero;
    char email[100];
}Contato;

typedef struct{
    Contato vetor[100];
    int quantidade;
}Agenda;

    void menu(){
        printf("h - Help\n");
        printf("a - Adicionar Contato\n");
        printf("e - Excluir Contato\n");
        printf("m - Modificar um Contato\n");
        printf("b - Buscar Contato pelo primeiro nome\n");
        printf("l - Listar todos os Contatos\n");
        printf("s - Sair do programa\n");

    }

    void adicionar_contato(Agenda agenda){
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","a"); //Abrir o arquivo
    Contato contato;
    printf("Digite o nome completo:");
    scanf(" %[^\n]",contato.nome_completo);
    printf("Digite o número de telefone:");
    scanf("%d",&contato.numero);
    printf("Digite o e-mail:");
    scanf(" %[^\n]",contato.email);
        agenda.vetor[agenda.quantidade] = contato;
        agenda.quantidade++;
    fwrite(&contato,sizeof(Contato),1,arquivo);//escreve no arquivo

    fflush(arquivo);//Limpa memoria
    fclose(arquivo);//fecha o arquivo
    }

    void listar_contatos(Agenda agenda){
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","r"); //Abrir o arquivo
    Contato contato;
    int i = 1;
    while(i == 1){
        fread(&contato,sizeof(Contato),1,arquivo); //Lê todas linhas do arquivo
        if(!feof(arquivo)){ //enquanto não chegar no final do arquivo faça
            printf("\nNome completo: %s|Número de telefone: %d| E-mail: %s \n",contato.nome_completo,contato.numero,contato.email);
            }

        else{
            break;
        }
    }

    fclose(arquivo); //fechar arquivo
    }

    void modificar_contato(Agenda agenda){
        int i = 0;
        int y = 0;
        int numero;
        FILE *arquivo;
        arquivo = fopen("arquivo.txt","r");
        Contato troca[100];
        while(0 < 1){
            if (feof(arquivo)){
                break;
            }
            else{
                fread(&troca[i],sizeof(Contato),1,arquivo); //joga as informações para vetor troca
                i++;
                }
            }
        fclose(arquivo);
        printf("\nDigite o número do contato que deseja substituir:");
        scanf("%d",&numero);

        for(y=0; y<i-1; y++){ // i quantidade de linhas do arquivo
            if(numero == troca[y].numero){
                printf("Digite o nome completo:");
                scanf(" %[^\n]",troca[y].nome_completo);
                printf("Digite o número de telefone:");
                scanf("%d",&troca[y].numero);
                printf("Digite o e-mail:");
                scanf(" %[^\n]",troca[y].email);
            }
        }

    arquivo = fopen("arquivo.txt","w");
    for(y=0; y<i-1; y++){
        fwrite(&troca[y],sizeof(Contato),1,arquivo);
    }
    fclose(arquivo);
    }

    void excluir_contato(Agenda agenda){
        int i=0;
        int y=0;
        int numero;
        FILE *arquivo;
        arquivo = fopen("arquivo.txt","r");

        Contato remove[100];
        while(0 < 1){
            if(feof(arquivo)){
                break;
            }
        else{
            fread(&remove[i],sizeof(Contato),1,arquivo);
            i++;
            }
        }
    fclose(arquivo);
    printf("Digite o número do contato:");
    scanf("%d",&numero);
    arquivo = fopen("arquivo.txt","w");
    for(y=0; y<i-1; y++){
        if(numero != remove[y].numero){
            fwrite(&remove[y],sizeof(Contato),1,arquivo);
        }
    }
    if(ferror(arquivo)){
        printf("Erro");
    }
    else{
        printf("Fixado com sucesso\n");
    }
    fclose(arquivo);
    }

    void procurarPrimeiroNome(Agenda agenda){
        char primeiroNome[20];
        printf("Digite o primeiro nome:");
        scanf(" %[^\n]",primeiroNome);

        FILE *arquivo;
        arquivo = fopen("arquivo.txt","r"); //Abrir o arquivo

        Contato contato;
        int cont = 0;
        int i = 1;
        int j;

        while(i == 1){
            fread(&contato,sizeof(Contato),1,arquivo); //Lê todas linhas do arquivo
            if(!feof(arquivo)){ //enquanto não chegar no final do arquivo faça
                for(j = 0; j < strlen(primeiroNome); j++ ){
                    if(primeiroNome[j] == contato.nome_completo[j]){
                            cont++;
                    }
                    else{
                        break;
                    }
                    if(cont == strlen(primeiroNome)){
                        printf("\nNome completo: %s|Número de telefone: %d| E-mail: %s \n",contato.nome_completo,contato.numero,contato.email);
                    }
                }

            }

            else{
                break;
            }
        }
    }

    int main(){
    Agenda agenda;
    agenda.quantidade = 0;
    int i=1;
    while(i == 1){
    menu();
    char comando;
    scanf(" %c",&comando);
    switch (comando){
        case 'h':
        menu();
        break;
        case 'a':
        adicionar_contato(agenda);
        break;
        case 'e':
        excluir_contato(agenda);
        break;
        case 'm':
        modificar_contato(agenda);
        break;
        case 'b':
        procurarPrimeiroNome(agenda);
        break;
        case 'l':
        listar_contatos(agenda);
        break;
        case 's':
        i = 0;
        break;
        default:
        printf("Opção invalida\n");
        }
    }

return 0;
}
