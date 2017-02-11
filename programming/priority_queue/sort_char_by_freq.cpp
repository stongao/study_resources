// Source: leetcode #451 https://leetcode.com/problems/sort-characters-by-frequency/
// Completed: 2/10/2017
// Time: ~20 min
// Errors: 1. Comparator override operator () should be public
//         2. Comparator reverse
//         3. string.append doesn't work with char, should use string.push_back


class Solution {
    
    class compare {
        public:
            bool operator()(pair<char,int>a,pair<char,int>b) {
                return (a.second < b.second);
            }
    };
    
public:
    string frequencySort(string s) {
        unordered_map<char,int> hmap;
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        string retString;
        
        for(int i = 0; i < s.length(); i++) {
            if(hmap.find(s.at(i)) == hmap.end()) {
                hmap.insert(make_pair(s.at(i),1));
            } else {
                hmap[s.at(i)]++;
            }
        }
        
        for(unordered_map<char,int>::iterator it = hmap.begin(); it != hmap.end(); it++) {
            pair<char,int> temp;
            temp.first = it->first;
            temp.second = it->second;
            pq.push(temp);
        }
        
        while(pq.size() != 0) {
            pair<char,int> charFreq = pq.top();
            for(int i = 0; i < charFreq.second; i++) {
                retString.push_back(charFreq.first);
            }
            pq.pop();
        }
        
        return retString;
    }
};
