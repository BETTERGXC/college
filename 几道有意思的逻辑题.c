#include<stdio.h>
#include<stdlib.h>
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

int main() {
	int A, B, C, D, E;
	for (A = 1; A <= 5; A++) {
		for (B = 1; B <= 5; B++) {
			for (C = 1; C <= 5; C++) {
				for (D = 1; D < +5; D++) {
					for (E = 1; E <= 5; E++) {
						/*
						if(
						(B==2)+(A==3)==1
						&&(B==2)+(E==4)==1
						&&(C==1)+(D==2)==1
						&&(c==5)+(D==3)==1
						&&(E==4)+(A==1)==1
						)
						*/
						if (
							((B != 2 && A == 3) || (B == 2 && A != 3))
							&& ((B != 2 && E == 4) || (B == 2 && E != 4))
							&& ((C != 1 && D == 2) || (C == 1 && D != 2))
							&& ((C != 5 && D == 3) || (C == 5 && D != 3))
							&& ((E != 4 && A == 1) || (E == 4 && A != 1))
							) {
							if (A != B && A != C && A != D && A != E && B != C && B != D && B != E && C != D && C != E && D != E) {
								/*
								if(A*B*C*D*E==120)
								*/
								printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}


/*
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

*/

int main() {
	int killer;
	for (killer = 1; killer < 5; killer++) {
		if ((killer != 1) + (killer == 3) + (killer == 4) + (killer != 4) == 3)
			printf("killer is %c\n", killer - 1 + 'A');
	}

	/*
	char killer;
	for(killer = 'A';killer<'E';killer++) {
	if((killer != 'A')+(killer == 'B')+(killer == 'C')+(killer != 'D') == 3)
	printf("killer is %c\n",killer);
	}
	*/
	system("pause");
	return 0;
}

/*
����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main() {
	int row;
	scanf("%d", &row);
	int** arr = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)malloc(sizeof(int*)*(i+1));
	}
	for (int i = 0; i < row; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (int i = 2; i < row; i++) {
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	for (int i = 0; i < row; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;

}
