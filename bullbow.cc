#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {

	public:

    string getHint(string secret, string guess) {
    
            unordered_map<char,vector<int>> s_table, g_table;
    
            int s_len = secret.size();
    
            int g_len = guess.size();
    
            int num_a = 0, num_b = 0;
    
            string result;
    
            for (int i=0; i<s_len; i++) {
	    
	                s_table[secret[i]].push_back(i);
	    
	            }
    
            for (int i=0; i<g_len; i++) {
	    
	                g_table[guess[i]].push_back(i);
	    
	            }
    
            for (auto ele:g_table) {
	    
	                auto s_ele = s_table.find(ele.first);
	    
	                if (s_ele != s_table.end()) {
			
			                auto s_pos = s_ele->second;
			
			                auto g_pos = ele.second;
			
			                int count_a=0;
			
			                for (auto itr=g_pos.begin(); itr!= g_pos.end(); ++itr) {
					
					                    if (find(s_pos.begin(),s_pos.end(),*itr) != s_pos.end()) {
							    
							                            num_a++;
							    
							                            count_a++;
							    
							                        }
					
					                }
			
			                if (!g_pos.empty()) {
					
					                    num_b += (s_pos.size() < g_pos.size()?s_pos.size():g_pos.size()) - count_a;
					
					                }
			
			            }
	    
	            }
    
            result += to_string(num_a) + "A" + to_string(num_b) + "B";
    
            return result;
    
        }

    

};

int main()
{
	string secret = "1122";
	string guess = "1222";
	Solution ss;
	string result;
	result = ss.getHint(secret, guess);
	cout << result << endl;
}
