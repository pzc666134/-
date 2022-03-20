#ifndef STACK_H_
#define STACK_H_

struct Node {
	int date;
	Node* next;
	Node(int d) :date(d), next(nullptr);
	Node() {};
};

class stack {
	Node* ptop;
	Node* pend;
public:
	void Init(); // ��ʼ��
	void Travers(); // ����ջ
	void Push(Node *p); // ѹջ
	bool Pop(); // ��ջ����ջ���Ľ��ɾ��
	bool getTop(int& val); // ��ȡջ��Ԫ�أ�����ɾ��ջ�����
	bool isEmpty(); // �ж�ջ�Ƿ�Ϊ��
	int getSize(); // ��ȡջ�ĳ���
};
#endif