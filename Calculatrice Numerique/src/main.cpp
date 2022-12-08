/*
  Titre      : Realisation d'une calculatrice Ardunino avec un  clavier numerique.
  Auteur     : Ernest Samuel Andre
  Date       : 06/12/2022
  Description: Ce programme a pour but de creer une calcultraice numerique qui est rouler sur um ardunino.
  Version    : 0.0.1
*/

/*C'est un programme pour une calculatrice avec un arduino MKr1000*/

#include <arduino.h> // biblioyheque pour l'utilisation de l'arduino
#include <keypad.h> // Bibliotheque pour l'utilisation du clavier 

// Declaration des constantes
#define LIGNES 4   // lignes verticales du clavier
#define COLONNES 4 // colonnes horizontales du clavier

// Declaration des variables que l'on va utiliser dans le programme pour notre calculatrice.
char appuyerUneTouche;
double nbr1 = 0.0;
double nbr2 = 0.0;
float resultat = 0.0;

// Definition du clavier
char clavier4X4[LIGNES][COLONNES] = {{'1', '2', '3', 'A'},
                                     {'4', '5', '6', 'B'},
                                     {'7', '8', '9', 'C'},
                                     {'*', '0', '#', 'D'}};

byte lignesClavier4X4Pins[4] = {6, 7, 8, 9}; // connection du clavier au pins de notre Arduino.
byte colonnesClavier4X4Pins[4] = {10, 11, 12, 13};   // connection du clavier au pins de notre Arduino

Keypad clavier = Keypad(makeKeymap(clavier4X4), lignesClavier4X4Pins, colonnesClavier4X4Pins, LIGNES, COLONNES); // Creation de notre Clavier.

void setup()
{
  Serial.begin(9600); // initialisation du moniteur serie pour la lecture des entrees et sorties pour les calcules.
  delay(1000);        // delai d'attente pour le moniteur serie pour afficher et executer les calculs.
}

void loop()
{

  nbr1 = nbr2 = 0; // renitialisation des variables d'operation pour passer a une autre operation

  appuyerUneTouche = clavier.waitForKey();
  Serial.print(" \nDonnez le premier chiffre pour votre calcul : ");
  appuyerUneTouche = clavier.waitForKey(); // pour stocker la valeuur de la touche appuyee dans un caractere.
  switch (appuyerUneTouche) // Choix sur clavier qui va conresondre a la valeur du premier chiffre
  {
  case '0':
    nbr1 = 0;
    break;

  case '1':
    nbr1 = 1;
    break;

  case '2':
    nbr1 = 2;
    break;

  case '3':
    nbr1 = 3;
    break;

  case '4':
    nbr1 = 4;
    break;

  case '5':
    nbr1 = 5;
    break;

  case '6':
    nbr1 = 6;
    break;

  case '7':
    nbr1 = 7;
    break;

  case '8':
    nbr1 = 8;
    break;

  case '9':
    nbr1 = 9;
    break;
  }

  Serial.println(nbr1); // affichage du premier chiffre
  delay(1500); // delai d'attente pour la demande du deuxieme chiffre par l'utilisateur

  Serial.print("\nDonnez le deuxieme chiffre pour votre calcul : ");
  appuyerUneTouche = clavier.waitForKey(); // pour stocker la valeuur de la touche appuyee dans un caractere.
  switch (appuyerUneTouche) // Choix sur clavier qui va conresondre a la valeur du deuxieme chiffre
  {
  case '0':
    nbr2 = 0;
    break;

  case '1':
    nbr2 = 1;
    break;

  case '2':
    nbr2 = 2;
    break;

  case '3':
    nbr2 = 3;
    break;

  case '4':
    nbr2 = 4;
    break;

  case '5':
    nbr2 = 5;
    break;

  case '6':
    nbr2 = 6;
    break;

  case '7':
    nbr2 = 7;
    break;

  case '8':
    nbr2 = 8;
    break;

  case '9':
    nbr2 = 9;
    break;
  }

  Serial.println(nbr2); // affichage du deuxieme chiffre 
  delay(1500); // delai d'attente pour la demande de l'operateur 
  
  // operateur des calculs par rapport aux touches disponibles sur le clavier numerique
  Serial.println("\n\nAppuyez sur A pour l'operateur addition (+) ");
  Serial.println("Appuyez sur B pour l'operateur soustraction (-) ");
  Serial.println("Appuyez sur C pour l'operateur multiplicatin (*) ");
  Serial.println("Appuyez sur D pour l'operateur division (/) ");
  Serial.print(" \nL'operateur pour le calcul des deux chiffres que vous avez entrez est : ");
  delay(300);

  appuyerUneTouche = clavier.waitForKey(); // pour stocker l'opewrateur de la touche appuyee dans un caractere.

  switch (appuyerUneTouche) // Choix sur clavier qui va conresondre a l'operateur choisis
  {
  case 'A':
    Serial.println("+");
    resultat = nbr1 + nbr2;
    break;

  case 'B':
    Serial.println("-");
    resultat = nbr1 - nbr2;
    break;

  case 'C':
    Serial.println("*");
    resultat = nbr1 * nbr2;
    break;

  case 'D':
    Serial.println("/");
    resultat = nbr1 / nbr2;
    break;
  }
  // affichge du resultat du calcul
  Serial.print("\n===========================================");
  Serial.print("\nLe resultat de votre calcul est : ");
  Serial.println(resultat);
  Serial.print("===========================================");
  Serial.print("\n\nAppuyer sur une touche pour refaire un autre calcul. ");
}