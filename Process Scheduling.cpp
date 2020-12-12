#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
using namespace std;
#define TIME 1       // 时间片轮转算法里边一次执行时间

typedef struct process {
	process()                           // 初始化进程信息
		:_arrive_time(0)
		, _run_time(0)
		, _priority_num(0)
		, _over_time(0)
	{}
	string _process_name;    // 进程名字
	float _arrive_time;              // 到达时间 
	float _run_time;				   // 运行时间
	float _priority_num;           // 优先级
	float _over_time;               // 完成时间
}porcess;

// 先来先服务
void FCFS(vector<process*> rd_vector) {
	// 按照进程到达顺序由小到大进行排序
	for (int i = 0; i < rd_vector.size()-1; i++) {
		for (int j = i + 1; j < rd_vector.size(); j++) {
			if (rd_vector[i]->_arrive_time > rd_vector[j]->_arrive_time) {
				swap(rd_vector[i], rd_vector[j]);
			}
		}
	}
	// 计算完成时间
	rd_vector[0]->_over_time = rd_vector[0]->_run_time;
	for (int i = 1; i < rd_vector.size(); i++) {
		rd_vector[i]->_over_time = rd_vector[i - 1]->_over_time + rd_vector[i]->_run_time;
	}
	// 打印结果
	cout << endl;
	cout << "进程名字" << "\t" << "到达时间" << "\t" << "结束时间" << endl;
	for (int i = 0; i < rd_vector.size(); i++) {
		cout << rd_vector[i]->_process_name << "\t\t" <<rd_vector[i]->_arrive_time << "\t\t" 
			<< rd_vector[i]->_over_time <<endl;
	}
	system("pause");
}

// 短作业优先
void SJF(vector<process*> rd_vector) {
	// 先判断出哪个进程是第一个到达的
	for (int i = 0; i < rd_vector.size(); i++) {
		if (rd_vector[i]->_arrive_time == 0) {
			swap(rd_vector[i], rd_vector[0]);
			break;
		}
	}

	// 按照运行时间长短进行排序
	for (int i = 1; i < rd_vector.size()-1; i++) {
		for (int j = i + 1; j < rd_vector.size(); j++) {
			if (rd_vector[i]->_run_time > rd_vector[j]->_run_time) {
				swap(rd_vector[i], rd_vector[j]);
			}
		}
	}

	// 计算完成时间
	rd_vector[0]->_over_time = rd_vector[0]->_run_time;
	for (int i = 1; i < rd_vector.size(); i++) {
		rd_vector[i]->_over_time = rd_vector[i - 1]->_over_time + rd_vector[i]->_run_time;
	}

	// 打印结果
	cout << endl;
	cout << "进程名字" << "\t" << "到达时间" << "\t" << "运行时间" << "\t" << "结束时间" << endl;
	for (int i = 0; i < rd_vector.size(); i++) {
		cout << rd_vector[i]->_process_name << "\t\t" << rd_vector[i]->_arrive_time << "\t\t"
			<< rd_vector[i]->_run_time << "\t\t" << rd_vector[i]->_over_time << endl;
	}
	system("pause");
}

// 高相应比
void HRRN(vector<process*> rd_vector) {
	int pos = 0;
	rd_vector[0]->_over_time = rd_vector[0]->_run_time;
	while (pos < rd_vector.size()) {
		int left = pos + 1;
		int right = rd_vector.size() - 1;
		while (left < right) {
			while (left < right && rd_vector[left]->_arrive_time < rd_vector[pos]->_over_time) {
				++left;
			}
			while (left < right && rd_vector[right]->_arrive_time > rd_vector[pos]->_over_time) {
				right--;
			}
			swap(rd_vector[left], rd_vector[right]);
		}
		// 如果有进程是在正在运行的进程运行过程中到达的，那就进行优先级比较
		if (pos + 1 < left) {
			// 给在等待的进程计算优先级
			for (int i = pos + 1; i < left; i++) {
				rd_vector[i]->_priority_num = ((rd_vector[pos]->_over_time - rd_vector[i]->_arrive_time)
					+ rd_vector[i]->_run_time) / rd_vector[i]->_run_time;
			}

			// 挑选出优先权最大的进程
			int maxi = 0;
			int max_priority = 0;
			for (int i = pos + 1; i < left; i++) {
				if (rd_vector[i]->_priority_num > max_priority) {
					max_priority = rd_vector[i]->_priority_num;
					maxi = i;
				}
			}
			// 将现在优先权最大的放到正在运行的进程后边
			swap(rd_vector[pos + 1], rd_vector[maxi]);
			rd_vector[pos + 1]->_over_time = rd_vector[pos]->_over_time + rd_vector[pos + 1]->_run_time;
			pos++;
		}
		// 如果没有进程是在正在运行中的进程运行结束前进入的，就找出最先到达的进程
		else {
			// 比较最先到达的进程
			int first = rd_vector.size() - 1;
			for (int i = pos + 1; i < rd_vector.size()-1; i++) {
				if (rd_vector[i]->_arrive_time < rd_vector[first]->_arrive_time) {
					first = i;
				}
			}
			if (pos + 1 < rd_vector.size() - 1) {
				swap(rd_vector[first], rd_vector[pos + 1]);
				rd_vector[pos + 1]->_over_time = rd_vector[pos]->_over_time + rd_vector[pos + 1]->_run_time;
				pos++;
			}
			else if (pos == 0) {
				rd_vector[pos]->_over_time = rd_vector[pos]->_run_time;
				pos++;
			}
			else  {
				rd_vector[pos]->_over_time = rd_vector[pos - 1]->_over_time + rd_vector[pos]->_run_time;
				pos++;
			}
				
		}
	}
	cout << endl;
	cout << "进程名字" << "\t" << "到达时间" << "\t" << "运行时间" << "\t" << "结束时间" << endl;
	for (int i = 0; i < rd_vector.size(); i++) {
		cout << rd_vector[i]->_process_name << "\t\t" << rd_vector[i]->_arrive_time << "\t\t"
			<< rd_vector[i]->_run_time << "\t\t" << rd_vector[i]->_over_time << endl;
	}
	system("pause");
}

// 时间片轮转
void RR(vector<process*> rd_vector) {
	queue<process*> rd_queue;           // 进程的就绪队列
	// 按照进程到达顺序由小到大进行排序
	for (int i = 0; i < rd_vector.size() - 1; i++) {
		for (int j = i + 1; j < rd_vector.size(); j++) {
			if (rd_vector[i]->_arrive_time > rd_vector[j]->_arrive_time) {
				swap(rd_vector[i], rd_vector[j]);
			}
		}
	}
	rd_queue.push(rd_vector[0]);
	int pos = 1;
	int count = 0;
	while (!rd_queue.empty()) {
		if (pos < rd_vector.size()) {
			rd_queue.push(rd_vector[pos]);
			pos++;
		}
		rd_queue.front()->_run_time -= TIME;
		int flag = rd_queue.front()->_run_time;
		++count;
		if (flag == 0) {
			for (int i = 0; i < rd_vector.size(); i++) {
				if (rd_queue.front()->_process_name == rd_vector[i]->_process_name) {
					rd_vector[i]->_over_time = count;
				}
			}
		}
		process* tmp = rd_queue.front();
		rd_queue.pop();
		if (flag > 0) {
			rd_queue.push(tmp);
		}
		
	}
	// 计算运行时间
	for (int i = 0; i < rd_vector.size(); i++) {
		rd_vector[i]->_run_time = rd_vector[i]->_over_time - rd_vector[i]->_arrive_time;
	}
	// 打印结果
	cout << endl;
	cout << "进程名字" << "\t" << "到达时间" << "\t" << "运行时间" << "\t" << "结束时间" << endl;
	for (int i = 0; i < rd_vector.size(); i++) {
		cout << rd_vector[i]->_process_name << "\t\t" << rd_vector[i]->_arrive_time << "\t\t"
			<< rd_vector[i]->_run_time << "\t\t" << rd_vector[i]->_over_time << endl;
	}
	system("pause");

}


// 菜单界面
void menu() {
	cout << "\t\t\t+------------------+"<< endl;
	cout << "\t\t\t请选择进程调度方式" << endl;
	cout << "\t\t\t1. 先来先服务"           << endl;
	cout << "\t\t\t2. 短作业优先"           << endl;
	cout << "\t\t\t3. 优先级调度"           << endl;
	cout << "\t\t\t4. 时间片轮转"            << endl;
	cout << "\t\t\t0. 退出"                      << endl;
	cout << "\t\t\t+------------------+"<< endl;
}

int main() {
	int N;                                               // 表示进程的个数
	cout << "请输入进程的个数" << endl;
	cin >> N;
	vector<process*> rd_vector;            // 存储进程的数组
	rd_vector.resize(N);
	process* _process = new process[N];  // 新建N的进程结点
	cout << "请依次输入进程信息" << endl;
	cout << "名字" << "\t" << "到达时间" << "\t" << "运行时间"  << endl;
	for (int i = 0; i < N; i++) {
		cin >> _process[i]._process_name >> _process[i]._arrive_time 
			 >> _process[i]._run_time;
		rd_vector[i] = &_process[i];
	}
	while (1) {
		system("cls");
		menu();
		int choice = 0;          // 选择的调度类型
		cin >> choice;
		if (choice == 1) {
			FCFS(rd_vector);
		}
		else if (choice == 2) {
			SJF(rd_vector);
		}
		else if (choice == 3) {
			HRRN(rd_vector);
		}
		else if (choice == 4) {
			RR(rd_vector);
		}
		else if (choice == 0) {
			break;
		}
	}
	
}