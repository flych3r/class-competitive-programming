// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/another-substring-problem-900ce141/

#include <bits/stdc++.h>
using namespace std;
#define PR(x) printf("%d\n",x)
const int MAXSIZE=100002;
#define y1 aasdfasdfasdf


int solve(int N,int K,int A[MAXSIZE])
{
	//write code here
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