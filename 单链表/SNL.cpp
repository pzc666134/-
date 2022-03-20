#include"SNL.h"
#include<iostream>

//��ʼ��
void LinkList::create() {
	head = new Node();
	head->date = 0;
	head->next = nullptr;
}

//ͷ�巨
void LinkList::insertHead(Node* p) {
	p->next = head->next;
	head->next = p;
	head->date++;
}

//β�巨
void LinkList::insertTail(Node* p){
	auto end = findByIndex(head->date);
	if (end == nullptr) {
		insertHead(p);
	}
	else {
		p->next = end->next;
		end->next = p;
		
	}
	head->date++;
}

//�����������ҽڵ�
Node* LinkList::findByIndex(int index) {
	if (index < 0 || index > head->date) {
		std::cout << "��������" << std::endl;
		return nullptr;
	}
	int i = 0;
	for (auto p = head; p != nullptr; p = p->next, i ++) {
		if (i == index)return p;
	}
	return nullptr;
}

//����ֵ���ҽڵ�
Node* LinkList::findByValue(int val) {
	for (auto p = head; p != nullptr; p = p->next) {
		if (p->date == val)return p;
	}
	return nullptr;
}

//��ȡ����ĳ���
int  LinkList::getLength() {
	return head->date;
}

//��������ɾ���ڵ�
void LinkList::deleteByIndex(int index) {
	if (index == 0) {
		std::cout << "����ɾ��ͷ�ڵ㣡" << std::endl;
		return;
	}
	Node* p = findByIndex(index);
	if (!p) {
		std::cout << "ɾ��ʧ�ܣ�" << std::endl;
		return;
	}
	else {
		Node* q = findByIndex(index - 1);
		q->next = p->next;
		head->date--;
		delete p;
	}
}

//���ݽڵ�ֵɾ����һ���ڵ�
void LinkList::deleteByValueOnce(int val) {
	bool flag = false;
	auto p = head;
	for (;p != nullptr; p = p->next) {
		if (p->next->date == val) {
			flag = true;
			break;
		}
	}
	if (flag == true) {
		p->next = p->next->next;
		p->next->next = nullptr;
		delete p->next;
		head->date--;
	}
}

//���ݽڵ�ֵɾ�����нڵ�
void LinkList::deleteByValueAll(int val) {
	bool flag = false;
	auto p = head;
	for (; p != nullptr; p = p->next) {
		if (p->next->date == val) {
			flag = true;
			p->next = p->next->next;
			p->next->next = nullptr;
			delete p->next;
			head->date--;
		}
	}
	if (!flag)std::cout << "�Ҳ������" << std::endl;
}

//���������޸Ľڵ��ֵ
void LinkList::editByIndex(int index, int val){
	if (index == 0) {
		std::cout << "�����޸�ͷ�ڵ㣡" << std::endl;
		return;
	}
	Node* p = findByIndex(index);
	if (!p) {
		std::cout << "�޸�ʧ�ܣ�" << std::endl;
		return;
	}
	else {
		p->date = val;
	}
}

//��ӡ��������
void LinkList::print() {
	for (Node* p = head->next; p; p = p->next) {
		std::cout << p->date << " ";
	}
	std::cout << std::endl;
}
