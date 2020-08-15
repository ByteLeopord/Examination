/*
长度为s的木棍，对半切最少的次数，每次切割可得到相应的价值，使价值相加大于等于指定m值
输出次数
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int solve(int s, int m){
	queue<int> q;
	q.push(s);
	int cnt = 0;
	vector<long long> res(s + 1, 1);
	res[0] = s;
	while (!q.empty()){
		int len = q.size();
		for (int i = 0; i < len; i++){
			int num = q.front();
			q.pop();
			cnt++;
			res[cnt] = (num - num / 2)*(num / 2) + res[cnt - 1];;
			if (res[cnt] >= m) 
				return cnt;
			q.push(num / 2);
			q.push(num - num / 2);
		}
	}
	return -1;
}

int main() {
	int s, m;
	cin >> s >> m;
	cout << solve(s, m) << endl;
	return 0;
}
