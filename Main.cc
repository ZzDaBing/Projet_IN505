#include <iostream>
#include "ArbreB.hh"
#include "Sommet.hh"

int main(){
	
	ArbreB A('a', 3, 0);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	A.setLettre('H');
	A.setOccurence(7);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	
	return 0;
}
