#include<iostream>
#include"stack.h"
using namespace std;

//初始化
void stack::Init() {
	ptop = new Node();
	pend = ptop;
	pend->next = nullptr, ptop->next = nullptr;
}

//压栈
void stack::Push(Node* p) {
	ptop->next = p;
	ptop = p;
}

//遍历
void stack::Travers() {
	for (auto p = ptop; p != pend; p = p->next) {
		cout << p->date << endl;
	}
}

//出栈
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

//获取栈顶元素：但不删除栈顶结点
bool stack::getTop(int& val) {
	if (isEmpty())
		return false;
	val = ptop->date;
	return true; // 否则返回栈顶的元素值
}

// 判断栈是否为空
bool stack::isEmpty() {
	if (ptop == pend)return true;
	return false;
}

// 获取栈的长度
int stack::getSize() {
	int i = 0;
	for (auto p = ptop; p != pend; p = p->next, i++);
	return i;
}