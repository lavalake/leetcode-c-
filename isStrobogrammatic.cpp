#include <string>
//#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;
class Solution {
	public:
		bool isStrobogrammtic(string num) {
			map<char,char> num_map = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
			int r = num.size()-1;
			int l = 0;
			while (l <= r) {
				if (num_map.find(num[l]) == num_map.end() || num_map.find(num[r]) == num_map.end()) return false;
				if (num_map[num[l]] != num[r]) return false;
			}
			return true;
		}
};

int main ()
{
	Solution s;
	string test = "1";
	bool result;
	result = s.isStrobogrammtic(test);
	cout << "return: " << result << endl;
	return 0;
}
