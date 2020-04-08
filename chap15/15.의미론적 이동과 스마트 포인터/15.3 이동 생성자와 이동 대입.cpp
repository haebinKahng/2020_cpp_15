#include <iostream>
#include "pch.h"
//#include "Timer.h"
#include "Resource2.h"
#include "Auto_ptr2.h"
using namespace std;

Auto_ptr<Resource> generateResource()
{
	Auto_ptr<Resource> res(new Resource(100000000));
	// new Resource���� Auto_ptr<Resource>�� �ʱ�ȭ �ϰ� �ִ�
	//���� �޸� �Ҵ� �޾� (��ȣ �� ������ŭ) Resource class�� ���� �ΰ� �װͿ� ���� auto_ptr ������ �ִ� ����  
	
	return res;
	// return ���ָ� �����ϴ� ���� �Ͼ 
}

int main()
{
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL);//disconnect cout from buffer
	//Timer timer;

	{
		Auto_ptr<Resource> main_res;    //Auto_ptr �ϳ� ����
		main_res = generateResource(); //generateresource �޾ƿ��� �ܼ��� �۾�
	}

	cout.rdbuf(orig_buf);
	//cout << timer.elapsed() << endl;

	return 0;

}