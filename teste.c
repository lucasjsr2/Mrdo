//bibliotecas importantes para o programa
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

//Valores globais para usar no programa
#define LINHAS 25
#define COLUNAS 40
#define VERDE 10
#define AZUL 11
#define AMARELO 14
#define VERMELHO 12
#define BRANCO 15
#define CINZA 8

void abre_fase (char m[LINHAS][COLUNAS], char nome_arquivo[40]);
void gotoxy (int x, int y){
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowConsoleCursor(int showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
typedef struct{
	int i;
	int j;
	int c;
	int b;
	int lastDirection;
	char status;
}Component;
//Funcao principal
int main(){
	
	int keypress=0; //Tecla pressionada
	char cenario[LINHAS][COLUNAS]; //Cenario de fundo
	int i,j;
	Component mrDo;
	int numero;
	
		char matriz[LINHAS][COLUNAS];

		system("color A");
		printf("\n _________________________________ ");
		printf("\n              Mr Do!             ");
		printf("\n _________________________________ ");
		printf("\n\t 1 - Novo Jogo ");
		printf("\n\t 2 - Continuar ");
		printf("\n\t 3 - High Scores ");
		printf("\n\t 4 - Sair ");
		printf("\n _________________________________ ");
		printf("\n Entre com a opcao desejada: "); 
		scanf("%d", &numero);
		printf("\n _________________________________ \n\n ");

	if(numero == 1){
		//variavel especial para trocar cor da fonte
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//função especial que troca a cor da fonte de acordo com uma tabela de cores
		SetConsoleTextAttribute (hConsole, AZUL);	
	
		//Limpa tela antes de começar o jogo
		system("cls");
	
		//Inicializa a tela em branco
		//==============================
		for(i=0; i<LINHAS; i++){
			for(j=0; j<COLUNAS; j++){
				cenario[i][j] = '|';
			}		
		}	
		//==============================
		//Esconder o cursor da tela
		ShowConsoleCursor(0);
		//Posicao inicial do MrDo
		mrDo.i = LINHAS - 1;
		mrDo.j = COLUNAS/2;
	
		while(keypress != (int)'o'){
			gotoxy(0,0);		
		
			//Desenha o mrDo
			cenario[mrDo.i][mrDo.j] = '0';
		
			//mostrar a tela
			//==============================
			for(i=0; i<=COLUNAS+1; i++) printf("#");
				printf("\n");
		
			for(i=0; i<LINHAS; i++){
				printf("#");
			
			for(j=0; j<COLUNAS; j++){
				printf("%c", cenario[i][j]);
			}
			
			printf("#\n");
			}

		for(i=0; i<=COLUNAS+1; i++) printf("#");
		printf("\n");

			//==============================
			//pega as setas do teclado
			if(kbhit()) keypress = getch();
			else keypress = 0;
		
			switch(keypress){
				case 224:
				
					//apaga o mrDo na posição anterior
					cenario[mrDo.i][mrDo.j]= ' ';

					//descobre qual seta foi clicada
					keypress = getch();
				
					if(keypress == 72) mrDo.j++; 
					if(keypress == 75) mrDo.j--;
					if(keypress == 77) mrDo.j++; 
					if(keypress == 80) mrDo.j--;
				
					break;
				case 32:
					//tiros
					break;			
			}			
		}
	}
}
//teste
void abre_fase (char m[LINHAS][COLUNAS], char nome_arquivo[40]){
    int i;
    int j;
    FILE *fp;

    fp = fopen(nome_arquivo, "r"); //Abre o jogo

    if (fp == NULL){
        printf("Erro na abertura da fase.");
    } else {
        for(i=0; i < LINHAS; i++)
        {//t
            for(j = 0; j < COLUNAS; j++)
            {
                m[i][j] = getc(fp);
            }
        }
        fclose(fp);
    }
}