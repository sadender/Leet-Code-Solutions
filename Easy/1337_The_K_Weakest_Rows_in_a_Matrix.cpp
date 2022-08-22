class Solution {
public:
    int binarySearch(vector<int> v) {
        int s = 0;
        int e = v.size() - 1;
        while (s <= e) {
            int mid = s + (e-s) / 2;
            if (v[mid] == 0) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return s;
    }
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        
        for(int i = 0; i < mat.size(); ++i) {
            int sum = binarySearch(mat[i]);
            pq.push({sum, i});
            if(pq.size()>k) {
                pq.pop();
			}
        }

		for(int i=0 ; i<k ; i++){
            ans.push_back(pq.top().second);
			pq.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};