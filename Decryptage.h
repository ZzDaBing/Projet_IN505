#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Sommet.h"
#include "ArbreB.h"
#include "Cryptage.h"

char decodifierMot(ArbreB* Arbre, std::string mot){
	ArbreB* tmp = Arbre;
	int position = 0;
	while(tmp != nullptr && position != mot.length()){
		if(mot[position] == '0')
			tmp = tmp->getfg();
		else{
			tmp = tmp->getfd();
		}
		position++;
	}
	return tmp->getLettre();
}

bool verifPath(std::string mot, ArbreB* Arbre){
	ArbreB* tmp = Arbre;
	int position=0;
	
	while(tmp != nullptr && position != mot.length()){
		if(mot[position] == '0')
			tmp = tmp->getfg();
		else{
			tmp = tmp->getfd();
		}
		position++;
	}
	
	if(tmp == nullptr || tmp->getLettre() == '0')
		return false;
	else
		return true;
}

bool verifCryptage(const char* path, ArbreB* Reference){
	std::ifstream fichierCrypte(path);
	std::string mot;
	Reference->rechAllElem(0, "Arbre", -1);
	if(not fichierCrypte.good())
		throw std::runtime_error("failed to open file");
		
	while(fichierCrypte >> mot){
		std::cout << "le mot est :" << mot << std::endl;
		if(not verifPath(mot, Reference))
			return false;
	}
	return true;
}

void ecritureDecodifiee(const char* path, ArbreB* Arbre){
	
	std::ofstream outFile("../TexteDecodifie.txt",std::ofstream::out);
	std::ifstream f(path);
	std::string mot;
	
	while(f >> mot){
		char decodeLettre = decodifierMot(Arbre, mot);	
		
		outFile << decodeLettre;
	}
	f.close();
	outFile.close();
}

void Decryptage(const char* path, ArbreB* A){
	if(verifCryptage(path, A)){	//Vérification du cryptage du texte
		std::cout << "Le texte a bien été crypté" << std::endl;
		
		ecritureDecodifiee(path, A);
	}
	else
		std::cout << "Le texte n'a pas été crypté" << std::endl;
}
