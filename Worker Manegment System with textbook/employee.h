#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class employee :public worker {
public:
	employee(int a,string b,int c);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdid();
};