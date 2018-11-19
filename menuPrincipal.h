#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultarCadastrar.h"
#include "relatorios.h"

int menuPrincipal ();
int menu (char *, int);
int relatorios ();

int menuPrincipal () {
    int entradaMenuPrincipal;
    char gastos[] = "GASTOS";
    char recebidos[] = "RECEBIDOS";
    char investimentos[] = "INVESTIMENTOS";

    for (;;) {
    	system ("cls");
    	printf ("\n----MENU PRINCIPAL----\n");
    	printf("\n[1] GASTOS.\n");
    	printf("\n[2] RECEBIDOS.\n");
    	printf("\n[3] INVESTIMENTOS.\n");
    	printf("\n[4] RELATORIOS.\n");
        printf("\n[0] SAIR.\n");
    	printf("\nDIGITE: ");
    	scanf ("%d", &entradaMenuPrincipal);
        while (entradaMenuPrincipal != 0 && entradaMenuPrincipal != 1 && entradaMenuPrincipal != 2 &&
        entradaMenuPrincipal != 3 && entradaMenuPrincipal != 4) {
            system ("cls");
    		printf ("\n----MENU PRINCIPAL----\n");
    		printf ("\nVALOR INCORRETO.\n");
    		for (int i = 0; i < 500000000; i++);
            system ("cls");
    	    printf ("\n----MENU PRINCIPAL----\n");
    	    printf("\n[1] GASTOS.\n");
    	    printf("\n[2] RECEBIDOS.\n");
    	    printf("\n[3] INVESTIMENTOS.\n");
    	    printf("\n[4] RELATORIOS.\n");
            printf("\n[0] SAIR.\n");
    	    printf("\nDIGITE: ");
    	    scanf ("%d", &entradaMenuPrincipal);
        } 
    	switch (entradaMenuPrincipal) {
            case 0:
                for (int i = 0; i < 2; i++) {
                    system ("cls");
    			    printf ("\n----MENU PRINCIPAL----\n");
                    printf ("\nSAINDO.\n");
                    for (int i = 0; i < 200000000; i++);
                    system ("cls");
    			    printf ("\n----MENU PRINCIPAL----\n");
                    printf ("\nSAINDO..\n");
                    for (int i = 0; i < 200000000; i++);
                    system ("cls");
    			    printf ("\n----MENU PRINCIPAL----\n");
                    printf ("\nSAINDO...\n");
                    for (int i = 0; i < 200000000; i++);
                }
                return 0;
                break;
    		case 1:
    			menu (gastos, 4);
    			break;
    		case 2:
    			menu (recebidos, 3);
    			break;
    		case 3:
    			menu (investimentos, 3);
    			break;
    		case 4:
    			relatorios ();
    			break;
    		
    	}
	}  
}

int menu (char *categoria, int colunas) {
    int entradaMenu;

    for (;;) {
        system ("cls");
        printf ("\n----%s----\n", categoria);
        printf("\n[1] CONSULTA.\n");
        printf("\n[2] CADASTRO.\n");
        printf("\n[0] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        scanf ("%d", &entradaMenu);
        while (entradaMenu != 0 && entradaMenu != 1 && entradaMenu != 2) {
            system ("cls");
            printf ("\n----%s----\n", categoria);
            printf("\nVALOR INCORRETO.\n");
            for (int i = 0; i < 500000000; i++);
            system ("cls");
            printf ("\n----%s----\n", categoria);
            printf("\n[1] CONSULTA.\n");
            printf("\n[2] CADASTRO.\n");
            printf("\n[0] MENU PRINCIPAL.\n");
            printf("\nDIGITE: ");
            scanf ("%d", &entradaMenu);
        }
        switch (entradaMenu) {
            case 0:
                return 0;
                break;
            case 1:
                consultar (categoria, colunas);
                break;
            case 2:
                cadastrar (categoria);
                break;
        }
    }
}

int relatorios () {
    int entradaRelatorios;

    for (;;) {
        system ("cls");
        printf ("\n----RELATORIOS----\n");
        printf("\n[1] MENSAL.\n");
        printf("\n[2] CATEGORIA.\n");
        printf("\n[0] MENU PRINCIPAL.\n");
        printf("\nDIGITE: ");
        scanf ("%d", &entradaRelatorios);
        while (entradaRelatorios != 0 && entradaRelatorios != 1 && entradaRelatorios != 2) {
            system ("cls");
            printf ("\n----RELATORIOS----\n");
            printf("\nVALOR INCORRETO.\n");
            for (int i = 0; i < 500000000; i++);
            system ("cls");
            printf ("\n----RELATORIOS----\n");
            printf("\n[1] MENSAL.\n");
            printf("\n[2] CATEGORIA.\n");
            printf("\n[0] MENU PRINCIPAL.\n");
            printf("\nDIGITE: ");
            scanf ("%d", &entradaRelatorios);
        }
        switch (entradaRelatorios) {
            case 0:
                return 0;
                break;
            case 1:
                relatorioMensal ();
                break;
            case 2:
                relatorioCategoria ();
                break;
        }
    }
}