#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"
class workermanage {
public:
	//记录职工的人数
	int num;
	//职工数组指针
	worker** s;
	//判断文件是否为空
	bool isempty;

	//展示菜单
	void showmenu();
	//退出系统
	void exitsystem();
	//增加职工
	void add();
	//保存文件
	void save();
	//统计成员函数
	int getnum();
	//初始化员工
	void init();
	//显示职工函数
	void show();
	//判断职工是否存在,存在返回下标值，不存在返回-1
	int isexist(int x);
	//删除职工
	void del();
	//修改职工信息
	void change();
	//查找员工
	void find();
	//排序
	void sort();
	//清空文件
	void clean();
	//构造函数
	workermanage();
	//析构函数
	~workermanage();
};
