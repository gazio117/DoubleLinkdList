#pragma once

#include "global.h"

class Node
{
private:
	Node *m_next;
	Node *m_prev;
	int m_data;

public:
	Node() { m_next = NULL; m_prev = NULL; m_data = 0; }
	Node(int value) { m_data = value; m_next = NULL; m_prev = NULL; }

	int getData() { return m_data; }
	Node *getNext() { return m_next; }
	Node *getPrev() { return m_prev; }

	void setData(int data) { m_data = data; }
	void setNext(Node *next) { m_next = next; }
	void setPrev(Node *prev) { m_prev = prev; }

};

class DLinkedList
{
private:
	Node *m_head;
	Node *m_tail;
	int m_count;

public:
	DLinkedList() 
	{ 
		m_head = new Node(); 
		m_tail = new Node(); 
		m_head->setNext(m_tail); 
		m_tail->setPrev(m_head); 
		m_count = 0; 
	}

	~DLinkedList()
	{
		Node *temp = 0;
		while (m_head != 0)
		{
			temp = m_head;
			m_head = m_head->getNext();
			delete temp;
		}
	}

	int getDataCount();

	void pushFront(int value);
	void pushBack(int value);
	void insert(int idx, int value);

	bool deleteHead();
	bool deleteTail();
	bool deleteData(int value);
	
	void display();

};

