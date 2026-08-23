#include <stdio.h>

int main(int argc, char** argv){
    FILE* arq;
    int contagem[256] = {0};
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

        contagem[c]++;

        c = fgetc(arq);

    }

    for (int i = 0; i < 256; i++){
        if(((i>= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) && contagem[i] > 0){
            printf("Caractere '%c': %d Quantidade\n", i, contagem[i]);
        }

    }

    fclose(arq);

    return 0;

}
