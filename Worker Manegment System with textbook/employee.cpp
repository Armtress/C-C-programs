#include"employee.h"
#include<iostream>
using namespace std;
#include<string>

employee::employee(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//显示个人性息
void employee::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "岗位职责：完成经理交给的任务\n";
}
//获取岗位名称
string employee::getdid() {
	return string("员工");
}