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
	//实现对输出运算符的重载
	friend ostream &operator <<(ostream& out, Student& t)
	{
		out << t.name;
		return out;
	}
};
int main()
{
	//构造一个map容器存储student对象
	map<int, Student> stus;

	map<int, string> mapS;
	//用pair对象进行插入
	mapS.insert(pair<int, string>(3, "小张"));//3是键，小张是值
	mapS.insert(pair<int, string>(4, "小王"));
	//也可以先构造在插入
	int key;
	string name;
	key = 5;
	name = "小赵";
	pair<int, string> p(key, name);
	mapS.insert(p);

	//通过value_type的方式插入对象
	mapS.insert(map<int, string>::value_type(1, "小李"));
	//也可以先构造在插入
	map<int, string>::value_type v(6, "小周");
	mapS.insert(v);
	map<int, string>::value_type v2(6, "小梁");//insert方式不会覆盖原来的值
	mapS.insert(v2);
	
	//通过数组的形式插入对象
	mapS[2] = "小郭";
	mapS[2] = "小马";//用类似数组的方式会覆盖原来的值


	//插入自定义对象
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
		//用重载的输出运算符输出：
		cout << key << ":" << value << endl;
	}

	//获取学号为3的名字
	string stu_name = mapS[3];
	cout << stu_name << endl;

	//获取学号为10的名字
	//stu_name = mapS[10];//如果容器中不存在键值为10的键值对，自动创建一个键值为10的键值对，值是默认值""
	//cout << stu_name << endl;

	//用find()获取键值
	map<int, string>::iterator it;
	it = mapS.find(3);
	if(it!=mapS.end())
		cout << (*it).first << ":" << (*it).second << endl;
	else
		cout << "can not find key: 3" << endl;
	//用find()获取键值为10的元素
	it = mapS.find(10);
	if (it == mapS.end())
		cout << "can not find key: 10" << endl;
	else
		cout << (*it).first << ":" << (*it).second << endl;


	//用at()输出键值元素
	cout << mapS.at(3) << endl;//如果键值不存在则会抛出异常
	//例如：
	//cout << mapS.at(20) << endl;

	return 0;
}