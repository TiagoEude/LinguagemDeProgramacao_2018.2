#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int relatorioMensal ();
int relatorioCategoria ();
void gerarRelatorioCategoria (char *, int);

int relatorioMensal () {
}

int relatorioCategoria () {
    char entradaRelatorios;
    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";
    do {
    	printf ("\e[H\e[2J");
    	printf ("\n----RELATORIOS----\n");
    	printf("\n[1] GASTOS.\n");
    	printf("\n[2] RECEBIDOS.\n");
    	printf("\n[3] INVESTIMENTOS.\n");
        printf("\n[0] VOLTAR.\n");
    	printf("\nDIGITE: ");
    	entradaRelatorios = getchar (); 
    	switch (entradaRelatorios) {
            case '0':
                return 0;
                break;
    		case '1':
    			gerarRelatorioCategoria (gastos, 4);
    			break;
    		case '2':
    			gerarRelatorioCategoria (recebidos, 3);
    			break;
    		case '3':
    			gerarRelatorioCategoria (investimentos, 3);
    			break;
    		default:
    			printf ("\e[H\e[2J");
    			printf ("\n----RELATORIOS----\n");
    			printf ("\nVALOR INCORRETO.\n");
    			for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
    	}
	} while (true); 
}

void gerarRelatorioCategoria (char *categoria, int colunas) {
    FILE *ptrArquivoDoUsuario;
    FILE *ptrRelatorio;
	char *chave;
	char *dados;
    char tipoArquivo[] = ".txt";
    char *nomeDoArquivo;

	if ((chave = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((dados = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((nomeDoArquivo = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
	if ((ptrArquivoDoUsuario = fopen (enderecoArquivo, "r")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
	}
    strcpy (nomeDoArquivo, categoria);
    strcat (nomeDoArquivo, tipoArquivo);
    if ((ptrRelatorio = fopen (nomeDoArquivo, "w")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
	}
	while (!feof (ptrArquivoDoUsuario)) {
        fscanf (ptrArquivoDoUsuario, "%s", chave);
		if (!(strcmp (chave, categoria))) {
            for (int i = 0; i < colunas; i++) {
                fprintf (ptrRelatorio, "%s", "|");
                fscanf (ptrArquivoDoUsuario, "%s", dados);
                fprintf (ptrRelatorio, "%s ", dados);
            }
            fprintf (ptrRelatorio, "%s", "|");
            fprintf (ptrRelatorio, "%s","\n");
        }
	}
	fclose (ptrArquivoDoUsuario);
    fclose (ptrRelatorio);
    free (chave);
    free (dados);
    free (nomeDoArquivo);
	printf ("\e[H\e[2J");
    printf ("\n----RELATORIOS----\n");
    printf("\nRELATORIO GERADO COM SUCESSO.\n");
    for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
}