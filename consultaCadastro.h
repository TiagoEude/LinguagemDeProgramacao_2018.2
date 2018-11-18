#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void consultar (char*, int);
void cadastrar (char*);

void consultar (char* categoria, int colunas) {
	FILE *ptrArquivoDoUsuario;
	char *chave;
	char *dados;

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
    printf ("\e[H\e[2J");
    printf ("\n----%s----\n",categoria);
    printf ("\nDIGITE QUALQUER TECLA PARA VOLTAR.\n");
	while (!feof (ptrArquivoDoUsuario)) {
        fscanf (ptrArquivoDoUsuario, "%s", chave);
		if (!(strcmp (chave, categoria))) {
            for (int i = 0; i < colunas; i++) {
                printf ("|");
                fscanf (ptrArquivoDoUsuario, "%s", dados);
                printf ("%s ", dados);
            }
            printf ("|");
            printf ("\n");
        }
	}
    free (chave);
    free (dados);
	fclose (ptrArquivoDoUsuario);
	getchar ();
}

void cadastrar (char* categoria) {
	typedef struct {
        int dia;
        int mes;
        int ano;
        char categoria[101];
        char descricao[101];
        double valor;
        char local[101];
    } DADOS;

    DADOS *cadastro; 
    FILE *ptrArquivoDoUsuario;
    char espaco[] = " ";
    char fimDeLinha[] = "\n";
    char barra[] = "\\";
    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";

    printf ("\e[H\e[2J");
    if ((ptrArquivoDoUsuario = fopen (enderecoArquivo, "a")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
    }
    if (!(strcmp (categoria, gastos))) {
        strcat (categoria, espaco);
        fprintf (ptrArquivoDoUsuario, "%s", categoria);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        fflush (stdin);
        scanf ("%d", &cadastro->dia);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nCATEGORIA: ");
        fflush (stdin);
        fgets (cadastro->categoria, 100, stdin);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDESCRICAO:");
        fflush (stdin);
        fgets (cadastro->descricao, 100, stdin);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->dia);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->mes);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->ano);
        fprintf (ptrArquivoDoUsuario, "%s", cadastro->categoria);
        fprintf (ptrArquivoDoUsuario, "%s", "\0");
        fprintf (ptrArquivoDoUsuario, "%s", cadastro->descricao);
        fprintf (ptrArquivoDoUsuario, "%s", "\0");
        fprintf (ptrArquivoDoUsuario, "%2f", cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%s", fimDeLinha);
    } else if (!(strcmp (categoria, recebidos))) {
        strcat (categoria, espaco);
        strcat (espaco, categoria);
        fprintf (ptrArquivoDoUsuario, "%s", categoria);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        fflush (stdin);
        scanf ("%d", &cadastro->dia);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDESCRICAO: ");
        fflush (stdin);
        fgets (cadastro->descricao, 100, stdin);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->dia);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->mes);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->ano);
        strcat (espaco, cadastro->descricao);
        fprintf (ptrArquivoDoUsuario, "%s", cadastro->descricao);
        strcat (cadastro->descricao, espaco);
        fprintf (ptrArquivoDoUsuario, "%2f", cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%s", fimDeLinha);
    } else if (!(strcmp (categoria, investimentos))) {
        strcat (categoria, espaco);
        fprintf (ptrArquivoDoUsuario, "%s", categoria);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nDIA: ");
        scanf ("%d", &cadastro->dia);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nMES: ");
        fflush (stdin);
        scanf ("%d", &cadastro->mes);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nDATA -> D\\M\\A \n");
        printf ("\nANO: ");
        fflush (stdin);
        scanf ("%d", &cadastro->ano);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nLOCAL: ");
        fflush (stdin);
        fgets (cadastro->local, 100, stdin);
        printf ("\e[H\e[2J");
        printf ("\n----%s----\n",categoria);
        printf ("\nVALOR: ");
        fflush (stdin);
        scanf ("%lf", &cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->dia);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->mes);
        fprintf (ptrArquivoDoUsuario, "%s", barra);
        fprintf (ptrArquivoDoUsuario, "%d", cadastro->ano);
        fprintf (ptrArquivoDoUsuario, "%s", cadastro->local);
        fprintf (ptrArquivoDoUsuario, "%2f", cadastro->valor);
        fprintf (ptrArquivoDoUsuario, "%s", fimDeLinha);
    }
    printf ("\nCADASTRO CONCLUIDO.\n");
    for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
    fclose (ptrArquivoDoUsuario);
}