#ifndef VECTORINT_H_
#define VECTORINT_H_

#include <iostream>
using namespace std;

class VectorInt {
	public:
		VectorInt(); //Costruttore senza parametri
		
		unsigned int size() const; //Metodo che ci restituisce la dimensione dell'array
		unsigned int capacity() const; //Metodo che ci restituisce la capacity dell'array
	
		void push_back(int e); //Metodo per inserire un elemento alla fine dell'array
		void pop_back(); //Metodo per eliminare l'ultimo elemento dell'array
		
		void reserve(unsigned int n); //Metodo per aumentare la capacity fino a n		
		void resize(unsigned int n); //Metodo per ridimensionare l'array al valore n
	
		int operator[](unsigned int i) const; //Ridefinizione operatore []
		int& operator[](unsigned int i); //Ridefinizione operatore []
	
		VectorInt(const VectorInt& v); //Costruttore di copia
		~VectorInt(); //Distruttore
		VectorInt& operator=(const VectorInt& v); //Ridefinizione operatore di assegnamento
	
	private:
		int* vec; //Array dinamico
		unsigned int sz; //Size
		unsigned int cap; //Capacity
};

#endif
