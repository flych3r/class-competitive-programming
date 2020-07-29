// https://www.hackerearth.com/pt-br/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/submissions/

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

vector<vector<int> > queue_and_stack (vector<int> A) {
    queue<int> primes;
    stack<int> composites;
    int i;

    for (const int &e: A)
    {
        if (isPrime(e))
        {
            primes.push(e);
        }
        else
        {
            composites.push(e);
        }
    }

    vector<int> p(primes.size());
    vector<int> c(composites.size());

    i = 0;
    while (!primes.empty())
    {
        p[i] = primes.front();
        primes.pop();
        i++;
    }
    i = 0;
    while (!composites.empty())
    {
        c[i] = composites.top();
        composites.pop();
        i++;
    }

    return vector<vector<int>> {p, c};
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
    	cin >> A[i_A];
    }

    vector<vector<int> > out_;
    out_ = queue_and_stack(A);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_][0];
    	for(int j_out_=1; j_out_<out_[i_out_].size(); j_out_++)
    	{
    		cout << " " << out_[i_out_][j_out_];
    	}
    	cout << "\n";
    }
}
