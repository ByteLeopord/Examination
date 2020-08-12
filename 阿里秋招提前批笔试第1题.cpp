#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ans;

void solution(vector<int>& num, int m, int cnt, int start, vector<int>& temp){
	if (cnt == m)
	{
		ans.push_back(temp);
		return;
	}
	for (int i = start; i < num.size(); i++)
	{
		temp[cnt] = num[i];
		solution(num, m, cnt+1, i+1, temp);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> num;
	for (int i = 0; i < n; i++){
		num.push_back(i + 1);
	}
	vector<int> res(m, -1);
	solution(num, m, 0, 0, res);
	int len = ans.size();
	for (int i = 0; i < len; i++){
		int len1 = ans[i].size();
		for (int j = 0; j < len1; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
