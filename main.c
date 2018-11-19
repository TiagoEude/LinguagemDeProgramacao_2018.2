#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "menuPrincipal.h"

int main() {
	int entrada;
	int retorno;

    for (;;) {
        system ("cls");
        printf ("\n----PAGINA INICIAL----\n");
        printf ("\n[1] CRIAR USUARIO.\n");
        printf ("\n[2] FAZER LOGIN\n");
        printf ("\n[0] ENCERRAR O PROGRAMA.\n");
        printf ("\nDIGITE: ");
        scanf ("%d", &entrada);
        while (entrada != 0 && entrada != 1 && entrada != 2) {
            system ("cls");
            printf ("\n----PAGINA INICIAL----\n");
    		printf("\nVALOR INCORRETO!\n");
            for (int i = 0; i < 200000000; i++);
            system ("cls");
            printf ("\n----PAGINA INICIAL----\n");
            printf ("\n[1] CRIAR USUARIO.\n");
            printf ("\n[2] FAZER LOGIN\n");
            printf ("\n[0] ENCERRAR O PROGRAMA.\n");
            printf ("\nDIGITE: ");
            scanf ("%d", &entrada);
        }
    	switch (entrada) {
    		case 0:
                for (int i = 0; i < 3; i++) {
                    system ("cls");
                    printf ("\n----PAGINA INICIAL----\n");
                    printf ("\nENCERRNADO O PROGRAMA.\n");
                    for (int i = 0; i < 100000000; i++);
                    system ("cls");
                    printf ("\n----PAGINA INICIAL----\n");
                    printf ("\nENCERRNADO O PROGRAMA..\n");
                    for (int i = 0; i < 100000000; i++);
                    system ("cls");
                    printf ("\n----PAGINA INICIAL----\n");
                    printf ("\nENCERRNADO O PROGRAMA...\n");
                    for (int i = 0; i < 100000000; i++);
                }
    			exit (1);
    			break;
    		case 1:
                criarUsuario ();
    			break;
    		case 2:
                if (fazerLogin () == true) {
                    menuPrincipal ();
                }
    			break;
    	}
    }
}
