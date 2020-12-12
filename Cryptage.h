#pragma once
#include <iostream>
#include <fstream>

#include "Sommet.h"
#include "ArbreB.h"

void initTabAscii(ArbreB* tab){
	for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
		tab[i].setLettre((char)(i+65));
		tab[i].setOccurence(0);
	}
}

void fileToTab(const char* path){
	char b;
	std::ifstream f(path);
	ArbreB tabFile[26];
	//initialisation tableau
	initTabAscii(tabFile);
	for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
		std::cout << tabFile[i].getLettre() << ", " << tabFile[i].getOccurence() << std::endl;
	}
	
	//Lecture Fichier
	while(f.get(b)){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
		for(int i=0;i<26;i++){
			if(b == tabFile[i].getLettre() || (char)(b-32) == tabFile[i].getLettre()){
				tabFile[i].incremente();
			}
		}
	}
	std::cout << std::endl;
	
	f.close();
	//Retourne le tableau
	
	//Crée un vecteur d'arbres stockant les lettres ayant une occurrence non nulle
	std::vector<ArbreB> v;
	for(int i=0;i<26;i++){	
		if(tabFile[i].getOccurence() != 0){
			v.push_back(tabFile[i]);
		}
	}
	for(int i=0;i<v.size();i++)
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
};
