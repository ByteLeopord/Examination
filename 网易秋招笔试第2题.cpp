/*
input: 1行 + n行
1. 方阵的大小n
2. 每行数组数据

output: n 行 每行2个数
行列相加最大的坐标x, y
每计算1次需要将相加的行列去掉，重新计算坐标
*/
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ans;

vector<int> rowsum(vector<vector<int>>& num){
	int len = num.size();
	vector<int> res;
	for (int i = 0; i < len; i++){
		int sum = 0;
		for (int j = 0; j < len; j++){
			sum += num[i][j];
		}
		res.push_back(sum);
	}
	return res;
}
vector<int> colsum(vector<vector<int>>& num){
	int len = num.size();
	vector<int> res;
	for (int i = 0; i < len; i++){
		int sum = 0;
		for (int j = 0; j < len; j++){
			sum += num[j][i];
		}
		res.push_back(sum);
	}
	return res;
}
vector<int> getrc(vector<vector<int>>& num, vector<int>& row, vector<int>& col){
	int len1 = row.size();
	int len2 = col.size();
	int maxsum = 0;
	int jump1 = 0, jump2 = 0;
	int ri, rj;
	vector<int> res(2, -1);
	for (int i = 0; i < len1; i++){
		if (row[i] == -1){
			jump1++;
			continue;
		}
		for (int j = 0; j < len2; j++){
			if (col[j] == -1){
				jump2++;
				continue;
			}
			int sum = row[i] + col[j] - num[j][i];
			if (sum > maxsum){
				maxsum = sum;
				res[0] = j - jump2 + 1;
				res[1] = i - jump1 + 1;
				ri = i;
				rj = j;
			}
		}
	}
	row[ri] = -1;
	col[rj] = -1;
	return res;
}

void solution(vector<vector<int>>& num){
	int cnt = num.size();
	//vector<vector<int>> res(cnt, vector<int>(2, 0));
	vector<int> rowarr = rowsum(num);
	vector<int> colarr = colsum(num);
	while (cnt > 0){
		vector<int> temp = getrc(num, rowarr, colarr);
		ans.push_back(temp);
		cnt--;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> num(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> num[i][j];
		}
	}
	//vector<vector<int>> res = solution(num);
	solution(num);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
