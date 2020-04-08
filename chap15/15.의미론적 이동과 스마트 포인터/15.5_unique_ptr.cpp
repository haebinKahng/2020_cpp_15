#include <iostream>
#include "pch.h"
//#include <memory>
#include "Resource2.h"
#include "Auto_ptr2.h"
using namespace std;

auto doSomething()
{
	//1 res1을 make unique로 만들고 이것을 return하는 방법
	auto res1 = make_unique<Resource>(5);
	return res1;

	//2 
    //return unique_ptr<Resource>(new Resource(5));

	//3 make unique로 바로 return 내부적으로 move semantics사용 소유권이 바로 넘어간다 copy 호출 하지 않는다 
	//return make_unique<Resource>(5);
}

// uniqueptr의 resference를 받고 있는 함수 
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
	//	//Resource *res = new Resource(1000000);   //new로 동적할당 받는다. 


	//	//delete res;  //소멸자 실행
	//	// 만약 early return or throw인 경우 delete 못한다면 
	//	// 소멸자 실행 되지 않기 때문에 destructor 실행 안되어서 
	//	// 메모리 leak이 발생하였고 결국 operating system이 뒤처리 한다. 
	//
	//	unique_ptr<Resource> res(new Resource(1000000));
	//
	//}

	//{
	//	unique_ptr<int> upi(new int);  //기본 자료형에도 사용 가능하다 

	//	//unique_ptr<Resource> res1(new Resource(5));

	//	// 조금 더 추천하는 방법 make unique 사용 
	//	//auto res1 = make_unique<Resource>(5);

	//	// 동적 할당된 메모리에 포인터를 집어넣을 수 있다 
	//	// 그 예시로 ptr을 안에 넣어서 소멸시킬 수 있다 
	//	   //auto *ptr = new Resource(5);
	//	   //unique_ptr<Resource> res1(ptr);
	//   
	//	auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();

	//	unique_ptr<Resource> res2;
	//	// nullptr인지 아닌지 출력해준다 
	//	// res1은 확실히 초기화 되었다. 그러므로 nullptr 아니다
	//	// res2는 갖고있는게 없다. nullptr이 들어가면 false가 뜨니 0이뜰것 
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	// res2 = res1; 오류발생! 복사 못한다  

	//	res2 = move(res1);
	//	// 소유권을 넘겨버리면 원래 가지고 있던 데는 소유권을 상실한다.
	//	// res2만 가지게 된다. 소유권이 unique. 즉 res1은 소유권 잃고 nullptr이다. res2는 소유권 얻은 상태 
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	//res2에서 55555 출력될것, move 됐으니 resource destroyed는 한번만 된다. 
	//	//res2만 unique 하게 소유권 가지고 있는 포인터 이므로 
	//	if (res1 != nullptr) res1->print();  //uniqueptr도 -> operator사용 가능 
	//	if (res2 != nullptr) res2->print();  
	//	//(*res2).print(); dereferencing operator도 operator overloading이 되어 있기 때문에 필요에 따라 사용 가능  


	//}

	//{
	//	auto res1 = make_unique<Resource>(5);
	//	res1->setAll(1);  //원소에 다 1을 넣는다는 의미 
	//	res1->print();    //1 다섯개 출력 

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;


	//	//파라미터를 집어 넣는 경우 
	//	//res1 = doSomething2(std::move(res1));  // ㅣ-value reference를 넣고 있다 
	//	doSomething2(res1.get());// get함수는 Resource 타입의 유니크 포인터가 내부적으로 가지고 있는 리소스의 포인터를 가져온다. 
	//	cout << boolalpha;
	//    cout << static_cast<bool>(res1) << endl;
	//	res1->print();  // doSo 함수 밖으로 나왔을 때에도 10 10 10 10 10 출력된다.
	//}

	{
		Resource *res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res); // res포인터에 대한 소유권을 두군데 res1,2에 준 경우 
		//이러면 안된다 


		delete res;  // 이미 unique 포인터에서 지웠는데 이건 지운걸 또지우는 것. 이러지 말자 

	}

	return 0;
}