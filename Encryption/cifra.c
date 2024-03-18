#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*
Código da cifra de césar. AVISO: necessário a ter na mesma pasta do código o arquivo Login.txt,
é necessário inserir os dados que queira criptografar com a cifra de cesar no mesmo.

Esse código é extremamente básico e demonstrativo, feito apenas para aprender conceitos básicos de 
arquivo em C.

*/


int main(){
    FILE *input, *output;
    char ch;
    int posicao;

    input = fopen("Login.txt","r");
    char primeiro_caractere = fgetc(input);

    //Verificação do arquivo
    if (input == NULL){
        puts ("Erro ao ler o arquivo");
        exit(1);
    }else{

        // Verificando se o arquivo está vazio
        if (primeiro_caractere == EOF) {
        printf("O arquivo está vazio.\nPor favor insira dados no arquivo Login.txt\n");
        fclose(input);
        exit(1);
    }

    //Verificação do arquivo
    output = fopen("Output.txt","w");
    if(input == NULL){
        puts("Erro ao escrever arquivo");
        exit(1);
    }

    //Determina a quantidade de casas que ira andar
    printf("Insira a quantidade de posicoes: ");
    scanf("%d", &posicao);

    /*Ele verifica se o caractere é um espaço através da tabela ascii, caso não seja,
    ele anda X posicoes de acordo com a número do caractere na tabela
    */
    do{
        ch = fgetc(input);
        if (ch != 32){
            fputc(ch+posicao, output);
        }else{
            fputc(ch, output);
        }
    } while (ch != EOF );
    

    return 0;    
    }
}
