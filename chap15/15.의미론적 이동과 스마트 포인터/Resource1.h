#include <iostream>
using namespace std;


class Resource
{
public:
	int m_data[100];

public:
	Resource()
	{
		cout << "Resource constructed " << endl;
	}

	~Resource()
	{
		cout << "Resource destroyed" << endl;
	}
};