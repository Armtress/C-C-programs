#include"boss.h"
#include<iostream>
using namespace std;
#include<string>

boss::boss(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//��ʾ������Ϣ
void  boss::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "��λְ�𣺹�������Ա��\n";
}
//��ȡ��λ����
string  boss::getdid() {
	return string("�ϰ�");
}