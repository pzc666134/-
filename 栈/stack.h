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
	void Init(); // 初始化
	void Travers(); // 遍历栈
	void Push(Node *p); // 压栈
	bool Pop(); // 出栈：把栈顶的结点删掉
	bool getTop(int& val); // 获取栈顶元素：但不删除栈顶结点
	bool isEmpty(); // 判断栈是否为空
	int getSize(); // 获取栈的长度
};
#endif