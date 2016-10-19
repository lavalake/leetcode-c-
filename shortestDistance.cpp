#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {

	public:

    int shortestDistance(vector<string>& words, string word1, string word2) {
    
            vector<int> index1;
    
            vector<int> index2;
    
            int len = words.size();
    
            int dist = 0;
    
            int len1 = 0, len2 = 0;
    
            int mn = 0;
    
            for (int i=0; i<len; i++) {
	    
	                
	    
	                if (words[i] == word1) index1.push_back(i);
	    
	                if (words[i] == word2) index2.push_back(i);
	    
	            }
    
            dist = len - 1;
    
            len1 = index1.size() - 1;
    
            len2 = index2.size() - 1;
    
            
    
            while (len1>=0 && len2>=0) {
	    
	                if (index1[len1] > index2[len2]) {
			
			                if (dist > (index1[len1] - index2[len2])) {
					
					                    dist = index1[len1] - index2[len2];
					
					                    
					
					                }
			
			                len1--;
			
			            }
	    
	                else if (index2[len2] > index1[len1]) {
					int ds = index2[len2] - index1[len1];
			
			                if (dist > ds) {
					
					                    dist = ds;
					
					                    
					
					                }
			
			                len2--;
			
			            }
	    
	            }
    
            return dist;
    
        }

};
int main()
{
	Solution s;
	int ds = 0;
	vector<string> words;
	string word1 = "a";
	string word2 = "b";
	words.push_back("c");
	words.push_back("c");
	words.push_back("c");
	words.push_back("b");
	words.push_back("c");
	words.push_back("c");
	words.push_back("c");
	words.push_back("c");
	words.push_back("c");
	words.push_back("c");
	words.push_back("a");

	ds = s.shortestDistance(words,word1,word2);
	cout << "shortest distance %d" << ds << endl;
	return 0;
}
