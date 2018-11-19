#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int dia;
    int mes;
    int ano;
    char categoria[101];
    char descricao[101];
    double valor;
    char local[101];
} DADOS;

int consultar (char*, int);
int cadastrar (char*);

int consultar (char* categoria, int colunas) {
	FILE *ptrArquivoDoUsuario;
	char *chave;
	char *dados;
    int entradaConsiltar;

	if ((chave = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((dados = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
	if ((ptrArquivoDoUsuario = fopen (enderecoArquivo, "r")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
	}
    system ("cls");
    printf ("\n----%s----\n",categoria);
    printf ("\nDIGITE [0] PARA VOLTAR.\n");
	while (!feof (ptrArquivoDoUsuario)) {
        fscanf (ptrArquivoDoUsuario, "%s", chave);
		if (!(strcmp (chave, categoria))) {
            for (int i = 0; i < colunas; i++) {
                if (feof(ptrArquivoDoUsuario) != 0)
                    break;
                printf ("|");
                fscanf (ptrArquivoDoUsuario, "%s", dados);
                printf ("%s ", dados);
            }
            if (feof(ptrArquivoDoUsuario) != 0)
                    break;
            printf ("|");
            printf ("\n");
        }
	}
    free (chave);
    free (dados);
	fclose (ptrArquivoDoUsuario);
    for (;;) {
        scanf ("%d", &entradaConsiltar);
        if (!(entradaConsiltar)) {
            return false;
        }
    }
}

int cadastrar (char* categoria) {
    DADOS *cadastro = malloc(sizeof(DADOS));
    FILE *ptrArquivoDoUsuario;

    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";

    system ("cls");

    if ((ptrArquivoDoUsuario = fopen (enderecoArquivo, "a")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
    }
    if (!strcmp (categoria, gastos)) {
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        scanf ("%d", &cadastro->dia);
        fflush (stdin);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nCATEGORIA: ");
        fflush (stdin);
        scanf ("%s", cadastro->categoria);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDESCRICAO:");
        fflush (stdin);
        scanf ("%s", cadastro->descricao);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d %s %d\\%d\\%d %s %s %.2f\n", cadastro->mes, categoria, cadastro->dia,
                 cadastro->mes, cadastro->ano, cadastro->categoria, cadastro->descricao, cadastro->valor);
    } else if (!strcmp (categoria, recebidos)) {
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        fflush (stdin);
        scanf ("%d", &cadastro->dia);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDESCRICAO: ");
        fflush (stdin);
        scanf ("%s", cadastro->descricao);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d %s %d\\%d\\%d %s %.2f\n", cadastro->mes,categoria,
                 cadastro->dia,cadastro->mes, cadastro->ano, cadastro->descricao, cadastro->valor);
    } else if (!(strcmp (categoria, investimentos))) {
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        scanf ("%d", &cadastro->dia);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nLOCAL: ");
        fflush (stdin);
        scanf ("%s", cadastro->local);
        system ("cls");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d %s %d\\%d\\%d %s %.2f\n", cadastro->mes, categoria,
                 cadastro->dia, cadastro->mes, cadastro->ano, cadastro->local, cadastro->valor);
    }
    printf ("\nCADASTRO CONCLUIDO.\n");
    int i;
    for (i = 0; i <= 500000000; i++);
    fclose (ptrArquivoDoUsuario);
}
