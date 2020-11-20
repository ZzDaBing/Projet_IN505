#pragma once
#include "Sommet.hh"
#include <cstring>

class ArbreB : public Sommet{
private:
	ArbreB* fg;
	ArbreB* fd;
public:
	ArbreB() : Sommet(){
		this->fg=NULL;
		this->fd=NULL;
	}
	
	ArbreB(char l, int o) : Sommet(l,o){
		this->fg=NULL;
		this->fd=NULL;
	}

	ArbreB(ArbreB fg, ArbreB fd) : Sommet(){
		this->fg=&fg;
		this->fd=&fd;
	}

	ArbreB(const char * direction ,  ArbreB f) : Sommet(){
		if (std::strcmp(direction, "droite")==0){
			this->fd=&f;
			this->fg=NULL;
		}
		else {
			this->fg=&f;
			this->fd=NULL;
		}
	}

	ArbreB(char l, int o, const char * direction ,  ArbreB f) : Sommet(l,o){
		if (std::strcmp(direction, "droite")==0){
			this->fd=&f;
			this->fg=NULL;
		}
		else {
			this->fg=&f;
			this->fd=NULL;
		}
	}
	
	ArbreB(char l, int o, ArbreB fg, ArbreB fd) : Sommet(l,o){
		this->fg=&fg;
		this->fd=&fd;
	}
	
	~ArbreB(){}
	
	ArbreB* getfg(){return this->fg;}
	ArbreB* getfd(){return this->fd;}

	//fonction qui renvoie toute les lettres et occurences par profondeur et si elle se situe a gauche ou a droite

	int rechAllElem(int prof, char const * nomArbre, int gORd){

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
	bool rechElem(char l){
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
	void rechercheElem(char l){
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
	
	
};
