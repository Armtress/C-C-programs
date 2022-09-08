

#include <iostream>
#include"operate.h"
using namespace std;

bool ad::add(MYSQL mysql) {
	cout << "请输入你要操纵的表名\n";
	string tablename;
	cin >> tablename;

	string query;

	//判断表格以区分插入元组
	if(tablename.compare("course") == 0) {
		cout << "请输入你要插入的数据元组\n";
		string a, b;
		cin >> a >> b;
		query = "insert into " + tablename + " values('" + a + "', '" + b + "');";
	}

	else if (tablename.compare("student") == 0|| tablename.compare("teacher") == 0) {
		cout << "请输入你要插入的数据元组\n";
		string a, b, c;
		cin >> a >> b >> c;
		query = "insert into " + tablename + " values('" + a + "', '" + b + "', '" + c +  "');";
	}

	else {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}

	if (mysql_query(&mysql, query.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	cout << "增加成功!\n\n";
	return true;

}

bool ad::del(MYSQL mysql)
{
	string tablename;
	cout << "请输入你要操作的表格名\n";
	cin >> tablename;
	string name;
	cout << "请输入你要删除的人(课)名\n";
	cin >> name;
	if (name.length() == 0) {
		cout << "人(课)名不能为空!" << endl;
		return FALSE;
	}
	string a;
	if (tablename.compare("course") == 0) {
		a = "cname";
	}
	else if (tablename.compare("student") == 0) {
		a = "sname";
	}
	else if (tablename.compare("teacher") == 0) {
		a = "tname";
	}
	std::string query = "delete from " + tablename + " where "+a+"= '" + name + "'; ";
	if (mysql_query(&mysql, query.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	cout << "删除成功!\n\n";
	return TRUE;
}

bool ad::alt(MYSQL mysql)
{
	//这里不一定要是名字，可以是你想要修改的其他数据
	string tablename;
	cout << "请输入你要修改的表名\n";
	cin >> tablename;
	if (tablename.length() == 0) {
		cout << "表名不能为空!" << endl;
		return FALSE;
	}

	string linename;
	cout << "请输入你要修改的列名\n";
	cin >> linename;
	if (linename.length() == 0) {
		cout << "列名不能为空!" << endl;
		return FALSE;
	}

	string ele;
	cout << "请输入你修改后的列值\n";
	cin >> ele;
	if (ele.length() == 0) {
		cout << "列值不能为空!" << endl;
		return FALSE;
	}

	string csuline;
	cout << "请输入你要查询的列名\n";
	cin >> csuline;
	if (csuline.length() == 0) {
		cout << "列名不能为空!" << endl;
		return FALSE;
	}

	string csulineele;
	cout << "请输入你要查询的列值\n";
	cin >> csulineele;
	if (csulineele.length() == 0) {
		cout << "列值不能为空!" << endl;
		return FALSE;
	}

	string query = "update " + tablename + " set " + linename + " = '" + ele + "' where " + csuline + "='" + csulineele + "'; ";
	

	if (mysql_query(&mysql, query.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	cout << query << "\n" << "修改成功！\n";
	return TRUE;
}

bool ad::csu(MYSQL mysql) {
	MYSQL_RES* res = NULL;      //指向数据的指针
	MYSQL_ROW       row;        //结果集
	char            query_str[1024];        //记录操作的sql语句
	int rc;                 //rc检测报错变量
	int i;                  //i循环变量
	int fields;             //总列数
	int rows;               //总行数

	string tablename;
	cout << "请输入你要查询的表名\n";
	cin >> tablename;
	if (tablename.length() == 0) {
		cout << "表名不能为空!" << endl;
		return FALSE;
	}

	string linename;
	cout << "请输入你要查询的列名\n";
	cin >> linename;
	if (linename.length() == 0) {
		cout << "列名不能为空!" << endl;
		return FALSE;
	}

	string ele;
	cout << "请输入你要查询值\n";
	cin >> ele;
	if (ele.length() == 0) {
		cout << "查询值不能为空!" << endl;
		return FALSE;
	}
	string query= "select * from " + tablename + " where " + linename + " = '" + ele + "';";

	if (tablename.compare("course") == 0) {
		//查询数据库中的数据
		sprintf_s(query_str, query.c_str());
		rc = mysql_real_query(&mysql, query_str, strlen(query_str));
		if (0 != rc) {
			cout << "mysql_real_query():" << mysql_error(&mysql) << endl;
			return false;
		}
		res = mysql_store_result(&mysql);
		if (NULL == res) {
			cout << "mysql_restore_result():" << mysql_error(&mysql) << endl;
			return false;
		}

		rows = mysql_num_rows(res);
		fields = mysql_num_fields(res);

		cout << "\n";
		cout << "\n以下为查询结果：\n\n";
		cout << "课程号" << "\t" << "课程名\n" ;
		while ((row = mysql_fetch_row(res))) {
			for (i = 0; i < fields; i++) {
				cout << row[i] << "\t";
			}

		}


		return true;
	}
	else if (tablename.compare("student") == 0) {

		//查询数据库中的数据
		sprintf_s(query_str, query.c_str());
		rc = mysql_real_query(&mysql, query_str, strlen(query_str));
		if (0 != rc) {
			cout << "mysql_real_query():" << mysql_error(&mysql) << endl;
			return false;
		}
		res = mysql_store_result(&mysql);
		if (NULL == res) {
			cout << "mysql_restore_result():" << mysql_error(&mysql) << endl;
			return false;
		}

		rows = mysql_num_rows(res);
		fields = mysql_num_fields(res);

		cout << "\n";
		cout << "\n以下为查询结果：\n\n";
		cout << "学号" << "\t" << "姓名" << "\t" << "班级\n";
		while ((row = mysql_fetch_row(res))) {
			for (i = 0; i < fields; i++) {
				cout << row[i] << "\t";
			}

		}


		return true;
	}
	else if (tablename.compare("teacher") == 0) {

		//查询数据库中的数据
		sprintf_s(query_str, query.c_str());
		rc = mysql_real_query(&mysql, query_str, strlen(query_str));
		if (0 != rc) {
			cout << "mysql_real_query():" << mysql_error(&mysql) << endl;
			return false;
		}
		res = mysql_store_result(&mysql);
		if (NULL == res) {
			cout << "mysql_restore_result():" << mysql_error(&mysql) << endl;
			return false;
		}

		rows = mysql_num_rows(res);
		fields = mysql_num_fields(res);

		cout << "\n";
		cout << "\n以下为查询结果：\n\n";
		cout << "工号" << "\t" << "姓名" << "\t" << "所教课程号\n";
		while ((row = mysql_fetch_row(res))) {
			for (i = 0; i < fields; i++) {
				cout << row[i] << "\t";
			}

		}


		return true;
	}
	return false;
}

bool teacher::add(MYSQL mysql) {
	cout << "请输入你的姓名\n";
	string name;
	cin >> name;

	cout << "请输入你所教的班级\n";
	string sclass;
	cin >> sclass;

	cout << "请输入你所教的课程号\n";
	string cid;
	cin >> cid;

	string query = "create table " + name + sclass + cid + "(select student.sname, student.sid from student where sclass = '" + sclass + "') ; ";
	if (mysql_query(&mysql, query.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}

	string query_1 = "alter table " + name + sclass + cid + " add chuqin int default 0;";
	string query_2 = "alter table " + name + sclass + cid + " add qingjia int default 0;";
	string query_3 = "alter table " + name + sclass + cid + " add kuangke int default 0;";
	string query_4 = "alter table " + name + sclass + cid + " add chidao int default 0;";
	string query_5 = "alter table " + name + sclass + cid + " add zaotui int default 0;";
	if (mysql_query(&mysql, query_1.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	if (mysql_query(&mysql, query_2.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	if (mysql_query(&mysql, query_3.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	if (mysql_query(&mysql, query_4.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	if (mysql_query(&mysql, query_5.c_str())) {
		cout << "mysql_real_query():" << mysql_error(&mysql);
		return FALSE;
	}
	return true;

}

bool teacher::alt(MYSQL mysql)
{
	cout << "请输入你的姓名\n";
	string name;
	cin >> name;

	cout << "请输入你所教的班级\n";
	string sclass;
	cin >> sclass;

	cout << "请输入你所教的课程号\n";
	string cid;
	cin >> cid;

	//先录入异常信息
	cout << "现在录入四种异常信息\n";
	int i,n;//循环变量，计数变量
	string sid;//记录学生的学号
	string query;//sql请求语句

	cout << "请输入有几个出勤学生sid\n";
	cin >> i;
	for (n = 1; n <= i; n++) {
		cout << "请输入第" << n << "个学生的sid\n";
		cin >> sid;
		query = "update " + name + sclass + cid + " set chuqin =chuqin +1 where sid='" + sid + "'; ";
		if (mysql_query(&mysql, query.c_str())) {
			cout << "mysql_real_query():" << mysql_error(&mysql);
			return FALSE;
		}
	}
	system("pause");
	system("cls");
	cout << "请输入有几个请假学生sid\n";
	cin >> i;
	for (n=1; n <= i;n++) {
		cout << "请输入第" << n << "个学生的sid\n";
		cin >> sid;
		query="update " +name+sclass+cid+" set qingjia =qingjia +1 where sid='"+sid+"'; ";
		if (mysql_query(&mysql, query.c_str())) {
			cout << "mysql_real_query():" << mysql_error(&mysql);
			return FALSE;
		}
	}
	system("pause");
	system("cls");
	cout << "请输入有几个旷课学生sid\n";
	cin >> i;
	for (n = 1; n <= i; n++) {
		cout << "请输入第" << n << "个学生的sid\n";
		cin >> sid;
		query = "update " + name + sclass + cid + " set kuangke =kuangke +1 where sid='" + sid + "'; ";
		if (mysql_query(&mysql, query.c_str())) {
			cout << "mysql_real_query():" << mysql_error(&mysql);
			return FALSE;
		}
	}
	system("pause");
	system("cls");
	cout << "请输入有几个迟到学生sid\n";
	cin >> i;
	for (n = 1; n <= i; n++) {
		cout << "请输入第" << n << "个学生的sid\n";
		cin >> sid;
		query = "update " + name + sclass + cid + " set chidao =chidao +1 where sid='" + sid + "'; ";
		if (mysql_query(&mysql, query.c_str())) {
			cout << "mysql_real_query():" << mysql_error(&mysql);
			return FALSE;
		}
	}
	system("pause");
	system("cls");
	cout << "请输入有几个早退学生sid\n";
	cin >> i;
	for (n = 1; n <= i; n++) {
		cout << "请输入第" << n << "个学生的sid\n";
		cin >> sid;
		query = "update " + name + sclass + cid + " set zaotui =zaotui +1 where sid='" + sid + "'; ";
		if (mysql_query(&mysql, query.c_str())) {
			cout << "mysql_real_query():" << mysql_error(&mysql);
			return FALSE;
		}
	}
	system("pause");
	system("cls");
	cout << "本次录入成功！\n";


	return true;
}

bool teacher::csu(MYSQL mysql) {
	cout << "你希望按照何种查询方式？\n1. 按班级\n2. 按学生\n";
	int x;
	cin >> x;
	string query;
	string name;
	string sclass;
	string cid;
	if (x == 1) {
		cout << "请输入你的姓名\n";
		cin >> name;

		cout << "请输入你所教的班级\n";
		cin >> sclass;

		cout << "请输入你所教的课程号\n";
		cin >> cid;
		
		query = "select * from " + name + sclass + cid + ";";
	}

	else if (x == 2) {
		cout << "请输入你的姓名\n";
		cin >> name;

		cout << "请输入你所教的班级\n";
		cin >> sclass;

		cout << "请输入你所教的课程号\n";
		cin >> cid;

		cout << "请输入你要查询的学生姓名\n";
		string sname;
		cin >> sname;

		query = "select * from " + name + sclass + cid + " where sname = '" + sname + "';";
	}


	MYSQL_RES* res = NULL;      //指向数据的指针
	MYSQL_ROW       row;        //结果集
	char            query_str[1024];        //记录操作的sql语句
	int rc;                 //rc检测报错变量
	int i;                  //i循环变量
	int fields;             //总列数
	int rows;               //总行数

	//查询数据库中的数据
	sprintf_s(query_str, query.c_str());
	rc = mysql_real_query(&mysql, query_str, strlen(query_str));
	if (0 != rc) {
		cout << "mysql_real_query():" << mysql_error(&mysql) << endl;
		return false;
	}
	res = mysql_store_result(&mysql);
	if (NULL == res) {
		cout << "mysql_restore_result():" << mysql_error(&mysql) << endl;
		return false;
	}

	rows = mysql_num_rows(res);
	fields = mysql_num_fields(res);

	cout << "\n以下为查询结果：\n";
	cout << "姓名" << "\t" << "学号" << "\t" << "出勤" << "\t" << "请假" << "\t" << "旷课" << "\t" << "迟到" << "\t" << "早退\n";
	while ((row = mysql_fetch_row(res))) {
		
		for (i = 0; i < fields; i++) {
			cout << row[i] << "\t";
		}
		cout << "\n";
	}
	return true;
}

bool student::csu(MYSQL mysql) {
	cout << "请输入你的老师姓名\n";
	string tname;
	cin >> tname;

	cout << "请输入你的班级\n";
	string sclass;
	cin >> sclass;

	cout << "请输入你要查询的课程编号\n";
	string cid;
	cin >> cid;

	cout << "请输入你的姓名\n";
	string sname;
	cin >> sname;

	string query = "select * from " + tname + sclass + cid + " where sname = '" + sname + "';";

	MYSQL_RES* res = NULL;      //指向数据的指针
	MYSQL_ROW       row;        //结果集
	char            query_str[1024];        //记录操作的sql语句
	int rc;                 //rc检测报错变量
	int i;                  //i循环变量
	int fields;             //总列数
	int rows;               //总行数

	//查询数据库中的数据
	sprintf_s(query_str, query.c_str());
	rc = mysql_real_query(&mysql, query_str, strlen(query_str));
	if (0 != rc) {
		cout << "mysql_real_query():" << mysql_error(&mysql) << endl;
		return false;
	}
	res = mysql_store_result(&mysql);
	if (NULL == res) {
		cout << "mysql_restore_result():" << mysql_error(&mysql) << endl;
		return false;
	}

	rows = mysql_num_rows(res);
	fields = mysql_num_fields(res);

	cout << "\n以下为查询结果：\n";
	cout << "姓名" << "\t" << "学号" << "\t" << "出勤" << "\t" << "请假" << "\t" << "旷课" << "\t" << "迟到" << "\t" << "早退\n";
	while ((row = mysql_fetch_row(res))) {

		for (i = 0; i < fields; i++) {
			cout << row[i] << "\t";
		}
		cout << "\n";
	}
	return true;
}