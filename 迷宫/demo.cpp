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
	{ false,false,false,false,false,false,false,false,false,false } };//迷宫矩阵
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			mpArray[i][j].x = i;
			mpArray[i][j].y = j;
			mpArray[i][j].can_move_to = initArray[i][j];
		}
	mPoint startp(1, 1, true);//初始坐标（入口）
	mPoint endp(8, 8, true);  //结束坐标（出口）

	mStack mpath;//定义对象
	mpath.push(startp);//把初始坐标入栈

	mPoint mp = startp;//记录当前坐标
	while (true)
	{
		if (mp.x == endp.x && mp.y == endp.y)
			break;//成功出迷宫
		if (mpArray[mp.x + 1][mp.y].can_move_to)//向下
		{
			mpArray[mp.x + 1][mp.y].can_move_to = false;//将走过的路标记为false
			mpath.push(mPoint(mp.x + 1, mp.y));
			mp = mpArray[mp.x + 1][mp.y];
			continue;
		}
		if (mpArray[mp.x - 1][mp.y].can_move_to)//向上
		{
			mpArray[mp.x - 1][mp.y].can_move_to = false;
			mpath.push(mPoint(mp.x - 1, mp.y));
			mp = mpArray[mp.x - 1][mp.y];
			continue;
		}
		if (mpArray[mp.x][mp.y + 1].can_move_to)//向右
		{
			mpArray[mp.x][mp.y + 1].can_move_to = false;
			mpath.push(mPoint(mp.x, mp.y + 1));
			mp = mpArray[mp.x][mp.y + 1];
			continue;
		}
		if (mpArray[mp.x][mp.y - 1].can_move_to)//向左
		{
			mpArray[mp.x][mp.y - 1].can_move_to = false;
			mpath.push(mPoint(mp.x, mp.y - 1));
			mp = mpArray[mp.x][mp.y - 1];
			continue;
		}
		if (0 == mpath.getLength())//栈空
		{
			cout << "没有路" << endl;
			return -1;
		}
		mpath.pop();
		mp = mpath.getTop();
	}
	cout << "路径:" << endl;
	mpath.printStack();//输出路径

	return 0;
}
