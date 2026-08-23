#include <stdio.h>

int main(int argc, char** argv){
    FILE* arq;
    int total_linhas = 0;
    int c;
    
    if(argc != 2){
        printf("Erro na chamada do comando.\n");
        return 1;
    }

    arq = fopen(argv[1], "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    c = fgetc(arq);

    while (c != EOF){

        if (c == '\n'){
            total_linhas++;
        }

        c = fgetc(arq);

    }

    printf("Total de linhas: %d\n", total_linhas);
    fclose(arq);

    return 0;

}
