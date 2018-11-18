#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char enderecoArquivo[101];

int fazerLogin ();
int verificaSenha (char*, char*);

int criarUsuario () {
    FILE *arquivoDoUsuario;
    char *usuario;
    char *senha;
    char tipoArquivo[] = ".txt";
    int entradaCriaUsuario;
    char fimDeLinha[] = "\n";

    if ((usuario = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((senha = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!");
        exit (1);
    }
    printf ("\e[H\e[2J");
    printf ("\n----CRIAR USUARIO----\n");
    printf ("\nINFORME UM NOME DE USUARIO: ");
    scanf ("%s", usuario);
    fflush (stdin);
    strcat (usuario, tipoArquivo);
    if (!((arquivoDoUsuario = fopen (usuario, "r")) == NULL)) {
        printf ("\e[H\e[2J");
        printf ("\n----CRIAR USUARIO----\n");
        printf ("\nUSUARIO JA EXISTENTE.\n");
        for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
        printf ("\e[H\e[2J");
        free (usuario);
        free (senha);
        fclose (arquivoDoUsuario);
        return 0;
    }
    printf ("\nINFORME UMA SENHA: ");
    scanf ("%s", senha);
    fflush (stdin);
    strcat (senha, fimDeLinha);
    arquivoDoUsuario = fopen(usuario, "w");
    fprintf (arquivoDoUsuario, "%s", senha);
    fclose (arquivoDoUsuario);
    printf ("\e[H\e[2J");
    printf ("\n----CRIAR USUARIO----\n");
    printf ("\nUSUARIO CRIADO COM SUCESSO.\n");
    for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
    free (usuario);
    free (senha);
    fclose (arquivoDoUsuario);
    return 0;
}

int fazerLogin() {
    FILE *arquivoDoUsuario;
    char *usuario;
    char tipoArquivo[] = ".txt";
    char *login;
    int entradaFazerLogin;

    if ((usuario = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!\n");
        exit (1);
    }
    if ((login = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!");
        exit (1);
    }
    printf ("\e[H\e[2J");
    printf ("\n----FAZER LOGIN----\n");
    printf ("\nINFORME UM NOME DE USUARIO: ");
    scanf ("%s", usuario);
    fflush (stdin);
    strcpy (login, usuario);
    strcat (usuario, tipoArquivo);
    if ((arquivoDoUsuario = fopen (usuario, "r")) == NULL) {
        printf ("\e[H\e[2J");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nUSUARIO NAO ENCONTRADO.\n");
        for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
        free (usuario);
        free (login);
        fclose (arquivoDoUsuario);
        return 0;
    }
    fclose (arquivoDoUsuario);
    return (verificaSenha (usuario, login));
}

int verificaSenha (char *nomeDoArquivo, char *nomeUsuario) {
    FILE *arquivoDoUsuario;
    char *senha;
    char fimDeLinha[] = "\n";
    char *senhaCorreta;
    int entradaSenhaIncorreta;
    int logado = 1;

    if ((senha = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!");
        exit (1);
    }
    if ((senhaCorreta = malloc (101 * sizeof (char))) == NULL) {
        printf ("ERRO!");
        exit (1);
    }
    strcpy (enderecoArquivo, nomeDoArquivo);
    arquivoDoUsuario = fopen (nomeDoArquivo, "r");
    printf ("\nINFORME UMA SENHA: ");
    scanf ("%s", senha);
    fflush (stdin);
    fscanf (arquivoDoUsuario, "%s", senhaCorreta);
    if (strcmp (senha, senhaCorreta) == 0) {
        printf ("\e[H\e[2J");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nINFORME UM NOME DE USUARIO: %s\n", nomeUsuario);
        printf ("\nINFORME UMA SENHA: %s\n", senha);
        printf ("\nSENHA CORRETA.\n");
        printf ("\e[H\e[2J");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nENTRANDO...\n");
        for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
        free (senha);
        free (senhaCorreta);
        fclose (arquivoDoUsuario);
        return 1;
    } else if (!(strcmp (senha, senhaCorreta) == 0)) {
        printf("\e[H\e[2J");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nINFORME UM NOME DE USUARIO: %s\n", nomeUsuario);
        printf ("\nINFORME UMA SENHA: %s\n", senha);
        printf ("\e[H\e[2J");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nSENHA INCORRETA.\n");
        for (int count = 0,i = 0; i <= 500000000; i++) count +=1;
        free (senha);
        free (senhaCorreta);
        fclose (arquivoDoUsuario);
        return 0;
    }
}