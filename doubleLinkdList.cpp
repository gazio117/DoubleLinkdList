#include "doubleLinkdList.h"


int DLinkedList::getDataCount()	//�б� ������ ����
{
	return m_count;
}

void DLinkedList::pushFront(int value)		// �տ� ����
{
	Node *newNode = new Node(value);
	
	newNode->setPrev(m_head);
	newNode->setNext(m_head->getNext());
	m_head->getNext()->setPrev(newNode);
	m_head->setNext(newNode);
	m_count++;
}

void DLinkedList::pushBack(int value)	// �ڿ� ����
{
	Node *newNode = new Node(value);	
	
	newNode->setNext(m_tail);
	newNode->setPrev(m_tail->getPrev());
	m_tail->getPrev()->setNext(newNode);
	m_tail->setPrev(newNode);
	m_count++;
}

void DLinkedList::insert(int idx, int value)
{
	if (idx < 0 || idx > m_count)
	{
		cout << "Index range exceeding" << endl;
		return;
	}
	else if (idx == 0)
	{
		pushFront(value);
	}
	else
	{
		Node *newNode = new Node(value);
		Node *cur = m_head;
		int i = 0;
		while (i < idx)
		{
			cur = cur->getNext();
			i++;
		}
		newNode->setNext(cur);
		newNode->setPrev(cur->getPrev());
		cur->getPrev()->setNext(newNode);
		cur->setPrev(newNode);
	}
	m_count++;
}

void DLinkedList::display()
{
	Node *temp = m_head;	//��� ���������� ��� (���� ���̳��)
	for (int i = 0; i < m_count; i++)
	{
		cout << i + 1 << " ��° : " << temp->getNext()->getData() << endl;
		temp = temp->getNext();	// ��� �� ���� ���� ����
	}
}

bool DLinkedList::deleteData(int value)
{
	Node *pre = m_head;
	Node *temp = pre->getNext();

	if (m_head->getNext() == m_tail)
	{
		cout << "Not nodes found" << endl;
		return false;
	}

	for (int i = 0; i < m_count; i++)
	{
		if (temp->getData() == value)
		{
			pre->setNext(temp->getNext());
			temp->getNext()->setPrev(pre);
			
			delete temp;
			m_count--;
			break;
		}
		pre = temp;
		temp = temp->getNext();
	}

	return true;
}

bool DLinkedList::deleteHead()
{
	Node *temp = m_head->getNext();
	if (temp == m_tail)
	{
		cout << "Not nodes found" << endl;
		return false;
	}
	temp->getNext()->setPrev(m_head);
	m_head->setNext(temp->getNext());
	delete temp;
	m_count--;
	return true;
}

bool DLinkedList::deleteTail()
{
	Node *temp = m_tail->getPrev();
	if (temp == m_head)
	{
		cout << "Not nodes found" << endl;
		return false;
	}
	temp->getPrev()->setNext(m_tail);
	m_tail->setPrev(temp->getPrev());
	delete temp;
	m_count--;
	return true;
}




	

	



