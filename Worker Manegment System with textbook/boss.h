#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;

class boss :public worker {
public:
	boss(int a, string b, int c);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdid();
};
