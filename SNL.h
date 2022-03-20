#ifndef LIST
#define LIST

//��ͷ���洢�����С
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
    void create();           //��ʼ��
    void insertHead(Node*);  //ͷ�巨
    void insertTail(Node*);  //β�巨
    Node* findByIndex(int);  //�����������ҽڵ㣬�����ؽڵ��ָ�룬ע��0����ͷ�ڵ�
    Node* findByValue(int);  //����ֵ���ҽڵ㣬�����ؽڵ��ָ�룬ע��0����ͷ�ڵ�
    int  getLength();        //��ȡ����ĳ���
    void deleteByIndex(int); //��������ɾ���ڵ�
    void deleteByValueOnce(int); //���ݽڵ�ֵɾ����һ���ڵ�
    void deleteByValueAll(int);//���ݽڵ�ֵɾ�����нڵ�
    void editByIndex(int, int);   //���������޸Ľڵ��ֵ
    void print();
}


#endif