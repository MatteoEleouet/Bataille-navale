#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"	// On inclut fonction.h

int seamap[10][10];				// Utile à la construction de la seamap
int ennemie_seamap[10][10];		// Utile à la construction de la seamap ennemi
int EtatJeux = 1;				// S'il est égal à 0 c'est que le programme se ferme.
int Ordi_life_Boat=6;   		// Utile pour le compteur de bateaux restant.
int Boat_life=6;        		// Utile pour le compteur de bateaux restant.
int boatDestroy=0;        		// Compteur de bateau détruit, si le compteur monte jusqu'à 6 nous perdons.
int ShotCounter=0;           	// Compteur de tir.
int ShotX,ShotY;				// // Variable de la cordonnée de tire X & Variable de la cordonnée de tire Y
int boatLifeEnemy=6;			// Nombre de bateau enemy en vie, si cette vleur tombe à 0 le void end_game s'active.
int boatDestroyEnemy=0;			// Nombre de bateau ennemie détruit.
int BoatX,BoatY;				// Permet le placement d'un placement sur les coordonnées X & Permet le placement d'un placement sur les coordonnées Y
int numBoat = 1;				// Numérotation pour savoir le combientième bateau on place
int CELL;						// Cellule map adverse
int ShotEnemyX,ShotEnemyY;		// Tir de l'ordinateur sur l'axe X & Tir de l'ordinateur sur l'axe Y
int choix = 0 ;					// Choix menu pour choisir si nous allons tirer ou bien quitter le jeu par lâcheté. ;)
int NbTour = 0 ;				// Compteur de tour joué

int main(void)
{
	//on appelle la fonction tableCreation dedans la fonction main pour générer la seamap avant le début de la partie
	tableCreation();
	//on appelle les fonctions PlacementBoat et PlacementBoatEnemy dans la fonction main pour placer les bateau avant le début de la partie
	PlacementBoat();
	PlacementBoatEnemy();
	//on appelle la fonction VerifFinDeJeu dans la fonction main pour renvoyer au menu à chaque fonction utilisé tant que EtatJeux est égale à 1(True), si il est égale à 0(False) le programme s'arrete.
	VerifFinDeJeu();
	do
    {
		menu();
	} while (EtatJeux == 1);


	return 0;
}

 
