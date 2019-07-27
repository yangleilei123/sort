#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &q, int l, int r)
{
	if(l >= r)
		return;
	int mid = (l + r) / 2;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	static vector<int> w;
	w.clear();

	int i = l, j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])	w.push_back(q[i++]);
		else	w.push_back(q[j++]);
	while(i <= mid)	w.push_back(q[i++]);
	while(j <= r)	w.push_back(q[j++]);
	for(i = 0; i < w.size(); i++)
		q[i + l] = w[i];
}

void quick_sort(vector<int>& q, int l, int r)
{
	if(l >= r)	return;
	int i = l - 1, j = r + 1, x = q[(l + r) / 2];
	while(i < j)
	{
		do i++; while(q[i] < x);
		do j--; while(q[j] > x);
		if(i < j)	swap(q[i], q[j]);
		else	quick_sort(q, l, j), quick_sort(q, j + 1, r);
	}
}

void insert_sort(vector<int>& q)
{
	int len = q.size();
	for(int i = 1; i < len; i++)
	{
		int tmp = q[i];
		for(int j = i - 1; j >= 0; j--)
		{
			if(q[j] > tmp)
			{
				q[j + 1] = q[j];
				q[j] = tmp;
			}
			else
				break;
		}
	}
}
int main()
{
	int a[5] = {5,4,3,2,1};
	vector<int> nums(a, a + 5);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	//merge_sort(nums, 0, nums.size() - 1);
	//quick_sort(nums, 0, nums.size() - 1);
	insert_sort(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}