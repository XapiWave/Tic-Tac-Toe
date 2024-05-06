/*Ideas
 * 
 * Insert Name			✔
 * ABC - 123  cords		✔
 * Better User UI		✔
 * AI 				to-do
 * Rematch
 * rounds?				✔
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char game[3][3];			// horizontal -- vertical

char player1[50];
char player2[50];
int AI;					// 1 -> AI - on		||	  0 -> AI - off
int *rounds;

void name();
void reset();
void display();
void play(int player);
int Vert(char cha);
int verif();
void win();
void gamemode();

// --------------------------------------------------------------------------------------------------------------------------

int main(void)
{
	int winner=0, plays=0, player=0 ;
	rounds = &plays;
	
	srand(time(NULL));
	gamemode();

	reset();

	switch (AI)
{

	case 0:			//------------------------------------- AI off
		
	name();
	
	while(winner==0 && plays<9)
	{
		if(plays%2==0)
			player=1;
		else
			player=2;
	system("clear");
	display();
	play(player);
	winner = verif();
	
	plays++;
	}
system("clear");
display();
win(player,winner);
		break;

	case 1: 		//------------------------------------- AI on

		
	while(winner==0 && plays<9)
	{
		if(plays%2==0)
			player=1;
		else
			player=2;
	system("clear");
	display();
	play(player);
	winner = verif();
	
	plays++;
	}
system("clear");
display();
win(player,winner);
			
		break;			//}

	default:
printf("[ ERROR ] Porfavor selecione um modo de jogo");
		break;
}
return 0;
}

// --------------------------------------------------------------------------------------------------------------------------

// =====================================================================================	name

void name() {
	printf("\n\n\t\t\t\tJogador 1 -> O\n\t\t\t\tJogador 2 -> X\n\n");
	
	printf("Jogador 1, Inproduza o seu nome: ");
	scanf("%s", player1);
	printf("\nJogador 2, Inproduza o seu nome: ");
	scanf("%s", player2);
 }

// =====================================================================================	reset

void reset(){
for (int h=0; h<3; h++)
	for (int v=0; v<3; v++)
		game[h][v]=' ';
}

// =====================================================================================	display

void display(){
printf("\n\t  A   B   C\n\t|---|---|---|\n");
for (int h=0; h<3; h++){
	printf("      %d |",h+1);
	for (int v=0; v<3; v++){
		printf(" %c |",game[h][v]);
	}
	printf("\n\t|---|---|---|\n");
}
if (AI==0)
	printf("\t\t\t\t%s -> X\n\t\t\t\t%s -> O\n\n", player1, player2);
if (AI==1)
	printf("\t\t\t\tJogador -> X\n\t\t\t\tAI -> O\n\n");
printf("\tRondas-> %lu\n\n", (long)*rounds);
}

// =====================================================================================	play

void play(int player)
{
	int ver=0, hor=0, validate=0;
	char verC;
	
	if(AI == 0) {		//------------------------------------------------------------------------- AI off
	do {
		if(player==1)
			printf("\n%s", player1);
		else
			printf("\n%s", player2);
	printf(" -Insira as coordenadas || linha(numero) e a coluna(letra) || :");
	scanf("%d %c", &hor, &verC);
	hor--;
	ver= Vert(verC);
	
	if(game[hor][ver]!=' ') {
		system("clear");
		display();
		printf("Coordenadas Invalidas!"); }
	else {	validate=1;	}
		
	}while(!validate);
		    }


	if(AI == 1) {		//------------------------------------------------------------------------- AI on
		if(player==1) {			// --------------- Jogador
		do {
			printf("\nJogador, Insira as coordenadas || linha(numero) e a coluna(letra) || :");
			scanf("%d %c", &hor, &verC);
			
			hor--;
			ver = Vert(verC);
			
			if(game[hor][ver]!=' ') 	  	  {
			system("clear");
			display();
			printf("Coordenadas Invalidas!"); }
			else {  validate=1;  }
			
		}while(!validate);
					  }
			
		if(player==2) {			// --------------- AI
			do{
			
			hor = rand()%3;
			ver = rand()%3;
			
			}while(game[hor][ver] != ' ');
					  }
		    }
	



		if(player==1)
		game[hor][ver]='X';
		else
		game[hor][ver]='O';

		if(player!=1 && player != 2) {
		printf("\n\n[ ERROR ] - player not found");
		system("exit");			}
	
}

// ===================================================================================== vertical convertor

int Vert(char cha){
	int nu;
	if(cha == 'A' || cha == 'a')
		nu = 0;
	if(cha == 'B' || cha == 'b')
		nu = 1;
	if(cha == 'C' || cha == 'c')
		nu = 2;
	if(cha != 'A' && cha != 'a' && cha != 'B' && cha != 'b' && cha != 'C' && cha != 'c')
		nu = -1;
	return nu;
}

// =====================================================================================	verif

int verif(){
for(int i=0;i<3;i++) {
	if(game[i][0]==game[i][1] && game[i][0]==game[i][2] && game[i][2]!=' ')
		return 1;
	if(game[0][i]==game[1][i] && game[0][i]==game[2][i] && game[2][i]!=' ')
		return 1;
	}
	
	 if (game[0][0]==game[1][1] && game[0][0]==game[2][2] && game[1][1]!=' ')
   		 return 1;
   	 if (game[0][2]==game[1][1] && game[0][2]==game[2][0] && game[1][1]!=' ')
   		 return 1;

return 0;}

// =====================================================================================	win

void win(int player, int winner){
	if(AI==0)	{		//------------------------------------- AI off
	if (winner)
	switch(player) {
		case 1: printf("\n Parabéns, o %s venceu!!\n\n", player1);
					break;
		case 2: printf("\n Parabéns, o %s venceu!!\n\n", player2);
					break;
					}
	else
		printf("Empate!!!!\n\n");
				}
				
	if(AI==1)	{		//------------------------------------- AI on
		if (winner)
	switch(player) {
		case 1: printf("\n Parabéns, voce venceu!!\n\n");
					break;
		case 2: printf("\n Lmao, voce perdeu a um AI, KEKW\n\n");
					break;			
					}
	else
		printf("Empate!!!!\n\n");
				}
}

// =====================================================================================	gamemode

void gamemode() {
	
	printf("\nEscolha o modo de jogo . . .\n\n\n\t\t[ 1 ] -> jogar solo(vs AI)\n\t\t[ 2 ] -> Multiplayer(local)\n\n\nSua escolha -> ");
	scanf("%d", &AI);
	if(AI==2)
		AI=AI-2;
	
	system("clear");
}



