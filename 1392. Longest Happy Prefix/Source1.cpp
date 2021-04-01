#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	string longestPrefix(string s) {
		vector<int>arr(s.length());
		int i = 1, j = 0;
		arr[0] = 0;
		while (i < arr.size()) {
			if (s[i] == s[j]) {
				arr[i] = j + 1;
				++j; ++i;
			}
			else {
				if (j == 0) {
					arr[i] = 0;
					++i;
				}
				else {
					j = arr[j - 1];
				}
			}
		}
		return s.substr(0, arr.back());
	}
};
int main()
{
	string s;
	cin >> s;
	Solution obj;
	cout << obj.longestPrefix(s);
}