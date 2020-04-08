#include <iostream>
#include "pch.h"
#include "Resource1.h"
#include "Auto_ptr1.h"

using namespace std;

/*
void dosomething()
{
	Resource *res = new Resource;  //동적할당 받아서 가져오기

	// if (true) return; //early return

	if (true)
	{
		delete res;
		return;
	}
	 
	delete res;  //new 한 곳에서 delete 해줘야 한다 RAII 개념 
	return;
}
*/
void dosomething2()
{
	try
	{
		// Resource *res = new Resource;  //dull pointer
		Auto_ptr<Resource> res = new Resource; //smart pointer delete 필요 없다 
		//Auto_ptr<Resource> res (new Resource); //문법상 이것이 더 깔끔 assignment 아니고 초기화니까 바로 생성자의 파라미터로 넣는다. 
		
		return;   //early return일 때도 깔끔하게 반납 된다. 
		
		if (true)
		{
			throw -1; //exception
		}
		// Auto ptr로 변환결과 ture든 false든 메모리 깔끔하게 반납된다. 
		// Resource constr~ destroy~ 둘다 나옴 
		//delete res;    //throw 하면서 동시에 delete 할 수 없다 
	}                  //실행결과 resource constructed만 나옴 destroyed 나오지 않음 
	
	catch (...)
	{

	}
}


int main()
{
	//dosomething2();

	{
		Auto_ptr<Resource> res1(new Resource); // int i; int *ptr1(&i); int *ptr2 = nullptr;와 같은 구조 
		Auto_ptr<Resource> res2;     //메모리 갖고있지 않고 포인터로만 존재, res1은 초기화 되었다.  
		
		cout << boolalpha;
		cout << res1.m_ptr << endl;  //유효한 주소 나움
		cout << res2.m_ptr << endl;  // nullptr이므로 0000나옴   

		res2 = res1;                //assignment 해줌 대입 
		// default assignment operator는 복사만 해준다. 내부적으로 auto_ptr가진 멤버들 복사해준다        
		// 포인터 하나 복사해준다. res1 res2 둘 다 new Resource의 주소 된다. 
		// 괄호 나가면서 res1도 destroy해서 메모리 없어졌는데 res2도 이미 없어진 메모리 destroy하려고 한다. 
		//즉 new resource 메모리에 대한 소유권을 res1 res2 둘다 갖게 된다.run time error!
		//"move semantics"를 구현한 것이다!!!!!!!!!!!!!

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

	}
}