/*1.�õ�����
  2.��ɾ�Ĳ�
  3.����������ʾ
*/ 
 
#include<stdio.h>
#include<stdlib.h> 
 
struct Score {                    //����ɼ��Ľṹ�� 
	
	int math;
	int C;
	int english;
};
 
struct student{                   //����ѧ��������Ϣ�Ľṹ�� 
	char name[20];
	long num;
	char sex[10];
	struct Score score;
	struct student *next;
};
 
struct student *creat(int number)                                     //�������� 
{
	
	int index;                                                        //����ѭ������ 
	struct student *head;
	struct student *p1,*p2,*p;
	head = p2 = (struct student *) malloc(sizeof(struct student));    //����ռ� 
	for(index = 0;index<number;index++) 
	{
		p1 = (struct student *) malloc(sizeof(struct student));       //p1��������ǰ�棬Ϊp1����ռ�
		p2->next = p1;
		p2 = p1;                                                      //��������ǰ�ƽ� 
	}
	p2->next = NULL;                                                  //ʹ�������Ľ��Ϊ��
	
	
	/*����ѧ������Ϣ*/
	
	p = head;                                                  //ʹp2��ָ������ͷ
	while(p->next!=NULL) 											  //����ɼ� 
	{
		printf("������ѧ��������:");
		scanf("%s",&p->name);
		printf("������ѧ����ѧ��:");
		scanf("%d",&p->num);
		printf("������ѧ�����Ա�:");
		scanf("%s",&p->sex);
		printf("��ֱ�����ѧ���ĸ�����C���ԡ�Ӣ��ɼ�:");
		scanf("%d%d%d",&p->score.math,&p->score.C,&p->score.english);
	    p = p->next;												   //���������ƽ� 
	    
	} 
	return  head;													   //������ͷ���� 
}
 
 
void  add(struct student *head)                   //����ѧ����Ϣ 
{
 
	struct student *p0,*p1,*p2;
	p1 = head;
	p2 = head->next;
	
		system("cls");
		p0=(struct student *)malloc(sizeof(struct student));
		printf("����������ѧ��������:");                    			   //��������Ҫ��������ݴ洢��P0��
		scanf("%s",&p0->name);
		printf("ѧ����ѧ��:");
		scanf("%d",&p0->num);
		printf("ѧ�����Ա�:");
		scanf("%s",&p0->sex);
		printf("�ֱ�����ѧ���ĸ�����C���ԡ�Ӣ��ɼ�");
		scanf("%d%d%d",&p0->score.math,&p0->score.C,&p0->score.english);
 
	p1->next = p0;
	p0->next = p2;
	
	
}
 
 
void decrease(struct student *head)         //ɾ��ѧ����Ϣ 
{
	int number;
	struct student *p2,*p1;
	printf("����������Ҫɾ���˵�ѧ�ţ�\n");
	scanf("%d",&number);                    //������Ҫɾ�����˵�ѧ��
    p1=head;                                //ʹ�����ͷ��ʼ
	p2=head->next;                          //p2��ǰ��p1�ں�
	if(number==head->num)
		head = p2;
	else
	while(p2->next!=NULL)                         //ѭ����������Ҫɾ����ѧ��ѧ��
	{
		if(number==p2->num)
			{
			p1->next=p2->next;              //������Ҫɾ����ѧ����Ϣ�洢�Ľڵ��������ȥ��
			break;
			}
		p1=p1->next;
		p2=p2->next;
	}
	
}
 
 
void change(struct student *head)            //�޸�ѧ����Ϣ 
{
	int n = 0;
	int number;
	int judge = 1;
	struct student *p1,*p2;
	p1 = (struct student *) malloc(sizeof(struct student));
	while(judge)
	{
		system("cls");
		printf("��������Ҫ�޸ĵ�ѧ�ţ�\n");
		scanf("%d",&number);
		p2 = head;
		while(p2->next!=NULL)                     //ѭ��������Ҫ�޸ĵ�ѧ����Ϣ
		{
			if(number==p2->num)             //���ҵ���Ҫ�޸�ѧ��ѧ�ţ�����������ݸ���
			{
				printf("ѧ��������Ϊ:");
				printf("%s\n",p2->name);
				printf("ѧ����ѧ��Ϊ:");
				printf("%d\n",p2->num);
				printf("ѧ�����Ա�Ϊ:");
				printf("%s\n",p2->sex);
				printf("ѧ���ĸ�����C���ԡ�Ӣ��ɼ��ֱ�Ϊ:");
				printf("%d %d %d\n",p2->score.math,p2->score.C,p2->score.english);
				judge = 0;
				n++;
			}
			p2=p2->next;
		
			
		}
		if(n==0)                        //��δ���ҵ�����Ҫ�޸ĵ�ѧ�����򱨴�
			{
				printf("���޴��ˣ�");
				judge = 1;
				
			}
 	}
 	
	printf("�������޸ĺ�ѧ��������:");      //�Բ��ҵ���ѧ����Ϣ���ݸ���
	scanf("%s",&p1->name);
	printf("ѧ����ѧ��:");
	scanf("%d",&p1->num);
	printf("ѧ�����Ա�:");
	scanf("%s",&p1->sex);
	printf("�ֱ�����ѧ���ĸ�����C���ԡ�Ӣ��ɼ�:");
	scanf("%d%d%d",&p1->score.math,&p1->score.C,&p1->score.english);
	p2=p1;
} 
 
 
void sort_num(struct student *head)         //���ܷ������г�ѧ���ɼ� 
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
	while(p1->next!=NULL)//ѭ������b�����ݣ�����ѧ�����ܳɼ���
	{
		
		score[i]=p1->score.math+p1->score.C+p1->score.english;//��ѧ�����п�Ŀ�ɼ����
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
	printf("����ѧ�����ܷ�����Ϊ��\n");
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
	while(p1->next!=NULL)//ѭ������b�����ݣ�����ѧ�����ܳɼ���
	{
		
		score[i]=p1->score.math;//��ѧ�����п�Ŀ�ɼ����
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
	printf("����ѧ���ĸ�������Ϊ��\n");
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
	while(p1->next!=NULL)//ѭ������b�����ݣ�����ѧ�����ܳɼ���
	{
		
		score[i]=p1->score.C;//��ѧ�����п�Ŀ�ɼ����
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
	printf("����ѧ����C��������Ϊ��\n");
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
	while(p1->next!=NULL)//ѭ������b�����ݣ�����ѧ�����ܳɼ���
	{
		
		score[i]=p1->score.english;//��ѧ�����п�Ŀ�ɼ����
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
	printf("����ѧ����Ӣ������Ϊ��\n");
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
		printf("\t\t\t\t\t\t ��ѡ������ʽ \n");
		printf("\t\t\t\t\t\t----------------\n");
		printf("\n\t\t\t\t\t\t1.���ܷ�����  \n");
		printf("\n\t\t\t\t\t\t2.����������  \n");
		printf("\n\t\t\t\t\t\t3.��C�������� \n");
		printf("\n\t\t\t\t\t\t4.��Ӣ������  \n");
		printf("\n\t\t\t\t\t\t5.����������  \n");
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
 
 
void find_number(struct student *head)          //����ѧ�Ų��Һ���
{
	int n=0;
	long i;                              //�������
	struct student *p2;                  //����ָ��
	p2=head;                       //ʹ�����ͷ��ʼ
	printf("����������Ҫ���ҵ�ѧ��ѧ��:");//��ʾ��Ϣ
	scanf("%d",&i);                      //������ҵ�ѧ��ѧ��
	while(p2->next!=NULL)                      //ѭ�����������ѧ��ѧ��
	{
	if(i==p2->num)                       //������ҵ�ѧ�����ҵ�
	{   system("cls");
	    printf("\n\n\n\t����Ҫ���ҵ�ѧ��������Ϊ:");//������ҵ���ѧ����Ϣ
		printf("%s\n",p2->name);
		printf("\tѧ����ѧ��Ϊ:");
		printf("%d",p2->num);
		printf("\tѧ�����Ա�Ϊ:");
		printf("%s\n",p2->sex);
		printf("\tѧ���ĸ�����C���ԡ�Ӣ��ɼ��ֱ�Ϊ:");
		printf("%d %d %d \n",p2->score.math,p2->score.C,p2->score.english);
		n++;
		break;
	}
	p2=p2->next;//ʹ������ǰ�ƽ�
	}
	if(n==0)//�ж��Ƿ��ҵ���Ҫ���ҵ�ѧ��
	printf("\t\t���޴��ˣ�");
	system("pause");
}
 
 
void find_name(struct student *head)//�����������Һ���
{
	char a[30];//�����ַ����飬���ڴ洢��Ҫ���ҵ�ѧ������
	int n=0;
	struct student *p2;//����ָ��
	printf("������������Ҫ���ҵ�����:");
	scanf("%s",a);//��������Ҫ���ҵ�ѧ������
	p2=head;//ʹ�����ͷ��ʼ
	while(p2->next!=NULL)//ѭ���������������
	{
		if(strcmp(a,p2->name)==0)//�������е���Ϣ��������������жԱ�
		{
		system("cls");
		printf("ѧ��������Ϊ:");
		printf("%s\n",p2->name);
		printf("ѧ����ѧ��Ϊ:");
		printf("%d",p2->num);
		printf("ѧ�����Ա�Ϊ:");
		printf("%s\n",p2->sex);
		printf("ѧ���ĸ�����C���ԡ�Ӣ��ɼ��ֱ�Ϊ:");
		printf("%d %d %d\n",p2->score.math,p2->score.C,p2->score.english);n++;
		system("pause");
		}
		p2=p2->next;
		
	}
	if(n==0)//�ж��Ƿ��ҵ���Ҫ���ҵ�����
	{
	printf("\t\t���޴��ˣ�");
	system("pause");
	}	
}
 
 
void cover()                                       //������溯�� 
{
    printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t****************\n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t\tѧ���ɼ�����ϵͳ\n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\t\t\t\t\t\t****************\n");
	printf("\n\t\t\t\t\t\t    ��ӭ��    \n");
	printf("\t\t\t\t\t\t----------------\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");
 
	system("color  0e");                          //������ɫΪ��ɫ������ɫ���� 
	system("pause");                              //��ͣ����ֹ���浯�ع��ܽ��� 
}
 
 
void function()                                          //���幦�ܽ��溯�� 
{
	system("cls");                                       //���� 
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t****************        \n");
	printf("\t\t\t\t\t\t----------------        \n");
	printf("\t\t\t\t\t\t        ������          \n");
	printf("\t\t\t\t\t\t----------------        \n");
	printf("\t\t\t\t\t\t1.------������Ϣ        \n");
	printf("\t\t\t\t\t\t2.------��������        \n");
	printf("\t\t\t\t\t\t3.------��ѧ�Ų�ѯ      \n");
	printf("\t\t\t\t\t\t4.------��������ѯ      \n");
	printf("\t\t\t\t\t\t5.------����ѧ��        \n");
	printf("\t\t\t\t\t\t6.------ɾ��ѧ��        \n");
	printf("\t\t\t\t\t\t7.------�޸�ѧ����Ϣ    \n");
	printf("\t\t\t\t\t\t8.------���ڳɼ�����ϵͳ\n");
	printf("\t\t\t\t\t\t9.------�˳�            \n");
	printf("\n\t\t\t\t\t\tѡ��Ҫִ�еĹ���        ");
	
}
 
 
void version()                           //����汾��Ϣ 
{
	
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t-------------------------------  \n");
	printf("\t\t\t\t\t*******************************  \n");
	printf("\t\t\t\t\t-------------------------------  \n");
	printf("\t\t\t\t\t-------�ɼ�����ϵͳ 1.0--------\n\n");
	printf("\t\t\t\t\t              By____18060207104\n\n");
	printf("\t\t\t\t\t--------------------- 2019/1/10\n\n");
	printf("\t\t\t\t\t�汾����------   �Ѿ������°汾\n\n");
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
	while(h==1)                                 //while�������ٴν���switchѡ�� 
		{ 	
		function();                            //��ʾ���ܽ��� 
		scanf("%d",&choose);                       //ѡ��ִ�еĲ���
		switch(choose)
			{
				case 1:system("cls");printf(" ����������Ҫ������ѧ������(�����������밴����ʾ���):");
					   scanf("%d",&n);             //����creat�Ĳ��������ƴ����ڵ������
					   head = creat(n);break;      //ѡ��1����������Ϣ���� 
				case 2:sort(head);break;               //ѡ��2����������� 
				case 3:find_number(head);break;        //ѡ��3���а�ѧ�Ų��Ҳ��� 
				case 4:find_name(head);break;          //ѡ��4���а��������Ҳ��� 
				case 5:add(head);break;
				case 6:decrease(head);break;
				case 7:change(head);break;
				case 8:version(head);break;            //ѡ��5����������� 
				case 9:h=0;break;                  //ѡ��7�����˳����� 
			}
			system("cls");                                            //���� 
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t��л����ʹ�ã�\n");
			printf("\t\t\t\t\t\t\t\t�ڴ��������ٴ�������\n");
			printf("\t\t\t\t\t\t");
	
    	}
	
 
}

