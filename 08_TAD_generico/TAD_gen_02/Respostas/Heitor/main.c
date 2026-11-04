#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

int main(){
    int opcao = -1, tipo = -1, numEle = -1;
    tGerenciador *geren = CriaGerenciador();
    
    while(scanf("%d", &opcao) == 1){
        
        printf("\nEscolha uma opcao:\n");
        printf("    (1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote especifico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");
        
        if(opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d\n", &tipo, &numEle);
            if(tipo != 1 && tipo != 0){
                printf("\nDigite um tipo valido!");
                continue;
            }
            tPacote *pacote = CriaPacote(tipo, numEle);
            LePacote(pacote);
            AdicionaPacoteNoGerenciador(geren, pacote);
        } else if(opcao == 2){
            scanf("%d\n", &numEle);
            ImprimirPacoteNoIndice(geren, numEle);
        } else if(opcao == 3){
            ImprimirTodosPacotes(geren);
            break;
        }
        continue;
    }

    DestroiGerenciador(geren);
    
    return 0;
}