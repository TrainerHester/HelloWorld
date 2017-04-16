// chapter2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct point {
	int x;
	int y;

	void print() {
		printf("x: %d, y: %d\n", x, y);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	stack integerStack;
	point* temp;
	integerStack.initialize();
	point po[20];
	//point** p = new point*[20];
	for (int i = 0; i < 20; i++) {
		po[i].x = i;
		po[i].y = i;
		integerStack.push(&po[i]);
	}
	while ((temp = (point*)integerStack.pop()) != 0) {
		temp->print();
	}
	return 0;
}

