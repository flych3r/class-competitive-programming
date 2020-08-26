// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/another-substring-problem-900ce141/

#include <bits/stdc++.h>
using namespace std;
#define PR(x) printf("%d\n",x)
const int MAXSIZE=100002;
#define y1 aasdfasdfasdf

typedef long long ll;

int solve(int N,int K,int A[MAXSIZE])
{
	int table[K + 1];
	for(size_t i = 1; i <= K; i++)
	{
		table[i] = 0;
	}
	ll min_distinct = LLONG_MAX;

	ll p = 0, c = 0;

	for (ll i = 0; i < N; i++)
	{
		table[A[i]]++;

		if(table[A[i]] <= 1) {
			c++;
		}

		if(c == K) {
			while(table[A[p]] > 1) {
				if(table[A[p]] > 1) {
					table[A[p]] -= 1;
				}

				p++;
			}

			min_distinct = min(min_distinct, i - p + 1);
		}
	}

	return min_distinct;
}

int main()
{
	int i,j,n,test,k;
	int a[MAXSIZE];

	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",solve(n,k,a));
	}

	return 0;
}