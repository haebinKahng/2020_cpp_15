#include <vector>
#include <string>
#include <iostream>
#include <utility>  //std::move
#include "pch.h"
#include "Resource2.h"
#include "Auto_ptr2.h"  // copy�� move �Ѵ� ��� 
using namespace std;

template<class T>
void MySwap(T &a, T &b)   //std�� swap �����Ѵ� 
{
	//T tmp = a;       // copy constructor 
	//a = b;           //����
	//b = tmp;         //assignment

	// move semantics �̿��ؼ� swap 
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}


int main()
{
	//{
	//	Auto_ptr<Resource> res1(new Resource(1000000));

	//	cout << res1.m_ptr << endl;

	//	//Auto_ptr<Resource> res2 = res1;   //copy semantics ����ϰ� ������
	//	Auto_ptr<Resource> res2 = std::move(res1); // move semantics��� 
	//	// r vlaue�� �ν� �Ѵ� 
	//	// res1�� ������ null ptr�ȴ�. �Ѱ��ذ� res�� �Ѱ� ������
	//	// res2�� ���� res1�� �ּ� �״�� �ްԵȴ�. ù��° res1 �ּҿ� ��ġ�ϴ� ���� ��µȴ�. 
	//	// new Resource�� �ִ� ���� �ִ� �޸𸮸� ��°�� �Ѱ� ������

	//	cout << res2.m_ptr << endl;
	//	cout << res1.m_ptr << endl;

	//}

	//{
	//	Auto_ptr<Resource> res1(new Resource(3));  //res1 �ʱ�ȭ ���� ���� 3 ���� 
	//	res1->setAll(3);                           // 3�� ���� ������ �ִ� 

	//	Auto_ptr<Resource> res2(new Resource(5));
	//	res2->setAll(5);

	//	//swap �� 
	//	res1->print();
	//	res2->print();

	//	MySwap(res1, res2);

	//	//swap ��
	//	res1->print();
	//	res2->print();

	//}

	//{
	//	vector<string> v;
	//	string str = "Hello";

	//	v.push_back(str); //&_Val�� �Ǿ��ִ�.  L value�� �޴´� 
	//	// ������ �޾Ƶ��δ�. �޸� �ٸ����� �ִ� ���� pushback �Ŀ��� ����Ѵ� ����
	//    //�� copy semantics�� ����Ѵ� 

	//    cout << str << endl;
	//	cout << v[0] << endl;   //str�� �ִ����� ����Ȱ� 
	//

	//	v.push_back(std::move(str)); 
	//	// &&_Val �� �Ǿ��ִ�. r value�� �ްڴٴ� �ǹ�

	//	cout << str << endl; // str�� �ִ����� move �Ȱ� �ƹ��͵� ���� �ʴ´� 
	//	cout << v[0] << " " << v[1] << endl; 
	//}

	{
		string x{ "abc" };
		string y{ "de" };

		cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;

		MySwap(x, y);

		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;

	}
	return 0;
}