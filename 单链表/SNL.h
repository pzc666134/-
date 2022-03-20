#ifndef LIST
#define LIST

//在头结点存储链表大小
struct Node {
	int date;
	Node* next;
	Node(int d) :date(d), next(nullptr);
	Node() {};
};


class LinkList {
private:
	Node* head;
public:
    void create();           //初始化
    void insertHead(Node*);  //头插法
    void insertTail(Node*);  //尾插法
    Node* findByIndex(int);  //根据索引查找节点，并返回节点的指针，注意0返回头节点
    Node* findByValue(int);  //根据值查找节点，并返回节点的指针，注意0返回头节点
    int  getLength();        //获取链表的长度
    void deleteByIndex(int); //根据索引删除节点
    void deleteByValueOnce(int); //根据节点值删除第一个节点
    void deleteByValueAll(int);//根据节点值删除所有节点
    void editByIndex(int, int);   //根据索引修改节点的值
    void print();
}


#endif