/*Ideas
 * 
 * Insert Name			✔
 * ABC - 123  cords		✔
 * Better User UI		✔
 * AI 				to-do
 * rounds?				
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char game[3][3];

char player1[50];
char player2[50];
int AI;					// 1 -> AI - on		||		0 -> AI - off

void name();
void reset();
void display();
void play(int player);
int Vert(char cha);
int verif();
void win();
void gamemode();

// --------------------------------------------------------------------------------------------------------------------------

int main(void){
	
	int winner=0, plays=0, player=0 ;
	
	srand(time(NULL));
	
	gamemode();
	reset();
	
	/* -------------------------- */ if(AI==0) {
	name();
	
	while(winner==0 && plays<=9)
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
	/* ------------------------------------- */ }
	
				if(AI==1) {
		
	while(winner==0 && plays<=9)
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
							}


return 0;
}

// --------------------------------------------------------------------------------------------------------------------------

// ====================	name

void name() {
	printf("\n\n\t\t\t\tJogador 1 -> O\n\t\t\t\tJogador 2 -> X\n\n");
	
	printf("Jogador 1, Inproduza o seu nome: ");
	scanf("%s", player1);
	printf("\nJogador 2, Inproduza o seu nome: ");
	scanf("%s", player2);
 }

// ====================	reset

void reset(){
for (int h=0; h<3; h++)
	for (int v=0; v<3; v++)
		game[v][h]=' ';
}

// ====================	display

void display(){
printf("\n\t  A   B   C\n\t|---|---|---|\n");
for (int v=0; v<3; v++){
	printf("      %d |",v+1);
	for (int h=0; h<3; h++){
		printf(" %c |",game[v][h]);
	}
	printf("\n\t|---|---|---|\n");
}
if (AI==0)	{
	printf("\t\t\t\t%s -> O\n\t\t\t\t%s -> X\n\n", player1, player2);	}
if (AI==1)	{
	printf("\t\t\t\tJogador -> O\n\t\t\t\tAI -> X\n\n");	}

}

// ====================	play

void play(int player){
	int ver=0, hor=0, validate=0;
	char verC;
	
	if(AI == 0) {
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

//------------------------------------------------------------------------------------
	
	if(AI == 1) {
		if(player==1) {			// --------------- Jogador
		do {
			printf("\nJogador, Insira as coordenadas || linha(numero) e a coluna(letra) || :");
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
			
		if(player==2) {			// --------------- AI
			do{
			
			ver = rand()%3;
			hor = rand()%3;
			
			}while(game[ver][hor] != ' ');
					   }
				}
	

		if(player==1)
		game[hor][ver]='O';
		else
		game[hor][ver]='X';
	
}

// ==================== vertical convertor

int Vert(char cha){
	int nu;
	if(cha == 'A' || cha == 'a')
		nu = 1;
	if(cha == 'B' || cha == 'b')
		nu = 2;
	if(cha == 'C' || cha == 'c')
		nu = 3;
	nu--;
	return nu;
}

// ====================	verif

int verif(){
	for(int i=0;i<3;i++) {
		if(game[i][0]==game[i][1] && game[i][0]==game[i][2] && game[i][2]!=' ')
			return 1;
		if(game[0][i]==game[1][i] && game[0][i]==game[2][i] && game[2][i]!=' ')
			return 1;
	}
	
	 if (game[0][0]==game[1][1] && game[0][0]==game[2][2] && game[2][2]!=' ')
   		 return 1;
   	 if (game[0][2]==game[1][1] && game[0][2]==game[2][0] && game[1][1]!=' ')
   		 return 1;

return 0;}

// ====================	win

void win(int player, int winner){
	if(AI==0)	{
	if (winner)
	switch(player) {
		case 1: printf("\n Parabéns, o %s venceu", player1);
					break;
		case 2: printf("\n Parabéns, o %s venceu", player2);
					break;
					}
	else
		printf("Empate!!!!");
				}
				
	if(AI==1)	{
		if (winner)
	switch(player) {
		case 1: printf("\n Parabéns, voce venceu");
					break;
		case 2: printf("\n Lmao, voce perdeu a um AI, KEKW");
					break;			
					}
	else
		printf("Empate!!!!");
				}
}

// ====================	gamemode

void gamemode() {
	
	printf("\nEscolha o modo de jogo . . .\n\n\n\t\t[ 1 ] -> jogar solo(vs AI)\n\t\t[ 2 ] -> Multiplayer(local)\n\n\nSua escolha -> ");
	scanf("%d", &AI);
	if(AI==2)
		AI=AI-2;
	
	system("clear");
}

