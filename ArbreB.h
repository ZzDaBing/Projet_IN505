#pragma once

#include "Sommet.hh"
#include <cstring>

class ArbreB : public Sommet{

private:
	ArbreB* fg;
	ArbreB* fd;

public:

	ArbreB();
	ArbreB(char l, int o);
	ArbreB(ArbreB fg, ArbreB fd);
	ArbreB(const char * direction ,  ArbreB f);
	ArbreB(char l, int o, const char * direction ,  ArbreB f);
	ArbreB(char l, int o, ArbreB fg, ArbreB fd);
	~ArbreB();

	ArbreB* getfg();
	ArbreB* getfd();
	int rechAllElem(int prof, char const * nomArbre, int gORd);
	bool rechElem(char l);
	bool rechercheElem(char l);
	//deleteArbre();



};

