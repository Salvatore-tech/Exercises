#include <iostream>
#include <vector>
using namespace std;

//-3   2 -4 5 8 10 -7 1
// Left = 3
// Right = 5
// Max = 23 

void maxSubr(int *left_index, int *right_index, vector<int>& v)
{  
    int max = INT_MIN;
    int temp = 0;
	for(int i=0; i<v.size()-2; i++)
	{    
		temp = v[i];
		for (int j = i; j < v.size() - 2; j++)
		{
			temp=temp+v[j+1];
			if (max < temp)
			{
				max=temp;
                *left_index=i;
                *right_index=j+1;
			}
		}
	}
	cout << max << endl;
}


int main()
{
	int left = 0;
	int right = 7;
	vector<int> v;
	v.push_back(-3);
	v.push_back(2);
	v.push_back(-4);
	v.push_back(5);
	v.push_back(8);
	v.push_back(10);
	v.push_back(-7);
	v.push_back(1);
	for (auto& i : v)
		cout << i << endl;
	maxSubr(&left, &right, v);
	cout << "Left index: " << left << "\tRight index: " << right << endl;


}