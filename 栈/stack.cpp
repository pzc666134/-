#include<iostream>
#include"stack.h"
using namespace std;

//��ʼ��
void stack::Init() {
	ptop = new Node();
	pend = ptop;
	pend->next = nullptr, ptop->next = nullptr;
}

//ѹջ
void stack::Push(Node* p) {
	ptop->next = p;
	ptop = p;
}

//����
void stack::Travers() {
	for (auto p = ptop; p != pend; p = p->next) {
		cout << p->date << endl;
	}
}

//��ջ
bool stack::Pop(){
	if (isEmpty()) {
		return false;
	}

	auto r = ptop;
	ptop = r->next;
	delete r;
	r = nullptr;
	return true;
}

//��ȡջ��Ԫ�أ�����ɾ��ջ�����
bool stack::getTop(int& val) {
	if (isEmpty())
		return false;
	val = ptop->date;
	return true; // ���򷵻�ջ����Ԫ��ֵ
}

// �ж�ջ�Ƿ�Ϊ��
bool stack::isEmpty() {
	if (ptop == pend)return true;
	return false;
}

// ��ȡջ�ĳ���
int stack::getSize() {
	int i = 0;
	for (auto p = ptop; p != pend; p = p->next, i++);
	return i;
}