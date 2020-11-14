#include <iostream>
#include "ArbreB.hh"
#include "Sommet.hh"

int main(){
	
	ArbreB A('a', 3);
	ArbreB b('b', 2);
	ArbreB c('c', 5);
	ArbreB Ab(A, b);
	ArbreB ABC(Ab,c);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	Ab.getfg()->setLettre('H');
	Ab.getfg()->setOccurence(7);
	std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	//ArbreB Ab(A, b);
		
	//en void
	Ab.rechercheElem('H');
	Ab.rechercheElem('b');
	Ab.rechercheElem('a');
	
	//en booleen
	if(ABC.rechElem('H'))
		std::cout << "Element H trouvé " << std::endl;
	if(ABC.rechElem('b'))
		std::cout << "Element b trouvé " << std::endl;
	if(ABC.rechElem('a'))
		std::cout << "Element a trouvé " << std::endl;
	if(ABC.rechElem('c'))
		std::cout << "Element c trouvé " << std::endl;
	
	return 0;
}
