#include <iostream>
#include <string>

using namespace std;

int main()
{
	int	t, n, l, h, i = 1;
	cin >> t;
	while(i <= t)
	{
		cin >> n;
		int w[n];
		for(int i = 0; i < n; i++)
			cin >> w[i];
		l = h = 0;
		for(int i = 0; i < n - 1; i++)
		{
			if(w[i] < w[i + 1])
				h++;
			else if(w[i] > w[i + 1])
				l++;
		}
		cout << "Case " << i << ": " << h << " " << l << endl;
		i++;
	}
	return 0;
}