#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco{
    char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main(int argc, char** argv){
    FILE *f;
    Endereco e;
    int c = 0;

    if(argc != 2){
        fprintf(stderr, "USO: %s [CEP]\n", argv[0]);
        return 1;
    }

    printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
	f = fopen("cep_ordenado.dat", "rb");

    if (f == NULL)
	{
		fprintf(stderr, "Erro ao abrir o arquivo.\n");
		return 1;
	}

    fseek(f, 0, SEEK_END);
	long tamanhoBytes = ftell(f);
	long tamanhoRegistros = tamanhoBytes / sizeof(Endereco);

    long inicio = 0;
	long fim = tamanhoRegistros - 1;
	long meio;
	int encontrado = 0;

    while (inicio <= fim)
	{
		c++;
		meio = (inicio + fim) / 2;

        fseek(f, meio * sizeof(Endereco), SEEK_SET);

        if (fread(&e, sizeof(Endereco), 1, f) == 1)
		{
			int comp = strncmp(argv[1], e.cep, 8);

			if (comp == 0)
			{
				printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",
				       e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
				encontrado = 1;
				break;
			}

            else if (comp < 0)
			{
				fim = meio - 1; 
			}
			else
			{
				inicio = meio + 1; 
			}
		}
    }

    if (!encontrado)
	{
		printf("CEP nao encontrado.\n");
	}

	printf("Total Lido (Acessos): %d\n", c);
	fclose(f);

	return 0;

}
