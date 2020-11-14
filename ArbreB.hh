#pragma once
#include "Sommet.hh"

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
	
	ArbreB(char l, int o, ArbreB f) : Sommet(l,o){
		this->fg=&f;
		this->fd=NULL;
	}
	
	ArbreB(ArbreB fg, ArbreB fd) : Sommet(){
		this->fg=&fg;
		this->fd=&fd;
	}
	
	ArbreB(char l, int o, ArbreB fg, ArbreB fd) : Sommet(l,o){
		this->fg=&fg;
		this->fd=&fd;
	}
	
	~ArbreB(){}
	
	ArbreB* getfg(){return this->fg;}
	ArbreB* getfd(){return this->fd;}
	
	//fonction de recherche renvoyant un boolean
	bool rechElem(char l){
		if(this->getLettre()==l)
			return true;
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
	
	//fonction de recherche en void
	void rechercheElem(char l){
		if(this->getLettre()==l)
			std::cout << "Element trouvé: " << l << std::endl;
		if(fg){
			fg->rechercheElem(l);
		}
		if(fd){
			fd->rechercheElem(l);
		}
	}
	
	
};
