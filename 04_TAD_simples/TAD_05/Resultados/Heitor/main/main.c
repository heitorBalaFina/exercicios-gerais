#include <stdio.h>
#include <string.h>
#include "conta.h"
#include "usuario.h"

int main(){
    int opcao = -1, qtdUsers = 0;
    int i, contador = 0, numConta = 0;
    float valor;
    char nome[50], cpf[15];
    tConta conta;

    scanf("%d", &qtdUsers);
    tConta contas[qtdUsers];

    while (opcao){
        scanf("%d", &opcao);
        switch (opcao){
            case 0:
            return 0;
            break;
        case 1:
            scanf("%d %f", &numConta, &valor);
            for(i = 0; i < qtdUsers; i++){
                if(VerificaConta(contas[i], numConta)){
                    contas[i] = SaqueConta(contas[i], valor);
                }
            }
            break;
        case 2:
            scanf("%d %f", &numConta, &valor);
            for(i = 0; i < qtdUsers; i++){
                if(VerificaConta(contas[i], numConta)){
                    contas[i] = DepositoConta(contas[i], valor);
                }
            }
            break;
        case 3:
            if(contador < qtdUsers){
                scanf(" %49[^ ] %14[^ ] %d", nome, cpf, &numConta);
                conta = CriaConta(numConta, CriaUsuario(nome, cpf));
                contas[contador] = conta;
                contador++;
            }
            break;
        case 4:
            printf("===| Imprimindo Relatorio |===\n");
            for(i = 0; i < qtdUsers; i++){
                ImprimeConta(contas[i]);
                printf("\n");
            }
            break;
        }
    }
    return 0;
}