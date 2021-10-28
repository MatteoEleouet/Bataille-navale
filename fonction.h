#ifndef __FONCTION__H__
#define __FONCTION__H__

// MET TOUT LES APPELS DE FONCTION (prototypes)


// Etat du Jeux


#define ColMax 10	// GOOD
#define lignMax 10	// idem
// POUR CREER LE TABLEAU
#define Boat 1
#define Libre 0

#define Coule -1
#define Plouf -2
// POUR LE PLACEMENT BATEAU
#define playerMaxBoat 6
#define OrdiMaxBoat 6

// LES APPELS FONCTIONS		
void VerifFinDeJeu();
void tableCreation();
void tableCreationEnemy() ;
void Affi_Flotte();
void affichage_seamap();
void PlacementBoat();
void PlacementBoatEnemy();
void affichage_Tire();
void Affi_seamapEnemy();
void ShotEnemy();
void Shot();
void menu();




#endif
