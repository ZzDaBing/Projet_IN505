#include <iostream>
#include <fstream>

#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QWidget>

#include "ArbreB.h"
#include "Sommet.h"
#include "Cryptage.h"
#include "Fenetre.hh"

int main(int argc,char** argv){
	
	Cryptage("../test.txt");
	//Partie Qt
	/*QApplication app(argc,argv);
	Fenetre window(&ArbreCA);
	window.show();
	
	return app.exec();*/
	
	return 0;
}
