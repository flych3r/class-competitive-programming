#include <iostream>
#include <string>

using namespace std;

int main()
{
	long int t, f, space, animals, value, budget;
	cin >> t;
	while(t)
	{
		cin >> f;
		budget = 0;
		while(f)
		{
			cin >> space >> animals >> value;
			budget += space * value;
			f--;
		}
		cout << budget << endl;
		t--;
	}
	return 0;
}