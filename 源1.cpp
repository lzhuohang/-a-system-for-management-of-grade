#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#pragma warning(disable: 4996)
using namespace std;
int q = -1; int b1 = 0; int shu = 0; int g = 1; int year, xf, pf;
char season[20];
char kcname[30];
char number[20];
double cj100;
class Xueqi
{
public:
	Xueqi() {};
	Xueqi(int yy, const char* sea)
	{
		year = yy;
		strcpy(season, sea);
	}
	~Xueqi() {};
	void getyear() {
		cout << year;
	}
	void getseason()
	{
		cout << season;
	}
	void setyear(int yy) {
		year = yy;
	}
	void setseason(const char* sea)
	{
		strcpy(season, sea);
	}
	int year;
	char season[10];
};
class Chengji
{
protected:
	char jidianpf[4] = "N/A";
	double jidian;
	char cj[3];
	double cj100;
	int xf;
	int pf;
public:
	char kcname[30];
	int genxf;
	double xfj;
	Chengji() {};
	Chengji(const char* kc, int x, int p, double n1)
	{
		strcpy(kcname, kc);
		xf = x;
		pf = p;
		cj100 = n1;
	}
	void getkcname() {
		cout << kcname;
	}
	int getkcnamelen()
	{
		return strlen(kcname);
	}
	void getjidianpf()
	{
		cout << jidianpf;
	}
	void getjidian()
	{
		cout << jidian;
	}
	double getjidian1() {
		return jidian;
	}
	void getcj()
	{
		cout << cj;
	}
	int getcjlen()
	{
		return strlen(cj);
	}
	void getcj100()
	{
		cout << cj100;
	}
	int getcj1001()
	{
		return cj100;
	}
	int getxf1()
	{
		return xf;
	}
	void getxf()
	{
		cout << xf;
	}
	int  getpf1()
	{
		return pf;
	}
	void  getpf()
	{
		cout << pf;
	}
	void setkcname(const char* kc) {
		strcpy(kcname, kc);
	}
	void setxf(int x)
	{
		xf = x;
	}
	void setpf(int p)
	{
		pf = p;
	}
	void setcj100(double n1)
	{
		cj100 = n1;
	}
	void calculate() {
		if (pf == 1)
		{
			if (cj100 >= 60)
			{
				strcpy(cj, "P");
			}
			else
			{
				strcpy(cj, "F");
			}
		}
		else
		{
			if (cj100 < 60)
			{
				strcpy(cj, "F");
				jidian = 0.0;
			}
			else if (cj100 >= 60 && cj100 < 65)
			{
				strcpy(cj, "D");
				jidian = 1.6;
			}
			else if (cj100 >= 65 && cj100 < 70)
			{
				strcpy(cj, "C-");
				jidian = 2.0;
			}
			else if (cj100 >= 70 && cj100 < 73)
			{
				strcpy(cj, "C");
				jidian = 2.4;
			}
			else if (cj100 >= 73 && cj100 < 77)
			{
				strcpy(cj, "C");
				jidian = 2.7;
			}
			else if (cj100 >= 77 && cj100 < 80)
			{
				strcpy(cj, "B-");
				jidian = 3.0;
			}
			else if (cj100 >= 80 && cj100 < 85)
			{
				strcpy(cj, "B");
				jidian = 3.3;
			}
			else if (cj100 >= 85 && cj100 < 90)
			{
				strcpy(cj, "B+");
				jidian = 3.6;
			}
			else if (cj100 >= 90 && cj100 < 95)
			{
				strcpy(cj, "A-");
				jidian = 4.0;
			}
			else if (cj100 >= 95 && cj100 < 100)
			{
				strcpy(cj, "A");
				jidian = 4.0;
			}
			else
			{
				strcpy(cj, "A+");
				jidian = 4.0;
			}
		}
	}
	~Chengji() {};
};
class student : public Chengji
{
public:
	char name[11];
	char number[20];
	char sex[5];
	int grade;
	int classno;
	char depart[20];
	double GPA;
	double GPA1;
	int rank;
	int shu;
	int genxf;
	double xfj;
	Chengji chj[200];
	student() {}
	student(const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :Chengji()
	{
		strcpy(name, n);
		strcpy(number, num);
		strcpy(sex, sexx);
		grade = g;
		classno = c;
		strcpy(depart, d);
	};
	~student() {};
	int shuru() {};
	void search2() {};
	int paiming(student stu[], int n, double x) {};
};
class database :public student, public Xueqi
{
public:
	student stu;
	Xueqi xq;
	database() {};
	database(int yy, const char* sea, const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :student(), Xueqi()
	{};
	~database() {};
	int shuru(student stu[], Xueqi xq[], database data[]) {};
	double getGPA(const char* number, database data[]) {};
	void search(database data[]) {};
	void search2(student stu[], database data[]) {};
	void revise(database data[]) {};
};
struct adminis
{
	char name[20];
	int gonghao;
	char userid[30];
	char password[50];
};
istream& operator>>(istream& input, adminis& ad)
{
	input >> ad.name >> ad.gonghao >> ad.userid >> ad.password;
	return input;
};
void input(adminis ad[])
{
	ifstream in;
	in.open("administrator.txt", ios::in);
	for (int i = 0; i < 4; i++)
	{
		in >> ad[i];
	}
	in.close();
};
void caidan()
{
	string a;
	int fg;
	char useri[30];
	char passwo[50];
	getline(cin, a);
	int b = 8 + a.size();
	cout << "********欢迎进入学生成绩管理系统！*********" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "学生成绩管理系统" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);
	cout << "请选择版本" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.管理员版" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.大学生版" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.退出系统" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "请选择序号（1-3）" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
}
void caidan2(adminis ad)
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "学生成绩管理系统（管理员版）" << endl;
	cout << a << "欢迎回来，" << ad.name << "  No." << ad.gonghao << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);
	cout << "主菜单" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.成绩录入" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.成绩查询" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.排名查询" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "4.成绩修改" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "5.退出系统" << endl;
	cout.width(26);
	cout.setf(ios::right);
	cout << "请选择序号（1-5）" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
}
void caidan3()
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "学生成绩管理系统（学生版）" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);
	cout << "主菜单" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.成绩查询" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.排名查询" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.退出系统" << endl;
	cout.width(26);
	cout.setf(ios::right);
	cout << "请选择序号（1-3）" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
}
int shuru(student stu[], Xueqi xq[], database data[])
{
	char a;
	int c, d;
	cout << "------输入开始！----" << endl;
	cout << "请输入考试年份：";
	cin >> year;
	cout << "请输入考试学期（春季输入1，夏季输入2，秋季输入3）：";
	cin >> c;
	if (c == 1) { strcpy(season, "春季"); }
	else if (c == 2) { strcpy(season, "夏季"); }
	else if (c == 3) { strcpy(season, "秋季"); }
	else {
		do {
			cout << "输入不合规范，请重新输入：";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);
	}
	if ((year % 4 == 0))
	{
		if (strcmp(season, "秋季") == 0) b1 = 0;
		else if (strcmp(season, "春季") == 0) b1 = 1;
		else if (strcmp(season, "夏季") == 0) b1 = 2;
	}
	else if ((year % 4 == 1))
	{
		if (strcmp(season, "秋季") == 0) b1 = 3;
		else if (strcmp(season, "春季") == 0) b1 = 4;
		else if (strcmp(season, "夏季") == 0) b1 = 5;
	}
	else if ((year % 4 == 2))
	{
		if (strcmp(season, "秋季") == 0) b1 = 6;
		else if (strcmp(season, "春季") == 0) b1 = 7;
		else if (strcmp(season, "夏季") == 0) b1 = 8;
	}
	else if ((year % 4 == 3))
	{
		if (strcmp(season, "秋季") == 0) b1 = 9;
		else if (strcmp(season, "春季") == 0) b1 = 10;
		else if (strcmp(season, "夏季") == 0) b1 = 11;
	}
	xq[b1].setyear(year);
	xq[b1].setseason(season);
	do {
		q++;
		cout << "请输入学生姓名:";
		cin >> stu[q].name;
		cout << "请输入学号:";
		cin >> stu[q].number;
		cout << "请输入性别（男性输入1，女性输入0）:";
		cin >> d;
		if (d == 0)
		{
			strcpy(stu[q].sex, "女");
		}
		else if (d == 1) strcpy(stu[q].sex, "男");
		else {
			do {
				cout << "输入不合规范，请重新输入：";
				cin >> d;
			} while (d != 0 && d != 1);
		}
		cout << "请输入年级:";
		cin >> stu[q].grade;
		cout << "请输入班级:";
		cin >> stu[q].classno;
		cout << "请输入院系:";
		cin >> stu[q].depart;
		cout << " 请输入要输入的课程成绩数量:" << endl;
		cin >> shu;
		stu[q].shu = shu;
		for (int i = 0; i < shu; i++)
		{
			cout << " 请输入课程名:" << endl;
			cin >> kcname;
			stu[q].chj[i].setkcname(kcname);
			cout << "请输入课程学分: " << endl;
			cin >> xf;
			stu[q].chj[i].setxf(xf);
			cout << "请输入该课程属性（是否记P/F）？（是输入1，否输入0）： " << endl;
			cin >> pf;
			stu[q].chj[i].setpf(pf);
			cout << "请输入该课程百分制成绩 " << endl;
			cin >> cj100;
			stu[q].chj[i].setcj100(cj100);
			stu[q].chj[i].calculate();
			cout << "该课程的成绩为"; stu[q].chj[i].getcj(); cout << endl;
			if (stu[q].chj[i].getpf1() == 1) { cout << " 该课程的绩点为："; stu[q].chj[i].getjidianpf(); cout << endl; }
			else { cout << "该课程的绩点为：";  cout.setf(ios::fixed); cout << setprecision(1); stu[q].chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
			cout << "该课程的百分制成绩为："; stu[q].chj[i].getcj100();  cout << endl;
		}
		int j = 0, m = 0, i = 0;
		stu[q].genxf = 0;
		stu[q].xfj = 0;
		do
		{
			if (stu[q].chj[i].getpf1() == 0)
			{
				stu[q].genxf += stu[q].chj[i].getxf1();
				stu[q].xfj += (stu[q].chj[i].getxf1()) * (stu[q].chj[i].getjidian1());
			}
			i++;
		} while (i < shu);
		m = j - 1;
		if (stu[q].genxf == 0) { stu[q].GPA = 0; }
		else { stu[q].GPA = stu[q].xfj / stu[q].genxf; }
		cout << "该学生在";
		xq[b1].getyear();
		cout << "学年";
		xq[b1].getseason();
		if (stu[q].genxf != 0) { cout.setf(ios::fixed); cout << "学期的GPA为：" << setprecision(3) << stu[q].GPA; cout.unsetf(ios::fixed); }
		else { cout << "学期的GPA为：" << "N/A"; }
		cout << endl;
		cout << "是否还要继续输入:(y/n)" << endl;
		cin >> a;
		data[b1 * 20 + q].xq = xq[b1];
		data[b1 * 20 + q].stu = stu[q];
	} while (a == 'y');
	return q + 1;
}
double getGPA(const char* number, database data[])
{
	int i1 = 0; int j1 = 0;
	int m1 = j1 - 1;
	int gef = 0;
	double xj = 0;
	double p = 0;
	char r[10];
	for (i1 = 0; i1 < 240; i1++)
	{
		if ((strcmp(number, data[i1].stu.number) == 0))
		{
			gef += data[i1].stu.genxf;
			xj += data[i1].stu.xfj;
		}
	}
	p = xj / gef;
	return p;
}
void search(database data[]) {
	char n = 'y';
	int z;
	while (n == 'y')
	{
		int j = -1, c;
		char n1[20];
		cout << "输入你要查询的学期（依次输入学年和学期（春季输入1，夏季输入2，秋季输入3））:" << endl;
		cin >> z;
		cin >> c;
		if (c == 1) { strcpy(season, "春季"); }
		else if (c == 2) { strcpy(season, "夏季"); }
		else if (c == 3) { strcpy(season, "秋季"); }
		cout << "输入你要查询的学生学号:" << endl;
		cin >> n1;
		for (int i = 0; i < 240; i++)
		{
			if ((strcmp(n1, data[i].stu.number) == 0) && (strcmp(season, data[i].xq.season) == 0) && (data[i].xq.year == z))
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";//没有找到
			cout << "是否退出?退出请按 n\n";
			cin >> n;
		}
		else {
			cout << "姓名：" << data[j].stu.name << " ";
			cout << "学号：" << data[j].stu.number << " ";
			cout << "性别：" << data[j].stu.sex << " ";
			if (data[j].stu.genxf != 0) { cout << "学期的GPA为：" << data[j].stu.GPA << " "; }
			else { cout << "学期的GPA为：" << "N/A "; }
			cout << "年级：" << data[j].stu.grade << " ";
			cout << "班号：" << data[j].stu.classno << " ";
			cout << "院系：" << data[j].stu.depart << " " << endl;
			cout << "|          课程名           |" << " 学分 |" << " 成绩 |" << " 百分制成绩 |" << "   绩点 |" << endl;
			for (int a = 0; a < data[j].stu.shu; a++)
			{
				int len = data[j].stu.chj[a].getkcnamelen();
				int len1 = floor((30 - len) / 2);
				cout << "|";
				cout << setfill(' ') << setw(len1 + len);
				data[j].stu.chj[a].getkcname();
				cout << setfill(' ') << setw(30 - len1 - len);
				cout << "|  ";
				if (data[j].stu.chj[a].getxf1() < 10) { data[j].stu.chj[a].getxf(); cout << "   |  "; }
				else if (data[j].stu.chj[a].getxf1() >= 10) { data[j].stu.chj[a].getxf(); cout << "  |  "; }
				int len2 = data[j].stu.chj[a].getcjlen();
				int len3 = (7 - len2) / 2;
				cout << setfill(' ') << setw(len3 - 1);
				data[j].stu.chj[a].getcj();
				cout << setfill(' ') << setw(7 - len2 - len3) << "  |  ";
				cout.setf(ios::fixed);
				cout << setiosflags(ios_base::right) << setprecision(0);
				if (data[j].stu.chj[a].getcj1001() < 10) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "00"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else if (data[j].stu.chj[a].getcj1001() >= 10 && data[j].stu.chj[a].getcj1001() < 100) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "0"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else {
					cout << setiosflags(ios_base::right) << setprecision(0);
					data[j].stu.chj[a].getcj100(); cout << "  ";
				}
				cout << "     | ";
				if (data[j].stu.chj[a].getpf1() == 0)
				{
					cout.setf(ios::fixed);
					cout << setprecision(1) << data[j].stu.chj[a].getjidian1();
					cout << setiosflags(ios_base::right) << setprecision(0);
				}
				else
				{
					cout << "N/A";
				}
				cout << "    |    " << endl;
			}
			cout << "是否继续查询(y/n)继续请按 y 退出按 n" << endl;
			cin >> n;
		}
	}
}
void search2(student stu[], database data[])
{
	int paiming(student stu[], int n, double x);
	int j = -1;
	char n = 'y';
	int g1 = g;
	int p = 0;
	int q = 0;
	char num[20];
	while (n == 'y')
	{
		cout << "输入你要查询的学生学号:" << endl;
		cin >> num;
		for (int i = 0; i < g1; i++)
		{
			if ((strcmp(num, stu[i].number) == 0))
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";//没有找到
			cout << "是否退出?退出请按 n\n";
			cin >> n;
		}
		else {
			for (int i = 0; i < g1; i++)
			{
				double GPA2 = getGPA(stu[i].number, data);
				stu[i].GPA1 = GPA2;
			}double x = stu[j].GPA1;
			int k1 = 0; int k2 = 0; int k3 = 0;
			int h = 0; int s = 0; int f = 0; int d = 0; int s1 = 0; int s2 = 0;
			char dep[20];
			cout << "姓名：" << stu[j].name << " ";
			cout << "学号：" << stu[j].number << " ";
			cout << "性别：" << stu[j].sex << " ";
			cout << "年级：" << stu[j].grade << " ";
			cout << "班号：" << stu[j].classno << " ";
			cout << "院系：" << stu[j].depart << " " << endl;
			student* stu3 = new student[20];
			student* same = new student[200];
			student* sum = new student[200];
			strcpy(dep, stu[j].depart);
			p = stu[j].grade;
			q = stu[j].classno;
			do
			{
				if (stu[s].grade == p)
				{
					stu3[d] = stu[s];
					d++;
				}
				s++;
			} while (s < g1);
			do
			{
				if (strcmp(dep, stu3[s1].depart) == 0)
				{
					same[h] = stu3[s1];
					h++;
				}
				s1++;
			} while (s1 < d);
			do
			{
				if (same[s2].classno == q)
				{
					sum[f] = same[s2];
					f++;
				}
				s2++;
			} while (s2 < h);
			cout << "级排名为：" << paiming(stu3, d, x) << endl;
			cout << "系排名为：" << paiming(same, h, x) << endl;
			cout << "班排名为：" << paiming(sum, f, x) << endl;
			cout.setf(ios::fixed);
			cout << "总体GPA为：" << setprecision(3) << x << endl;
			cout.unsetf(ios::fixed);
			delete[]stu3;
			delete[]same;
			delete[]sum;
		}
		cout << "是否继续查询(y/n)继续请按 y 退出按 n" << endl;
		cin >> n;
	}

}
int paiming(student stu[], int n, double x)
{
	int k1 = -2;
	double a[20];
	for (int i = 0; i < n; i++)
	{
		a[i] = stu[i].GPA1;
	}
	if (n == 1)
	{
		k1 = 1;
	}
	else if (n == 2)
	{
		if (a[0] < a[1])
		{
			double t = a[0]; a[0] = a[1]; a[1] = t;
		}
		for (int i = 0; i < 2; i++)
		{
			if (a[i] == x)k1 = i + 1;
		}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j1 = 0; j1 < n - 1 - i; j1++)
			{
				if (a[j1] < a[j1 + 1])
				{
					double t = a[j1]; a[j1] = a[j1 + 1]; a[j1 + 1] = t;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)k1 = i + 1;
		}
	}
	return k1;
}
void revise(database* data[], Xueqi xq[], student* stu[])
{
	int k = 1, j = -1, c, a[10], b1;
	int flgh;
	int h;
	char n = 'y';
	int d;
	cout << "------输入开始！----" << endl;
	cout << "请输入考试年份：";
	cin >> year;
	cout << "请输入考试学期（春季输入1，夏季输入2，秋季输入3）：";
	cin >> c;
	if (c == 1) { strcpy(season, "春季"); }
	else if (c == 2) { strcpy(season, "夏季"); }
	else if (c == 3) { strcpy(season, "秋季"); }
	else {
		do {
			cout << "输入不合规范，请重新输入：";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);
	}
	while (k == 1)
	{
		cout << "请输入你要修改成绩的学生学号" << endl;
		cin >> number;
		flgh = 0;
		for (int i = 0; i < 240; i++)
		{
			if ((strcmp(number, (*data)[i].stu.number) == 0) && (strcmp(season, (*data)[i].xq.season) == 0) && (*data)[i].xq.year == year)
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";//没有找到
			cout << "是否退出?退出请按 n\n";
			cin >> n;
		}
		else {
			char kcn[30];
			cout << "请输入要修改的课程名：" << endl;
			cin >> kcn;
			int b = (*data)[j].stu.shu;
			for (int i = 0; i < b; i++)
			{
				if (strcmp((*data)[j].stu.chj[i].kcname, kcn) == 0)
				{
					(*data)[j].stu.genxf = (*data)[j].stu.genxf - (*data)[j].stu.chj[i].getxf1();
					(*data)[j].stu.xfj = (*data)[j].stu.xfj - ((*data)[j].stu.chj[i].getxf1()) * ((*data)[j].stu.chj[i].getjidian1());
					cout << "请重新输入课程学分: " << endl;
					cin >> xf;
					(*data)[j].stu.chj[i].setxf(xf);
					(*data)[j].stu.genxf = (*data)[j].stu.genxf + (*data)[j].stu.chj[i].getxf1();
					cout << "请重新输入该课程属性（是否记P/F）？（是输入1，否输入0）： " << endl;
					cin >> pf;
					(*data)[j].stu.chj[i].setpf(pf);
					cout << "请重新输入该课程百分制成绩 " << endl;
					cin >> cj100;
					(*data)[j].stu.chj[i].setcj100(cj100);
					(*data)[j].stu.chj[i].calculate();
					cout << "该课程的成绩为";  (*data)[j].stu.chj[i].getcj(); cout << endl;
					cout << "该课程的百分制成绩为：";  (*data)[j].stu.chj[i].getcj100(); cout << endl;
					if ((*data)[j].stu.chj[i].getpf1() == 1) { cout << " 该课程的绩点为：";  (*data)[j].stu.chj[i].getjidianpf(); cout << endl; }
					else { cout << "该课程的绩点为：";  cout.setf(ios::fixed); cout << setprecision(1);  (*data)[j].stu.chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
					cout << "该课程的百分制成绩为：";  (*data)[j].stu.chj[i].getcj100();  cout << endl;
					(*data)[j].stu.xfj = (*data)[j].stu.xfj + ((*data)[j].stu.chj[i].getxf1()) * ((*data)[j].stu.chj[i].getjidian1());
					if ((*data)[j].stu.genxf == 0) { (*data)[j].stu.GPA = 0; }
					else { (*data)[j].stu.GPA = (*data)[j].stu.xfj / (*data)[j].stu.genxf; }
				}
			}
		}
		cout << "还要继续吗?退出请按 0,继续请按1：" << endl;
		cin >> k;
	}

}
int main()
{
	student* stu = new student[20];
	Xueqi* xq = new Xueqi[12];
	database* data = new database[240];
	adminis ad[5] =
	{
		"wxq",1,"wxqtsinghua.edu.cn","234755687sddvcEFCTd!dfgf",
		"zxd",2,"zxdtsinghua.edu.cn","8237rtghdsfgRTDFYR%TREF^t",
		"shc",3,"shctsinghua.edu.cn","iwue3hrbu887ydsfUV&^&RR$#4",
		"sls",4,"slstsinghua.edu.cn","vytr567rfut5r5E%$EDYCRTY",
		"zzy",5,"zzytsinghua.edu.cn","Gugy7u65tf7vytjFDRFY%^jb67"
	};
	void input(adminis ad);
	int ch;
	while (1)
	{
	B:
		string a;
		int fg;
		char useri[30];
		char passwo[50];
		caidan();
		ifstream in;
		ofstream ofile;
		ifstream ifile;
		if (!ofile || !ifile || !in)
		{
			cerr << "文件打开错误" << endl;
			abort();
		}
		cin >> fg;
		if (fg == 1) {
			char n = 'y';
			int j = -1;
			in.open("administrator.txt", ios::in);
			for (int i = 0; i < 5; i++)
			{
				in.read((char*)&ad[i], sizeof(ad[i]));
			}
			do {
				cout << "请输入用户名" << endl;
				cin >> useri;
				cout << "请输入密码" << endl;
				cin >> passwo;
				for (int i = 0; i < 5; i++)
				{
					if ((strcmp(useri, ad[i].userid) == 0) && (strcmp(passwo, ad[i].password) == 0))
					{
						j = i;
					}
				}
			A:
				caidan2(ad[0]);
				cin >> ch;
				switch (ch)
				{
				case 1:ofile.open("grade management system.txt", ios::binary);
					g = shuru(stu, xq, data);
					for (int i = 0; i < g; i++)
					{
						ofile.write((char*)&stu[i], sizeof(stu[i]));
					}
					for (int i = 0; i < 240; i++)
					{
						ofile.write((char*)&data[i], sizeof(data[i]));
					}
					ofile.close();
					goto A;
				case 2:ifile.open("grade management system.txt", ios::binary);
					for (int i = 0; i < 240; i++)
					{
						ifile.read((char*)&data[i], sizeof(data[i]));
					}
					search(data);
					ifile.close();
					goto A;
				case 3: ifile.open("grade management system.txt", ios::binary);
					for (int i = 0; i < g; i++)
					{
						ifile.read((char*)&stu[i], sizeof(stu[i]));
					}
					for (int i = 0; i < 240; i++)
					{
						ifile.read((char*)&data[i], sizeof(data[i]));
					}
					search2(stu, data);
					ifile.close();
					goto A;
				case 4: ofile.open("grade management system.txt", ios::binary);
					ifile.open("grade management system.txt", ios::binary);
					for (int i = 0; i < g; i++)
					{
						ifile.read((char*)&stu[i], sizeof(stu[i]));
					}
					for (int i = 0; i < 240; i++)
					{
						ifile.read((char*)&data[i], sizeof(data[i]));
					}
					revise(&data, xq, &stu);
					for (int i = 0; i < 240; i++)
					{
						ofile.write((char*)&data[i], sizeof(data[i]));
					}
					for (int i = 0; i < g; i++)
					{
						ofile.write((char*)&stu[i], sizeof(stu[i]));
					}
					ifile.close();
					ofile.close();
					goto A;
				case 5: cout << "系统已关闭" << endl;
					goto B;
				}
			} while (n == 'y');
		}
		else if (fg == 2)
		{
		C:
			caidan3();
			cin >> ch;
			switch (ch)
			{
			case 1:ifile.open("grade management system.txt", ios::binary);
				for (int i = 0; i < 240; i++)
				{
					ifile.read((char*)&data[i], sizeof(data[i]));
				}
				search(data);
				ifile.close();
				goto C;
			case 2: ifile.open("grade management system.txt", ios::binary);
				for (int i = 0; i < g; i++)
				{
					ifile.read((char*)&stu[i], sizeof(stu[i]));
				}
				for (int i = 0; i < 240; i++)
				{
					ifile.read((char*)&data[i], sizeof(data[i]));
				}
				search2(stu, data);
				ifile.close();
				goto C;
			case 3: cout << "系统已关闭" << endl;
				goto B;
			}
		}
		else exit(0);
	}
	delete[]data;
	delete[]stu;
	delete[]xq;
	return 0;
}