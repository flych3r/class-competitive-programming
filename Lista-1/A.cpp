#include <iostream>

using namespace std;

int main()
{
    int t, m, n;
    cin >> t;
    while(t)
    {
        cin >> n >> m;
        cout << (n/3) * (m/3) << endl;
        t--;
    }
}
