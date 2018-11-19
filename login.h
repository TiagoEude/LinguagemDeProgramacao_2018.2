#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char enderecoArquivo[101];

int criarUsuario ();
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
    system ("cls");
    printf ("\n----CRIAR USUARIO----\n");
    printf ("\nINFORME UM NOME DE USUARIO: ");
    scanf ("%s", usuario);
    fflush (stdin);
    strcat (usuario, tipoArquivo);
    if (!((arquivoDoUsuario = fopen (usuario, "r")) == NULL)) {
        system ("cls");
        printf ("\n----CRIAR USUARIO----\n");
        printf ("\nUSUARIO JA EXISTENTE.\n");
        for (int i = 0; i < 500000000; i++);
        system ("cls");
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
    system ("cls");
    printf ("\n----CRIAR USUARIO----\n");
    printf ("\nUSUARIO CRIADO COM SUCESSO.\n");
    for (int i = 0; i < 500000000; i++);
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
    system ("cls");
    printf ("\n----FAZER LOGIN----\n");
    printf ("\nINFORME UM NOME DE USUARIO: ");
    scanf ("%s", usuario);
    fflush (stdin);
    strcpy (login, usuario);
    strcat (usuario, tipoArquivo);
    if ((arquivoDoUsuario = fopen (usuario, "r")) == NULL) {
        system ("cls");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nUSUARIO NAO ENCONTRADO.\n");
        for (int i = 0; i < 500000000; i++);
        free (usuario);
        free (login);
        fclose (arquivoDoUsuario);
        return false;
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
    if (!(strcmp (senha, senhaCorreta))) {
        system ("cls");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nINFORME UM NOME DE USUARIO: %s\n", nomeUsuario);
        printf ("\nINFORME UMA SENHA: %s\n", senha);
        printf ("\nSENHA CORRETA.\n");
        for (int i = 0; i < 2; i++) {
            system ("cls");
            printf ("\n----FAZER LOGIN----\n");
            printf ("\nENTRANDO.\n");
            for (int count = 0,i = 0; i < 200000000; i++);
            system ("cls");
            printf ("\n----FAZER LOGIN----\n");
            printf ("\nENTRANDO..\n");
            for (int count = 0,i = 0; i < 200000000; i++);
            system ("cls");
            printf ("\n----FAZER LOGIN----\n");
            printf ("\nENTRANDO...\n");
            for (int count = 0,i = 0; i < 200000000; i++);
        }
        free (senha);
        free (senhaCorreta);
        fclose (arquivoDoUsuario);
        return true;
    } else {
        system ("cls");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nINFORME UM NOME DE USUARIO: %s\n", nomeUsuario);
        printf ("\nINFORME UMA SENHA: %s\n", senha);
        system ("cls");
        printf ("\n----FAZER LOGIN----\n");
        printf ("\nSENHA INCORRETA.\n");
        for (int i = 0; i < 500000000; i++);
        free (senha);
        free (senhaCorreta);
        fclose (arquivoDoUsuario);
        return false;
    }
}