#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int n, vector<int>& nums){
	vector<int> mark(nums.begin(), nums.end());
	sort(nums.begin(), nums.end());
	int len = n;
	int mid1 = nums[len / 2];
	int mid2 = nums[len / 2 - 1];
	for (int i = 0; i < n; i++){
		int temp = mark[i];
		if (temp < mid2){
			cout << mid1 << endl;
		}
		else{
			cout << mid2 << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	solve(n, nums);
	system("pause");
	return 0;
}
