#include <iostream>
#include "ArbreB.hh"
#include "Sommet.hh"

int main(){
	
	ArbreB A('a', 3);
	ArbreB b('b', 2);
	ArbreB c('c', 5,A,b);
	ArbreB Ab(A, b);
	ArbreB Ac(1, b);
	ArbreB ABC(Ab,c);
	ArbreB ABAB(Ab,ABC);

	c.getfg()->setLettre('H');
	c.getfg()->setOccurence(7);
	c.getfd()->setLettre('B');
	c.getfd()->setOccurence(9);

	// c.rechAllElem(0,"c",-1);
	// b.rechAllElem(0,"b",-1);
	// A.rechAllElem(0,"A",-1);
	Ac.rechAllElem(0,"Ac",-1);
	
	// std::cout << A.getLettre() << " " << A.getOccurence() << " " << std::endl;
	// Ab.rechAllElem(0,"Ab",-1);
	// std::cout << std::endl;

	// Ab.rechAllElem(0,"Ab",-1);
	// std::cout << std::endl;

	// Ab.getfg()->setLettre('H');
	// Ab.getfg()->setOccurence(7);


	// Ab.rechAllElem(0,"Ab",-1);
	// std::cout << std::endl;
	// std::cout << Ab.getLettre() << " " << Ab.getOccurence() << " " << std::endl;
	//ArbreB Ab(A, b);
		
	//en void
	// Ab.rechercheElem('H');
	// Ab.rechercheElem('b');
	// Ab.rechercheElem('a');

	//rechercher tout les elements dans l'arbre 

	// A.rechAllElem(0,"A",-1);
	// std::cout << std::endl;
	// b.rechAllElem(0,"B",-1);
	// std::cout << std::endl;
	// c.rechAllElem(0,"C",-1);
	// std::cout << std::endl;
	// Ab.rechAllElem(0,"Ab",-1);
	// std::cout << std::endl;
	// ABC.rechAllElem(0,"ABC",-1);
	// std::cout << std::endl;
	// ABAB.rechAllElem(0,"ABAB",-1);
	// std::cout << std::endl;


	
	//en booleen
	// if(ABC.rechElem('H'))
	// 	std::cout << "Element H trouvé " << std::endl;
	// if(ABC.rechElem('b'))
	// 	std::cout << "Element b trouvé " << std::endl;
	// if(ABC.rechElem('a'))
	// 	std::cout << "Element a trouvé " << std::endl;
	// if(ABC.rechElem('c'))
	// 	std::cout << "Element c trouvé " << std::endl;

	// std::cout << ABC.getLettre() <<std::endl;


	
	return 0;
}
