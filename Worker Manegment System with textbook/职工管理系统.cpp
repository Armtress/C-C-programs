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
		cout << "���������ѡ��\n";
		wm.showmenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:		//�˳�
			wm.exitsystem();
			break;
		case 2:		//����
			wm.add();
			break;
		case 3:		//��ʾ
			wm.show();
			break;
		case 4:		//ɾ��
			wm.del();
			break;
		case 5:		//�޸�
			wm.change();
			break;
		case 6:		//����
			wm.find();
			break;
		case 7:		//����
			wm.sort();
			break;
		case 8:		//���
			wm.clean();
			break;
		default:
			//����
			cout << "����������������������룡\n";
			break;
		}
		system("pause");
		system("cls");
	}
	cout << "\n";
	system("pause");
	return 0;
}
