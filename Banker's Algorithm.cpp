#include <iostream>
#include <vector>
using namespace std;
vector<int> Available;                    // 资源可用总量
vector<vector<int>> Max;             // 最大需求矩阵
vector<vector<int>> Allocation;   // 当前分配给每个进程各种资源数量
vector<vector<int>> Need;          // 各个进程还需要分配的各种资源
vector<int> Work;                         // 当前可分配的资源
vector<bool> Finish;                     // 进程是否结束
vector<int> order;                         // 输出最后的安全序列 
// 系统中进程总数
int N;
// 资源总数
int M;

void menu() {
	cout << "\t\t\t+------------------------+" << endl;
	cout << "\t\t\t       功能选择                   " << endl;
	cout << "\t\t\t 1. 显示当前资源情况        " << endl;
	cout << "\t\t\t 2. 显示当前安全序列        " << endl;
	cout << "\t\t\t 3. 请求资源分配               " << endl;
	cout << "\t\t\t 0. 退出                            " << endl;
}

// 初始化
void init() {

	// 开空间
	Available.resize(M);
	Max.resize(N);
	for (int i = 0; i < N; i++) {
		Max[i].resize(M);
	}
	Allocation.resize(N);
	for (int i = 0; i < N; i++) {
		Allocation[i].resize(M);
	}
	Need.resize(N);
	for (int i = 0; i < N; i++) {
		Need[i].resize(M);
	}
	Work.resize(M);
	Finish.resize(N);

	cout << "输入每种资源的个数~" << endl;
	for (int i = 0; i < M; i++) {
		cin >> Available[i];
	}

	cout << "输入每个进程所需资源情况~" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Max[i][j];
		}
	}

	cout << "输入每个进程已分配的资源数量~" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Allocation[i][j];
		}
	}

	// 各个进程还需分配的各种资源数量
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Need[i][j] = Max[i][j] - Allocation[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		Finish[i] = false;
	}

}



// 进行安全检查处理的函数
void handle() {
	// 清空最后安全序列，因为可能经过请求之后安全序列发生改变，所以每次清空重新寻找安全序列
	order.clear();
	// 每种资源当前可分配的数量
	for (int i = 0; i < M; i++) {
		Work[i] = Available[i];
		for (int j = 0; j < N; j++) {
			Work[i] -= Allocation[j][i];
		}
	}
	bool exit = false;
	int ttl = M*N;
	while (!exit) {
		for (int i = 0; i < N; i++) {
			int flag = 1;
			for (int j = 0; j < M; j++) {
				if (Need[i][j] > Work[j]) {
					flag = 0;
					break;
				}
			}
			if (Finish[i] == false && flag == 1) {
				for (int j = 0; j < M; j++) {
					Work[j] = Work[j] + Allocation[i][j];
				}
				Finish[i] = true;
				order.push_back(i);
			}
		}
		exit = true;
		for (int i = 0; i < N; i++) {
			if (Finish[i] == false) {
				exit = false;
				break;
			}
		}
		ttl -= 1;
		if (ttl == 0)
			break;
	}
}

	
// 银行家算法
void BankerAlgorithm() {
	int n;
	cout << "^_^输入要请求资源的进程~" << endl;
	cin >> n;
	vector<int>resources(M,0);        // 要请求的资源数
	cout << "^_^输入要请求的各种资源的数量~" << endl;
	for (int i = 0; i < M; i++) {
		cin >> resources[i];
	}
	for (int i = 0; i < M; i++) {
		if (resources[i] > Need[n][i]) {
			cout << ">_<所需要的资源超过最大值！！！" << endl;
			system("pause");
			return;
		}
		
	}
	for (int i = 0; i < M; i++) {
		if (resources[i] > Available[i]) {
			cout << ">_<尚无足够资源！！！" << endl;
			system("pause");
			return;
		}
	}
	for (int i = 0; i < M; i++) {
		Available[i] -= resources[i];
	}
	for (int i = 0; i < M; i++) {
		Allocation[n][i] += resources[i];
		Need[n][i] -= resources[i];
	}
	system("pause");
}

// 安全检查函数
bool SecurityCheck() {
	handle();
	int flag = 1;
	for (int i = 0; i < N; i++) {
		if (Finish[i] == false) {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		cout << "^_^ 系统是安全的~" << endl;
		return true;
	}
	else {
		cout << "T_T 系统是不安全的~~" << endl;
		return false;
	}
}

void OutOrder() {
	for (int i = 0; i < N; i++) {
		Finish[i] = false;
	}
	bool ret = SecurityCheck();
	if (ret == true) {
		cout << "安全序列如下！" << endl;
		for (int i = 0; i < N; i++) {
			cout << order[i] << "   ";
		}
		cout << endl;
	}
	system("pause");
}

// 输出当前进程的资源情况
void output() {
	cout << "进程" << "\t";
	for (int i = 0; i < M; i++) {
		cout << "资源" << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << i << "\t";
		for (int j = 0; j < M; j++) {
			cout << Allocation[i][j] << "\t";
		}
		cout << endl;
	}
	system("pause");
}

int main() {
	cout << "^_^因为您是首次使用，请先按照提示信息进行输入！" << endl;
	cout << "^_^ 请输入系统中进程总数和资源总数~" << endl;
	cin >> N >> M;
	init();
	int choice = 0;
	while (1) {
		system("cls");
		menu();
		cin >> choice;
		if (choice == 1) {
			system("cls");
			output();
		}
		else if (choice == 2) {
			system("cls");
			OutOrder();
		}
		else if (choice == 3) {
			system("cls");
			BankerAlgorithm();
		}
		else if (choice == 0) {
			break;
		}
	}
	return 0;
}
