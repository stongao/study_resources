// Source: leetcode #347 https://leetcode.com/problems/top-k-frequent-elements/
// Completed: 2/10/2016
// Time: ~15 mins
// Errors: Didni't write .end() in iterator loop


class Solution {
    
    class compare {
        public: 
        bool operator()(pair<int,int> a, pair<int,int> b) {
            return (a.second > b.second);
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        priority_queue<pair<int,int>,vector<pair<int,int>>, compare> minheap;
        vector<int> ret;
        
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if(hmap.find(*it) == hmap.end()) {
                hmap.insert(make_pair(*it, 1));
            }
            else {
                hmap[*it]++;
            }
        }
        
        for(unordered_map<int,int>::iterator it = hmap.begin(); it != hmap.end(); it++) {
            if(minheap.size() < k ) {
                pair<int,int> temp;
                //temp.first = *it->first;
                //temp.second = *it->second;
                minheap.push(make_pair(it->first, it->second));
            }
            else {
                if(it->second > minheap.top().second) {
                    minheap.pop();
                    minheap.push(make_pair(it->first,it->second));
                }
            }
        }
        
        while(minheap.size()!= 0) {
            int temp = minheap.top().first;
            ret.insert(ret.begin(), temp);
            minheap.pop();
        }
        
        return ret;
        
    }
};
