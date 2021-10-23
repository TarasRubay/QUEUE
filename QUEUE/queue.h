#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
template<typename t>
class queue {
   template<typename t>
   struct node {
	   node* p_next;
	   t data;
	   node(t _data = t(), node* _p_next = nullptr) {
		   this->data = _data;
		   this->p_next = _p_next;
	   }
   };
   node<t>* head;
   int length;
public:
	queue();
	queue(const queue& _tmp) {
		if (_tmp.head != nullptr) {
			while (this->length != _tmp.length) {
			    node<t>* tmp = _tmp.head;
				for (int i = 0; i < (_tmp.length - this->length)-1;i++) {
					tmp = tmp->p_next;
				}
				this->en_queue(tmp->data);
			}
		}
	}
	~queue();
	queue& operator=(t _data) {
		this->en_queue(_data);
		return *this;
	}
	void en_queue(t _data);
	t de_queue();
	t top();
	int size_list();
	bool empty();
	void clear();

};

template<typename t>
inline queue<t>::queue()
{
	this->head = nullptr;
	this->length = 0;
}



template<typename t>
inline queue<t>::~queue()
{
	clear();
}



template<typename t>
inline void queue<t>::en_queue(t _data)
{
		head = new node<t>(_data, head);
		length++;	
}

template<typename t>
inline t queue<t>::de_queue()
{
	t dat = 0;
	if (head->p_next == nullptr) {
		dat = head->data;
		delete head;
		head = nullptr;
		length--;
		return dat;
	}
	else{
	node<t>* last_nod = this->head;
	node<t>* penunlimate = nullptr;
	while(last_nod->p_next != nullptr)
	{
		penunlimate = last_nod;
		last_nod = last_nod->p_next;
	}
	penunlimate->p_next = nullptr;
	dat = last_nod->data;
	delete last_nod;

	length--;
	return dat;
	}
}

template<typename t>
inline t queue<t>::top()
{
	if (head->p_next == nullptr) {
		return head->data;
	}
	else {
		node<t> *last = this->head;
		while (last->p_next != nullptr)
		{
			last = last->p_next;
		}
		return last->data;
	}
}

template<typename t>
inline int queue<t>::size_list()
{
	return length;
}

template<typename t>
inline bool queue<t>::empty()
{
	return !length;
}

template<typename t>
inline void queue<t>::clear()
{
	while (head != nullptr)this->de_queue();
}

