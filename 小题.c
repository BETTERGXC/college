

// 猜数字游戏
/************************************************/ 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//猜数字
void Game() {
	int num, unknow;
	//设置随机种子
	srand(time(0));
	//取一个1-100之间的随机数
	unknow = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜的数字\n");
		scanf("%d", &num);
		if (num < unknow)
			printf("低了！\n");
		if (num > unknow)
			printf("高了！\n");
		if (num == unknow) {
			printf("恭喜你！猜对了！\n");
			break;
	}
	}
 
}
 
int main() {
	
	int choice = 0;
	while (1) {
		printf("=======================\n");
		printf("1.开始游戏\n");
		printf("0.结束游戏\n");
		printf("=======================\n");
		scanf("%d", &choice);
		if (choice == 1)
			Game();
		else if (choice == 0)
			break;
		else
			printf("您的输入有误！请重新输入！\n");
		
	}
	system("pause");
	return 0;
}





/*************************************************/


//二分法查数字 


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int find(int arr[], int size,int to_Find) {
	int left, right, mid;
	left = 0;
	right = size - 1;
	mid = left + right / 2;
	while(left <= right) {
		mid = left + right / 2;
		if (to_Find<arr[mid]) {
			//往左找
			right = mid-1;
		}
		if (to_Find > arr[mid]) {
			//往右找
			left =mid + 1;
		}
		if (to_Find == arr[mid]) {
			//找到了
			return mid;
		}
	}
	return -1;
 
}
int main() {
	int size;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n",find(arr, size,10));
	system("pause");
	return 0;
}



/************************************************/

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”,密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。 

define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
//.编写代码模拟三次密码输入的场景。 
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
 
int main() {
	char password[10];
	int count = 0;
	for (int index = 0; index < 3; index++) {
		printf("请输入密码：(记住你只有三次机会哦)\n");
		scanf("%s", password);
		if (strcmp("wasd123.", password) == 0) {
			printf("密码正确！欢迎您！\n");
			break;
		}
		else {
			printf("密码错误！请重新输入！\n");
			count++;
		}
	}
	if (count == 3) {
		printf("您已经输错三次！即将退出程序！\n");
	}
	system("pause");
	return 0;
}


/************************************************/

//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出 



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
int main() {
	while (1)
	{
		char ch;
		ch = getchar();
		if (ch >= 'a' && ch <= 'z')
			printf("%c\n", ch - 32);
		if (ch >= 'A'&&ch <= 'Z')
			printf("%c\n", ch + 32);
	}
	system("pause");
	return 0;
}

