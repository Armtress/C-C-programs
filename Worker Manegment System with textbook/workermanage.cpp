#include"workermanage.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
//初始化函数
workermanage::workermanage() {

	//第一种情况，文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		this->num = 0;
		this->s = NULL;
		isempty = true;
		ifs.close();
		return;
	}
	//第二种情况，文件存在，数据为空
	char ch;
	ifs >> ch;
	if(ifs.eof()) {
		this->num = 0;
		this->s = NULL;
		isempty = true;
		ifs.close();
		return;
	}
	//第三种情况，文件存在，并且不为空
	int x = this->getnum();

	//开辟空间
	this->num = x;
	this->s = new worker * [num];
	//初始化数组
	this->init();

	//测试读取文件代码
	/*for (int i = 0; i < this->num; i++)
	{
		cout << this->s[i]->id << " "
			<< this->s[i]->name << " "
			<< this->s[i]->id << endl;
	}*/
}

//显示菜单
void workermanage::showmenu() {
	cout << "********************************************\n";
	cout << "*********** 欢迎使用职工管理系统 ***********\n";
	cout << "*********** 1.退出管理程序 *****************\n";
	cout << "*********** 2.增加职工信息 *****************\n";
	cout << "*********** 3.显示职工信息 *****************\n";
	cout << "*********** 4.删除离职职工 *****************\n";
	cout << "*********** 5.修改职工信息 *****************\n";
	cout << "*********** 6.查找职工信息 *****************\n";
	cout << "*********** 7.按照编号排序 *****************\n";
	cout << "*********** 8.清空所有文档 *****************\n";
}
//退出系统
void workermanage::exitsystem() {
	cout << "欢迎下次继续使用！\n";
	system("pause");
	exit(0);
}
//添加职工
void workermanage::add() {
	cout << "请输入添加职工的数量\n";
	int x=0;
	cin >> x;

	if (x > 0) {
		//添加
		//计算新的空间大小=原来人数+新增人数
		int newsize = this->num + x;
		worker** newspace = new worker * [newsize];
		//转移到新的数组
		if (this->s!=NULL) {
			for (int i = 0; i < this->num; i++) {
				newspace[i] = this->s[i];
			}
		}
		//添加新的数据
		for (int i = 0; i < x; i++) {
			int id;//职工编号
			string name;//职工姓名
			int dep;//部门编号

			cout << "请输入第" << i + 1 << "个员工的编号:\n";
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名:\n";
			cin >> name;
			cout << "请输入第" << i + 1 << "个员工的部门编号:\n";
			cout << "1.普通职工\n2.经理\n3.老板\n";
			cin >> dep;

			worker* w = NULL;
			switch (dep)
			{
			case 1:
				w = new employee(id, name, 1);
				break;
			case 2:
				w = new manager(id, name, 1);
				break;
			case 3:
				w = new boss (id, name, 1);
				break;
			default:
				break;
			}
			//将新的指针保存到数组中
			newspace[this->num + i] = w;
		}
		//释放旧的数组
		delete[] this->s;
		//更改新空间的指向
		this->s = newspace;
		//更新新的职工人数
		this->num = newsize;

		cout << "成功添加" << x << "名职工!\n";
		//保存数据到文件中
		this->save();
		isempty = false;
	}
	else {
		cout << "你的输入有误\n";
	}

}

void workermanage::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//输出文件打开，写入内容

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->num; i++) {
		ofs << this->s[i]->id << " "
			<< this->s[i]->name << " "
			<< this->s[i]->did << endl;
	}
	
	//关闭文件
	ofs.close();
}

int workermanage::getnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	int id;
	string name;
	int did;
	int x=0;
	while (ifs>>id && ifs>>name && ifs>>did) {
		x++;//记录人数
	}
	return x;
}

void workermanage::init() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) 
	{
		worker* w=NULL;
		if (did == 1) {
			w = new employee(id, name, did);
		}
		else if (did == 2) {
			w = new manager(id, name, did);
		}
		else  {
			w = new boss(id, name, did);
		}
		this->s[index] = w;
		index++;
	}
	//关闭文件
	ifs.close();
}

void workermanage::show() {
	if (this->isempty == true) {
		cout << "该文件为空或不存在！\n";
	}
	if (this->isempty == false) {
		for (int i = 0; i < this->num; i++)
		{
			this->s[i]->showinfo();
		}
	}
}

int workermanage::isexist(int x) {
	int index = -1;
	for (int i = 0; i < this->num;i++) {
		if (this->s[i]->id == x) {
			index = i;
			break;
		}
	}
	return index;
}

void workermanage::del() {
	int x;
	if (this->isempty) {
		cout << "文件不存在或记录为空！\n";
		return;
	}
	else {
		cout << "请输入你想删除的职工编号\n";
		cin >> x;
	}

	int index = this->isexist(x);
	if (index == -1) {
		cout << "删除失败，没有找到该职工\n";
		return;
	}
	else {
		for (int i = index; i < this->num - 1; i++) {
			//数据前移
			this->s[i] = this->s[i + 1];
		}
		//人总数减一
		this->num--;
		//保存txt文件
		this->save();
		cout << "删除成功!\n";
	}
}

void workermanage::change() {
	int x;
	if (this->isempty) {
		cout << "文件不存在或记录为空！\n";
		return;
	}
	else {
		cout << "请输入你想修改的职工编号\n";
		cin >> x;
	}

	int index = this->isexist(x);


	if (index == -1) {
		cout << "修改失败，没有找到该职工\n";
		return;
	}
	else {
		delete this->s[index];

		int newid = 0;
		string newname = "";
		int newdid = 0;

		cout << "查找到id为" << x << "的职工\n";

		cout << "请输入新的id号\n";
		cin >> newid;

		cout << "请输入新的姓名\n";
		cin >> newname;

		cout << "请输入新的部门编号\n1.普工\n2.经理\n3.老板\n";
		cin >> newdid;

		worker* w = NULL;
		switch (newdid)
		{
		case 1:
			w = new employee(newid, newname, newdid);
			break;
		case 2:
			w = new manager(newid, newname, newdid);
			break;
		case 3:
			w = new boss(newid, newname, newdid);
			break;
		default:
			cout << "你的输入有误！\n";
			break;
		}
		this->s[index] = w;
		cout << "修改成功！\n";
		this->save();
	}
}

void workermanage::find() {
	if (this->isempty) {
		cout << "文件不存在或者记录为空!\n";
	}
	else {
		cout << "请输入查找方式：\n1. 按照职工id\n2. 按照职工姓名\n";
		int select;
		cin >> select;

		if (select == 1) 
		{
			int id;
			cout << "请输入职工id\n";
			cin >> id;
			
			int ret = isexist(id);
			if (ret == -1) {
				cout << "没有找到该职工!\n";
			}
			else {
				cout << "查找成功，该职工的信息如下！\n";
				this->s[ret]->showinfo();
			}

		}

		else if (select == 2) {
			string n;
			cout << "请输入职工姓名\n";
			cin >> n;
			bool flag = false;
			for (int i = 0; i < this->num; i++) {
				if (this->s[i]->name == n) {
					cout  << this->s[i]->id << "号职工符合条件，该职工的信息如下\n";
					this->s[i]->showinfo();
					flag = true;
				}
			}
			if (flag==false) {
				cout << "没有找到相应的职工！\n";
			}
		}

		else {
			cout << "输入的选项有误!\n";
		}
	}
}

void workermanage::sort() {
	if (this->isempty) {
		cout << "文件不存在或者记录为空!\n";
	}
	else {
		cout << "请输入排序方式:\n1. 按照id号升序\n2. 按照id号降序\n";
		int select;
		cin >> select;

		int i, j,temp;
		if (select == 2) {
			for (i = 0; i < this->num; i++) {
				for (j = i + 1; j < this->num; j++) {
					if (this->s[i]->id < this->s[j]->id) {
						temp=this->s[i]->id;
						this->s[i]->id = this->s[j]->id;
						this->s[j]->id = temp;
					}
				}
			}
			cout << "排序完成\n";
			this->save();
		}

		else if (select == 1) {
			for (i = 0; i < this->num; i++) {
				for (j = i + 1; j < this->num; j++) {
					if (this->s[i]->id > this->s[j]->id) {
						temp = this->s[i]->id;
						this->s[i]->id = this->s[j]->id;
						this->s[j]->id = temp;
					}
				}
			}
			cout << "排序完成\n";
			this->save();
		}

		else {
			cout << "你的输入有误\n";
		}
	}
}

void workermanage::clean() {
	cout << "确认删除所有文件？\n1. 确认\n2. 返回\n";
	int select;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//删除堆区的每个职工对象
		if (this->s != NULL) {
			for (int i = 0; i < this->num; i++) {
				delete this->s[i];
				this->s[i] = NULL;
			}
		}
		//删除堆区的数组指针
		delete[] this->s;
		this->s = NULL;
		this->num = 0;
		this->isempty = true;

		//删除成功
		cout << "删除成功\n";
	}

}

workermanage::~workermanage(){
	if (this->s != NULL) {
		for (int i = 0; i < this->num; i++) {
			if (this->s[i] != NULL) {
				delete this->s[i];
			}
		}
		delete[] this->s;
		this->s = NULL;
	}
}