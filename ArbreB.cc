#include "ArbreB.hh"

ArbreB::ArbreB() : Sommet(){
	this->fg=nullptr;
	this->fd=nullptr;
}

ArbreB::ArbreB(char l, int o) : Sommet(l,o){
	this->fg=nullptr;
	this->fd=nullptr;
}

ArbreB::ArbreB(ArbreB fg, ArbreB fd) : Sommet(){
	this->fg=&fg;
	this->fd=&fd;
}

ArbreB::ArbreB(const char * direction ,  ArbreB f) : Sommet(){
	if (std::strcmp(direction, "droite")==0){
		this->fd=&f;
		this->fg=nullptr;
	}
	else {
		this->fg=&f;
		this->fd=nullptr;
	}
}

ArbreB::ArbreB(char l, int o, const char * direction ,  ArbreB f) : Sommet(l,o){
	if (std::strcmp(direction, "droite")==0){
		this->fd=&f;
		this->fg=nullptr;
	}
	else {
		this->fg=&f;
		this->fd=nullptr;
	}
}
	
ArbreB::ArbreB(char l, int o, ArbreB fg, ArbreB fd) : Sommet(l,o){
	this->fg=&fg;
	this->fd=&fd;
}
	
ArbreB::~ArbreB(){
	// std::cout << "je passe par le destructeur et je suis je suis l'arbre avec le sommet : " 
	// << this->getLettre() << std::endl;
	// std::cout << std::endl;
	// //this->deleteArbre();
	// if(fd){
	// 	std::cout << "je passe par fd " << std::endl;
	// 	std::cout << "delete fd avec la lettre : " << this->getLettre() << std::endl;
	// 	delete fd
	// 	fd = nullptr;
	// }

	// if(fg) {
	// 	std::cout << "je passe par fg " << std::endl;
	// 	std::cout << "delete fg avec la lettre : " << this->getLettre() << std::endl;
	// 	delete fg;
	// 	fg = nullptr;
	// }
}

ArbreB* ArbreB::getfg(){return this->fg;}
ArbreB* ArbreB::getfd(){return this->fd;}

//fonction qui renvoie toute les lettres et occurences par profondeur et si elle se situe a gauche ou a droite
int ArbreB::rechAllElem(int prof, char const * nomArbre, int gORd){

		if (gORd == -1)
			std::cout << "Sommet de l'arbre "<<  nomArbre <<  " egale a : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << std::endl;

		else if (gORd)
			std::cout << "Element trouvé a la profondeur "<< prof << " : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << " dans l'abre " << nomArbre << " a droite" << std::endl;

		else 
			std::cout << "Element trouvé a la profondeur "<< prof << " : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << " dans l'abre " << nomArbre << " a gauche" << std::endl;


		if(fg and fd)
			return fg->rechAllElem(prof+1,nomArbre,0) + fd->rechAllElem(prof+1,nomArbre,1);
		else if(fg){
			return fg->rechAllElem(prof+1,nomArbre,0);
		}
		else if(fd){
			return fd->rechAllElem(prof+1,nomArbre,1);
		}

		else return 0;
}

	
//fonction de recherche d'un caractère dans un arbre, elle renvoie un boolean,
bool ArbreB::rechElem(char l){
		if(this->getLettre()==l){
			std::cout << "Element trouvé: " << l << std::endl;
			return true;
		}
		if(fg and fd)
			return fg->rechElem(l) + fd->rechElem(l);
		if(fg){
			return fg->rechElem(l);
		}
		if(fd){
			return fd->rechElem(l);
		}
		return false;
}
	
//fonction de recherche d'un caractère dans un arbre, elle renvoie un rien
void ArbreB::rechercheElem(char l){
		if(this->getLettre()==l){
			std::cout << "Element trouvé: " << l << "son occurence est de: " << this->getOccurence() << std::endl;
		}
		if(fg){
			fg->rechercheElem(l);
		}
		if(fd){
			fd->rechercheElem(l);
		}
}

// void ArbreB::deleteArbre(){

// 	if (fg == nullptr && fd == nullptr){
// 		std::cout << "je retourne en arrière j'ai la lettre : " << this->getLettre() << std::endl;
// 		return;
// 	}

// 	if(fd){
// 		std::cout << "je passe par fd " << std::endl;
// 		fd->deleteArbre();
// 		std::cout << "delete fd avec la lettre : " << this->getLettre() << std::endl;
// 		delete fd;
// 		fd = nullptrptr;
// 	}

// 	if(fg) {
// 		std::cout << "je passe par fg " << std::endl;
// 		fg->deleteArbre();
// 		std::cout << "delete fg" << std::endl;
// 		delete fg;
// 		fg = nullptrptr;
// 	}
// }
	
	