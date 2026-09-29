#include "vetor.h"
#include "stdio.h"

void LeDadosParaVetor(int * vet, int tam){
    int posicao;
    for(posicao = 0; posicao < tam; posicao++){
        scanf(" %d", &vet[posicao]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    int posicao;
    for(posicao = 0; posicao < tam; posicao++){
        printf("%d ", n[posicao]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int posicao = 0;
    *paraTrocar = vet[posicao];
    for(posicao = 0; posicao < tam; posicao++){
        if(*paraTrocar > vet[posicao]) *paraTrocar = vet[posicao];
    }
}

void OrdeneCrescente(int * vet, int tam){
    int i, j, maior;
    for(i = 0; i < tam; i++)
    {
        for(j = i; j < tam; j++)
        {
            if(vet[i] > vet[j])
            {
                maior = vet[i];
                vet[i] = vet[j];
                vet[j] = maior;
            }
        }
    }
}