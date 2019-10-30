/*1.用到链表
  2.增删改查
  3.各种排序显示
*/ 
 
#include<stdio.h>
#include<stdlib.h> 
 
struct Score {                    //定义成绩的结构体 
	
	int math;
	int C;
	int english;
};
 
struct student{                   //定义学生个人信息的结构体 
	char name[20];
	long num;
	char sex[10];
	struct Score score;
	struct student *next;
};
 
struct student *creat(int number)                                     //创建链表 
{
	
	int index;                                                        //用于循环变量 
	struct student *head;
	struct student *p1,*p2,*p;
	head = p2 = (struct student *) malloc(sizeof(struct student));    //分配空间 
	for(index = 0;index<number;index++) 
	{
		p1 = (struct student *) malloc(sizeof(struct student));       //p1在链表最前面，为p1分配空间
		p2->next = p1;
		p2 = p1;                                                      //将链表向前推进 
	}
	p2->next = NULL;                                                  //使链表最后的结点为空
	
	
	/*输入学生的信息*/
	
	p = head;                                                  //使p2先指向链表头
	while(p->next!=NULL) 											  //输入成绩 
	{
		printf("请输入学生的姓名:");
		scanf("%s",&p->name);
		printf("请输入学生的学号:");
		scanf("%d",&p->num);
		printf("请输入学生的性别:");
		scanf("%s",&p->sex);
		printf("请分别输入学生的高数、C语言、英语成绩:");
		scanf("%d%d%d",&p->score.math,&p->score.C,&p->score.english);
	    p = p->next;												   //往链表后边推进 
	    
	} 
	return  head;													   //将链表头返回 
}
 
 
void  add(struct student *head)                   //插入学生信息 
{
 
	struct student *p0,*p1,*p2;
	p1 = head;
	p2 = head->next;
	
		system("cls");
		p0=(struct student *)malloc(sizeof(struct student));
		printf("请输入增加学生的姓名:");                    			   //将所有需要插入的内容存储到P0中
		scanf("%s",&p0->name);
		printf("学生的学号:");
		scanf("%d",&p0->num);
		printf("学生的性别:");
		scanf("%s",&p0->sex);
		printf("分别输入学生的高数、C语言、英语成绩");
		scanf("%d%d%d",&p0->score.math,&p0->score.C,&p0->score.english);
 
	p1->next = p0;
	p0->next = p2;
	
	
}
 
 
void decrease(struct student *head)         //删除学生信息 
{
	int number;
	struct student *p2,*p1;
	printf("请输入所需要删除人的学号：\n");
	scanf("%d",&number);                    //输入需要删除的人的学号
    p1=head;                                //使链表从头开始
	p2=head->next;                          //p2在前，p1在后
	if(number==head->num)
		head = p2;
	else
	while(p2->next!=NULL)                         //循环查找所需要删除的学生学号
	{
		if(number==p2->num)
			{
			p1->next=p2->next;              //将所需要删除的学生信息存储的节点从链表中去除
			break;
			}
		p1=p1->next;
		p2=p2->next;
	}
	
}
 
 
void change(struct student *head)            //修改学生信息 
{
	int n = 0;
	int number;
	int judge = 1;
	struct student *p1,*p2;
	p1 = (struct student *) malloc(sizeof(struct student));
	while(judge)
	{
		system("cls");
		printf("请输入你要修改的学号：\n");
		scanf("%d",&number);
		p2 = head;
		while(p2->next!=NULL)                     //循环查找需要修改的学生信息
		{
			if(number==p2->num)             //查找到需要修改学生学号，对其进行数据覆盖
			{
				printf("学生的姓名为:");
				printf("%s\n",p2->name);
				printf("学生的学号为:");
				printf("%d\n",p2->num);
				printf("学生的性别为:");
				printf("%s\n",p2->sex);
				printf("学生的高数、C语言、英语成绩分别为:");
				printf("%d %d %d\n",p2->score.math,p2->score.C,p2->score.english);
				judge = 0;
				n++;
			}
			p2=p2->next;
		
			
		}
		if(n==0)                        //若未查找到所需要修改的学生，则报错
			{
				printf("查无此人！");
				judge = 1;
				
			}
 	}
 	
	printf("请输入修改后学生的姓名:");      //对查找到的学生信息数据覆盖
	scanf("%s",&p1->name);
	printf("学生的学号:");
	scanf("%d",&p1->num);
	printf("学生的性别:");
	scanf("%s",&p1->sex);
	printf("分别输入学生的高数、C语言、英语成绩:");
	scanf("%d%d%d",&p1->score.math,&p1->score.C,&p1->score.english);
	p2=p1;
} 
 
 
void sort_num(struct student *head)         //按总分排序，列出学生成绩 
{
	struct student *p1,*p2,*p3;
	long num[100];
	int score[100];
	int index = 0,indexj = 0,i = 0,j = 0;
	p3=head;
	while(p3->next!=NULL)
	{
		num[j] = p3->num;
		j++;
		p3=p3->next;
	}
	p1=head;
	while(p1->next!=NULL)//循环控制b的内容（单个学生的总成绩）
	{
		
		score[i]=p1->score.math+p1->score.C+p1->score.english;//将学生所有科目成绩相加
		i++;
		p1=p1->next;
	}
	for(index = 0;index<i;index++)
	{
		for(indexj = 0;indexj<i-index;indexj++)
		{
			if(score[indexj]<score[indexj+1])
			{
				int temp1;
				long temp2;
				temp1 = score[indexj+1];
				score[indexj+1] = score[indexj];
				score[indexj]  = temp1;
				
				temp2 = num[indexj+1];
				num[indexj+1] = num[indexj];
				num[indexj] = temp2;
			}
		}
	}
	printf("所有学生的总分排序为：\n");
	for(index = 0;index<i;index++)
	{
		printf("%d\t%d\n",num[index],score[index]);
	}
}
 
 
void sort_math(struct student *head)
{
	struct student *p1,*p2,*p3;
	long num[100];
	int score[100];
	int index = 0,indexj = 0,i = 0,j = 0;
	p3=head;
	while(p3->next!=NULL)
	{
		num[j] = p3->num;
		j++;
		p3=p3->next;
	}
	p1=head;
	while(p1->next!=NULL)//循环控制b的内容（单个学生的总成绩）
	{
		
		score[i]=p1->score.math;//将学生所有科目成绩相加
		i++;
		p1=p1->next;
	}
	for(index = 0;index<i;index++)
	{
		for(indexj = 0;indexj<i-index;indexj++)
		{
			if(score[indexj]<score[indexj+1])
			{
				int temp1;
				long temp2;
				temp1 = score[indexj+1];
				score[indexj+1] = score[indexj];
				score[indexj]  = temp1;
				
				temp2 = num[indexj+1];
				num[indexj+1] = num[indexj];
				num[indexj] = temp2;
			}
		}
	}
	printf("所有学生的高数排序为：\n");
	for(index = 0;index<i;index++)
	{
		printf("%d\t%d\n",num[index],score[index]);
	}
} 
 
 
void sort_C(struct student *head)
{
	struct student *p1,*p2,*p3;
	long num[100];
	int score[100];
	int index = 0,indexj = 0,i = 0,j = 0;
	p3=head;
	while(p3->next!=NULL)
	{
		num[j] = p3->num;
		j++;
		p3=p3->next;
	}
	p1=head;
	while(p1->next!=NULL)//循环控制b的内容（单个学生的总成绩）
	{
		
		score[i]=p1->score.C;//将学生所有科目成绩相加
		i++;
		p1=p1->next;
	}
	for(index = 0;index<i;index++)
	{
		for(indexj = 0;indexj<i-index;indexj++)
		{
			if(score[indexj]<score[indexj+1])
			{
				int temp1;
				long temp2;
				temp1 = score[indexj+1];
				score[indexj+1] = score[indexj];
				score[indexj]  = temp1;
				
				temp2 = num[indexj+1];
				num[indexj+1] = num[indexj];
				num[indexj] = temp2;
			}
		}
	}
	printf("所有学生的C语言排序为：\n");
	for(index = 0;index<i;index++)
	{
		printf("%d\t%d\n",num[index],score[index]);
	}
 } 
 
 
void sort_english(struct student *head)
 {
	struct student *p1,*p2,*p3;
	long num[100];
	int score[100];
	int index = 0,indexj = 0,i = 0,j = 0;
	p3=head;
	while(p3->next!=NULL)
	{
		num[j] = p3->num;
		j++;
		p3=p3->next;
	}
	p1=head;
	while(p1->next!=NULL)//循环控制b的内容（单个学生的总成绩）
	{
		
		score[i]=p1->score.english;//将学生所有科目成绩相加
		i++;
		p1=p1->next;
	}
	for(index = 0;index<i;index++)
	{
		for(indexj = 0;indexj<i-index;indexj++)
		{
			if(score[indexj]<score[indexj+1])
			{
				int temp1;
				long temp2;
				temp1 = score[indexj+1];
				score[indexj+1] = score[indexj];
				score[indexj]  = temp1;
				
				temp2 = num[indexj+1];
				num[indexj+1] = num[indexj];
				num[indexj] = temp2;
			}
		}
	}
	printf("所有学生的英语排序为：\n");
	for(index = 0;index<i;index++)
	{
		printf("%d\t%d\n",num[index],score[index]);
	}
 }
 
 
void sort(struct student *head)
{
	
 	int k=1,choose;
 	while(k==1)
 	{	
 		system("cls");
	  	void sort_num();
		void sort_math();
		void sort_C();
		void sort_english(); 
	 	printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t****************\n");
		printf("\t\t\t\t\t\t----------------\n");
		printf("\t\t\t\t\t\t 请选择排序方式 \n");
		printf("\t\t\t\t\t\t----------------\n");
		printf("\n\t\t\t\t\t\t1.按总分排序  \n");
		printf("\n\t\t\t\t\t\t2.按高数排序  \n");
		printf("\n\t\t\t\t\t\t3.按C语言排序 \n");
		printf("\n\t\t\t\t\t\t4.按英语排序  \n");
		printf("\n\t\t\t\t\t\t5.返回主界面  \n");
		printf("\t\t\t\t\t\t****************\n");
		printf("\t\t\t\t\t\t");
		while(1)
		{
			scanf("%d",&choose);
			switch(choose)
			{
				case 1:system("cls");sort_num(head);system("pause");break;
				case 2:system("cls");sort_math(head);system("pause");break;
				case 3:system("cls");sort_C(head);system("pause");break;
				case 4:system("cls");sort_english(head);system("pause");break;
				case 5:k = 0;break;
			}
			break;
		}
	}
} 
 
 
void find_number(struct student *head)          //按照学号查找函数
{
	int n=0;
	long i;                              //定义变量
	struct student *p2;                  //定义指针
	p2=head;                       //使链表从头开始
	printf("请输入您所要查找的学生学号:");//提示信息
	scanf("%d",&i);                      //输入查找的学生学号
	while(p2->next!=NULL)                      //循环查找输入的学生学号
	{
	if(i==p2->num)                       //输入查找的学号已找到
	{   system("cls");
	    printf("\n\n\n\t您所要查找的学生的姓名为:");//输出查找到的学生信息
		printf("%s\n",p2->name);
		printf("\t学生的学号为:");
		printf("%d",p2->num);
		printf("\t学生的性别为:");
		printf("%s\n",p2->sex);
		printf("\t学生的高数、C语言、英语成绩分别为:");
		printf("%d %d %d \n",p2->score.math,p2->score.C,p2->score.english);
		n++;
		break;
	}
	p2=p2->next;//使链表向前推进
	}
	if(n==0)//判断是否找到需要查找的学号
	printf("\t\t查无此人！");
	system("pause");
}
 
 
void find_name(struct student *head)//按照姓名查找函数
{
	char a[30];//定义字符数组，用于存储需要查找的学生姓名
	int n=0;
	struct student *p2;//定义指针
	printf("请输入你所需要查找的姓名:");
	scanf("%s",a);//输入所需要查找的学生姓名
	p2=head;//使链表从头开始
	while(p2->next!=NULL)//循环查找输入的姓名
	{
		if(strcmp(a,p2->name)==0)//对链表中的信息与输入的姓名进行对比
		{
		system("cls");
		printf("学生的姓名为:");
		printf("%s\n",p2->name);
		printf("学生的学号为:");
		printf("%d",p2->num);
		printf("学生的性别为:");
		printf("%s\n",p2->sex);
		printf("学生的高数、C语言、英语成绩分别为:");
		printf("%d %d %d\n",p2->score.math,p2->score.C,p2->score.english);n++;
		system("pause");
		}
		p2=p2->next;
		
	}
	if(n==0)//判断是否找到需要查找的姓名
	{
	printf("\t\t查无此人！");
	system("pause");
	}	
}
 
 
void cover()                                       //定义封面函数 
{
    printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t****************\n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t\t学生成绩管理系统\n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t\t****************\n");
	printf("\n\t\t\t\t\t\t    欢迎您    \n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");
 
	system("color  0e");                          //调整颜色为黑色背景黄色字体 
	system("pause");                              //暂停，防止里面弹回功能界面 
}
 
 
void function()                                          //定义功能界面函数 
{
	system("cls");                                       //清屏 
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t****************        \n");
	printf("\t\t\t\t\t\t----------------        \n");
	printf("\t\t\t\t\t\t        功能区          \n");
	printf("\t\t\t\t\t\t----------------        \n");
	printf("\t\t\t\t\t\t1.------输入信息        \n");
	printf("\t\t\t\t\t\t2.------进行排序        \n");
	printf("\t\t\t\t\t\t3.------按学号查询      \n");
	printf("\t\t\t\t\t\t4.------按姓名查询      \n");
	printf("\t\t\t\t\t\t5.------增加学生        \n");
	printf("\t\t\t\t\t\t6.------删除学生        \n");
	printf("\t\t\t\t\t\t7.------修改学生信息    \n");
	printf("\t\t\t\t\t\t8.------关于成绩管理系统\n");
	printf("\t\t\t\t\t\t9.------退出            \n");
	printf("\n\t\t\t\t\t\t选择要执行的功能        ");
	
}
 
 
void version()                           //定义版本信息 
{
	
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t-------------------------------  \n");
	printf("\t\t\t\t\t*******************************  \n");
	printf("\t\t\t\t\t-------------------------------  \n");
	printf("\t\t\t\t\t-------成绩管理系统 1.0--------\n\n");
	printf("\t\t\t\t\t              By____18060207104\n\n");
	printf("\t\t\t\t\t--------------------- 2019/1/10\n\n");
	printf("\t\t\t\t\t版本更新------   已经是最新版本\n\n");
	printf("\t\t\t\t\t\t");
	system("pause");
	
}
 
 
 
int main()
{
	struct student * head;
	int n;
	
	
//	struct student *creat();
 
	
	cover();
	
	int h = 1,choose;
	while(h==1)                                 //while语句可以再次进行switch选择 
		{ 	
		function();                            //显示功能界面 
		scanf("%d",&choose);                       //选择执行的操作
		switch(choose)
			{
				case 1:system("cls");printf(" 请输入您所要创建的学生人数(接下来步骤请按照提示完成):");
					   scanf("%d",&n);             //输入creat的参数，控制创建节点的数量
					   head = creat(n);break;      //选择1进行输入信息操作 
				case 2:sort(head);break;               //选择2进行排序操作 
				case 3:find_number(head);break;        //选择3进行按学号查找操作 
				case 4:find_name(head);break;          //选择4进行按姓名查找操作 
				case 5:add(head);break;
				case 6:decrease(head);break;
				case 7:change(head);break;
				case 8:version(head);break;            //选择5进行输出操作 
				case 9:h=0;break;                  //选择7进行退出操作 
			}
			system("cls");                                            //清屏 
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t感谢您的使用！\n");
			printf("\t\t\t\t\t\t\t\t期待与您的再次相遇！\n");
			printf("\t\t\t\t\t\t");
	
    	}
	
 
}

