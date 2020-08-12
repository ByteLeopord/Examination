#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

string DecToBinary(const string &dec)
{
	int i, len, sta;
	stack<int> s;

	len = dec.length();
	int *num = new int[len + 1];

	for (i = 0; i<len; ++i)
	{
		num[i] = dec[i] - '0';
	}

	while (true)
	{
		sta = len;
		for (i = 0; i<len; ++i)
		{
			if (num[i] != 0)
			{
				sta = i;
				break;
			}
		}

		if (sta == len) break;

		int remain = 0;
		for (i = sta; i<len; ++i)
		{
			remain = remain * 10 + num[i];
			num[i] = remain / 2;
			remain = remain % 2;
		}
		s.push(remain);
	}

	string ans;
	while (!s.empty())
	{
		ans += s.top() + '0';
		s.pop();
	}
	if (ans.length() == 0)
		ans = "0";

	delete[] num;
	return ans;
}

string BinaryToDec(string& str){
	int len = str.size();
	string res;
	for (int i = 0; i < len; i++){
		if (str[i] == '0') continue;

	}
	return res;
}

string substact(string a, string b) // 默认的就是 s1 > s2
{
	//1.翻转
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	//2.按位做减法
	for (int i = 0; i < b.size(); i++)
	{
		if (a[i] >= b[i])
		{
			a[i] = a[i] - b[i] + '0';
		}
		else //借位
		{
			int k = 1;
			while (a[i + k] == '0')  //下一位如果是0.就变为9
			{
				a[i + k] = '9';
				k++;
			}

			//这里可以保证i + k这一位上不是0

			// 所以要借位了
			a[i + k] = a[i + k] - '1' + '0'; //a[i+k] - '1'以后是int型，要转化出字符，所以+'0'

			//  a[i] =  (整数） - （整数） + '0’
			a[i] = (a[i] - '0' + 10) - (b[i] - '0') + '0';
		}
	}
	reverse(a.begin(), a.end());
	if (a.find_first_not_of('0') == string::npos) //找不到非0，也就是全是0 所以return"0"
		return "0";
	return a.substr(a.find_first_not_of('0')); // 如果不加上面的判断，这里会出现越界。因为找不到非0数
}

string solution(string& str1){
	string num = DecToBinary(str1);
	string sub = "1";
	string numsub = substact(str1, sub);
	numsub = DecToBinary(numsub);
	
	int len1 = num.size();
	int len2 = numsub.size();
	if (len1 > len2)
		return numsub;
		//return BinaryToDec(numsub);
	int mark = 0;
	for (int i = 0; i < len1; i++){
		if (num[i] != numsub[i]){
			mark = i;
			break;
		}
	}
	for (int i = mark + 1; i < len1; i++){
		numsub[i] = '1';
	}
	return numsub;
	//return BinaryToDec(numsub);
}

int main() {
	int T;
	cin >> T;
	vector<string> res;
	for (int i = 0; i < T; i++){
		string num;
		cin >> num;
		res.push_back(solution(num));
	}

	for (auto it : res){
		cout << it << endl;
	}

	system("pause");
	return 0;
}
