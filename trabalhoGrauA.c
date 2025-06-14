#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogar_dado(){
    return (rand() % 6)+ 1;
}

int computador(){
    
    int dado;
    int computador_total = 0;
    int extra = 0;
    
    while(extra == 0){
        dado = jogar_dado();
        printf("Valor do dado: %d\n", dado);
        if(dado == 1){
            printf("Passou a vez!\n");
            computador_total = 0;
            printf("Total Computador: ");
            return computador_total;
        }    
        
        if(dado >= 4){
            printf("Passo a vez!\n");
            printf("Total Computador: ");
            return computador_total += dado;
        }
        
        computador_total += dado;
    }
    printf("Total Computador: ");

    return computador_total; 
}

int main(){
    int x; 
    srand(time(NULL));
    
    printf("CORRIDA ATÉ 100\n");
    printf("Escolha o número de jogadores: ");
    scanf("%d", &x);
    
    int jogadores[x];
    int dado;
    int a, extra, jogar, rodada_computador;
    int computador_total = 0;
    
    for(int i = 0; i < x; i++) 
        jogadores[i] = 0;
    
    while(jogadores[x] < 100 || computador_total < 100){
        for(a = 0; a < x; a++){
            int pontuacao_rodada = 0;
            extra = 1; 
            printf("Vez do jogador %d!\n", a + 1);
            printf("Digite 1 para jogar os dados: ");
            scanf("%d", &jogar);
            while(extra == 1){
                dado = jogar_dado();
                printf("Valor do dado: %d\n", dado);
                if(dado == 1){
                    printf("Passou a vez!\n");
                    pontuacao_rodada = 0;
                    break;
                }
                
                pontuacao_rodada += dado;
                printf("Deseja jogar o dado de novo? (1-sim 2-não): ");
                scanf("%d", &extra);
            }
            
            jogadores[a] += pontuacao_rodada;
            printf("Total jogador %d: %d\n", a + 1, jogadores[a]);
        }
        
        printf("Vez do Computador!\n");
        rodada_computador = computador();
        computador_total += rodada_computador;
        printf("%d\n", computador_total);
        if(computador_total >= 100)
            printf("Computador Venceu!");
    }    
    
    return 0;
}