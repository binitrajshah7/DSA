class Solution {
    bool is_overlapping(vector<int> pair1, vector<int> pair2){
        return (pair1[1] >= pair2[0]) && (pair1[0] <= pair2[1]);
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while(i<firstList.size() && j<secondList.size()){
            // cout << "i: " << i << " j:" << j << endl;
            if(is_overlapping(firstList[i], secondList[j])){
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                result.push_back({start, end});
            }
            if(secondList[j][1] > firstList[i][1])
                i++;
            else if(secondList[j][1] < firstList[i][1])
                j++;
            else{
                i++;
                j++;
            }
        }

        return result;
    }
};