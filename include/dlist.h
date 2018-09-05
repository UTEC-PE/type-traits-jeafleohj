#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
public: 
	DListIterator() : Iterator<T>() {};
	DListIterator(Node<T> *current) : Iterator<T>(current) {};
	DListIterator<T> operator++(){
		current = current->next;
		return *this;
	};
	DListIterator<T> operator--(){
		current = current->prev;
		return *this;
	};
};

template <typename Tr>
class DList {     
public:
	typedef typename Tr::T T;
	typedef DListIterator<T> iterator;
      
private:
	Node<T>* head;
	Node<T>* tail;
              
public:
	DList() {
		head = tail = nullptr;
	};

	void push_front(T data) {
		Node<T>* node = new Node<T>;
		node->data = data;
		if( head ){
			node->next = node->prev = nullptr;
			head = tail = node;
		}else{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	void push_back(T data) {
		Node<T>* node = new Node<T>;
		node->data = data;
		if( head ){
			node->next = node->prev = nullptr;
			head = tail = node;				
		}else{
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}
             
	void pop_front() {
		if( head ){
			Node<T>* node = head;
			head = head ->next;
			head->prev = nullptr;
			delete node;
		}
	}
             
	void pop_back() {
		if( head ){
			Node<T>* node = tail;
			tail = tail ->prev;
			tail->next = nullptr;
			delete node;
		}
	}
             
	iterator begin() {
		Iterator<T> b(head);
		return b;
	}
             
	iterator end() {
		Iterator<T> e(tail);
		return e;
	}
             
	~DList() {
		if (head) {
			head->killSelf();
		} 
	}         
};

#endif
