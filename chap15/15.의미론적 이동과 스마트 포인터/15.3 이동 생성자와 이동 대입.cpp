#include <iostream>
#include "pch.h"
//#include "Timer.h"
#include "Resource2.h"
#include "Auto_ptr2.h"
using namespace std;

Auto_ptr<Resource> generateResource()
{
	Auto_ptr<Resource> res(new Resource(100000000));
	// new Resource에서 Auto_ptr<Resource>를 초기화 하고 있다
	//동적 메모리 할당 받아 (괄호 안 갯수만큼) Resource class에 놓어 두고 그것에 대한 auto_ptr 가지고 있는 구조  
	
	return res;
	// return 해주면 복사하는 과정 일어남 
}

int main()
{
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL);//disconnect cout from buffer
	//Timer timer;

	{
		Auto_ptr<Resource> main_res;    //Auto_ptr 하나 선언
		main_res = generateResource(); //generateresource 받아오는 단순한 작업
	}

	cout.rdbuf(orig_buf);
	//cout << timer.elapsed() << endl;

	return 0;

}