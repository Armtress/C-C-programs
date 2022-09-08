#include"boss.h"
#include<iostream>
using namespace std;
#include<string>

boss::boss(int a, string b, int c) {
	this->id = a;
	this->name = b;
	this->did = c;
}
//显示个人性息
void  boss::showinfo() {
	cout << "id:" << this->id
		<< "\t" <<
		"name:" << this->name
		<< "\t" <<
		"did:" << this->getdid()
		<< "\t" << "岗位职责：管理所有员工\n";
}
//获取岗位名称
string  boss::getdid() {
	return string("老板");
}