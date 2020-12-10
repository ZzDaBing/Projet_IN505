#pragma once
#include <iostream>
#include <fstream>

#include "Sommet.h"

void fileToTab(const char* path){
	char b;
	std::ifstream f(path);
	//Sommet tabFile[54];
	//initialisation tableau
	while(f.get(b)){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
	}
	std::cout << std::endl;
	f.close();
	//Retourne le tableau
};
