#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;
class Student
{
public:
	int id;
	string name;
	Student()
	{

	}
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
	//ʵ�ֶ���������������
	friend ostream &operator <<(ostream& out, Student& t)
	{
		out << t.name;
		return out;
	}
};
int main()
{
	//����һ��map�����洢student����
	map<int, Student> stus;

	map<int, string> mapS;
	//��pair������в���
	mapS.insert(pair<int, string>(3, "С��"));//3�Ǽ���С����ֵ
	mapS.insert(pair<int, string>(4, "С��"));
	//Ҳ�����ȹ����ڲ���
	int key;
	string name;
	key = 5;
	name = "С��";
	pair<int, string> p(key, name);
	mapS.insert(p);

	//ͨ��value_type�ķ�ʽ�������
	mapS.insert(map<int, string>::value_type(1, "С��"));
	//Ҳ�����ȹ����ڲ���
	map<int, string>::value_type v(6, "С��");
	mapS.insert(v);
	map<int, string>::value_type v2(6, "С��");//insert��ʽ���Ḳ��ԭ����ֵ
	mapS.insert(v2);
	
	//ͨ���������ʽ�������
	mapS[2] = "С��";
	mapS[2] = "С��";//����������ķ�ʽ�Ḳ��ԭ����ֵ


	//�����Զ������
	Student s1(1,"xiaoli");
	stus.insert(pair<int, Student>(s1.id, s1));

	Student s2(2, "xiaowang");
	stus.insert(map<int, Student>::value_type(s2.id, s2));

	Student s3(3, "xiaotian");
	stus[s3.id] = s3;

	map<int, string>::iterator it1;
	for (it1 = mapS.begin(); it1 != mapS.end(); it1++)
	{
		pair<int, string> p = *it1;
		int key = p.first;
		string value = p.second;
		cout << key << ":" << value << endl;
	}


	map<int, Student>::iterator it2;
	for (it2 = stus.begin(); it2 != stus.end(); it2++)
	{
		pair<int, Student> p = *it2;
		int key = p.first;
		Student value = p.second;
		//cout << key << ":" << value.name << endl;
		//�����ص��������������
		cout << key << ":" << value << endl;
	}

	//��ȡѧ��Ϊ3������
	string stu_name = mapS[3];
	cout << stu_name << endl;

	//��ȡѧ��Ϊ10������
	//stu_name = mapS[10];//��������в����ڼ�ֵΪ10�ļ�ֵ�ԣ��Զ�����һ����ֵΪ10�ļ�ֵ�ԣ�ֵ��Ĭ��ֵ""
	//cout << stu_name << endl;

	//��find()��ȡ��ֵ
	map<int, string>::iterator it;
	it = mapS.find(3);
	if(it!=mapS.end())
		cout << (*it).first << ":" << (*it).second << endl;
	else
		cout << "can not find key: 3" << endl;
	//��find()��ȡ��ֵΪ10��Ԫ��
	it = mapS.find(10);
	if (it == mapS.end())
		cout << "can not find key: 10" << endl;
	else
		cout << (*it).first << ":" << (*it).second << endl;


	//��at()�����ֵԪ��
	cout << mapS.at(3) << endl;//�����ֵ����������׳��쳣
	//���磺
	//cout << mapS.at(20) << endl;

	return 0;
}