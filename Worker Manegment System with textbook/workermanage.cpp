#include"workermanage.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
//��ʼ������
workermanage::workermanage() {

	//��һ��������ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		this->num = 0;
		this->s = NULL;
		isempty = true;
		ifs.close();
		return;
	}
	//�ڶ���������ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if(ifs.eof()) {
		this->num = 0;
		this->s = NULL;
		isempty = true;
		ifs.close();
		return;
	}
	//������������ļ����ڣ����Ҳ�Ϊ��
	int x = this->getnum();

	//���ٿռ�
	this->num = x;
	this->s = new worker * [num];
	//��ʼ������
	this->init();

	//���Զ�ȡ�ļ�����
	/*for (int i = 0; i < this->num; i++)
	{
		cout << this->s[i]->id << " "
			<< this->s[i]->name << " "
			<< this->s[i]->id << endl;
	}*/
}

//��ʾ�˵�
void workermanage::showmenu() {
	cout << "********************************************\n";
	cout << "*********** ��ӭʹ��ְ������ϵͳ ***********\n";
	cout << "*********** 1.�˳�������� *****************\n";
	cout << "*********** 2.����ְ����Ϣ *****************\n";
	cout << "*********** 3.��ʾְ����Ϣ *****************\n";
	cout << "*********** 4.ɾ����ְְ�� *****************\n";
	cout << "*********** 5.�޸�ְ����Ϣ *****************\n";
	cout << "*********** 6.����ְ����Ϣ *****************\n";
	cout << "*********** 7.���ձ������ *****************\n";
	cout << "*********** 8.��������ĵ� *****************\n";
}
//�˳�ϵͳ
void workermanage::exitsystem() {
	cout << "��ӭ�´μ���ʹ�ã�\n";
	system("pause");
	exit(0);
}
//���ְ��
void workermanage::add() {
	cout << "���������ְ��������\n";
	int x=0;
	cin >> x;

	if (x > 0) {
		//���
		//�����µĿռ��С=ԭ������+��������
		int newsize = this->num + x;
		worker** newspace = new worker * [newsize];
		//ת�Ƶ��µ�����
		if (this->s!=NULL) {
			for (int i = 0; i < this->num; i++) {
				newspace[i] = this->s[i];
			}
		}
		//����µ�����
		for (int i = 0; i < x; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dep;//���ű��

			cout << "�������" << i + 1 << "��Ա���ı��:\n";
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������:\n";
			cin >> name;
			cout << "�������" << i + 1 << "��Ա���Ĳ��ű��:\n";
			cout << "1.��ְͨ��\n2.����\n3.�ϰ�\n";
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
			//���µ�ָ�뱣�浽������
			newspace[this->num + i] = w;
		}
		//�ͷžɵ�����
		delete[] this->s;
		//�����¿ռ��ָ��
		this->s = newspace;
		//�����µ�ְ������
		this->num = newsize;

		cout << "�ɹ����" << x << "��ְ��!\n";
		//�������ݵ��ļ���
		this->save();
		isempty = false;
	}
	else {
		cout << "�����������\n";
	}

}

void workermanage::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//����ļ��򿪣�д������

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->num; i++) {
		ofs << this->s[i]->id << " "
			<< this->s[i]->name << " "
			<< this->s[i]->did << endl;
	}
	
	//�ر��ļ�
	ofs.close();
}

int workermanage::getnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int did;
	int x=0;
	while (ifs>>id && ifs>>name && ifs>>did) {
		x++;//��¼����
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
	//�ر��ļ�
	ifs.close();
}

void workermanage::show() {
	if (this->isempty == true) {
		cout << "���ļ�Ϊ�ջ򲻴��ڣ�\n";
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
		cout << "�ļ������ڻ��¼Ϊ�գ�\n";
		return;
	}
	else {
		cout << "����������ɾ����ְ�����\n";
		cin >> x;
	}

	int index = this->isexist(x);
	if (index == -1) {
		cout << "ɾ��ʧ�ܣ�û���ҵ���ְ��\n";
		return;
	}
	else {
		for (int i = index; i < this->num - 1; i++) {
			//����ǰ��
			this->s[i] = this->s[i + 1];
		}
		//��������һ
		this->num--;
		//����txt�ļ�
		this->save();
		cout << "ɾ���ɹ�!\n";
	}
}

void workermanage::change() {
	int x;
	if (this->isempty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�\n";
		return;
	}
	else {
		cout << "�����������޸ĵ�ְ�����\n";
		cin >> x;
	}

	int index = this->isexist(x);


	if (index == -1) {
		cout << "�޸�ʧ�ܣ�û���ҵ���ְ��\n";
		return;
	}
	else {
		delete this->s[index];

		int newid = 0;
		string newname = "";
		int newdid = 0;

		cout << "���ҵ�idΪ" << x << "��ְ��\n";

		cout << "�������µ�id��\n";
		cin >> newid;

		cout << "�������µ�����\n";
		cin >> newname;

		cout << "�������µĲ��ű��\n1.�չ�\n2.����\n3.�ϰ�\n";
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
			cout << "�����������\n";
			break;
		}
		this->s[index] = w;
		cout << "�޸ĳɹ���\n";
		this->save();
	}
}

void workermanage::find() {
	if (this->isempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��!\n";
	}
	else {
		cout << "��������ҷ�ʽ��\n1. ����ְ��id\n2. ����ְ������\n";
		int select;
		cin >> select;

		if (select == 1) 
		{
			int id;
			cout << "������ְ��id\n";
			cin >> id;
			
			int ret = isexist(id);
			if (ret == -1) {
				cout << "û���ҵ���ְ��!\n";
			}
			else {
				cout << "���ҳɹ�����ְ������Ϣ���£�\n";
				this->s[ret]->showinfo();
			}

		}

		else if (select == 2) {
			string n;
			cout << "������ְ������\n";
			cin >> n;
			bool flag = false;
			for (int i = 0; i < this->num; i++) {
				if (this->s[i]->name == n) {
					cout  << this->s[i]->id << "��ְ��������������ְ������Ϣ����\n";
					this->s[i]->showinfo();
					flag = true;
				}
			}
			if (flag==false) {
				cout << "û���ҵ���Ӧ��ְ����\n";
			}
		}

		else {
			cout << "�����ѡ������!\n";
		}
	}
}

void workermanage::sort() {
	if (this->isempty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��!\n";
	}
	else {
		cout << "����������ʽ:\n1. ����id������\n2. ����id�Ž���\n";
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
			cout << "�������\n";
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
			cout << "�������\n";
			this->save();
		}

		else {
			cout << "�����������\n";
		}
	}
}

void workermanage::clean() {
	cout << "ȷ��ɾ�������ļ���\n1. ȷ��\n2. ����\n";
	int select;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//ɾ��������ÿ��ְ������
		if (this->s != NULL) {
			for (int i = 0; i < this->num; i++) {
				delete this->s[i];
				this->s[i] = NULL;
			}
		}
		//ɾ������������ָ��
		delete[] this->s;
		this->s = NULL;
		this->num = 0;
		this->isempty = true;

		//ɾ���ɹ�
		cout << "ɾ���ɹ�\n";
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