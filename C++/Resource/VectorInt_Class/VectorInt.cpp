#include "vector.h"
#include <cassert>

VectorInt::VectorInt(): sz(0), cap(1){
	vec = new int[cap];
}

unsigned int VectorInt::size() const{return sz;};
unsigned int VectorInt::capacity() const{return cap;};

void reserve(unsigned int n){//ridimensionare capacity
	if(n > cap){
		cap = n;
		int* tmp = new int[cap];
		
		for(int i = 0; i < sz; i++)
			tmp[i] = vec[i];

		delete[] vec;
		vec = tmp;
	}
}

void resize(unsigned int n){
	if(n < sz)
		sz = n;
}

void VectorInt::push_back(int e){
	if(sz == cap){
		reserve(cap*2);
	}
	vec[sz] = e;
	sz++;
}

void VectorInt::pop_back(){
	if(sz > 0)
		sz--;
}

int VectorInt::operator[](unsigned int i) const{
	assert(i < sz);
	return vec[i];
}

int& VectorInt::operator[](unsigned int i){
	assert(i < sz);
	return vec[i];
}

VectorInt::VectorInt(const VectorInt& v){
	sz = v.sz;
	cap = v.cap;

	vec = new int[cap];

	for (int i = 0; i < sz; i++){
		vec[i] = v.vec[i];
	}
}

VectorInt::~VectorInt(){
	delete[] vec;
}

VectorInt& VectorInt::operator=(const VectorInt& v){
	if(this != &v){
		sz = v.sz;
		cap = v.cap;
		delete[] vec;
		vec = new int[cap];

		for (int i = 0; i < sz; i++){
			vec[i] = v.vec[i]
		}
	}
	return *this;
}
