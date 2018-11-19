#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int relatorioMensal ();
int relatorioCategoria ();
int gerarRelatorioMensal (char*);
int gerarRelatorioCategoria (char *, int);

int relatorioMensal () {
    int entradaRelatoriosMensal;
    char *mes;

    mes = malloc (3 * sizeof (char));
    for (;;) {
        for (int i = 0; i < 500000000; i++);
        system ("cls");
    	printf ("\n----RELATORIOS----\n");
        printf ("\nINFORME O MES: ");
        scanf ("%d", &entradaRelatoriosMensal);
        while (entradaRelatoriosMensal != 1 && entradaRelatoriosMensal != 2 &&
        entradaRelatoriosMensal != 3 && entradaRelatoriosMensal != 4 &&
        entradaRelatoriosMensal != 5 && entradaRelatoriosMensal != 6 &&
        entradaRelatoriosMensal != 7 && entradaRelatoriosMensal != 8 &&
        entradaRelatoriosMensal != 9 && entradaRelatoriosMensal != 10 &&
        entradaRelatoriosMensal != 11 && entradaRelatoriosMensal != 12) {
            system ("cls");
    	    printf ("\n----RELATORIOS----\n");
            printf ("\nVALOR INCORRETO.\n");
            for (int i = 0; i < 500000000; i++);
            system ("cls");
    	    printf ("\n----RELATORIOS----\n");
            printf ("\nINFORME O MES: ");
            scanf ("%d", &entradaRelatoriosMensal);
        }
        switch (entradaRelatoriosMensal) {
            case 1:
                mes = "1";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 2:
                mes = "2";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 3:
                mes = "3";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 4:
                mes = "4";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 5:
                mes = "5";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 6:
                mes = "6";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 7:
                mes = "7";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 8:
                mes = "8";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 9:
                mes = "9";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 10:
                mes = "10";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 11:
                mes = "11";
                gerarRelatorioMensal (mes);
                return 0;
                break;
            case 12:
                mes = "12";
                gerarRelatorioMensal (mes);
                return 0;
                break;
        }
    }
}

int gerarRelatorioMensal (char *mes) {
    FILE *ptrArquivoDoUsuario;
    FILE *ptrRelatorio;
	char *chave;
	char *dados;
    char tipoArquivo[] = ".txt";
    char *nomeDoArquivo;
    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";

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
    nomeDoArquivo = "relatoriomenal.txt";
    if ((ptrRelatorio = fopen (nomeDoArquivo, "w")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
	}
	while (!feof (ptrArquivoDoUsuario)) {
        fscanf (ptrArquivoDoUsuario, "%s", chave);
		if (!(strcmp (chave, mes))) {
            fprintf (ptrRelatorio, "%s", "|");
            fscanf (ptrArquivoDoUsuario, "%s", dados);
            fprintf (ptrRelatorio, "%s ", dados);
            if (!(strcmp (dados, gastos))) {
                for (int i = 0; i < 4; i++) {
                    fprintf (ptrRelatorio, "%s", "|");
                    fscanf (ptrArquivoDoUsuario, "%s", dados);
                    fprintf (ptrRelatorio, "%s ", dados);
                }
            }
            if (!(strcmp (dados, recebidos))) {
                for (int i = 0; i < 3; i++) {
                    fprintf (ptrRelatorio, "%s", "|");
                    fscanf (ptrArquivoDoUsuario, "%s", dados);
                    fprintf (ptrRelatorio, "%s ", dados);
                }
            }
            if (!(strcmp (dados, investimentos))) {
                for (int i = 0; i < 3; i++) {
                    fprintf (ptrRelatorio, "%s", "|");
                    fscanf (ptrArquivoDoUsuario, "%s", dados);
                    fprintf (ptrRelatorio, "%s ", dados);
                }
            }
            fprintf (ptrRelatorio, "%s", "|");
            fprintf (ptrRelatorio, "%s","\n");
        }
    }
    system ("cls");
    printf ("\n----RELATORIOS----\n");
    printf("\nRELATORIO GERADO COM SUCESSO.\n");
    for (int i = 0; i < 500000000; i++);
	fclose (ptrArquivoDoUsuario);
    fclose (ptrRelatorio);
    free (nomeDoArquivo);
    free (chave);
    free (dados);
    return 0;
}

int relatorioCategoria () {
    int entradaRelatoriosCategoria;
    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";

    for (;;) {
    	system ("cls");
    	printf ("\n----RELATORIOS----\n");
    	printf("\n[1] GASTOS.\n");
    	printf("\n[2] RECEBIDOS.\n");
    	printf("\n[3] INVESTIMENTOS.\n");
        printf("\n[0] VOLTAR.\n");
    	printf("\nDIGITE: ");
    	scanf ("%d", &entradaRelatoriosCategoria);
        while (entradaRelatoriosCategoria != 0 && entradaRelatoriosCategoria != 1 &&
        entradaRelatoriosCategoria != 2 && entradaRelatoriosCategoria != 3) {
            system ("cls");
    		printf ("\n----RELATORIOS----\n");
    		printf ("\nVALOR INCORRETO.\n");
    		for (int i = 0; i < 500000000; i++);
        }
    	switch (entradaRelatoriosCategoria) {
            case 0:
                return 0;
                break;
    		case 1:
    			gerarRelatorioCategoria (gastos, 4);
    			break;
    		case 2:
    			gerarRelatorioCategoria (recebidos, 3);
    			break;
    		case 3:
    			gerarRelatorioCategoria (investimentos, 3);
    			break;
    	}
	}
}

int gerarRelatorioCategoria (char *categoria, int colunas) {
    FILE *ptrArquivoDoUsuario;
    FILE *ptrRelatorio;
	char *chave;
	char *dados;
    char tipoArquivo[] = ".txt";
    char *nomeDoArquivo;

	if ((chave = (char *) malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((dados = (char *) malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((nomeDoArquivo = (char *) malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
	if ((ptrArquivoDoUsuario = fopen (enderecoArquivo, "r")) == NULL) {
		printf ("\nERRO AO ABRIR O AQUIVO.\n");
		exit (1);
	}

	strcpy(nomeDoArquivo, "relatorio");
    strcat(nomeDoArquivo, categoria);
    strcat(nomeDoArquivo, tipoArquivo);
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
    system ("cls");
    printf ("\n----RELATORIOS----\n");
    printf("\nRELATORIO GERADO COM SUCESSO.\n");
    for (int i = 0; i < 500000000; i++);
	fclose (ptrArquivoDoUsuario);
    fclose (ptrRelatorio);
    free (chave);
    free (dados);
    free (nomeDoArquivo);
	return 0;
}
