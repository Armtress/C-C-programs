#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;

class manager :public worker {
public:
	manager(int a, string b, int c);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdid();
};
