#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangleCount(vector<int> &vec)
{
	if(vec.empty())
		return 0;

	sort(vec.begin(), vec.end());

	int result = 0;

	for(int i = vec.size() - 1; i >= 2; --i)
	{
		int l = 0, r = i - 1;
		while(l < r)
		{
			if(vec[i] < vec[l] + vec[r])
			{
				result += r - l;
				r--;
			}else
			{
				l++;
			}
		}
	}

	return result;
}

int main()
{
	vector<int> vec = {2,2,3,4};
	int result = triangleCount(vec);
	cout << result << endl;
	return 0;
}
