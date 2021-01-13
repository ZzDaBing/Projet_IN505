#include <iostream>
#include <fstream>

#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QWidget>

#include "ArbreB.h"
#include "Sommet.h"
#include "Cryptage.h"
#include "Decryptage.h"
#include "Fenetre.hh"

int main(int argc,char** argv){
	
	//Partie 1
	std::cout << "Partie 1" << std::endl << std::endl;
	
	const char * d = "droite";
	const char * g = "gauche";
	ArbreB a ('a',3); 						// création d'un sommet seul avec la lettre "a" et l'occurence "3"
	ArbreB b ; 								// création d'un sommet vide 0,0
	ArbreB c ('c',4); 						// création d'un arbre ArbreB ArbreCA  avec les deux sommet a et c qui aura pour sommet vide
	ArbreB ArbreCA (a,c); 					// création d'un arbre ArbreB ArbreCA  avec les deux sommet a et c qui aura pour sommet vide
	ArbreB ArbreVideCA( 'd',5,g,ArbreCA ); 	// création d'un arbre avec un  sommet avec la lettre d et une occurence de 5 a partir d'un autre arbre qu'on positionne dans la branche gauche 
	ArbreVideCA.rechAllElem(0,"ArbreVideCA",-1); // recherche de tout les elements contenue dans l'arbre ArbreVideCA
	std::cout << std::endl;
	ArbreCA.rechAllElem(0,"ArbreCA",-1); 
	
	//Partie 2
	
	//std::cout << "Partie 2" << std::endl << std::endl;
	//ArbreB Arbre = Cryptage("../texteBasePrédéfini.txt");
	//Arbre.rechAllElem(0, "Arbre", -1);
	
	//Partie 3
	
	//std::cout << "Partie 3" << std::endl << std::endl;
	//Decryptage("../TexteCodifie.txt", &Arbre);
	
	//Partie Qt
	/*QApplication app(argc,argv);
	Fenetre window(&ArbreCA);
	window.show();
	
	return app.exec();*/
	std::cout << std::endl;
	
	return 0;
}
