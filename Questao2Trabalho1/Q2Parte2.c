#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int busca_binaria (int tam, char **vet, char buscado[12])
{
    int L = 0;
    int R = tam-1;
    int m;
    int comp;
    while(L <= R) {
        m = floor((L+R)/2);
        comp = strcmp(vet[m], buscado);
        if(comp == 0) {
            return m;
        }
        else if(comp < 0) {
            L = m+1;
        }
        else {
            R = m-1;
        }
    }
    return -1;
}
 
//TRANSFERIR OQUE TEM NO ARQUIVO PARA UM VETOR
char** ler_arquivo(FILE *arquivo, char **vet)
{
    int i = 0;
    while(fgets(vet[i], BUFSIZ, arquivo) != NULL) {
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
    FILE *arq;
    char **mes1;
    char **mes2;
    char **mes3;
    char **mes4;
    char **mes5;
    char busca[12];
 
    //ALOCAO DINAMICA
    mes1 = (char **)malloc((100)*sizeof(char *));
    for (int i = 0; i < 100; i++)
    {
        mes1[i] = (char*)malloc((12)*sizeof(char));
    }
    mes2 = (char **)malloc((500)*sizeof(char *));
    for (int i = 0; i < 500; i++)
    {
        mes2[i] = (char*)malloc((12)*sizeof(char));
    }
 
    mes3 = (char **)malloc((1000)*sizeof(char *));
    for (int i = 0; i < 1000; i++)
    {
        mes3[i] = (char*)malloc((12)*sizeof(char));
    }
 
    mes4 = (char **)malloc((5000)*sizeof(char *));
    for (int i = 0; i < 5000; i++)
    {
        mes4[i] = (char*)malloc((12)*sizeof(char));
    }
 
    mes5 = (char **)malloc((10000)*sizeof(char *));
    for (int i = 0; i < 10000; i++)
    {
        mes5[i] = (char*)malloc((12)*sizeof(char));
    }
 
    //PASSA OQUE TEM NOS NOVOS ARQUIVOS PARA O ARRAY DE STRING
    arq = fopen("newMes1.txt", "r");
    mes1 = ler_arquivo (arq, mes1);
    fclose(arq);
    arq = fopen("newMes2.txt", "r");
    mes2 = ler_arquivo (arq, mes2);
    fclose(arq);
    arq = fopen("newMes3.txt", "r");
    mes3 = ler_arquivo (arq, mes3);
    fclose(arq);
    arq = fopen("newMes4.txt", "r");
    mes4 = ler_arquivo (arq, mes4);
    fclose(arq);
    arq = fopen("newMes5.txt", "r");
    mes5 = ler_arquivo (arq, mes5);
    fclose(arq);
 
    //BUSCA DO CODIGO
    printf ("Escolha o codigo que deseja buscar: ");
    scanf ("%s%*c", busca);
 
    int result1 = busca_binaria (100,mes1, busca);
    int result2 = busca_binaria (500,mes2, busca);
    int result3 = busca_binaria (1000,mes3, busca);
    int result4 = busca_binaria (5000,mes4, busca);
    int result5 = busca_binaria (10000,mes5, busca);
    if (result1 != -1 || result2 != -1 || result3 != -1 || result4 != -1 || result5 != -1 ){
        if (result1 != -1)
        {
            printf ("Esta no novo arquivo de mes 1 no indice %d (linha %d do arquivo)\n", result1,result1+1);
        }
        if (result2 != -1)
        {
            printf ("Esta no novo arquivo de mes 2 no indice %d (linha %d do arquivo)\n", result2, result2+1);
        }
        if (result3 != -1)
        {
            printf ("Esta no novo arquivo de mes 3 no indice %d (linha %d do arquivo)\n", result3, result3+1);
        }
        if (result4 != -1)
        {
            printf ("Esta no novo arquivo de mes 4 no indice %d (linha %d do arquivo)\n", result4, result4+1);
        }
        if (result5 != -1)
        {
            printf ("Esta no novo arquivo de mes 5 no indice %d (linha %d do arquivo)\n", result5, result5+1);
        }
    }
 
    else {
        printf ("O codigo nao foi encontrado em nenhum dos arquivos!");
    }
}