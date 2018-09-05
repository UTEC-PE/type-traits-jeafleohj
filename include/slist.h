#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
public:
	SListIterator() : Iterator<T>() {};
	SListIterator(Node<T> *current) : Iterator<T>(current) {};
	SListIterator<T> operator++();
};

template <typename Tr>
class SList {     
public:
	typedef typename Tr::T T;
	typedef typename Tr::Operation Operation;
	typedef SListIterator<T> iterator;

private:
	Node<T>* head;
	Operation cmp;
              
public:
	SList() {
		head = nullptr;
	};

	bool find(T search, Node<T> **&pointer) {
		Node<T> *it = head;
		while ( it ) {
			if( cmp( it->data, search) ){
				pointer = &it;
				if( it->data == search ) return true;
				return false;
			}
			it = it->next;
		}
		pointer = &it;
		return false;
	}
             
	bool insert(T data) {
		Node<T> **pos;
		if( find(data, pos) ) return false;
		Node<T> *tmp = new Node<T>;
		tmp->data = data;
		tmp->next = (*pos)->next;
		(*pos) = tmp;
		return true;
	}
             
	bool remove(T item) {
		Node<T> **pos;
		if( find(data, pos) ){
			Node<T> *tmp = (*pos);
			(*pos) = (*pos)->next;
			delete tmp;
		}
		return false;
	}  
             
	iterator begin() {
		// TODO
	}
             
	iterator end() {
		// TODO
	}
             
	~SList() {
		if (head) {
			head->killSelf();
		} 
	}         
};

#endif
