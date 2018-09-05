#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
protected:
	Node<T>* current;
      
public:
	Iterator() : current(nullptr) {};
	Iterator(Node<T>* current) : current(current) {};
             
	Iterator<T> operator=(Iterator<T> other);
	bool operator!=(Iterator<T> other);
	T operator*();
};  

template <typename T
Iterator<T> Iterator<T>operator=(Iterator<T> other){
	current = other.current;
	return *this;
}
template <typename T>
bool Iterator<T>operator!=(Iterator<T> other){
	return current != other.current;
}
template <typename T>
T Iterator<T>operator*(){
	return current->data;
}
#endif
