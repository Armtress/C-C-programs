#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"
class workermanage {
public:
	//��¼ְ��������
	int num;
	//ְ������ָ��
	worker** s;
	//�ж��ļ��Ƿ�Ϊ��
	bool isempty;

	//չʾ�˵�
	void showmenu();
	//�˳�ϵͳ
	void exitsystem();
	//����ְ��
	void add();
	//�����ļ�
	void save();
	//ͳ�Ƴ�Ա����
	int getnum();
	//��ʼ��Ա��
	void init();
	//��ʾְ������
	void show();
	//�ж�ְ���Ƿ����,���ڷ����±�ֵ�������ڷ���-1
	int isexist(int x);
	//ɾ��ְ��
	void del();
	//�޸�ְ����Ϣ
	void change();
	//����Ա��
	void find();
	//����
	void sort();
	//����ļ�
	void clean();
	//���캯��
	workermanage();
	//��������
	~workermanage();
};
