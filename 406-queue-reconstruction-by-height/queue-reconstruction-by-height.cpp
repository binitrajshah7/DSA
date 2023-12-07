class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());

        int n = people.size();
        vector<vector<int>> result(n, vector<int> (2, -1));

        for (int i = 0; i < n; i++){
            int height = people[i][0];
            int count = people[i][1];

            for (int j = 0; j < n; j++){
                if(result[j][0] == -1 && count == 0){
                    result[j] = people[i];
                    break;
                }

                else if((result[j][0] == -1 || result[j][0] >= height) && count != 0){
                    count--;
                }
            }
        }

        return result;
    }
};