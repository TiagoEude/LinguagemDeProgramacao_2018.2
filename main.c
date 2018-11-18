#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "menuPrincipal.h"

int main() {
	char entrada;
	int retorno;

    do {
        printf ("\e[H\e[2J");
        printf ("\n----PAGINA INICIAL----\n");
        printf ("\n[1] CRIAR USUARIO.\n");
        printf ("\n[2] FAZER LOGIN\n");
        printf ("\n[0] ENCERRAR O PROGRAMA.\n");
        printf ("\nDIGITE: ");
        entrada = getchar ();
    	switch (entrada) {
    		case '0':
    			exit (1);
    			break;
    		case '1':
    			criarUsuario ();
    			break;
    		case '2':
    			retorno = fazerLogin ();
                if (retorno == 1) {
                    menuPrincipal ();
                }
    			break;
    		default:
                printf ("\e[H\e[2J");
                printf ("\n----PAGINA INICIAL----\n");
    			printf("\nVALOR INCORRETO!\n");
                for (int count = 0,i = 0; i <= 200000000; i++) count +=1;
    	}
    }  while (true);
}