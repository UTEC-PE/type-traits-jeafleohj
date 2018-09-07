#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include <cstdio>
#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
public:
	SListIterator() : Iterator<T>() {};
	SListIterator(Node<T> *current) : Iterator<T>(current) {};
	SListIterator<T> operator++(){
		this->current = this->current->next;
		return *this;
	}
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
		pointer = &head;
		if( *pointer){
			while ( (*pointer)->next && cmp( (*pointer)->next->data, search) ) {
				pointer = &((*pointer)->next);
			}
		}
		return ((*pointer))&&( (*pointer)->data == search);
	}
             
	bool insert(T data) {
		Node<T> **pos;
		if( find(data, pos) ){
			return false;
		}
		Node<T> *node = new Node<T>(data);
		if( (*pos) ){
			node->next = (*pos)->next;
			(*pos)->next = node;
		}else{
			node->next = nullptr;
			head = node;
		}
		return true;
	}
             
	bool remove(T item) {
		Node<T> **pos;
		if( find(item, pos) ){
			Node<T> *tmp = (*pos);
			(*pos) = (*pos)->next;
			delete tmp;
		}
		return false;
	}  
             
	iterator begin() {
		iterator b(head);
		return b;
	}
             
	iterator end() {
		iterator e(nullptr);
		return e;
	}
    void print(){
		Node<T> *it = head;
		while(it){
			std::cout << it->data << " \n"[it->next == nullptr];
			it = it->next;
		}
	}
	~SList() {
		if (head) {
			head->killSelf();
		} 
	}
	
};

#endif
