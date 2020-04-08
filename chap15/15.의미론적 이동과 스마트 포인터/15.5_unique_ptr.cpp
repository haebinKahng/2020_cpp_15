#include <iostream>
#include "pch.h"
//#include <memory>
#include "Resource2.h"
#include "Auto_ptr2.h"
using namespace std;

auto doSomething()
{
	//1 res1�� make unique�� ����� �̰��� return�ϴ� ���
	auto res1 = make_unique<Resource>(5);
	return res1;

	//2 
    //return unique_ptr<Resource>(new Resource(5));

	//3 make unique�� �ٷ� return ���������� move semantics��� �������� �ٷ� �Ѿ�� copy ȣ�� ���� �ʴ´� 
	//return make_unique<Resource>(5);
}

// uniqueptr�� resference�� �ް� �ִ� �Լ� 
//auto doSomething2(unique_ptr<Resource> res)
//void doSomething2(unique_ptr<Resource> & res)

void doSomething2(Resource * res)
{
	res->setAll(100);
	res->print();

	//return res;
}


int main()
{
	//{
	//	//Resource *res = new Resource(1000000);   //new�� �����Ҵ� �޴´�. 


	//	//delete res;  //�Ҹ��� ����
	//	// ���� early return or throw�� ��� delete ���Ѵٸ� 
	//	// �Ҹ��� ���� ���� �ʱ� ������ destructor ���� �ȵǾ 
	//	// �޸� leak�� �߻��Ͽ��� �ᱹ operating system�� ��ó�� �Ѵ�. 
	//
	//	unique_ptr<Resource> res(new Resource(1000000));
	//
	//}

	//{
	//	unique_ptr<int> upi(new int);  //�⺻ �ڷ������� ��� �����ϴ� 

	//	//unique_ptr<Resource> res1(new Resource(5));

	//	// ���� �� ��õ�ϴ� ��� make unique ��� 
	//	//auto res1 = make_unique<Resource>(5);

	//	// ���� �Ҵ�� �޸𸮿� �����͸� ������� �� �ִ� 
	//	// �� ���÷� ptr�� �ȿ� �־ �Ҹ��ų �� �ִ� 
	//	   //auto *ptr = new Resource(5);
	//	   //unique_ptr<Resource> res1(ptr);
	//   
	//	auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();

	//	unique_ptr<Resource> res2;
	//	// nullptr���� �ƴ��� ������ش� 
	//	// res1�� Ȯ���� �ʱ�ȭ �Ǿ���. �׷��Ƿ� nullptr �ƴϴ�
	//	// res2�� �����ִ°� ����. nullptr�� ���� false�� �ߴ� 0�̶�� 
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	// res2 = res1; �����߻�! ���� ���Ѵ�  

	//	res2 = move(res1);
	//	// �������� �Ѱܹ����� ���� ������ �ִ� ���� �������� ����Ѵ�.
	//	// res2�� ������ �ȴ�. �������� unique. �� res1�� ������ �Ұ� nullptr�̴�. res2�� ������ ���� ���� 
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	//res2���� 55555 ��µɰ�, move ������ resource destroyed�� �ѹ��� �ȴ�. 
	//	//res2�� unique �ϰ� ������ ������ �ִ� ������ �̹Ƿ� 
	//	if (res1 != nullptr) res1->print();  //uniqueptr�� -> operator��� ���� 
	//	if (res2 != nullptr) res2->print();  
	//	//(*res2).print(); dereferencing operator�� operator overloading�� �Ǿ� �ֱ� ������ �ʿ信 ���� ��� ����  


	//}

	//{
	//	auto res1 = make_unique<Resource>(5);
	//	res1->setAll(1);  //���ҿ� �� 1�� �ִ´ٴ� �ǹ� 
	//	res1->print();    //1 �ټ��� ��� 

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;


	//	//�Ķ���͸� ���� �ִ� ��� 
	//	//res1 = doSomething2(std::move(res1));  // ��-value reference�� �ְ� �ִ� 
	//	doSomething2(res1.get());// get�Լ��� Resource Ÿ���� ����ũ �����Ͱ� ���������� ������ �ִ� ���ҽ��� �����͸� �����´�. 
	//	cout << boolalpha;
	//    cout << static_cast<bool>(res1) << endl;
	//	res1->print();  // doSo �Լ� ������ ������ ������ 10 10 10 10 10 ��µȴ�.
	//}

	{
		Resource *res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res); // res�����Ϳ� ���� �������� �α��� res1,2�� �� ��� 
		//�̷��� �ȵȴ� 


		delete res;  // �̹� unique �����Ϳ��� �����µ� �̰� ����� ������� ��. �̷��� ���� 

	}

	return 0;
}