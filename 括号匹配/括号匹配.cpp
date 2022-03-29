#include<iostream>
#include<string.h>
using namespace std;

//����ջ 
#define max_size 200//ջ��������� 
typedef char datatype;
typedef struct {
    datatype zhan[max_size];
    int top;//ջ�� 
}stack;



//ջ�ĳ�ʼ��
void initial(stack& st)
{
    st.top = 0;
}



//����Ϊdatatype��x��ջ 
void push(stack& st, datatype x)
{
    //��ջ����max_size���ʱ��ջ�� 
    if (st.top == max_size) {
        // cout<<"This stack has already full!";
        cout << "no";
        exit(0);
    }
    else {
        st.zhan[st.top] = x;
        st.top++;
    }
}



//��ջ 
char pop(stack& st) {
    if (st.top == 0) {
        // cout<<"This stack is empty!";
        cout << "no";
        exit(0);
    }
    else {
        st.top--;
        return st.zhan[st.top];
    }
}



int main() {

    stack s;
    initial(s);

    /*�����ַ����������ַ����ŵ��ַ������У�
    ʵ���ܹ����ɨ���ַ����е��ַ������Ҳ������ո��
    */
    string str;
    getline(cin, str);
    char ch[200] = { '\0' };
    strcpy(ch, str.c_str());



    //flag��־״̬ 1Ϊ����ƥ�䣬0Ϊ��ƥ�� 
    int flag = 1;
    int i;
    for (i = 0; ch[i] != '\0'; i++) {
        //Ԫ����Ϊ{��(��[����ջ
        if ((ch[i] == '{') || (ch[i] == '[') || (ch[i] == '(')) {
            push(s, ch[i]);
        }//Ԫ����Ϊ}��)��]���ջ ��ֵ��a 
        else if ((ch[i] == '}') || (ch[i] == ']') || (ch[i] == ')')) {
            char a;
            a = pop(s);
            //��a��ch[i]ƥ�䣬������һ���ַ�ɨ�� 
            if ((a == '{' && ch[i] == '}') || (a == '(' && ch[i] == ')') || (a == '[' && ch[i] == ']')) {
                continue;
            }
            else flag = 0;
        }
    }

    if (s.top != 0) {    //�������Ŷ��û����������ƥ���ʱ���磺" {() "��
        flag = 0
    }

    if (flag == 0) {
        cout << "no";
    }
    else cout << "yes";
    return 0;
}