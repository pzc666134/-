# include <iostream>
#include "mStack.h"
using namespace std;


int main()
{
	mPoint mpArray[10][10];
	bool initArray[10][10] = {
	{ false,false,false,false,false,false,false,false,false,false },
	{ false,true ,true ,false,true ,true ,true ,false,true ,false },
	{ false,true ,true ,false,true ,true ,true ,false,true ,false },
	{ false,true ,true ,true ,true ,false,false,true ,true ,false },
	{ false,true ,false,false,false,true ,true ,true ,true ,false },
	{ false,true ,true ,true ,false,true ,true ,true ,true ,false },
	{ false,true ,false,true ,true ,true ,false,true ,true ,false },
	{ false,true ,false,false,false,true ,false,false,true ,false },
	{ false,true,true ,true ,true ,true ,true ,true ,true ,false },
	{ false,false,false,false,false,false,false,false,false,false } };//�Թ�����
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			mpArray[i][j].x = i;
			mpArray[i][j].y = j;
			mpArray[i][j].can_move_to = initArray[i][j];
		}
	mPoint startp(1, 1, true);//��ʼ���꣨��ڣ�
	mPoint endp(8, 8, true);  //�������꣨���ڣ�

	mStack mpath;//�������
	mpath.push(startp);//�ѳ�ʼ������ջ

	mPoint mp = startp;//��¼��ǰ����
	while (true)
	{
		if (mp.x == endp.x && mp.y == endp.y)
			break;//�ɹ����Թ�
		if (mpArray[mp.x + 1][mp.y].can_move_to)//����
		{
			mpArray[mp.x + 1][mp.y].can_move_to = false;//���߹���·���Ϊfalse
			mpath.push(mPoint(mp.x + 1, mp.y));
			mp = mpArray[mp.x + 1][mp.y];
			continue;
		}
		if (mpArray[mp.x - 1][mp.y].can_move_to)//����
		{
			mpArray[mp.x - 1][mp.y].can_move_to = false;
			mpath.push(mPoint(mp.x - 1, mp.y));
			mp = mpArray[mp.x - 1][mp.y];
			continue;
		}
		if (mpArray[mp.x][mp.y + 1].can_move_to)//����
		{
			mpArray[mp.x][mp.y + 1].can_move_to = false;
			mpath.push(mPoint(mp.x, mp.y + 1));
			mp = mpArray[mp.x][mp.y + 1];
			continue;
		}
		if (mpArray[mp.x][mp.y - 1].can_move_to)//����
		{
			mpArray[mp.x][mp.y - 1].can_move_to = false;
			mpath.push(mPoint(mp.x, mp.y - 1));
			mp = mpArray[mp.x][mp.y - 1];
			continue;
		}
		if (0 == mpath.getLength())//ջ��
		{
			cout << "û��·" << endl;
			return -1;
		}
		mpath.pop();
		mp = mpath.getTop();
	}
	cout << "·��:" << endl;
	mpath.printStack();//���·��

	return 0;
}
