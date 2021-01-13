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
	for(int i=0;i<94;i++){	//ASCII à partir du caractere espace jusqu'au 127e caractere ASCII
		tab[i].setLettre((char)(i+32));
		tab[i].setOccurence(0);
	}
}

void lectureFichier(ArbreB* tab, const char* path){
	char b;
	std::ifstream f(path);
	while(f.get(b)){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
		for(int i=0;i<94;i++){
			if(b == tab[i].getLettre()){
				tab[i].incremente();
			}
		}
	}
	std::cout << std::endl;
	f.close();
}

void tabToVector(ArbreB* tab, std::vector<ArbreB> &res){
	for(int i=0;i<94;i++){	
		if(tab[i].getOccurence() != 0){
			res.push_back(tab[i]);
		}
	}
}

void huffmann(std::vector<ArbreB> &vector){
	while(vector.size()>1){
		ArbreB tmp(getMin(vector),getMin(vector));
		vector.push_back(tmp);
		vector.back().setOccurence(vector.back().getfg()->getOccurence()+vector.back().getfd()->getOccurence());
	}
}

void ecritureCodifiee(const char* path, ArbreB Arbre){
	char b;
	std::ofstream outFile("../TexteCodifie.txt",std::ofstream::out);
	std::ifstream f(path);
	int position = 0;
	
	f.seekg(-1, std::ios::end);
	int taille = f.tellg();
	f.seekg(0, std::ios::beg);
	
	while(f.get(b)){
		if(position == taille)
			break;
		std::string codeLettre = Arbre.codifierText(b,"");
		position++;
		if(codeLettre == ""){	//cas où une lettre n'est pas reconnue
			outFile << "?" << " ";
		}		
		else   //cas où la lettre est reconnue
			outFile << codeLettre << " ";
	}
	f.close();
	outFile.close();
}

ArbreB Cryptage(const char* path){
	ArbreB tabFile[94];
	
	//initialisation tableau
	initTabAscii(tabFile);
	
	//Lecture Fichier
	lectureFichier(tabFile,path);
	
	//Affichage du tableau rempli
	for(int i=0;i<94;i++)
		std::cout<< tabFile[i].getLettre() << ", " << tabFile[i].getOccurence() << std::endl;
	std::cout << std::endl;
	
	//Crée un vecteur d'arbres stockant les lettres ayant une occurrence non nulle
	std::vector<ArbreB> v;
	tabToVector(tabFile, v);
	
	//Affichage du contenu du vecteur
	std::cout << "Contenu du Vecteur : "<<std::endl;
	for(int i=0;i<v.size();i++)
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
	//Application de l'algorithme de Huffmann
	huffmann(v);
	
	//Affichage final du vecteur
	std::cout << std::endl;
	for(int i=0;i<v.size();i++)	
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
	//Affichage de l'arbre final
	ArbreB Final = v.front();
	//Final.rechAllElem(0,"Final",-1);
	
	//Ecriture du texte codifié dans le fichier TexteCodifie.txt
	ecritureCodifiee(path, Final);
	
	return Final;
};
