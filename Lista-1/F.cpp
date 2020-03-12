#include <iostream>
#include <string>

using namespace std;

int main()
{
	string bitString;
	int t, i, j, _min, _max, r = 1;
	while(cin >> bitString)
	{
		if(bitString.length() == 0)
			break;
		cin >> t;
		cout << "Case " << r << ":" << endl;
 		while(t)
		{
			t--;
			cin >> i >> j;
			_min = min(i, j);
			_max = max(i, j);
			bool yes = true;
			for(int k = _min; k < _max; k++)
			{
				if(bitString[k] != bitString[k + 1])
				{
					yes = false;
					break;
				}
			}
			if(yes)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			
		}
		r++;
	}
	return 0;
}