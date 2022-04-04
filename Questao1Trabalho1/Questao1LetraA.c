#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int comp;
int mov;
 
//METODO DE INSERCAO DIRETA
int insercao_direta(char **a, int N) {
    comp = 0;
    mov = 0;
    char x[12];
    for (int i = 2; i <= N; i++) {
        comp++;
        strcpy(x, a[i]);
        mov++;
        strcpy(a[0], x);
        mov++;
        int j = i;
        while (strcmp(x, a[j-1]) < 0)
        {
            comp++;
            strcpy(a[j], a[j-1]);
            mov++;
            j = j-1;
        }
        strcpy(a[j], x);
        mov++;
    }
}
 
//METODO DE INSERCAO BINARIA
void insercao_binaria(char **a, int N) {
    comp = 0;
    mov = 0;
    char x[12];
    int L;
    int R;
    int m;
    int j;
    for (int i = 2; i <= N; i++) {
        strcpy(x, a[i]);
        mov++;
        L = 1;
        R = i;
        while( L < R) {
            m = floor( ( L + R ) / 2);
            comp++;
            if(strcmp(a[m], x) <= 0) {
                L = m + 1;
            }
            else {
                R = m;
            }
        }
        j = i;
        while (j > R) {
            strcpy(a[j], a[j-1]);
            mov++;
            j = j-1;
        }
        strcpy(a[R], x);
        mov++;
    }
}
 
//METODO DE SELECAO
void selecao (char **a, int N) {
    comp = 0;
    mov = 0;
    char x[12];
    int indice_menor;
    int j;
 
    for (int i = 1; i <= N-1; i++)
    {
        indice_menor = i;
        for (j = i+1; j <= N; j++)
        {
            comp++;
            if (strcmp(a[j],a[indice_menor]) < 0){
               indice_menor = j;
            }
        }
        strcpy (x, a[i]);
        mov++;
        strcpy (a[i], a[indice_menor]);
        mov++;
        strcpy (a[indice_menor], x);
        mov++;
    }
}
 
//METODO DE BUBBLE SORT
void bubblesort(char **a, int N) {
    comp = 0;
    mov = 0;
    char x[12];
    for(int i = 2; i <= N; i++) {
        for(int j = N; j >= i; j--) {
            comp++;
            if(strcmp(a[j-1], a[j]) > 0) {
                strcpy(x, a[j-1]);
                mov++;
                strcpy(a[j-1],a[j]);
                mov++;
                strcpy(a[j], x);
                mov++;
            }
        }
    }
}
 
//METODO DE FUSAO
void mergesort(char **a, int N) {
    comp = 0;
    mov = 0;
    char **c = (char **)malloc((N+1)*sizeof(char *));
    for (int i = 0; i < N+1; i++)
    {
        c[i] = (char*)malloc((12)*sizeof(char));
    }
    comp = 0;
    mov = 0;
    int p = 1;
    while(p < N)
    {
        mpass(a,N,p,c);
        p = 2*p;
        mpass(c,N,p,a);
        p = 2*p;
    }
}
 
void mpass(char **a, int N, int p, char **c)
{
    int i = 1;
    while(i <= (N-(2*p)+1))
    {
        merge(a,i,i+p-1,(i+(2*p)-1),c);
        i = i+(2*p);
    }
    if(i+p-1<N)
    {
        merge(a,i,i+p-1,N,c);
    }
    else
    {
        for(int j = i; j <= N; j++)
        {
            strcpy(c[j],a[j]);
            mov++;
        }
    }
}
 
void merge(char **a, int L, int h, int R, char **c) {
    int i = L;
    int j = h + 1;
    int k = L - 1;
    while(i <= h && j <= R)
    {
        k = k+1;
        comp++;
        if(strcmp(a[i],a[j]) < 0){
            strcpy(c[k],a[i]);
            mov++;
            i = i+1;
        }
        else {
            strcpy(c[k],a[j]);
            mov++;
            j = j+1;
        }
    }
    while(i <= h)
    {
        k=k+1;
        strcpy(c[k],a[i]);
        mov++;
        i = i+1;
    }
    while(j<=R)
    {
        k=k+1;
        strcpy(c[k],a[j]);
        mov++;
        j=j+1;
    }
}
 
//METODO DE HEAPSORT
void heapsort(char **a, int N) {
    mov = 0;
    comp = 0;
    char w[12];
    for(int L = N/2; L >= 1; L--) {
        heapify(a, L, N);
    }
    for(int R = N; R >= 2; R--) {
        strcpy(w, a[1]);
        strcpy(a[1], a[R]);
        strcpy(a[R], w);
        mov += 3;
        heapify(a,1,R-1);
    }
}
 
void heapify(char **a, int L, int R) {
    int i = L;
    int j = 2*L;
    char x[12];
    strcpy(x, a[L]);
    mov++;
    comp++;
    if((j < R) && (strcmp(a[j], a[j+1]) < 0)) {
        j = j+1;
    }
    comp++;
    while((j <= R) && (strcmp(x,a[j]) < 0)) {
        strcpy(a[i], a[j]);
        mov++;
        i = j;
        j = 2*j;
        comp++;
        if((j < R) && (strcmp(a[j], a[j+1]) < 0)) {
            j = j+1;
        }
        comp++;
    }
    strcpy(a[i], x);
    mov++;
}
 
//METODO DE QUICKSORT
void quicksort(char **a, int N) {
    comp = 0;
    mov = 0;
    qisort(a,1,N);
}
 
void qisort(char **a, int L, int R) {
    int i = L;
    int j = R;
    int temp = floor((L+R)/2);
    char x[12];
    char w[12];
    strcpy(x,a[temp]);
    mov++;
 
    do {
        comp++;
        while (strcmp(a[i],x) < 0)
        {
            i = i + 1;
            comp++;
        }
 
        comp++;
        while (strcmp(x,a[j]) < 0)
        {
            j = j-1;
            comp++;
        }
 
        if (i <= j)
        {
            strcpy(w,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],w);
 
            mov+=3;
            i = i + 1;
            j = j - 1;
        }
    }
    while (i <= j);
    if (L < j)
    {
        qisort(a, L, j);
    }
    if (i < R)
    {
        qisort(a,i,R);
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
 
        //ORDENA - pode escolher o método que quiser
        quicksort (mes, quantidade_codigos[i]);
        printf ("mes %d -> Comparacoes = %d e Movimentacoes = %d\n", i+1, comp, mov);
 
        //SALVAR EM NOVOS ARQUIVOS
        novo_mes = fopen(new_meses[i], "wt");
        salvar_arquivo (novo_mes, quantidade_codigos[i]+1, mes);
        fclose(novo_mes);
    }
}





