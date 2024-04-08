class Solution {
public:
    // Count the number of students preferring each type of sandwich.
    // Serve sandwiches to students based on their preferences.
    // Keep track of remaining sandwiches to be served.
    // Return the count of remaining sandwiches, representing the number of students unable to eat lunch.
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        
        for(auto student: students)
            counts[student]++;

        int remaining = sandwiches.size();
        for(auto sandwich: sandwiches){
            // implies there is sandwich on the top of stack and no person to eat it
            if(counts[sandwich] == 0)
                break;
            // remaining
            if(remaining == 0)
                break;

            counts[sandwich]--;
            remaining--;
        }
        return remaining;
    }
};