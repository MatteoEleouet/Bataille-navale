#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

/*
 J'ai mal programmé mes variables, j'ai fait que du global au début donc pour rattrapé le tir j'utilise l'instruction 'extern' 
(Je précise que je voulais abosulement utiliser de la programmation modulaire pour avoir un code assez propre et que je vennais de d'apprendre ce chapitre.)
La fonction 'extern' indique au compilateur qu'il sagit d'une variable qui a été définie ailleurs dans le programme, Cette déclaration n'utilise donc pas plus de mémoire.
*/
extern int seamap[10][10];			
extern int ennemie_seamap[10][10];
extern int EtatJeux;
extern int Ordi_life_Boat; 
extern int Boat_life;        
extern int boatDestroy;        
extern int ShotCounter;           
extern int ShotX,ShotY;
extern int boatLifeEnemy;
extern int boatDestroyEnemy;
extern int BoatX,BoatY;
extern int numBoat;
extern int CELL;
extern int ShotEnemyX,ShotEnemyY;
extern int choix;
extern int NbTour;


// PLEIN DE VOID, j'aurai limite pu faire un 3ème fichier fonction.c.


//=========================================================================


//fonction permettant de dire qui à gagné et de mettre fin au jeux
void VerifFinDeJeu()
{
    if ((boatLifeEnemy==0)||(Boat_life==0))	// Si l'ennemie ou l'utilisateur n'a plus de bateau : 
    {
        EtatJeux=0;
        if(boatLifeEnemy=0)
        {
            printf("Vous avez perdu ! \n bawawahaha t'es trop nul !!!\n\n");
        }
        else printf("Vous avez gagne !\nMais ce n'est que de la chance, je ferai mieux la prochaine fois.");
    }
}

//fonction permettant de générer la seamap
void tableCreation()
{
	for(int il=0;il<10;il++)
    {
        for(int ic=0;ic<10;ic++)
        {
            seamap[il][ic]=Libre;
        }
	}
}
//fonction permettant de générer la map de l'ennemie
void tableCreationEnemy() {
	for(int il=0;il<10;il++) {
		for(int ic=0;ic<10;ic++){
			ennemie_seamap[il][ic]=Libre;
		}
	}
}
//fonction permettant d'afficher l'état de sa flotte et de la flotte ennemie
void Affi_Flotte()
{
	printf("\nNombre de bateau de notre flotte en vie = %d\n",Boat_life);
	printf("Nombre de bateau ennemie en vie = %d\n\n",boatLifeEnemy);
	printf("============================================\n\n");
	printf("Nombre de bateau de notre flotte couler = %d\n",boatDestroy);
	printf("Nombre de bateau ennemie couler = %d\n\n",boatDestroyEnemy);
	printf("============================================\n\n");
	printf("Nombre de tir = %d\n",ShotCounter);
}

//=========================================================================


//fonction permettant d'afficher la seamap
void affichage_seamap(){
	printf("===SEAMAP===\n");
	for(int il=-1;il<10;il++) {
		if (il == -1) {
			printf("  ");
		} else {
			printf("%d ",il);
		}

		for(int ic=0;ic<10;ic++) {
			if (il == -1) {
				printf(" %d ",ic);
			} else {

				switch(seamap[il][ic]){
					case Boat:
						printf(" B ");
						break;
					case Libre:
						printf(" ~ ");
						break;
					case Coule:
						printf(" X ");
						break;
					case Plouf:
						printf(" o ");
						break;
				}
			}
		}
		printf("\n");
	}
}

//=========================================================================


//fonction permettant de placer ses bateaux sur la seamap
void PlacementBoat()
{
	printf("PLACEZ VOS BATEAUX\n\n");
    srand(time(NULL));

    for(int i=0;i<playerMaxBoat;i++)
    {
        printf("entrez la ligne d'un bateau %d : ",numBoat);
        scanf("%d",&BoatX);

        printf("entrez la colone d'un bateau %d : ",numBoat);
        scanf("%d",&BoatY);


        seamap[BoatX][BoatY]=1;
        numBoat++;
        printf("\n");
    }
}













//fonction permettant à l'ordi de placer ses bateaux aléatoirement
void PlacementBoatEnemy()
{
	srand(time(NULL));			// Permet d'avoir une génération différente pour le placement des bateaux adverse sur plusieurs partie
    int i = 0;
	while(i<+6)
    {
		int RndX,RndY;
		RndX = 1+rand()%9;		// Pour que l'ordi ne choisissent pas de prendre une valeur supérieur à 9
		RndY = 1+rand()%9;		// On doit ajouter '+1' au résultat pour que 9 soit compris. (Avant c'était les valeurs entre 0 et 8, maintenant ça sera des valeurs compris entre 1 et 9)


		if (ennemie_seamap[RndX][RndY] != 1)
        {
			ennemie_seamap[RndX][RndY]=1;
			i++;
		}
	}
}


//=========================================================================


//fonction permettant d'afficher la map sur laquel le joueur à tiré
void affichage_Tire()
{
	for(int il=-1;il<10;il++)
        {
		if (il == -1)
		{
			printf("  ");
		} else
		{
			printf("%d ",il);
		}

	for(int ic=0;ic<10;ic++)
        {
		if (il == -1)
		{
				printf(" %d ",ic);
		} else
		{

			switch(seamap[il][ic]){
				case Coule:
					printf(" X "); // Affiche les bateaux détruit
					break;
				case Plouf:
					printf(" o "); // Affiche les tires qui n'ont pas touché de bateau
					break;
			  	default:
			  		printf(" ~ "); // Si ni l'un si l'autre
			  		break;
				}
			}
		}
		printf("\n");
	}
}



//=========================================================================


//fonction permettant d'afficher la map de l'ennemie pour finir le programme vite
void Affi_seamapEnemy() {
printf("===MAP ENNEMIE===\n\n");
printf("    0  1  2  3  4  5  6  7  8  9 \n");
int CELL;
    for(int il=0;il<lignMax;il++)
        {
            printf(" %d ",il);
            for( int ic=0;ic<ColMax;ic++)
            {
                CELL=ennemie_seamap[il][ic];
                switch(CELL)
                {
                case Libre :
                	printf(" ~ ");
                    break;
                case Boat :
                	printf(" B ");
                    break;
                case Plouf :
                	printf(" O ");
                    break;
                case Coule :
                	printf(" X ");
                    break;
                }
            }
            printf("\n");
        }
}


//=========================================================================


//fonction permettant à l'ennemie de tirer aléatoirement
void ShotEnemy()
{

	if (EtatJeux == 1)			// Si il est égale à 1 c'est que tout les bateaux d'une équipe ne sont pas détruit
    {
		printf("=====L'ENNEMIE TIRE====\n\n");
	    srand(time(NULL));
	    ShotEnemyX=rand()%9;
	    ShotEnemyY=rand()%9;
	    if (seamap[ShotEnemyX][ShotEnemyY]==Boat)
	    {
	        seamap[ShotEnemyX][ShotEnemyY]=Coule;
	        Boat_life--;		// Puis ce que l'ordinateur indique les coordonnés d'un bateau, on soustrait 1 au compteur de bateau vivant de l'utilisateur pour que dans le cas qu'il n'ait plus de bateau, un message lui indiquant qu'il a perdu soit affiché.
	        boatDestroy++;  	// On incrémente le nombre de bateau détruit.
	        // Es ce que j'aurai pu faire 'boatDestroy -= -1;' ???
	        printf("GLOUGLOU, navire coule\n");
	    }
	    else if (seamap[ShotEnemyX][ShotEnemyY]==Coule);
	    else seamap[ShotEnemyX][ShotEnemyY]=Plouf;
	    {
	        printf("PLOUF\n");
        }
        printf("%d %d",ShotEnemyX,ShotEnemyY);
	}
	VerifFinDeJeu();
}


//=========================================================================


//fonction permettant de tirer sur l'ennemie
void Shot()
{
	VerifFinDeJeu();
	printf("=====TIRER SUR L'ENNEMIE====\n\n");
    printf("entrez la coordonnee ligne de tire = ");
    scanf("%d",&ShotX);
if (ShotX>=0 && ShotX<=9)
    {
	    printf("bon\n");
	    printf("entrez la coordonne colonne de tire =");
	    scanf("%d",&ShotY);
	    if (ShotY>=0 && ShotY<=9)
	    {
        	printf("bon\n");
       		if (ennemie_seamap[ShotX][ShotY]==Boat)
       	 	{
	            ennemie_seamap[ShotX][ShotY]=Coule;
	            boatLifeEnemy--;
	            boatDestroyEnemy=boatDestroyEnemy+1;
	            printf("GLOUGLOU, navire coule\n");
        	}
            else if (ennemie_seamap[ShotX][ShotY]==Coule);
            else ennemie_seamap[ShotX][ShotY]=Plouf;
            {
                printf("PLOUF\n");
            }
        }
    }
}


//=========================================================================


//fonction permettant d'afficher le menu et d'y faire différent choix
void menu() {
	do
	{
	printf("\n================ M E N U ================");
	printf("\n0 -- Quitter le jeux\n");
	printf("\n1 -- Tire : entrer les coordonnees Li et Ci");
	printf("\n2 -- Affichage de la matrice de tire");
	printf("\n3 -- Affichage de l'etat de la flotte");
	printf("\n4 -- Affichage SEAMAP!");
	printf("\n5 -- Affichage map ennemie");
	printf("\n faite votre choix : ");
	scanf("%d",&choix);

}while(!(choix == 0 || choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5)); // <-- Coup de génie pour obligé l'utilisateur à rentré une valeur correspondant à un choix mais s'il saisit une chaine de caractère le programme bug...
	
	switch(choix)
	{
		case (1):
			Shot();
			ShotEnemy();
			NbTour++;
			break;
		case (2):
			printf("\nVous avez choisi d'afficher la matrice de Tire\n\n");
			affichage_Tire();
			break;
		case (3):
			printf("ETAT_Flotte");
			Affi_Flotte();
			break;
		case (4):
			printf("\nVous avez choisi d'Afficher la SEAMAP\n\n");
			affichage_seamap();
			break;
		case (5):
			Affi_seamapEnemy();
			break;
		case (0):
			printf("END");
			EtatJeux = 0;
			VerifFinDeJeu();
			break;
			VerifFinDeJeu();
	}
	printf("\n ");
}

//=========================================================================




