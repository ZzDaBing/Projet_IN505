#pragma once
#include "Sommet.hh"

class ArbreB : public Sommet{
private:
	int cle;
	ArbreB* fg;
	ArbreB* fd;
public:
	ArbreB(char l, int o) : Sommet(l,o){
		this->cle=-1;
		this->fg=NULL;
		this->fd=NULL;
	}
	
	ArbreB(char l, int o, int cle) : Sommet(l,o){
		this->cle=cle;
		this->fg=NULL;
		this->fd=NULL;
	}
	
	ArbreB(char l, int o, ArbreB f) : Sommet(l,o){
		this->cle=-1;
		this->fg=&f;
		this->fd=NULL;
	}
	
	ArbreB(char l, int o, ArbreB fg, ArbreB fd) : Sommet(l,o){
		this->cle=-1;
		this->fg=&fg;
		this->fd=&fd;
	}
	
	ArbreB(char l, int o, int cle, ArbreB fg, ArbreB fd) : Sommet(l,o){
		this->cle=cle;
		this->fg=&fg;
		this->fd=&fd;
	}
	
	~ArbreB(){}
	
	bool rechercheElem(char l){
		if(this->getLettre()==l)
			return true;
		if(fg){
			fg->rechercheElem(l);
		}
		if(fd){
			fd->rechercheElem(l);
		}
		return false;
	}
	
	
};
