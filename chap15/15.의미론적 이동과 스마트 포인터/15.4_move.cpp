#include <vector>
#include <string>
#include <iostream>
#include <utility>  //std::move
#include "pch.h"
#include "Resource2.h"
#include "Auto_ptr2.h"  // copy와 move 둘다 허용 
using namespace std;

template<class T>
void MySwap(T &a, T &b)   //std에 swap 존재한다 
{
	//T tmp = a;       // copy constructor 
	//a = b;           //대입
	//b = tmp;         //assignment

	// move semantics 이용해서 swap 
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}


int main()
{
	//{
	//	Auto_ptr<Resource> res1(new Resource(1000000));

	//	cout << res1.m_ptr << endl;

	//	//Auto_ptr<Resource> res2 = res1;   //copy semantics 사용하고 싶을때
	//	Auto_ptr<Resource> res2 = std::move(res1); // move semantics사용 
	//	// r vlaue로 인식 한다 
	//	// res1의 포인터 null ptr된다. 넘겨준것 res는 넘겨 받은것
	//	// res2는 원래 res1의 주소 그대로 받게된다. 첫번째 res1 주소와 일치하는 값이 출력된다. 
	//	// new Resource에 있는 힙에 있던 메모리를 통째로 넘겨 받은것

	//	cout << res2.m_ptr << endl;
	//	cout << res1.m_ptr << endl;

	//}

	//{
	//	Auto_ptr<Resource> res1(new Resource(3));  //res1 초기화 전부 숫자 3 넣음 
	//	res1->setAll(3);                           // 3을 세개 가지고 있다 

	//	Auto_ptr<Resource> res2(new Resource(5));
	//	res2->setAll(5);

	//	//swap 전 
	//	res1->print();
	//	res2->print();

	//	MySwap(res1, res2);

	//	//swap 후
	//	res1->print();
	//	res2->print();

	//}

	//{
	//	vector<string> v;
	//	string str = "Hello";

	//	v.push_back(str); //&_Val로 되어있다.  L value로 받는다 
	//	// 변수로 받아들인다. 메모리 다른데에 있다 가정 pushback 후에도 사용한다 가정
	//    //즉 copy semantics를 사용한다 

	//    cout << str << endl;
	//	cout << v[0] << endl;   //str에 있던것이 복사된것 
	//

	//	v.push_back(std::move(str)); 
	//	// &&_Val 로 되어있다. r value로 받겠다는 의미

	//	cout << str << endl; // str에 있던것이 move 된것 아무것도 뜨지 않는다 
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