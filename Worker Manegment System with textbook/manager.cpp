#include"manager.h"
#include<iostream>
using namespace std;
#include<string>

manager::manager(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//��ʾ������Ϣ
void  manager::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "��λְ�𣺸�Ա����������\n";
}
//��ȡ��λ����
string  manager::getdid() {
	return string("����");
}