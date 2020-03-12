#include <iostream>
#include <string>

using namespace std;

int main()
{
	int	t, a, m = 0;
	string op;
	cin >> t;
	while(t)
	{
		cin >> op;
		if(op[0] == 'd')
		{
			cin >> a;
			m += a;
		}
		else
			cout << m << endl;
		t--;
	}
	return 0;
}