#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{ 3��32��321 }�����ӡ���������������ųɵ���С����Ϊ321323��

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

void TestFunc(){
	vector<int> array = {2,23,212};
	Solution s;
	string temp;
	temp = s.PrintMinNumber(array);
	cout << temp << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}