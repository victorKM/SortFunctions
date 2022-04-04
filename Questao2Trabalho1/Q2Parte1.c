#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
//ORDENAR POR SELECAO
void ordenacao_mes (char **vet, int tam)
{
    char x[12];
    int indice_menor;
    int j;
 
    for (int i = 1; i <= tam-1; i++)
    {
        indice_menor = i;
        for (j = i+1; j <= tam; j++)
        {
            if (strcmp(vet[j],vet[indice_menor]) < 0)
               indice_menor = j;
        }
        strcpy (x, vet[i]);
        strcpy (vet[i], vet[indice_menor]);
        strcpy (vet[indice_menor], x);
    }
}
 
//SALVAR OQUE TEM NO VETOR NO ARQUIVO
void salvar_arquivo (FILE *arquivo, int tam, char **vet)
{
    for (int i  = 1; i < tam; i++)
    {
        fprintf (arquivo, "%s\n", vet[i]);
    }  
}
 
//TRANSFERIR OQUE TEM NO ARQUIVO PARA UM VETOR
char** ler_arquivo(FILE *arquivo, char **vet)
{
    char temp[12];
    int i = 1;
    while(fgets(temp, BUFSIZ, arquivo) != NULL) {
            strcpy (vet[i], temp);
            for (int j = 0; j < 12; j++) {
                if (vet[i][j] == '\n' || vet[i][j] == '\r') {
                    vet[i][j] = '\0';
                }
            }
            i++;
    }
    return vet;
}
 
int main ()
{
    //DECLARACOES
    char **mes;
    FILE *novo_mes;
    FILE *arq;
    char meses[5][10] = {"mes_1.txt", "mes_2.txt", "mes_3.txt", "mes_4.txt", "mes_5.txt"};
    char new_meses[5][12] = {"newMes1.txt", "newMes2.txt", "newMes3.txt", "newMes4.txt", "newMes5.txt"};
    int quantidade_codigos[5] = {100, 500, 1000, 5000, 10000};
 
    for(int i = 0; i < 5; i++) {
        //ALOCACAO DO VETOR DE STRINGS
        mes = (char **)malloc((quantidade_codigos[i]+1)*sizeof(char *));
        for (int j = 0; j < quantidade_codigos[i]+1; j++)
        {
            mes[j] = (char*)malloc((12)*sizeof(char));
        }
 
        //PASSA OQUE TEM NO ARQUIVO PARA O VETOR DE STRING
        arq = fopen(meses[i], "r");
        mes = ler_arquivo (arq, mes);
        fclose(arq);
 
        //ORDENA
        ordenacao_mes(mes, quantidade_codigos[i]);
 
        //SALVAR EM NOVOS ARQUIVOS
        novo_mes = fopen(new_meses[i], "wt");
        salvar_arquivo (novo_mes, quantidade_codigos[i]+1, mes);
        fclose(novo_mes);
    }
}
