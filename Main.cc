#include <iostream>
#include "ArbreB.hh"
#include "Sommet.hh"

int main(){
	
	ArbreB A('a', 3);
	ArbreB b('b', 2);
	ArbreB Ab(A, b);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	A.setLettre('H');
	A.setOccurence(7);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	if(A.rechercheElem('a'))
		std::cout << "Element a trouvé" << std::endl;
	if(A.rechercheElem('H'))
		std::cout << "Element H trouvé" << std::endl;
		
	//à tester
	if(Ab.rechercheElem('H'))
		std::cout << "Element H trouvé dans Ab" << std::endl;
	if(Ab.rechercheElem('b'))
		std::cout << "Element b trouvé dans Ab" << std::endl;
	if(Ab.rechercheElem('a'))
		std::cout << "Element a trouvé dans Ab" << std::endl;
	
	
	return 0;
}
