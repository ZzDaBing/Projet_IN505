#pragma once

#include "Sommet.h"
#include <iostream>
#include <cstring>

class ArbreB : public Sommet{

private:
	ArbreB* fg;
	ArbreB* fd;

public:

	ArbreB();
	ArbreB(char l, int o);
	ArbreB(const ArbreB& fg, const ArbreB& fd);
	ArbreB(const char * direction ,  const ArbreB& f);
	ArbreB(char l, int o, const char * direction ,  const ArbreB& f);
	ArbreB(char l, int o, const ArbreB& fg, const ArbreB& fd);
	~ArbreB();

	ArbreB* getfg();
	ArbreB* getfd();
	
	void setfg(const ArbreB& A);
	void setfd(const ArbreB& A);
	
	std::string codifierText(char l, std::string res);
	
	int rechAllElem(int prof, char const * nomArbre, int gORd);
	bool rechElem(char l);
	void rechercheElem(char l);
};
