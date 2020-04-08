#include "pch.h"
#include <iostream>
#include <memory>
#include "Resource2.h"
#include "Auto_ptr2.h"
using namespace std;


int main()
{
    //1. Resource를 포인터로 만들고, shared pointer를 ptr 포인터에 넣으면서 초기화 하는 방법 
	Resource *res = new Resource(3);
	res->setAll(1);
	shared_ptr<Resource> ptr1(res);

	//2. make_shared 사용 
	//auto ptr1 = make_shared<Resource>(3);
	//ptr1->setAll(1)

	ptr1->print();


	{
		shared_ptr<Resource> ptr2(ptr1);

		ptr2->setAll(3);
		ptr2->print();

		cout << "Going out of the block" << endl;


	}
}
