#include<iostream>
#include<string>
#include<vector>

using namespace std;

//0285289430826
//2
//0 2
//2 3
string solution(vector<int>& c, string& s){
	int slen = s.size();
	for (int i = 0; i < slen; i++){
		s[i] = c[s[i] - '0'] + '0';
	}
	return s;
}

int main()
{
	string s;
	cin >> s;

	vector<int> mp(10, -1);
	for (int i = 0; i <= 9; i++){
		mp[i] = i;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int temp, num;
		cin >> temp >> num;
		for (int j = 0; j <= 9; j++){
			if (mp[j] == temp){
				mp[j] = num;
			}
		}
	}

	cout << solution(mp, s) << endl;
	return 0;
}
