#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*VARIAVEIS IMPORTANTES*/
int pontos_cpu = 0;
int pontos_jogador = 0;
/*-----------------------*/

/*FUNÇÕES UTILIZADAS*/
void inicializar();
void checar(int jogador, int cpu);
int pergunta(int resposta);
void placar();
/*------------------------*/

/*FUNÇÃO MAIN*/
int main(){
	srand(time(NULL));
	int jogador, cpu, resposta;
	inicializar();
	checar(jogador, cpu);
	
	while(1 != 0){
		if(pergunta(resposta) == 1){
			inicializar();
			checar(jogador, resposta);
		}else {
			placar();
			printf("\n\nobrigado por jogar :)\n\n");
			break;
		}
	}
	

	return 0;
}
/*------------------------------------------*/

void inicializar(){
	printf("\nbem vindos ao jogo de pedra, papel ou tesora!\n");
	printf("1 para PAPEL\n2 para PEDRA\n3 para TESOURA\n");
}
void checar(int jogador, int cpu){
	scanf("%d", &jogador);
	placar();
	switch(jogador){
		case 1:
			printf("\nO JOGADOR ESCOLHEU PAPEL\n");
		break;
		case 2:
			printf("\nO JOGADOR ESCOLHEU PEDRA\n");
		break;
		case 3:
			printf("\nO JOGADOR ESCOLHEU TESOURA\n");
		break;
	}
	if(jogador > 3 && jogador < 1){
		exit(0);
	}
	cpu = rand()%3 + 1;

	switch(cpu){
		case 1:
			printf("A CPU ESCOLHEU PAPEL\n");
		break;
		case 2:
			printf("A CPU ESCOLHEU PEDRA\n");
		break;
		case 3:
			printf("A CPU ESCOLHEU TESOURA\n");
		break;
	}

	if((jogador == 1 && cpu == 2) || (jogador == 2 && cpu == 3) || (jogador == 3 && cpu == 1)){
		printf("\nVOCE VENCEU!\n");
		pontos_jogador++;
	}else if((jogador == 1 && cpu == 3) || (jogador == 2 && cpu == 1) || (jogador == 3 && cpu ==2)){
		printf("\nVOCE PERDEU!\n");
		pontos_cpu++;
	}else {
		printf("\nEMPATOU\n");
	}
}
int pergunta(int resposta){
	printf("\nVOCE DESEJA JOGAR NOVAMENTE?\n");
	printf("1 - SE SIM\nqualquer tecla - SE NÃO\n");
	scanf("%d", &resposta);

	if(resposta == 1){
		return 1;
	}else {
		return 0;
	}
}
void placar(){
    printf ("\n");
    printf (" #-------- PLACAR --------#\n");
    printf (" #   %d Jogador X CPU %d    #\n", pontos_jogador, pontos_cpu);
    printf (" #------------------------#\n");
}
