#include <iostream>
#include<string>
#define MAX 1000
using namespace std;

//封装函数显示在该界面

//联系人结构体
struct Person {
	string m_Name;   //姓名
	int m_Sex;      //性别  1代表男 2代表女
	int m_Age;      //年龄
	string m_Phone;    //电话
	string m_Addr;   //住址
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保持联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录人数
	int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满，满了则不再添加
	if(abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
	//添加联系人

		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (1) 
		{
			//如果输入的是1或2可以退出循环，
			cin >> sex;
			
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cin.clear();   //清除错误标识符    如果sex输入值为字母会陷入死循环 
			cin.ignore();    //抛弃当前字符
			cout << "输入有误，请重新输入" << endl; 
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size += 1;

		cout << "添加成功" << endl;
		system("pause");  //请按任意键继续
		system("cls");    //清屏
	}
}

//2.显示联系人
void showPerson(Addressbooks* abs)
{
//判断通讯录是否为0 为0显示记录为空，
	if (abs->m_Size == 0) cout << "当前记录为空" << endl;

//不为0显示信息
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " <<( abs->personArray[i].m_Sex ==1?"男":"女")<< "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");   //按任意键继续
	system("cls");    //清屏
}

//检测联系人是否存在，存在返回具体位置，不存在返回-1
//参数1：通讯录 参数2： 对比姓名
int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{  
		if (abs->personArray[i].m_Name == name) return i;    //找到了，返回下边编号
		
	}
	return -1;    //没找到
}

//3.删除指定联系人
void deletePerson(Addressbooks *abs)
{
	cout << "输入删除联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if ( ret != -1)    //这里abs已经是地址了，因为传入的就是地址，所以不用&abs
	{
		//删除操作
		for (int i = ret; i < abs->m_Size-1; i++)     //注意越界情况，这里要减一
		{
			abs->personArray[i] = abs->personArray[i+1];   //从ret+1开始，数据前移
		}
		abs->m_Size -= 1;
		cout << "删除成功" << endl;
	}
	else cout << "查无此人" << endl;
	system("pause");   //按任意键继续
	system("cls");    //清屏
}

//4.查找联系人
void findperson(Addressbooks* abs)
{
	cout << "请输入查找的联系人" << endl;
	string name;
	cin >> name;
	//判断联系人是否存在
	int ret = isExit(abs, name);

	if(ret!=-1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else cout << "查无此人" << endl;
	system("pause");   //按任意键继续
	system("cls");    //清屏

}

//5.修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入修改的联系人" << endl;
	string name;
	cin >> name;
	//判断联系人是否存在
	int ret = isExit(abs, name);

	if (ret != -1) 
	{
		//修改联系人

		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别

		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (1)
		{
			//如果输入的是1或2可以退出循环，
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cin.clear();   //清除错误标识符    如果sex输入值为字母会陷入死循环 
			cin.ignore();    //抛弃当前字符
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "添加成功" << endl;
		system("pause");  //请按任意键继续
		system("cls");    //清屏

	}
	else cout << "查无此人" << endl;
	system("pause");   //按任意键继续
	system("cls");    //清屏
}

//6.清空
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");   //按任意键继续
	system("cls");    //清屏
}


//菜单界面
void showMenu() 
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
}


int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化当前人员个数
	abs.m_Size = 0;


	int select = 0;  //创建一个用户选择输入变量
	while (1) {
		
		//调用菜单
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:   //1、添加联系人
			addPerson(&abs);      //一定要用地址传递（来修改实参）
			break;
		case 2:  // 2、显示联系人
			showPerson(&abs);
			break;
		case 3: //3、删除联系人
			deletePerson(&abs);
			break;
		case 4:   // 4、查找联系人
			findperson(&abs);
			break;
		case 5:   //5、修改联系人
			modifyPerson(&abs);
				break;
		case 6:    //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:      //0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}