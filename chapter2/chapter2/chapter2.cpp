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
	point** p = new point*[20];
	for (int i = 0; i < 20; i++) {
		p[i] = new point;
		p[i]->x = i;
		p[i]->y = i;
		integerStack.push(p[i]);
	}
	while ((temp = (point*)integerStack.pop()) != 0) {
		temp->print();
	}
	return 0;
}

