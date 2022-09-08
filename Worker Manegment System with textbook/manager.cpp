#include"manager.h"
#include<iostream>
using namespace std;
#include<string>

manager::manager(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//显示个人性息
void  manager::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "岗位职责：给员工布置任务\n";
}
//获取岗位名称
string  manager::getdid() {
	return string("经理");
}