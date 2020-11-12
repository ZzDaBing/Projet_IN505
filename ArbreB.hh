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
