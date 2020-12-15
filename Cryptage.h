#pragma once
#include <iostream>
#include <fstream>

#include "Sommet.h"
#include "ArbreB.h"

ArbreB getMin(std::vector<ArbreB>& Vec){	//Prend un vecteur en argument et retourne l'arbre ayant la plus petite occurrence 
	int min = Vec.back().getOccurence();
	int indice=0;
	for(size_t i=1;i<Vec.size();i++){
		if(min > Vec[i].getOccurence()){
			min = Vec.back().getOccurence();
			indice = i;
		}
	}
	ArbreB res;
	res=Vec[indice];
	
	Vec.erase(Vec.begin()+indice);
	return res;
}

void initTabAscii(ArbreB* tab){	//Initialise un tableau d'arbre
	for(int i=0;i<94;i++){	//ASCII à partir de l'espace jusqu'au 127e caractere ASCII
		tab[i].setLettre((char)(i+32));
		tab[i].setOccurence(0);
	}
}

void fileToTab(const char* path){
	char b;
	std::ifstream f(path);
	ArbreB tabFile[94];
	
	//initialisation tableau
	initTabAscii(tabFile);
	
	//Lecture Fichier
	while(f.get(b)){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
		for(int i=0;i<94;i++){
			if(b == tabFile[i].getLettre()){
				tabFile[i].incremente();
			}
		}
	}
	std::cout << std::endl;
	f.close();
	
	//Affichage du tableau rempli
	for(int i=0;i<94;i++)
		std::cout<< tabFile[i].getLettre() << ", " << tabFile[i].getOccurence() << std::endl;
	std::cout << std::endl;
	
	//Crée un vecteur d'arbres stockant les lettres ayant une occurrence non nulle
	std::vector<ArbreB> v;
	for(int i=0;i<94;i++){	
		if(tabFile[i].getOccurence() != 0){
			v.push_back(tabFile[i]);
		}
	}
	
	std::cout << "Contenu du Vecteur : "<<std::endl;
	for(int i=0;i<v.size();i++) //Contenu du Vecteur
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
	//Fusion
	
	while(v.size()>1){
		ArbreB tmp;
		tmp.setfg(getMin(v));
		tmp.setfd(getMin(v));
		v.push_back(tmp);
		v.back().setOccurence(v.back().getfg()->getOccurence()+v.back().getfd()->getOccurence());
	}
	std::cout << std::endl;
	
	for(int i=0;i<v.size();i++)	//Affichage
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
	//Affichage de l'arbre final
	ArbreB Final = v.front();
	//Final.rechAllElem(0,"Final",-1);
};
