#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;

class manager :public worker {
public:
	manager(int a, string b, int c);
	//显示个人性息
	virtual void showinfo();
	//获取岗位名称
	virtual string getdid();
};
