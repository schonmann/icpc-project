#include <limits>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct res{
	int i;
	int j;
	int sum;
} RES;

RES max_sub(int a[], int n)
{
	int min = numeric_limits<int>::min();
	int i;
	
	RES max, max_cur, *maxsub;
	
	maxsub = new res[n];
	max.sum = min;
	max_cur = max;
	
	for(int i = 0; i < n; i++)
	{
		if(max_cur.sum < 0){
			max_cur.sum = a[i];
			max_cur.i = i;
			max_cur.j = i;
		}
		else {
			max_cur.sum += a[i];
			max_cur.j = i;
		}
		if(max_cur.sum > max.sum)
		{
			max = max_cur;
		}
		
		maxsub[i] = max;
	}
	
	return maxsub[n-1];
}

int main(void)
{
	int t,n,x;
	while(cin >> n, n) {
		int array[n];
		
		for(int i = 0; i < n; i++)
			cin >> array[i];
		
		RES R = max_sub(array,n);
		
		int soma = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(array[i] >= 0)
			{
				soma+=array[i];
			}
		}
		
		if(R.sum > 0) {
			cout << "The maximum winning streak is " << R.sum << "." << endl;
		} else {
			cout << "Losing streak." << endl;
		}
	}
	
	return 0;
}

