#include <stdio.h>
#include <stdlib.h>
int main() {
 int scoreJoueur = 0;
 int scoreOrdi = 0;
 int manche = 1;
 int choixJoueur;
 int choixOrdi;
 printf("=== PIERRE - FEUILLE - CISEAUX - LÉZARD - SPOCK (2 points d'écart ou 7 manches max) ===\n");
 printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lézard, 5 = Spock\n\n");
 // La partie continue tant qu'on n'a pas dépassé 7 manches
 // ET que l'écart de points est inférieur à 2
 while (manche <= 7 && abs(scoreJoueur - scoreOrdi) < 2) {
 printf("--- Manche %d (7 max) ---\n", manche);
 // Saisie du joueur
 printf("Votre choix (1, 2, 3, 4 ou 5) : ");
 scanf("%d", &choixJoueur);
 // Choix aléatoire de l'ordinateur (1 à 5)
 choixOrdi = (rand() % 5) + 1;
 printf("L'ordinateur a choisi : %d\n", choixOrdi);
 // Détermination du gagnant de la manche
 if (choixJoueur == choixOrdi) {
 printf("Égalité !\n");
 } else if ((choixJoueur == 1 && choixOrdi == 3) || // Pierre écrase Ciseaux
 (choixJoueur == 1 && choixOrdi == 4) || // Pierre écrase Lézard
 (choixJoueur == 2 && choixOrdi == 1) || // Feuille recouvre Pierre
 (choixJoueur == 2 && choixOrdi == 5) || // Feuille réfute Spock
 (choixJoueur == 3 && choixOrdi == 2) || // Ciseaux coupent Feuille
 (choixJoueur == 3 && choixOrdi == 4) || // Ciseaux décapitent Lézard
 (choixJoueur == 4 && choixOrdi == 2) || // Lézard mange Feuille
 (choixJoueur == 4 && choixOrdi == 5) || // Lézard empoisonne Spock
 (choixJoueur == 5 && choixOrdi == 1) || // Spock vaporise Pierre
 (choixJoueur == 5 && choixOrdi == 3)) { // Spock casse Ciseaux
 printf("Vous gagnez cette manche !\n");
 scoreJoueur = scoreJoueur + 1;
 } else {
 printf("L'ordinateur gagne cette manche !\n");
 scoreOrdi = scoreOrdi + 1;
 }
 printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
 manche = manche + 1;
 }
 // Bilan de la partie
 printf("=== FIN DE LA PARTIE ===\n");
 printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);
 if (scoreJoueur > scoreOrdi) {
 printf("Bravo, vous avez gagné la partie !\n");
 } else if (scoreOrdi > scoreJoueur) {
 printf("L'ordinateur remporte la partie...\n");
 } else {
 printf("Match nul parfait !\n");
 }
 return 0;
}