#include"employee.h"
#include<iostream>
using namespace std;
#include<string>

employee::employee(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//��ʾ������Ϣ
void employee::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "��λְ����ɾ�����������\n";
}
//��ȡ��λ����
string employee::getdid() {
	return string("Ա��");
}