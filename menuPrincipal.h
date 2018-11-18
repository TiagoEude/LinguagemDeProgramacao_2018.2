#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultaCadastro.h"
#include "relatorios.h"

int menuPrincipal ();
int gastos ();
int recebidos ();
int investimentos ();
int relatorios ();

int menuPrincipal () {
    char entradaMenuPrincipal;

    do {
    	printf ("\e[H\e[2J");
    	printf ("\n----MENU PRINCIPAL----\n");
    	printf("\n[1] GASTOS.\n");
    	printf("\n[2] RECEBIDOS.\n");
    	printf("\n[3] INVESTIMENTOS.\n");
    	printf("\n[4] RELATORIOS.\n");
        printf("\n[0] SAIR.\n");
    	printf("\nDIGITE: ");
    	entradaMenuPrincipal = getchar (); 
    	switch (entradaMenuPrincipal) {
            case '0':
                printf ("\e[H\e[2J");
    			printf ("\n----MENU PRINCIPAL----\n");
                printf ("\nSAINDO...\n");
                for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                return 0;
                break;
    		case '1':
    			gastos ();
    			break;
    		case '2':
    			recebidos ();
    			break;
    		case '3':
    			investimentos ();
    			break;
    		case '4':
    			relatorios ();
    			break;
    		default:
    			printf ("\e[H\e[2J");
    			printf ("\n----MENU PRINCIPAL----\n");
    			printf ("\nVALOR INCORRETO.\n");
    			for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
    	}
	} while (true);   
}

int gastos () {
    char entradaGastos;

    do {
        printf ("\e[H\e[2J");
        printf ("\n----GASTOS----\n");
        printf("\n[1] CONSULTA.\n");
        printf("\n[2] CADASTRO.\n");
        printf("\n[3] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        entradaGastos = getchar ();
        switch (entradaGastos) {
            case '1':
                consultar ("GASTOS", 4);
                break;
            case '2':
                cadastrar ("GASTOS");
                break;
            case '3':
                return 0;
                break;
            default:
                printf ("\e[H\e[2J");
                printf ("\n----MENU GASTOS----\n");
                printf("\nVALOR INCORRETO.\n");
                for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
        }

    } while (true);
}

int recebidos () {
    char entradaRecebidos;

    do {
        printf ("\e[H\e[2J");
        printf ("\n----RECEBIDOS----\n");
        printf("\n[1] CONSULTA.\n");
        printf("\n[2] CADASTRO.\n");
        printf("\n[3] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        entradaRecebidos = getchar ();
        switch (entradaRecebidos) {
            case '1':
                consultar ("RECEBIDOS", 3);
                break;
            case '2':
                cadastrar ("RECEBIDOS");
                break;
            case '3':
                return 0;
                break;
            default:
                printf ("\e[H\e[2J");
                printf ("\n----RECEBIDOS----\n");
                printf("\nVALOR INCORRETO.\n");
                for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
        }

    } while (true);
}

int investimentos () {
    char entradaInvestimentos;

    do {
        printf ("\e[H\e[2J");
        printf ("\n----INVESTIMENTOS----\n");
        printf("\n[1] CONSULTA.\n");
        printf("\n[2] CADASTRO.\n");
        printf("\n[3] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        entradaInvestimentos = getchar ();
        switch (entradaInvestimentos) {
            case '1':
                consultar ("INVESTIMENTOS", 3);
                break;
            case '2':
                cadastrar ("INVESTIMENTOS");
                break;
            case '3':
                return 0;
                break;
            default:
                printf ("\e[H\e[2J");
                printf ("\n----INVESTIMENTOS----\n");
                printf("\nVALOR INCORRETO.\n");
                for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
        }

    } while (true);
}

int relatorios () {
    char entradaInvestimentos;

    do {
        printf ("\e[H\e[2J");
        printf ("\n----RELATORIOS----\n");
        printf("\n[1] MENSAL.\n");
        printf("\n[2] CATEGORIA.\n");
        printf("\n[3] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        entradaInvestimentos = getchar ();
        switch (entradaInvestimentos) {
            case '1':
                relatorioMensal ();
                break;
            case '2':
                relatorioCategoria ();
                break;
            case '3':
                return 0;
                break;
            default:
                printf ("\e[H\e[2J");
                printf ("\n----RELATORIOS----\n");
                printf("\nVALOR INCORRETO.\n");
                for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
                break;
        }

    } while (true);
}