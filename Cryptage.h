#pragma once
#include <iostream>
#include <fstream>

#include "Sommet.h"

void initTabAscii(Sommet* tab){
	for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
		tab[i].setLettre((char)(i+65));
		tab[i].setOccurence(0);
	}
}

void fileToTab(const char* path){
	char b;
	std::ifstream f(path);
	Sommet tabFile[26];
	//initialisation tableau
	initTabAscii(tabFile);
	for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
		std::cout << tabFile[i].getLettre() << ", " << tabFile[i].getOccurence() << std::endl;
	}
	
	//Lecture Fichier
	while(f.get(b)){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
		for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
			if(b == tabFile[i].getLettre() || (char)(b-32) == tabFile[i].getLettre()){
				tabFile[i].incremente();
			}
		}
	}
	std::cout << std::endl;
	
	f.close();
	//Retourne le tableau
};
