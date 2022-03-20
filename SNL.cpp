#include"SNL.h"
#include<iostream>

//初始化
void LinkList::create() {
	head = new Node();
	head->date = 0;
	head->next = nullptr;
}

//头插法
void LinkList::insertHead(Node* p) {
	p->next = head->next;
	head->next = p;
	head->date++;
}

//尾插法
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

//根据索引查找节点
Node* LinkList::findByIndex(int index) {
	if (index < 0 || index > head->date) {
		std::cout << "索引错误" << std::endl;
		return nullptr;
	}
	int i = 0;
	for (auto p = head; p != nullptr; p = p->next, i ++) {
		if (i == index)return p;
	}
	return nullptr;
}

//根据值查找节点
Node* LinkList::findByValue(int val) {
	for (auto p = head; p != nullptr; p = p->next) {
		if (p->date == val)return p;
	}
	return nullptr;
}

//获取链表的长度
int  LinkList::getLength() {
	return head->date;
}

//根据索引删除节点
void LinkList::deleteByIndex(int index) {
	if (index == 0) {
		std::cout << "不能删除头节点！" << std::endl;
		return;
	}
	Node* p = findByIndex(index);
	if (!p) {
		std::cout << "删除失败！" << std::endl;
		return;
	}
	else {
		Node* q = findByIndex(index - 1);
		q->next = p->next;
		head->date--;
		delete p;
	}
}

//根据节点值删除第一个节点
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

//根据节点值删除所有节点
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
	if (!flag)std::cout << "找不到结点" << std::endl;
}

//根据索引修改节点的值
void LinkList::editByIndex(int index, int val){
	if (index == 0) {
		std::cout << "不能修改头节点！" << std::endl;
		return;
	}
	Node* p = findByIndex(index);
	if (!p) {
		std::cout << "修改失败！" << std::endl;
		return;
	}
	else {
		p->date = val;
	}
}

//打印整个队列
void LinkList::print() {
	for (Node* p = head->next; p; p = p->next) {
		std::cout << p->date << " ";
	}
	std::cout << std::endl;
}
