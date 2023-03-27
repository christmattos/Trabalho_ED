#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOGADORES 50

typedef struct {
    char nome[50];
    int prioridade;
    int equipe;
} Jogador;

char estadoDeJogo;
int num_jogadores = 0;
int num_jogadores_jogando = 0;
Jogador jogadores[MAX_JOGADORES];
Jogador jogadores_jogando[MAX_JOGADORES];
char jogadorDaVez[50];

void inserir_jogador() {
    if (num_jogadores == MAX_JOGADORES) {
        printf("Nao e possivel inserir mais jogadores.\n");
        return;
    }

    Jogador novo_jogador;
    printf("Digite o nome do jogador: ");
    scanf("%s", novo_jogador.nome);
    printf("Digite a prioridade do jogador: ");
    scanf("%d", &novo_jogador.prioridade);
    printf("Digite a equipe do jogador (1 ou 2): ");
    scanf("%d", &novo_jogador.equipe);

    jogadores[num_jogadores] = novo_jogador;
    num_jogadores++;
}

void listar_jogadores() {
    printf("Jogadores:\n");
    for (int i = 0; i < num_jogadores; i++) {
        printf("%d - Nome: %s | Prioridade: %d | Equipe: %d\n", i+1, jogadores[i].nome, jogadores[i].prioridade, jogadores[i].equipe);
    }
}

void remover_jogador() {
    if (num_jogadores == 0) {
        printf("Nao ha jogadores para remover.\n");
        return;
    }

    printf("Escolha o jogador que deseja remover:\n");
    listar_jogadores();
    int opcao;
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > num_jogadores) {
        printf("Opcao invalida.\n");
        return;
    }

    for (int i = opcao-1; i < num_jogadores-1; i++) {
        jogadores[i] = jogadores[i+1];
    }

    num_jogadores--;
}

void iniciar_partida() {
    if (num_jogadores < 2) {
        printf("Nao ha jogadores suficientes para iniciar a partida.\n");
        return;
    }

    int num_equipe_1 = 0, num_equipe_2 = 0;

    for (int i = 0; i < num_jogadores; i++) {
        if (jogadores[i].equipe == 1) {
            num_equipe_1++;
        } else {
            num_equipe_2++;
        }
    }

    if (num_equipe_1 < 1 || num_equipe_2 < 1) {
        printf("Nao ha jogadores suficientes em cada equipe para iniciar a partida.\n");
        return;
    }

    estadoDeJogo = 'b';
}

int comparador(const void *v1, const void *v2)
{
    const Jogador *p1 = (Jogador *)v1;
    const Jogador *p2 = (Jogador *)v2;
    if (p1->prioridade < p2->prioridade)
        return -1;
    else if (p1->prioridade > p2->prioridade)
        return +1;
    else
        return 0;
}

void mostrar_ordem_e_vez(){
    for (int i = 0; i < num_jogadores; i++)
    {
        jogadores_jogando[num_jogadores_jogando] = jogadores[i];
        num_jogadores_jogando++;
    }
    qsort(jogadores_jogando, num_jogadores_jogando, sizeof(Jogador), comparador); 
    for (int i = 0; i < num_jogadores_jogando; i++) {
        printf("Nome: %s | Prioridade: %d | Equipe: %d\n", jogadores_jogando[i].nome, jogadores_jogando[i].prioridade, jogadores_jogando[i].equipe);
    }
    strcpy (jogadorDaVez, jogadores_jogando[0].nome);
    printf("A vez agora é de: %s", jogadorDaVez);
}

void encerrar_turno(){

}

void remover_jogador_turno(){

}

void encerrar_jogo_turno(){

}

void inserir_jogador_turno(){
    
}

int main() {
    int opcao;
    estadoDeJogo = 'a';
    while(1){
        if (estadoDeJogo == 'a'){
            while (opcao != 5){
                if (estadoDeJogo == 'b'){
                    break;
                }
                printf("\n1 - Inserir jogador\n2 - Listar jogadores\n3 - Remover jogador\n4 - Iniciar Partida\n5 - Sair\n");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        inserir_jogador();
                        break;
                    case 2:
                        listar_jogadores();
                        break;
                    case 3:
                        remover_jogador();
                        break;
                    case 4:
                        iniciar_partida();
                        break;
                    case 5:
                        printf("Saindo...\n");
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
            }
        }
        else if (estadoDeJogo == 'b'){
            while (opcao != 5){
                if (estadoDeJogo == 'a'){
                    break;
                }
                printf("\n1 - Encerrar Turno\n2 - Remover Jogador\n3 - Encerrar Jogo\n4 - Inserir Jogador\n5 - Sair\n");
                mostrar_ordem_e_vez();
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        encerrar_turno();
                        break;
                    case 2:
                        remover_jogador_turno();
                        break;
                    case 3:
                        encerrar_jogo_turno();
                        break;
                    case 4:
                        inserir_jogador_turno();
                        break;
                    case 5:
                        printf("Saindo...\n");
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
            }
        }
    }
    return 0;
}