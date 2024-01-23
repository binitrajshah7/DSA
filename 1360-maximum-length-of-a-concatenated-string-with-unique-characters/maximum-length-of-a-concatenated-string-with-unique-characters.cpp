class Solution {
public:
    bool check(string word, vector<int> &track){
        // check if same character repeats in word
        vector<int> freq(26, 0);
        for(auto e: word){
            if(freq[e-'a'])
                return false;
            freq[e-'a'] = 1;
        }

        // check if already included in our answer
        for(auto e: word){
            if(track[e-'a'])
                return false;
        }
        return true;
    }

    void max_length(int index, vector<string> &arr, vector<int> &track, int curr_result, int &result){
        // storing result
        if(index == arr.size()){
            result = max(curr_result, result);
            return;
        }

        // pick
        if(check(arr[index], track)){
            // including every character from current indexed string to result set
            for(auto e: arr[index])
                track[e-'a'] = 1;
            
            // if current is included then curr length with increase by current indexed string
            max_length(index+1, arr, track, curr_result + arr[index].length(), result);

            // backtrack
            for(auto e: arr[index])
                track[e-'a'] = 0;
        }

        // not pick
        max_length(index+1, arr, track, curr_result, result);
    }

    int maxLength(vector<string>& arr) {
        vector<int> track(26, 0);
        int result = 0, curr_result=0;
        max_length(0, arr, track, curr_result, result);
        return result;
    }
};