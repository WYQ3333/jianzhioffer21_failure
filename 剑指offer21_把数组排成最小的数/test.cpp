#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{ 3，32，321 }，则打印出这三个数字能排成的最小数字为321323。

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0) return "";
		sort(numbers.begin(), numbers.end(), cmp);
		string res;
		for (int i = 0; i < len; i++){
			res += to_string(numbers[i]);
		}
		return res;
	}
	static bool cmp(int a, int b){
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};

class Solution1 {
public:
	string PrintMinNumber(vector<int> numbers) {
		string res;
		// check param
		if (numbers.empty())
			return res;
		int Size = numbers.size();
		vector<string> nums(Size);
		for (int i = 0; i<Size; ++i){
			int n = numbers[i];
			while (n / 10){
				char p = n % 10 + '0';
				nums[i].push_back(p);
				n /= 10;
			}
			char h = n % 10 + '0';
			nums[i].push_back(h);
			reverse(nums[i].begin(), nums[i].end());
		}
		// get longest num size
		int max = INT_MIN;
		for (int i = 0; i<Size; ++i){
			int tmp = nums[i].size();
			if (max<tmp)
				max = tmp;
		}

		// sort
		vector<vector<string>> R(10);
		for (int j = 0; j<max; ++j){
			for (int i = 0; i<Size; ++i){
				// in 
				if (nums[i].size()<j + 1){
					char tmp = nums[i].back() - '0';
					R[tmp].push_back(nums[i]);
					continue;
				}
				int indx = nums[i][j] - '0';
				R[indx].push_back(nums[i]);

			}
			//out
			nums.clear();
			for (int k = 0; k<10; ++k){
				int length = R[k].size();
				for (int m = 0; m<length; ++m){
					nums.push_back(R[k][m]);
					// clear R
					R[k][m].clear();
				}
				R[k].clear();
			}
		}

		// return 
		for (int i = 0; i<Size; ++i){
			res.insert(res.end(), nums[i].begin(), nums[i].end());
		}
		return res;
	}
};

void TestFunc(){
	vector<int> array = {2,23,212};
	Solution1 s;
	string temp;
	temp = s.PrintMinNumber(array);
	cout << temp << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}