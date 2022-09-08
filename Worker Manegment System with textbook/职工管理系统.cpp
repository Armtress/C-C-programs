#include<iostream>
#include"workermanage.h"
#include"manager.h"
#include"boss.h"
using namespace std;
#include"worker.h"
#include"employee.h"
int main() {
	

	workermanage wm;
	

	
	while (1) {
		cout << "请输入你的选择\n";
		wm.showmenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:		//退出
			wm.exitsystem();
			break;
		case 2:		//增加
			wm.add();
			break;
		case 3:		//显示
			wm.show();
			break;
		case 4:		//删除
			wm.del();
			break;
		case 5:		//修改
			wm.change();
			break;
		case 6:		//查找
			wm.find();
			break;
		case 7:		//排序
			wm.sort();
			break;
		case 8:		//清空
			wm.clean();
			break;
		default:
			//报错
			cout << "你的输入有误请你重新输入！\n";
			break;
		}
		system("pause");
		system("cls");
	}
	cout << "\n";
	system("pause");
	return 0;
}
