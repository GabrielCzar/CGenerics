#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void info_basic(){
    int x = 5; // Cria uma variavel do tipo INT
    void * y = &x; // Cria uma variavel do tipo VOID que recebe o endereco de X,
                    // Logo ponteiro void so armazena enderecos
    int * z; // Cria um ponteiro do tipo INT

    z = y; // Z recebe o endereco armazenado em Y
    * z = 9; // Z altera o valor do endereco armazenado

    printf("%d", x);
    // Saida sera 9
}

char * read_string(int size_string){
    char * string = malloc(sizeof(char) * size_string);
    fgets(string, size_string, stdin);
    return string;
}

int read_int(int * num){
    scanf("%d", num);
    return * num;
}

int get_value_inteiro (void * value){
    uintptr_t new_value = (uintptr_t) value; //converte para ponteiro
    int * value_final = (int *) new_value; //de ponteiro para int
    return * value_final;
}

float get_value_float (void * value){
    uintptr_t new_value = (uintptr_t) value; //converte para ponteiro
    float * value_final = (float *) new_value; //de ponteiro para float
    return * value_final;
}


char get_value_char (void * value){
    uintptr_t new_value = (uintptr_t) value; //converte para ponteiro
    char * value_final = (char *) new_value; //de ponteiro para char
    return * value_final;
}

char * get_value_string(void * value){
    return (char *) value;
}

int main()
{
    int tamanho = 4;
    void ** vet = (void **) malloc(sizeof(void) * tamanho);

    int tam_string = 20;

    vet[0] = read_string(tam_string);

    int n;
    read_int(&n);

    vet[1] = &n;

    float n2 = 2.5;
    vet[2] = &n2;

    char l = 'z';
    vet[3] = &l;

    printf("\n%s", get_value_string(vet[0]));

    printf("%d\n", get_value_inteiro(vet[1]));

    printf("%.2f\n", get_value_float(vet[2]));

    printf("%c", get_value_char(vet[3]));

    return 0;
}

