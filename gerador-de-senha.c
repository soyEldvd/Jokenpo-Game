#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------------FUNÇÕES PRINCIPAIS------------
void inicializar();
void geraSenhas();
//------------------------------------------
int main (){
    srand(time(NULL));//INICIA FUNÇÃO A GERAR NUMEROS ALEATORIOS

    int tamanho_da_senha;
    inicializar();//CHAMA A FUNÇÃO PARA INICIALIZAR O PROGRAMA
    printf("Digite o tamanho da senha que você deseja:");
    scanf("%d", &tamanho_da_senha);

    if(tamanho_da_senha < 9){
        printf("o valor ideal de senha precisa ser diferente de 0 e deve ter, no minimo, 8 caracteres.\n");
    } else{
    geraSenhas(tamanho_da_senha);
    }

    return 0;
}

void inicializar(){
    printf("\n#------------BEM VINDO AO GERADOR DE SENHAS------------#\n");
    printf("#             develop by: DEIVID CALIXTO               #\n");
    printf("#------------------------------------------------------#\n\n");
}

void geraSenhas(int tamanho_da_senha){
    int i, aleatorio;//INICIA UM I PARA O LAÇO E UMA VARIAVEL PARA GUARDAR VALORES ALEATORIOS

//------------VARIAVEIS QUE GUARDAM UM TIPO DE CARACTERER QUE GERARÁ A SENHA-------------------
    char num[10] = "1234567890";
    char letras[26] = "abcdefghijklmnopqrstuvwxyz"; 
    char letrasM[26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char sinais[10] = "!@#$*+-<>=";
//----------------------------------------------------------------------------------------------
    char senha[tamanho_da_senha];

    for(i = 0; i < tamanho_da_senha; i++){
        aleatorio = rand()%4 + 1; //GERA UM VALOR ALEATORIO DE 1 A 4
        switch (aleatorio){
        case 1:
            senha[i] = num[rand()%10];
            break;
        case 2:
            senha[i] = letras[rand()%26];
            break;
        case 3:
            senha[i] = letrasM[rand()%26];
            break;
        case 4:
            senha[i] = sinais[rand()%10];
            break;
        }
    }

    printf("Senha Gerada: %s\n", senha);
}
