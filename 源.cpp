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
class People//���������
{
public:
	char name[11];
	char number[20];
	char sex[5];//����������������
	People() {};
	People(const char* n, const char* num, const char* sexx )
	{
		strcpy(name, n);
		strcpy(number, num);
		strcpy(sex, sexx);
	}//���幹�캯��
	~People() {};//������������
	virtual void xueli()const { cout << "δ֪"; }//�鿴ѧ��
	virtual void work()const = 0;//�鿴ְҵ���޺����壩
};
class Xueqi//����ѧ����
{
public:
	int year;
	char season[10];//����ѧ��ͼ���������������
	Xueqi() {};
	Xueqi(int yy, const char* sea)
	{
		year = yy;
		strcpy(season, sea);
	}//���캯��
	~Xueqi() {};//��������
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
class Chengji//����ɼ���
{
protected:
	char jidianpf[4] = "N/A";
	double jidian;
	char cj[3];
	double cj100;
	int xf;
	int pf;//����ɼ��Ļ������ԣ���װ�������֣�
public:
	char kcname[30];
	int genxf;//����ɼ��Ļ������ԣ������������֣�
	Chengji() {};
	Chengji(const char* kc, int x, int p, double n1)
	{
		strcpy(kcname, kc);
		xf = x;
		pf = p;
		cj100 = n1;
	}//���캯��
	~Chengji() {};//��������
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
	void  getpf(){cout << pf;}//��ȡ�������͵�����
	void setkcname(const char* kc) {strcpy(kcname, kc);}
	void setxf(int x){xf = x;}
	void setpf(int p){pf = p;}
	void setcj100(double n1){cj100 = n1;}//���뱣�����͵�����
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
	}//�����ƶ��Ĺ�����ݰٷ��Ƴɼ�����ɶ�Ӧ�ĵȼ��Ƴɼ��뼨������PF�ɼ�

};
class student : public Chengji,public People//�ɳɼ���People�����๲ͬ������ѧ����
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
	double xfj;//����ѧ�����������
	Chengji chj[200];//����ѧ��������ĸ��γ̳ɼ���ɵĶ�������
	student() {}
	student(const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :Chengji(),People()
	{
		grade = g;
		classno = c;
		strcpy(depart, d);
	};//���캯��
	~student() {};//��������
	virtual void work()const { cout << "��ѧ��"; }//�麯�������ѧ��ְҵ
	virtual void xueli()const { cout << "���м�����"; }//�麯������������ʵ���������ѧ��ѧ��
	int paiming(student stu[], int n, double x) {};//��ȫ��ѧ���м���ָ��ѧ�ŵ�ѧ������������

};
class database :public student, public Xueqi//��ѧ�������ĳѧ��˫�����Թ��ɵ�������
{
public:
	student stu;
	Xueqi xq;//����ѧ����ѧ��������ɲ��֣����ԣ�
	database() {};
	database(int yy, const char* sea, const char* n, const char* num, const char* sexx, int g, int c, const char* d, const char* kc, int x, int p, double n1, int nu) :student(), Xueqi()
	{};//���캯��
	~database() {};//��������
	int shuru(student stu[], Xueqi xq[], database data[]) {};//����ѧ���ɼ�
	double getGPA(const char* number, database data[]) {};//����ָ��ѧ�ŵ�ѧ����GPA����
	void search(database data[]) {};//��ѯѧ��ָ��ѧ�ڳɼ��ĺ���
	void search2(student stu[], database data[]) {};//��ѯѧ��������GPA�ĺ���
	void revise(database data[]) {};//�޸�ѧ��ָ��ѧ�ڳɼ��ĺ���
};
struct adminis
{
	char name[20];
	int gonghao;
	char userid[30];
	char password[50];
};//�������Ա�ṹ��
 istream& operator>>(istream& input, adminis& ad)
{
	input >> ad.name >> ad.gonghao >> ad.userid >> ad.password;
	return input;
};//�����������Ա��Ϣ���������
void input(adminis ad[])
{
	ifstream in;	
	in.open("administrator.txt", ios::in);
	for (int i = 0; i < 4; i++)
	{
		in >> ad[i];
	}
	in.close();
};//������Ա����Ϣ����ָ���ļ���
int shuru(student stu[], Xueqi xq[], database data[])//����ѧ���ɼ�
{
	char a;
	int c, d;
	cout << "�����뿼����ݣ�";
	cin >> year;
	cout << "�����뿼��ѧ�ڣ���������1���ļ�����2���＾����3����";
	cin >> c;//��ʾ������Ϣ������ָ��ѧ�ڵ�������������ѧ��
	if (c == 1) { strcpy(season, "����"); }
	else if (c == 2) { strcpy(season, "�ļ�"); }
	else if (c == 3) { strcpy(season, "�＾"); }
	else {
		do {
			cout << "���벻�Ϲ淶�����������룺";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);
	}//�ж϶�Ӧ�ļ���
	if ((year % 4 == 0))
	{
		if (strcmp(season, "�＾") == 0) b1 = 0;
		else if (strcmp(season, "����") == 0) b1 = 1;
		else if (strcmp(season, "�ļ�") == 0) b1 = 2;
	}
	else if ((year % 4 == 1))
	{
		if (strcmp(season, "�＾") == 0) b1 = 3;
		else if (strcmp(season, "����") == 0) b1 = 4;
		else if (strcmp(season, "�ļ�") == 0) b1 = 5;
	}
	else if ((year % 4 == 2))
	{
		if (strcmp(season, "�＾") == 0) b1 = 6;
		else if (strcmp(season, "����") == 0) b1 = 7;
		else if (strcmp(season, "�ļ�") == 0) b1 = 8;
	}
	else if ((year % 4 == 3))
	{
		if (strcmp(season, "�＾") == 0) b1 = 9;
		else if (strcmp(season, "����") == 0) b1 = 10;
		else if (strcmp(season, "�ļ�") == 0) b1 = 11;
	}//��������뼾�����жϸ�ѧ�����ܵ�ѧ�������е�λ��
	xq[b1].setyear(year);
	xq[b1].setseason(season);
	do {
		q++;
		cout << "������ѧ������:";
		cin >> stu[q].name;
		cout << "������ѧ��:";
		cin >> stu[q].number;
		cout << "�������Ա���������1��Ů������0��:";
		cin >> d;
		if (d == 0)
		{
			strcpy(stu[q].sex, "Ů");
		}
		else if (d == 1) strcpy(stu[q].sex, "��");
		else {
			do {
				cout << "���벻�Ϲ淶�����������룺";
				cin >> d;
			} while (d != 0 && d != 1);
		}//�ж϶�Ӧ���Ա�
		cout << "�������꼶:";
		cin >> stu[q].grade;
		cout << "������༶:";
		cin >> stu[q].classno;
		cout << "������Ժϵ:";
		cin >> stu[q].depart;//����ѧ��������Ϣ
		cout << " ������Ҫ����Ŀγ̳ɼ�����:" << endl;
		cin >> shu;//����γ�����
		stu[q].shu = shu;
		for (int i = 0; i < shu; i++)
		{
			cout << " ������γ���:" << endl;
			cin >> kcname;
			stu[q].chj[i].setkcname(kcname);
			cout << "������γ�ѧ��: " << endl;
			cin >> xf;
			stu[q].chj[i].setxf(xf);
			cout << "������ÿγ����ԣ��Ƿ��P/F������������1��������0���� " << endl;
			cin >> pf;
			stu[q].chj[i].setpf(pf);
			cout << "������ÿγ̰ٷ��Ƴɼ� " << endl;
			cin >> cj100;
			stu[q].chj[i].setcj100(cj100);
			stu[q].chj[i].calculate();
			cout << "�ÿγ̵ĳɼ�Ϊ"; stu[q].chj[i].getcj(); cout << endl;
			if (stu[q].chj[i].getpf1() == 1) { cout << " �ÿγ̵ļ���Ϊ��"; stu[q].chj[i].getjidianpf(); cout << endl; }//����ÿγ̼�pf��ֱ�ӻ����pf�ɼ�
			else { cout << "�ÿγ̵ļ���Ϊ��";  cout.setf(ios::fixed); cout << setprecision(1); stu[q].chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
			cout << "�ÿγ̵İٷ��Ƴɼ�Ϊ��"; stu[q].chj[i].getcj100();  cout << endl;//����ÿγ̲���pf������ɵȼ��Ƴɼ��뼨��
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
		} while (i < shu);//���㲻��pf�Ŀγ̵���ѧ������ѧ�ּ�
		m = j - 1;
		if (stu[q].genxf == 0) { stu[q].GPA = 0; }
		else { stu[q].GPA = stu[q].xfj / stu[q].genxf; }//�����ѧ����ѧ�ڵ�GPA
		cout << "��ѧ����";
		xq[b1].getyear();
		cout << "ѧ��";
		xq[b1].getseason();
		if (stu[q].genxf != 0) { cout.setf(ios::fixed); cout << "ѧ�ڵ�GPAΪ��" << setprecision(3) << stu[q].GPA; cout.unsetf(ios::fixed); }
		else { cout << "ѧ�ڵ�GPAΪ��" << "N/A"; }
		cout << endl;//�����Ӧ��Ϣ
		cout << "�Ƿ�Ҫ��������:(y/n)" << endl;
		cin >> a;
		data[b1 * 20 + q].xq = xq[b1];
		data[b1 * 20 + q].stu = stu[q];//����ѧ�ڸ�ѧ������Ϣ���뵽���ݵĶ���������
	} while (a == 'y');
	return q + 1;//��������ѧ��������
}
double getGPA(const char* number, database data[]) //����ָ��ѧ�ŵ�ѧ����GPA����
{
	int i1 = 0; int j1 = 0;
	int m1 = j1 - 1;
	int gef = 0;
	double xj = 0;
	double p = 0;
	char r[10];
	for (i1 = 0; i1 < 240; i1++)
	{
		if ((strcmp(number, data[i1].stu.number) == 0))//�������������������йظ�ѧ���Ķ���
		{
			gef += data[i1].stu.genxf;//�����ѧ������ѧ�ڵ���ѧ��
			xj += data[i1].stu.xfj;//�����ѧ������ѧ�ڵ���ѧ��
		}
	}
	if (gef == 0)p == 0;
	else { p = xj / gef; }//�����ѧ������ѧ����GPA
	return p;//���ؼ���õ���GPA
}
void search(database data[]) //��ѯѧ��ָ��ѧ�ڳɼ��ĺ���
{
	char n = 'y';
	int z;
	while (n == 'y')
	{
		int j = -1, c;
		char n1[20];
		cout << "������Ҫ��ѯ��ѧ�ڣ���������ѧ���ѧ�ڣ���������1���ļ�����2���＾����3����:" << endl;
		cin >> year;
		cin >> c;
		if (c == 1) { strcpy(season, "����"); }
		else if (c == 2) { strcpy(season, "�ļ�"); }
		else if (c == 3) { strcpy(season, "�＾"); }//������ҵ�ѧ����Ϣ
		cout << "������Ҫ��ѯ��ѧ��ѧ��:" << endl;
		cin >> number;//�������ѧ����ѧ��
		for (int i = b1; i < b1*20+g; i++)
		{
			if ((strcmp(number, data[i].stu.number) == 0) && (strcmp(season, data[i].xq.season) == 0) && (data[i].xq.year == year))//��ѯ������������������ͬʱ����Ķ���
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "û������Ҫ��ѧ��!";
			cout << "�Ƿ��˳�?�˳��밴 n\n";
			cin >> n;
		}//û���ҵ���Ӧ�Ķ��������ʾ
		else {
			cout << "������" << data[j].stu.name << " ";
			cout << "ѧ�ţ�" << data[j].stu.number << " ";
			cout << "�Ա�" << data[j].stu.sex << " ";
			if (data[j].stu.genxf != 0) { cout << "ѧ�ڵ�GPAΪ��" << data[j].stu.GPA << " "; }
			else { cout << "ѧ�ڵ�GPAΪ��" << "N/A "; }
			cout << "�꼶��" << data[j].stu.grade << " ";
			cout << "��ţ�" << data[j].stu.classno << " ";
			cout << "Ժϵ��" << data[j].stu.depart << " " << endl;//�����ѧ�ڸ�ѧ�������ɼ���Ϣ
			cout << "|          �γ���           |" << " ѧ�� |" << " �ɼ� |" << " �ٷ��Ƴɼ� |" << "   ���� |" << endl;//�趨����ɼ������ʽ
			for (int a = 0; a < data[j].stu.shu; a++)
			{
				int len = data[j].stu.chj[a].getkcnamelen();
				int len1 = floor((30 - len) / 2);
				cout << "|";
				cout << setfill(' ') << setw(len1 + len);
				data[j].stu.chj[a].getkcname();//����ָ�����ܿ�Ȱ��ո�ʽ����γ���
				cout << setfill(' ') << setw(30 - len1 - len);
				cout << "|  ";
				if (data[j].stu.chj[a].getxf1() < 10) { data[j].stu.chj[a].getxf(); cout << "   |  "; }
				else if (data[j].stu.chj[a].getxf1() >= 10) { data[j].stu.chj[a].getxf(); cout << "  |  "; }//����ָ�����ܿ�Ȱ��ո�ʽ����γ�ѧ��
				int len2 = data[j].stu.chj[a].getcjlen();
				int len3 = (7 - len2) / 2;
				cout << setfill(' ') << setw(len3 - 1);
				data[j].stu.chj[a].getcj();//����ָ�����ܿ�Ȱ��ո�ʽ����γ̳ɼ�
				cout << setfill(' ') << setw(7 - len2 - len3) << "  |  ";
				cout.setf(ios::fixed);
				cout << setiosflags(ios_base::right) << setprecision(0);
				if (data[j].stu.chj[a].getcj1001() < 10) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "00"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else if (data[j].stu.chj[a].getcj1001() >= 10 && data[j].stu.chj[a].getcj1001() < 100) { cout << setiosflags(ios_base::right) << setprecision(0); cout << "0"; data[j].stu.chj[a].getcj100(); cout << "  "; }
				else {
					cout << setiosflags(ios_base::right) << setprecision(0);
					data[j].stu.chj[a].getcj100(); cout << "  ";
				}//����ָ�����ܿ�Ȱ��ո�ʽ����γ̰ٷ��Ƴɼ�
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
				}//����ָ�����ܿ�Ȱ��ո�ʽ����γ̼���
				cout << "    |    " << endl;
			}
			cout << "�Ƿ������ѯ(y/n)�����밴 y �˳��� n" << endl;
			cin >> n;
		}
	}
}
void search2(student stu[], database data[])//��ѯѧ��������GPA�ĺ���
{
	int paiming(student stu[], int n, double x);//���ò�ѯѧ�������ĺ���
	int j = -1;
	char n = 'y';
	int g1 = g;
	int p = 0;
	int q = 0;
	char num[20];
	while (n == 'y')
	{
		cout << "������Ҫ��ѯ��ѧ��ѧ��:" << endl;
		cin >> num;//����ָ��ѧ��ѧ��
		for (int i = 0; i < g1; i++)
		{
			if ((strcmp(num, stu[i].number) == 0))//��ѧ���������ҵ�����������ѧ������
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "û������Ҫ��ѧ��!";
			cout << "�Ƿ��˳�?�˳��밴 n\n";
			cin >> n;
		}//û���ҵ�����ʾ
		else {
			for (int i = 0; i < g1; i++)
			{
				double GPA2 = getGPA(stu[i].number, data);
				stu[i].GPA1 = GPA2;//���������ѧ����GPA
			}double x = stu[j].GPA1;//��ָ��ѧ��GPA���и�ֵ����
			int k1 = 0; int k2 = 0; int k3 = 0;
			int h = 0; int s = 0; int f = 0; int d = 0; int s1 = 0; int s2 = 0;
			char dep[20];
			cout << "������" << stu[j].name << " ";
			cout << "ѧ�ţ�" << stu[j].number << " ";
			cout << "�Ա�" << stu[j].sex << " ";
			cout << "�꼶��" << stu[j].grade << " ";
			cout << "��ţ�" << stu[j].classno << " ";
			cout << "Ժϵ��" << stu[j].depart << " " << endl;//�����ѧ��������Ϣ
			student* stu3 = new student[20];
			student* same = new student[200];
			student* sum = new student[200];//Ϊ���������������붯̬�ڴ�ռ�
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
			} while (s < g1);//�������꼶��ͬ��ѧ���ϲ�Ϊ�µĶ�������
			do
			{
				if (strcmp(dep, stu3[s1].depart) == 0)
				{
					same[h] = stu3[s1];
					h++;
				}
				s1++;
			} while (s1 < d);//��������������ϵһ����ѧ���ϲ�Ϊ�¶�������
			do
			{
				if (same[s2].classno == q)
				{
					sum[f] = same[s2];
					f++;
				}
				s2++;
			} while (s2 < h);//�������������а༶һ����ѧ���ϲ�Ϊ�¶�������
			cout << "������Ϊ��" << paiming(stu3, d, x) << endl;//�����ѧ���꼶����
			cout << "ϵ����Ϊ��" << paiming(same, h, x) << endl;//�����ѧ��ϵ����
			cout << "������Ϊ��" << paiming(sum, f, x) << endl;//�����ѧ���༶����
			cout.setf(ios::fixed);//ָ�������ʽ
			cout << "����GPAΪ��" << setprecision(3) << x << endl;//�����ѧ����GPA
			cout.unsetf(ios::fixed);
			delete[]stu3;
			delete[]same;
			delete[]sum;//�ͷ��ڴ�ռ�
		}
		cout << "�Ƿ������ѯ(y/n)�����밴 y �˳��� n" << endl;
		cin >> n;
	}
}
int paiming(student stu[], int n, double x)//������ָ��ѧ��������ĳһѧ��������
{
	int k1 = -2;
	double a[20];
	for (int i = 0; i < n; i++)
	{
		a[i] = stu[i].GPA1;//��ѧ����GPA��ֵ��a������
	}
	if (n == 1)
	{
		k1 = 1;//ֻ��һ��ѧ��������Ϊ1
	}
	else if (n == 2)
	{
		if (a[0] < a[1])//������ѧ��GPA���дӸߵ��͵�����
		{
			double t = a[0]; a[0] = a[1]; a[1] = t;
		}
		for (int i = 0; i < 2; i++)
		{
			if (a[i] == x)k1 = i + 1;//���������������в���ָ��ѧ��GPA�õ������������е�λ�ý����õ�����
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
					double t = a[j1]; a[j1] = a[j1 + 1]; a[j1 + 1] = t;//����ð������Զ��ѧ��GPA���дӸߵ��͵�����
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)k1 = i + 1;//���������������в���ָ��ѧ��GPA�õ������������е�λ�ý����õ�����
		}
	}
	return k1;//���صõ�������
}
void revise(database data[], Xueqi xq[], student stu[])//�޸�ѧ��ָ��ѧ�ڳɼ��ĺ���
{
	int k = 1, j = -1, c, a[10], b1;
	int flgh;
	int h;
	char n = 'y';
	int d;
	cout << "------���뿪ʼ��----" << endl;
	cout << "�����뿼����ݣ�";
	cin >> year;
	cout << "�����뿼��ѧ�ڣ���������1���ļ�����2���＾����3����";
	cin >> c;
	if (c == 1) { strcpy(season, "����"); }
	else if (c == 2) { strcpy(season, "�ļ�"); }
	else if (c == 3) { strcpy(season, "�＾"); }
	else {
		do {
			cout << "���벻�Ϲ淶�����������룺";
			cin >> c;
		} while (c != 1 && c != 2 && c != 3);
	}//������ʾ�����������Ϣ
	while (k == 1)
	{
		cout << "��������Ҫ�޸ĳɼ���ѧ��ѧ��" << endl;
		cin >> number;
		flgh = 0;
		for (int i = 0; i < 240; i++)
		{
			if ((strcmp(number, data[i].stu.number) == 0) && (strcmp(season, data[i].xq.season) == 0) && data[i].xq.year == year)//����ָ��ѧ��ָ��ѧ�ŵľ������
			{
				j = i;
			}
		}
		if (j == -1)
		{
			cout << "û������Ҫ��ѧ��!";
			cout << "�Ƿ��˳�?�˳��밴 n\n";
			cin >> n;//��ʾû���ҵ�����Ϣ
		}
		else {
			char kcn[30];
			cout << "������Ҫ�޸ĵĿγ�����" << endl;
			cin >> kcn;//�����޸ĵĿγ���
			int b = data[j].stu.shu;
			for (int i = 0; i < b; i++)
			{
				if (strcmp(data[j].stu.chj[i].kcname, kcn) == 0)//�Բ鵽�����ݶ����е�ѧ���ɼ�������б������ң��ҵ�ָ���γ�����Ӧ�ĳɼ�����
				{
					data[j].stu.genxf = data[j].stu.genxf - data[j].stu.chj[i].getxf1();
					data[j].stu.xfj = data[j].stu.xfj - (data[j].stu.chj[i].getxf1()) * (data[j].stu.chj[i].getjidian1());
					cout << "����������γ�ѧ��: " << endl;
					cin >> xf;
					data[j].stu.chj[i].setxf(xf);
					data[j].stu.genxf = data[j].stu.genxf + data[j].stu.chj[i].getxf1();
					cout << "����������ÿγ����ԣ��Ƿ��P/F������������1��������0���� " << endl;
					cin >> pf;
					data[j].stu.chj[i].setpf(pf);
					cout << "����������ÿγ̰ٷ��Ƴɼ� " << endl;
					cin >> cj100;
					data[j].stu.chj[i].setcj100(cj100);
					data[j].stu.chj[i].calculate();
					cout << "�ÿγ̵ĳɼ�Ϊ";  data[j].stu.chj[i].getcj(); cout << endl;
					cout << "�ÿγ̵İٷ��Ƴɼ�Ϊ��";  data[j].stu.chj[i].getcj100(); cout << endl;
					if (data[j].stu.chj[i].getpf1() == 1) { cout << " �ÿγ̵ļ���Ϊ��";  data[j].stu.chj[i].getjidianpf(); cout << endl; }
					else { cout << "�ÿγ̵ļ���Ϊ��";  cout.setf(ios::fixed); cout << setprecision(1);  data[j].stu.chj[i].getjidian(); cout << setiosflags(ios_base::right) << setprecision(0); cout << endl; }
					cout << "�ÿγ̵İٷ��Ƴɼ�Ϊ��"; data[j].stu.chj[i].getcj100();  cout << endl;
					data[j].stu.xfj = data[j].stu.xfj + (data[j].stu.chj[i].getxf1()) * (data[j].stu.chj[i].getjidian1());
					if (data[j].stu.genxf == 0) { data[j].stu.GPA = 0; }
					else { data[j].stu.GPA = data[j].stu.xfj / data[j].stu.genxf; }//��ʾ�����Ժ�ĳɼ�������
				}
			}
			cout << "|          �γ���           |" << " ѧ�� |" << " �ɼ� |" << " �ٷ��Ƴɼ� |" << "   ���� |" << endl;
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
			}//ͬǰ��Ĳ�ѯ������ָ����ʽ�Ը�ѧ������������гɼ��������չʾ
		}
		cout << "��Ҫ������?�˳��밴 0,�����밴1��" << endl;
		cin >> k;
	}

}
void caidan()//��ʾ��ʼ���ܲ˵�
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << "********��ӭ����ѧ���ɼ�����ϵͳ��*********" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);//�趨��ʽ
	cout << a << "ѧ���ɼ�����ϵͳ" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);//�趨��ʽ
	cout << "��ѡ��汾" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.����Ա��" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.��ѧ����" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.�˳�ϵͳ" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "��ѡ����ţ�1-3��" << endl;//�趨����ѡ���ʾ����ѡ��
	cout << setfill('*') << setw(40) << "" << endl;
}
void caidan2(adminis ad)//ѡ��ѡ��1�������û�������������ɼ�����ϵͳ�Ĺ���Ա�˿�
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "ѧ���ɼ�����ϵͳ������Ա�棩" << endl;
	cout << a << "��ӭ������" << ad.name << "  No." << ad.gonghao << endl;//�����û�����ʾ����Ա�������Ϣ
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);
	cout << "���˵�" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.�ɼ�¼��" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.�ɼ���ѯ" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.������ѯ" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "4.�ɼ��޸�" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "5.�˳�ϵͳ" << endl;
	cout.width(26);
	cout.setf(ios::right);
	cout << "��ѡ����ţ�1-5��" << endl;//�������ѡ���ʾ����ѡ��
	cout << setfill('*') << setw(40) << "" << endl;//�趨��ʽ
}
void caidan3()//ѡ��ѡ��2�����ɼ�����ϵͳ��ѧ���˿�
{
	string a;
	getline(cin, a);
	int b = 8 + a.size();
	cout << setfill('*') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(b);
	cout.setf(ios::right);
	cout << a << "ѧ���ɼ�����ϵͳ��ѧ���棩" << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setfill('+') << setw(40) << "" << endl;
	cout.fill(' ');
	cout.width(20);
	cout.setf(ios::right);
	cout << "���˵�" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "1.�ɼ���ѯ" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "2.������ѯ" << endl;
	cout.width(22);
	cout.setf(ios::right);
	cout << "3.�˳�ϵͳ" << endl;
	cout.width(26);
	cout.setf(ios::right);
	cout << "��ѡ����ţ�1-3��" << endl;//��������ѡ���ʾ����ѡ��
	cout << setfill('*') << setw(40) << "" << endl;//�趨��ʽ
}
int main()//������
{
	student* stu = new student[20];
	Xueqi* xq = new Xueqi[12];
	database* data = new database[240];//�������������������鲢Ϊ����䶯̬�ڴ�ռ�
	adminis ad[5] =
	{
		"wxq",1,"wxqtsinghua.edu.cn","234755687sddvcEFCTd!dfgf",
		"zxd",2,"zxdtsinghua.edu.cn","8237rtghdsfgRTDFYR%TREF^t",
		"shc",3,"shctsinghua.edu.cn","iwue3hrbu887ydsfUV&^&RR$#4",
		"sls",4,"slstsinghua.edu.cn","vytr567rfut5r5E%$EDYCRTY",
		"zzy",5,"zzytsinghua.edu.cn","Gugy7u65tf7vytjFDRFY%^jb67"
	};//Ϊ�ṹ��������и�ֵ
	void input(adminis ad);//���ṹ��������Ϣд��ָ���ļ�
	int ch;
	while (1)//����ѡ�����
	{
	B:
		string a;
		int fg;
		char useri[30];
		char passwo[50];
		ifstream in;
		ofstream ofile;
		ifstream ifile;//��������ļ������������
		caidan();//��ʾ�ܲ˵�
		if (!ofile || !ifile || !in)
		{
			cerr << "�ļ��򿪴���" << endl;
			abort();
		}//�ж��ļ��Ƿ�򿪳ɹ�
		cin >> fg;//�����ܲ˵���ʾ��ѡ��ֵ
		if (fg == 1)//ѡ��������Ա�˿� 
		{
			char n = 'y';
			int j = -1;
			in.open("administrator.bin", ios::in);//�򿪴洢����Ա��Ϣ���ļ�
			for (int i = 0; i < 5; i++)
			{
				in.read((char*)&ad[i], sizeof(ad[i]));//�������Ա�������Ϣ
			}
			in.close();
			do {
				cout << "�������û���" << endl;
				cin >> useri;
				cout << "����������" << endl;
				cin >> passwo;//�������Ա�����Ϣ
				for (int i = 0; i < 5; i++)
				{
					if ((strcmp(useri, ad[i].userid) == 0) && (strcmp(passwo, ad[i].password) == 0))//�жϹ���Ա��Ϣ�����Ƿ���ȷ
					{
						j = i;
					}
				}
				if (j == -1)
				{
					cout << "�û�������������������˳�����" << endl<<endl;
					goto B;//��ʾ������󲢷����ܲ˵�
				}
				else {
				A:
					caidan2(ad[j]);//�򿪹���ϵͳ������Ա�棩�˵�
					cin >> ch;//�������Ա�˵���ʾ��ѡ��
					switch (ch)//�������ѡ��ֵ���д���
					{
					case 1:ofile.open("grade management system.bin", ios::out | ios::binary);//���ļ�������д�������ָ���ļ���������
						g = shuru(stu, xq, data);//����ѧ���ɼ�
						for (int i = 0; i < g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//���ļ�д��ѧ��������Ϣ
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//���ļ�д������������Ϣ
						ofile.close();//�ر��ļ�
						goto A;//���ع���ϵͳ������Ա�棩�˵�
					case 2:ifile.open("grade management system.bin", ios::in | ios::binary);//���ļ������ж���������ָ���ļ���������
						for (int i = 0; i < g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//����ѧ��������Ϣ
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}
						for (int i = 0; i < 240; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//��������������Ϣ
						search(data);//�����������в�ѯѧ���ɼ�
						ifile.close();//�ر��ļ�
						goto A;//���ع���ϵͳ������Ա�棩�˵�
					case 3: ifile.open("grade management system.bin", ios::in | ios::binary);//���ļ������ж���������ָ���ļ���������
						for (int i = 0; i < g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
						}//����ѧ��������Ϣ
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}
						for (int i = 0; i < 240; i++)
						{
							ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//��������������Ϣ
						search2(stu, data);//��ѯѧ��GPA������
						ifile.close();//�ر��ļ�
						goto A;//���ع���ϵͳ������Ա�棩�˵�
					case 4: ofile.open("grade management system.bin",ios::out|| ios::binary);//���ļ�������д�������ָ���ļ���������
						ifile.open("grade management system.bin",ios::in|| ios::binary);//���ļ������ж���������ָ���ļ���������
						for (int i = 0; i < g; i++)
						{
							ifile.read((char*)&stu[i], sizeof(stu[i]));
						}//����ѧ��������Ϣ
						for (int i = 0; i < 240; i++)
						{
							ifile.read((char*)&data[i], sizeof(data[i]));
						}//��������������Ϣ
						revise(data, xq, stu);//�޸�ѧ���ɼ�
						for (int i = b1 * 20; i < b1 * 20 + g; i++)
						{
							ofile.write(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
						}//���ļ�д������������Ϣ
						ifile.close();
						ofile.close();//�ر��ļ�
						goto A;//���ع���ϵͳ������Ա�棩�˵�
					case 5:cout << "ϵͳ�ѹر�" << endl;//��ʾ�˳���Ϣ
						goto B;//�����ܲ˵�
					}
				}
			} while (n == 'y');
		}
		else if (fg == 2)//ѡ�����ѧ���˿� 
		{
		C:
			caidan3();//�򿪹���ϵͳ��ѧ���棩�˵�
			cin >> ch;//����ѧ���˵���ʾ��ѡ��
			switch (ch)//�������ѡ��ֵ���д���
			{
			case 1:ifile.open("grade management system.bin", ios::in | ios::binary);//���ļ������ж���������ָ���ļ���������
				for (int i = 0; i < g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
				}//����ѧ��������Ϣ
				for (int i = b1 * 20; i < b1 * 20 + g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}
				for (int i = 0; i < 240; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}//��������������Ϣ
				search(data);//�����������в�ѯѧ���ɼ�
				ifile.close();//�ر��ļ�
				goto C;//���ع���ϵͳ��ѧ���棩�˵�
			case 2: ifile.open("grade management system.bin", ios::in | ios::binary);//���ļ������ж���������ָ���ļ���������
				for (int i = 0; i < g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&stu[i]), sizeof(stu[i]));
				}//����ѧ��������Ϣ
				for (int i = b1 * 20; i < b1 * 20 + g; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}
				for (int i = 0; i < 240; i++)
				{
					ifile.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
				}//��������������Ϣ
				search2(stu, data);//��ѯѧ��GPA������
				ifile.close();//�ر��ļ�
				goto C;//���ع���ϵͳ��ѧ���棩�˵�
			case 3: cout << "ϵͳ�ѹر�" << endl;//��ʾ�˳���Ϣ
				goto B;//�����ܲ˵�
			}
		}
		else exit(0);//�˳�ϵͳ
	}
	delete[]data;
	delete[]stu;
	delete[]xq;//�ͷ��ڴ�ռ�
	return 0;
}
