#pragma once

class Sommet{
private:
	char lettre;
	int occurence;
public:
	Sommet(char l, int o){
		this->lettre=l;
		this->occurence=o;
	}
	
	~Sommet(){}
	
	void setLettre(char l){
		this->lettre=l;
	}
	
	char getLettre(){
		return this->lettre;
	}
	
	void setOccurence(int o){
		this->occurence=o;
	}
	
	int getOccurence(){
		return this->occurence;
	}
};
