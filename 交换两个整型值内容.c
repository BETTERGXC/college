// 交换两个整数的值 


#include<stdio.h>
#include<stdlib.h>
int change(int x,int y) {
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
	printf("x = %d\ny = %d\n", x, y);
	return 0;
}
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("x = %d\ny = %d\n", x, y);
	change(x,y);
	system("pause");
	return 0;
}






//  不允许创建临时变量，交换两个整数的值



#include<stdio.h>
#include<stdlib.h>
int change(int x,int y) {
	x = x + y;
	y = x + y;
	x = y - x;
	y = y - 2*x;
	printf("x = %d\ny = %d\n", x, y);
	return 0;
	
}
int main() {
	int x, y;
	scanf("%d %d",&x,&y);
	printf("x = %d\ny = %d\n", x, y);
	change(x, y);
	system("pause");
	return 0;
}

