#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
public: 
	DListIterator() : Iterator<T>() {};
	DListIterator(Node<T> *current) : Iterator<T>(current) {};
	DListIterator<T> operator++(){
		this->current = this->current->next;
		return *this;
	};
	DListIterator<T> operator--(){
		this->current = this->current->prev;
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
		Node<T>* node = new Node<T>(data);
		node->prev = nullptr;
		if( head ){
			head->prev = node;
			node->next = head;
		}else{
			node->next = nullptr;
			tail = node;
		}
		head = node;
	}

	void push_back(T data) {
		Node<T>* node = new Node<T>(data);
		node->next = nullptr;
		if( head ){
			node->prev = tail;
			tail->next = node;
		}else{
			node->prev = nullptr;
			head = node;
		}
		tail = node;
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
		iterator b(head);
		return b;
	}
             
	iterator end() {
		iterator e(nullptr);
		return e;
	}
             
	~DList() {
		if (head) {
			head->killSelf();
		} 
	}         
};

#endif
