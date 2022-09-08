#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class employee :public worker {
public:
	employee(int a,string b,int c);
	//显示个人性息
	virtual void showinfo();
	//获取岗位名称
	virtual string getdid();
};