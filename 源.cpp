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
class People//定义抽象类
{
public:
	char name[11];
	char number[20];
	char sex[5];//定义三个基本属性
	People() {};
	People(const char* n, const char* num, const char* sexx )
	{
		strcpy(name, n);
		strcpy(number, num);
		strcpy(sex, sexx);
	}//定义构造函数
	~People() {};//定义析构函数
	virtual void xueli()const { cout << "未知"; }//查看学历
	virtual void work()const = 0;//查看职业（无函数体）
};
class Xueqi//定义学期类
{
public:
	int year;
	char season[10];//定义学年和季节两个基本属性
	Xueqi() {};
	Xueqi(int yy, const char* sea)
	{
		year = yy;
		strcpy(season, sea);
	}//构造函数
	~Xueqi() {};//析构函数
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
	
};
class Chengji//定义成绩类
{
protected:
	char jidianpf[4] = "N/A";
	double jidian;
	char cj[3];
	double cj100;
	int xf;
	int pf;//定义成绩的基本属性（封装保护部分）
public:
	char kcname[30];
	int genxf;//定义成绩的基本属性（公共公开部分）
	Chengji() {};
	Chengji(const char* kc, int x, int p, double n1)
	{
		strcpy(kcname, kc);
		xf = x;
		pf = p;
		cj100 = n1;
	}//构造函数
	~Chengji() {};//析构函数
	void getkcname() {cout << kcname;}
	int getkcnamelen(){return strlen(kcname);}
	void getjidianpf(){cout << jidianpf;}
	void getjidian(){cout << jidian;}
	double getjidian1() {return jidian;}
	void getcj(){cout << cj;}
	int getcjlen(){return strlen(cj);}
	void getcj100(){cout << cj100;}
	int getcj1001(){return cj100;}
	int getxf1(){return xf;}
	void getxf(){cout << xf;}
	int  getpf1(){return pf;}
	void  getpf(){cout << pf;}//获取保护类型的属性
	void setkcname(const char* kc) {strcpy(kcname, kc);}
	void setxf(int x){xf = x;}
	void setpf(int p){pf = p;}
	void setcj100(double n1){cj100 = n1;}//输入保护类型的属性
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
	}//按照制定的规则根据百分制成绩换算成对应的等级制成绩与绩点或计算PF成绩

};
class student : public Chengji,public People//由成绩与People两个类共同派生出学生类
{
public:
	char depart[20];
	int grade;
	int classno;
	double GPA;
	double GPA1;
	int rank;
	int shu;
	int genxf;
	double xfj;//定义学生类基本属性
	Chengji chj[200];//定义学生类包含的各课程成绩组成的对象数组
	student() {}
	student(const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :Chengji(),People()
	{
		grade = g;
		classno = c;
		strcpy(depart, d);
	};//构造函数
	~student() {};//析构函数
	virtual void work()const { cout << "大学生"; }//虚函数，输出学生职业
	virtual void xueli()const { cout << "高中及以上"; }//虚函数，将抽象类实例化，输出学生学历
	int paiming(student stu[], int n, double x) {};//在全体学生中计算指定学号的学生的排名函数

};
class database :public student, public Xueqi//由学生与具体某学期双重属性构成的数据类
{
public:
	student stu;
	Xueqi xq;//定义学期与学生两个组成部分（属性）
	database() {};
	database(int yy, const char* sea, const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :student(), Xueqi()
	{};//构造函数
	~database() {};//析构函数
	int shuru(student stu[], Xueqi xq[], database data[]) {};//输入学生成绩
	double getGPA(const char* number, database data[]) {};//计算指定学号的学生的GPA函数
	void search(database data[]) {};//查询学生指定学期成绩的函数
	void search2(student stu[], database data[]) {};//查询学生排名和GPA的函数
	void revise(database data[]) {};//修改学生指定学期成绩的函数
};
struct adminis
{
	char name[20];
	int gonghao;
	char userid[30];
	char password[50];
};//定义管理员结构体
 istream& operator>>(istream& input, adminis& ad)
{
	input >> ad.name >> ad.gonghao >> ad.userid >> ad.password;
	return input;
};//重载输入管理员信息的流运算符
void input(adminis ad[])
{
	ifstream in;	
	in.open("administrator.txt", ios::in);
	for (int i = 0; i < 4; i++)
	{
		in >> ad[i];
	}
	in.close();
};//将管理员的信息导入指定文件中
int shuru(student stu[], Xueqi xq[], database data[])//输入学生成绩
{
	char a;
	int c, d;
	cout << "请输入考试年份：";
	cin >> year;
	cout << "请输入考试学期（春季输入1，夏季输入2，秋季输入3）：";
	cin >> c;//提示输入信息，输入指定学期的属性来锁定该学期
	if (c == 1) { strcpy(season, "春季"); }
	else if (c == 2) { strcpy(season, "夏季"); }
	else if (c == 3) { strcpy(season, "秋季"); }
	else {
		do {
			cout << "输入不合规范，请重新输入：";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);
	}//判断对应的季节
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
	}//依据年份与季节来判断该学期在总的学期数组中的位置
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
		}//判断对应的性别
		cout << "请输入年级:";
		cin >> stu[q].grade;
		cout << "请输入班级:";
		cin >> stu[q].classno;
		cout << "请输入院系:";
		cin >> stu[q].depart;//输入学生基本信息
		cout << " 请输入要输入的课程成绩数量:" << endl;
		cin >> shu;//输入课程数量
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
			if (stu[q].chj[i].getpf1() == 1) { cout << " 该课程的绩点为："; stu[q].chj[i].getjidianpf(); cout << endl; }//如果该课程记pf，直接换算成pf成绩
			else { cout << "该课程的绩点为：";  cout.setf(ios::fixed); cout << setprecision(1); stu[q].chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
			cout << "该课程的百分制成绩为："; stu[q].chj[i].getcj100();  cout << endl;//如果该课程不记pf，则换算成等级制成绩与绩点
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
		} while (i < shu);//计算不记pf的课程的总学分与总学分绩
		m = j - 1;
		if (stu[q].genxf == 0) { stu[q].GPA = 0; }
		else { stu[q].GPA = stu[q].xfj / stu[q].genxf; }//计算该学生本学期的GPA
		cout << "该学生在";
		xq[b1].getyear();
		cout << "学年";
		xq[b1].getseason();
		if (stu[q].genxf != 0) { cout.setf(ios::fixed); cout << "学期的GPA为：" << setprecision(3) << stu[q].GPA; cout.unsetf(ios::fixed); }
		else { cout << "学期的GPA为：" << "N/A"; }
		cout << endl;//输出对应信息
		cout << "是否还要继续输入:(y/n)" << endl;
		cin >> a;
		data[b1 * 20 + q].xq = xq[b1];
		data[b1 * 20 + q].stu = stu[q];//将该学期该学生的信息导入到数据的对象数组中
	} while (a == 'y');
	return q + 1;//返回输入学生的数量
}
double getGPA(const char* number, database data[]) //计算指定学号的学生的GPA函数
{
	int i1 = 0; int j1 = 0;
	int m1 = j1 - 1;
	int gef = 0;
	double xj = 0;
	double p = 0;
	char r[10];
	for (i1 = 0; i1 < 240; i1++)
	{
		if ((strcmp(number, data[i1].stu.number) == 0))//查找数据数组中所有有关该学生的对象
		{
			gef += data[i1].stu.genxf;//计算该学生所有学期的总学分
			xj += data[i1].stu.xfj;//计算该学生所有学期的总学分
		}
	}
	if (gef == 0)p == 0;
	else { p = xj / gef; }//计算该学生所有学期总GPA
	return p;//返回计算得到的GPA
}
void search(database data[]) //查询学生指定学期成绩的函数
{
	char n = 'y';
	int z;
	while (n == 'y')
	{
		int j = -1, c;
		char n1[20];
		cout << "输入你要查询的学期（依次输入学年和学期（春季输入1，夏季输入2，秋季输入3））:" << endl;
		cin >> year;
		cin >> c;
		if (c == 1) { strcpy(season, "春季"); }
		else if (c == 2) { strcpy(season, "夏季"); }
		else if (c == 3) { strcpy(season, "秋季"); }//输入查找的学期信息
		cout << "输入你要查询的学生学号:" << endl;
		cin >> number;//输入查找学生的学号
		for (int i = b1; i < b1*20+g; i++)
		{
			if ((strcmp(number, data[i].stu.number) == 0) && (strcmp(season, data[i].xq.season) == 0) && (data[i].xq.year == year))//查询数据数组中三种属性同时满足的对象
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";
			cout << "是否退出?退出请按 n\n";
			cin >> n;
		}//没有找到对应的对象并输出提示
		else {
			cout << "姓名：" << data[j].stu.name << " ";
			cout << "学号：" << data[j].stu.number << " ";
			cout << "性别：" << data[j].stu.sex << " ";
			if (data[j].stu.genxf != 0) { cout << "学期的GPA为：" << data[j].stu.GPA << " "; }
			else { cout << "学期的GPA为：" << "N/A "; }
			cout << "年级：" << data[j].stu.grade << " ";
			cout << "班号：" << data[j].stu.classno << " ";
			cout << "院系：" << data[j].stu.depart << " " << endl;//输出该学期该学生基本成绩信息
			cout << "|          课程名           |" << " 学分 |" << " 成绩 |" << " 百分制成绩 |" << "   绩点 |" << endl;//设定具体成绩输出格式
			for (int a = 0; a < data[j].stu.shu; a++)
			{
				int len = data[j].stu.chj[a].getkcnamelen();
				int len1 = floor((30 - len) / 2);
				cout << "|";
				cout << setfill(' ') << setw(len1 + len);
				data[j].stu.chj[a].getkcname();//依照指定的总宽度按照格式输出课程名
				cout << setfill(' ') << setw(30 - len1 - len);
				cout << "|  ";
				if (data[j].stu.chj[a].getxf1() < 10) { data[j].stu.chj[a].getxf(); cout << "   |  "; }
				else if (data[j].stu.chj[a].getxf1() >= 10) { data[j].stu.chj[a].getxf(); cout << "  |  "; }//依照指定的总宽度按照格式输出课程学分
				int len2 = data[j].stu.chj[a].getcjlen();
				int len3 = (7 - len2) / 2;
				cout << setfill(' ') << setw(len3 - 1);
				data[j].stu.chj[a].getcj();//依照指定的总宽度按照格式输出课程成绩
				cout << setfill(' ') << setw(7 - len2 - len3) << "  |  ";
				cout.setf(ios::fixed);
				cout << setiosflags(ios_base::right) << setprecision(0);
				if (data[j].stu.chj[a].getcj1001() < 10) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "00"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else if (data[j].stu.chj[a].getcj1001() >= 10 && data[j].stu.chj[a].getcj1001() < 100) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "0"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else {
					cout << setiosflags(ios_base::right) << setprecision(0);
					data[j].stu.chj[a].getcj100(); cout << "  ";
				}//依照指定的总宽度按照格式输出课程百分制成绩
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
				}//依照指定的总宽度按照格式输出课程绩点
				cout << "    |    " << endl;
			}
			cout << "是否继续查询(y/n)继续请按 y 退出按 n" << endl;
			cin >> n;
		}
	}
}
void search2(student stu[], database data[])//查询学生排名和GPA的函数
{
	int paiming(student stu[], int n, double x);//调用查询学生排名的函数
	int j = -1;
	char n = 'y';
	int g1 = g;
	int p = 0;
	int q = 0;
	char num[20];
	while (n == 'y')
	{
		cout << "输入你要查询的学生学号:" << endl;
		cin >> num;//输入指定学生学号
		for (int i = 0; i < g1; i++)
		{
			if ((strcmp(num, stu[i].number) == 0))//在学生数组里找到满足条件的学生对象
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";
			cout << "是否退出?退出请按 n\n";
			cin >> n;
		}//没有找到并提示
		else {
			for (int i = 0; i < g1; i++)
			{
				double GPA2 = getGPA(stu[i].number, data);
				stu[i].GPA1 = GPA2;//计算出所有学生的GPA
			}double x = stu[j].GPA1;//对指定学生GPA进行赋值处理
			int k1 = 0; int k2 = 0; int k3 = 0;
			int h = 0; int s = 0; int f = 0; int d = 0; int s1 = 0; int s2 = 0;
			char dep[20];
			cout << "姓名：" << stu[j].name << " ";
			cout << "学号：" << stu[j].number << " ";
			cout << "性别：" << stu[j].sex << " ";
			cout << "年级：" << stu[j].grade << " ";
			cout << "班号：" << stu[j].classno << " ";
			cout << "院系：" << stu[j].depart << " " << endl;//输出该学生基本信息
			student* stu3 = new student[20];
			student* same = new student[200];
			student* sum = new student[200];//为三个对象数组申请动态内存空间
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
			} while (s < g1);//将所有年级相同的学生合并为新的对象数组
			do
			{
				if (strcmp(dep, stu3[s1].depart) == 0)
				{
					same[h] = stu3[s1];
					h++;
				}
				s1++;
			} while (s1 < d);//将上述新数组中系一样的学生合并为新对象数组
			do
			{
				if (same[s2].classno == q)
				{
					sum[f] = same[s2];
					f++;
				}
				s2++;
			} while (s2 < h);//将上述新数组中班级一样的学生合并为新对象数组
			cout << "级排名为：" << paiming(stu3, d, x) << endl;//计算该学生年级排名
			cout << "系排名为：" << paiming(same, h, x) << endl;//计算该学生系排名
			cout << "班排名为：" << paiming(sum, f, x) << endl;//计算该学生班级排名
			cout.setf(ios::fixed);//指定输出格式
			cout << "总体GPA为：" << setprecision(3) << x << endl;//输出该学生总GPA
			cout.unsetf(ios::fixed);
			delete[]stu3;
			delete[]same;
			delete[]sum;//释放内存空间
		}
		cout << "是否继续查询(y/n)继续请按 y 退出按 n" << endl;
		cin >> n;
	}
}
int paiming(student stu[], int n, double x)//计算在指定学生数组中某一学生的排名
{
	int k1 = -2;
	double a[20];
	for (int i = 0; i < n; i++)
	{
		a[i] = stu[i].GPA1;//将学生的GPA赋值到a数组中
	}
	if (n == 1)
	{
		k1 = 1;//只有一个学生则排名为1
	}
	else if (n == 2)
	{
		if (a[0] < a[1])//对两个学生GPA进行从高到低的排序
		{
			double t = a[0]; a[0] = a[1]; a[1] = t;
		}
		for (int i = 0; i < 2; i++)
		{
			if (a[i] == x)k1 = i + 1;//在新排完序数组中查找指定学生GPA得到其在新数组中的位置进而得到排名
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
					double t = a[j1]; a[j1] = a[j1 + 1]; a[j1 + 1] = t;//采用冒泡排序对多个学生GPA进行从高到低的排序
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)k1 = i + 1;//在新排完序数组中查找指定学生GPA得到其在新数组中的位置进而得到排名
		}
	}
	return k1;//返回得到的排名
}
void revise(database data[], Xueqi xq[], student stu[])//修改学生指定学期成绩的函数
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
	}//进行提示，输入相关信息
	while (k == 1)
	{
		cout << "请输入你要修改成绩的学生学号" << endl;
		cin >> number;
		flgh = 0;
		for (int i = 0; i < 240; i++)
		{
			if ((strcmp(number, data[i].stu.number) == 0) && (strcmp(season, data[i].xq.season) == 0) && data[i].xq.year == year)//查找指定学期指定学号的具体对象
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "没有你所要的学生!";
			cout << "是否退出?退出请按 n\n";
			cin >> n;//提示没有找到的信息
		}
		else {
			char kcn[30];
			cout << "请输入要修改的课程名：" << endl;
			cin >> kcn;//输入修改的课程名
			int b = data[j].stu.shu;
			for (int i = 0; i < b; i++)
			{
				if (strcmp(data[j].stu.chj[i].kcname, kcn) == 0)//对查到的数据对象中的学生成绩数组进行遍历查找，找到指定课程名对应的成绩对象
				{
					data[j].stu.genxf = data[j].stu.genxf - data[j].stu.chj[i].getxf1();
					data[j].stu.xfj = data[j].stu.xfj - (data[j].stu.chj[i].getxf1()) * (data[j].stu.chj[i].getjidian1());
					cout << "请重新输入课程学分: " << endl;
					cin >> xf;
					data[j].stu.chj[i].setxf(xf);
					data[j].stu.genxf = data[j].stu.genxf + data[j].stu.chj[i].getxf1();
					cout << "请重新输入该课程属性（是否记P/F）？（是输入1，否输入0）： " << endl;
					cin >> pf;
					data[j].stu.chj[i].setpf(pf);
					cout << "请重新输入该课程百分制成绩 " << endl;
					cin >> cj100;
					data[j].stu.chj[i].setcj100(cj100);
					data[j].stu.chj[i].calculate();
					cout << "该课程的成绩为";  data[j].stu.chj[i].getcj(); cout << endl;
					cout << "该课程的百分制成绩为：";  data[j].stu.chj[i].getcj100(); cout << endl;
					if (data[j].stu.chj[i].getpf1() == 1) { cout << " 该课程的绩点为：";  data[j].stu.chj[i].getjidianpf(); cout << endl; }
					else { cout << "该课程的绩点为：";  cout.setf(ios::fixed); cout << setprecision(1);  data[j].stu.chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
					cout << "该课程的百分制成绩为："; data[j].stu.chj[i].getcj100();  cout << endl;
					data[j].stu.xfj = data[j].stu.xfj + (data[j].stu.chj[i].getxf1()) * (data[j].stu.chj[i].getjidian1());
					if (data[j].stu.genxf == 0) { data[j].stu.GPA = 0; }
					else { data[j].stu.GPA = data[j].stu.xfj / data[j].stu.genxf; }//显示修正以后的成绩各属性
				}
			}
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
			}//同前面的查询函数，指定格式对该学期修正后的所有成绩进行输出展示
		}
		cout << "还要继续吗?退出请按 0,继续请按1：" << endl;
		cin >> k;
	}

}
void caidan()//显示开始的总菜单
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << "********欢迎进入学生成绩管理系统！*********" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);//设定格式
	cout << a << "学生成绩管理系统" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);//设定格式
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
	cout << "请选择序号（1-3）" << endl;//设定三个选项并提示进行选择
	cout << setfill('*') << setw(40) << "" << endl;
}
void caidan2(adminis ad)//选择选项1并输入用户名和密码后进入成绩管理系统的管理员端口
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "学生成绩管理系统（管理员版）" << endl;
	cout << a << "欢迎回来，" << ad.name << "  No." << ad.gonghao << endl;//根据用户名显示管理员的相关信息
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
	cout << "请选择序号（1-5）" << endl;//设置五个选项并提示输入选项
	cout << setfill('*') << setw(40) << "" << endl;//设定格式
}
void caidan3()//选择选项2后进入成绩管理系统的学生端口
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
	cout << "请选择序号（1-3）" << endl;//设置三个选项并提示输入选项
	cout << setfill('*') << setw(40) << "" << endl;//设定格式
}
int main()//主函数
{
	student* stu = new student[20];
	Xueqi* xq = new Xueqi[12];
	database* data = new database[240];//定义三个基本对象数组并为其分配动态内存空间
	adminis ad[5] =
	{
		"wxq",1,"wxqtsinghua.edu.cn","234755687sddvcEFCTd!dfgf",
		"zxd",2,"zxdtsinghua.edu.cn","8237rtghdsfgRTDFYR%TREF^t",
		"shc",3,"shctsinghua.edu.cn","iwue3hrbu887ydsfUV&^&RR$#4",
		"sls",4,"slstsinghua.edu.cn","vytr567rfut5r5E%$EDYCRTY",
		"zzy",5,"zzytsinghua.edu.cn","Gugy7u65tf7vytjFDRFY%^jb67"
	};//为结构体数组进行赋值
	void input(adminis ad);//将结构体数组信息写入指定文件
	int ch;
	while (1)//进入选择界面
	{
	B:
		string a;
		int fg;
		char useri[30];
		char passwo[50];
		ifstream in;
		ofstream ofile;
		ifstream ifile;//定义基本文件输入输出对象
		caidan();//显示总菜单
		if (!ofile || !ifile || !in)
		{
			cerr << "文件打开错误" << endl;
			abort();
		}//判断文件是否打开成功
		cin >> fg;//输入总菜单提示的选项值
		if (fg == 1)//选择进入管理员端口 
		{
			char n = 'y';
			int j = -1;
			in.open("administrator.bin", ios::in);//打开存储管理员信息的文件
			for (int i = 0; i < 5; i++)
			{
				in.read((char*)&ad[i], sizeof(ad[i]));//读入管理员的相关信息
			}
			in.close();
			do {
				cout << "请输入用户名" << endl;
				cin >> useri;
				cout << "请输入密码" << endl;
				cin >> passwo;//输入管理员相关信息
				for (int i = 0; i < 5; i++)
				{
					if ((strcmp(useri, ad[i].userid) == 0) && (strcmp(passwo, ad[i].password) == 0))//判断管理员信息输入是否正确
					{
						j = i;
					}
				}
				if (j == -1)
				{
					cout << "用户名或密码输入错误，请退出重试" << endl<<endl;
					goto B;//提示输入错误并返回总菜单
				}
				else {
				A:
					caidan2(ad[j]);//打开管理系统（管理员版）菜单
					cin >> ch;//输入管理员菜单提示的选项
					switch (ch)//对输入的选项值进行处理
					{
					case 1:ofile.open("grade management system.bin", ios::out | ios::binary);//打开文件并进行写入操作，指定文件操作对象
						g = shuru(stu, xq, data);//输入学生成绩
						for (int i = 0; i < g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//向文件写入学生数组信息
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//向文件写入数据数组信息
						ofile.close();//关闭文件
						goto A;//返回管理系统（管理员版）菜单
					case 2:ifile.open("grade management system.bin", ios::in | ios::binary);//打开文件并进行读出操作，指定文件操作对象
						for (int i = 0; i < g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//读入学生数组信息
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}
						for (int i = 0; i < 240; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//读入数据数组信息
						search(data);//在数据数组中查询学生成绩
						ifile.close();//关闭文件
						goto A;//返回管理系统（管理员版）菜单
					case 3: ifile.open("grade management system.bin", ios::in | ios::binary);//打开文件并进行读出操作，指定文件操作对象
						for (int i = 0; i < g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//读入学生数组信息
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}
						for (int i = 0; i < 240; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//读入数据数组信息
						search2(stu, data);//查询学生GPA和排名
						ifile.close();//关闭文件
						goto A;//返回管理系统（管理员版）菜单
					case 4: ofile.open("grade management system.bin",ios::out|| ios::binary);//打开文件并进行写入操作，指定文件操作对象
						ifile.open("grade management system.bin",ios::in|| ios::binary);//打开文件并进行读出操作，指定文件操作对象
						for (int i = 0; i < g; i++)
						{
							ifile.read((char*)&stu[i], sizeof(stu[i]));
						}//读入学生数组信息
						for (int i = 0; i < 240; i++)
						{
							ifile.read((char*)&data[i], sizeof(data[i]));
						}//读入数据数组信息
						revise(data, xq, stu);//修改学生成绩
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//向文件写入数据数组信息
						ifile.close();
						ofile.close();//关闭文件
						goto A;//返回管理系统（管理员版）菜单
					case 5:cout << "系统已关闭" << endl;//提示退出信息
						goto B;//返回总菜单
					}
				}
			} while (n == 'y');
		}
		else if (fg == 2)//选择进入学生端口 
		{
		C:
			caidan3();//打开管理系统（学生版）菜单
			cin >> ch;//输入学生菜单提示的选项
			switch (ch)//对输入的选项值进行处理
			{
			case 1:ifile.open("grade management system.bin", ios::in | ios::binary);//打开文件并进行读出操作，指定文件操作对象
				for (int i = 0; i < g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
				}//读入学生数组信息
				for (int i = b1 * 20; i < b1 * 20 + g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}
				for (int i = 0; i < 240; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}//读入数据数组信息
				search(data);//在数据数组中查询学生成绩
				ifile.close();//关闭文件
				goto C;//返回管理系统（学生版）菜单
			case 2: ifile.open("grade management system.bin", ios::in | ios::binary);//打开文件并进行读出操作，指定文件操作对象
				for (int i = 0; i < g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
				}//读入学生数组信息
				for (int i = b1 * 20; i < b1 * 20 + g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}
				for (int i = 0; i < 240; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}//读入数据数组信息
				search2(stu, data);//查询学生GPA和排名
				ifile.close();//关闭文件
				goto C;//返回管理系统（学生版）菜单
			case 3: cout << "系统已关闭" << endl;//提示退出信息
				goto B;//返回总菜单
			}
		}
		else exit(0);//退出系统
	}
	delete[]data;
	delete[]stu;
	delete[]xq;//释放内存空间
	return 0;
}
