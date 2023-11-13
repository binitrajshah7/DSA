class Solution {
public:
    // Intuition: We keep frequency map of every kind of task
    // Now in our operation we always will consider the task first whose frequency is more we keep track of this using our max heap
    // Whenever we take consider a element to process from our max heap we decrease its frequence and push it to our queue with the next time 
    // frame that when to consider this element again
    int leastInterval(vector<char>& tasks, int n) {
        // task frequency map
        unordered_map<char, int> mp;
        for(auto element: tasks)
            mp[element]++;

        // max heap that stores frequency of every task
        priority_queue<int> pq;
        for(auto element: mp)
            pq.push(element.second);

        int time = 0;

        // stores at what time task can be added to our max heap again {task, time}
        queue<pair<int, int>> q;

        while(!pq.empty() || !q.empty()){
            time++;
            // if max heap is not empty we pop the max frequency task
            if(!pq.empty()){
                // decrease its frequency by 1
                int count = pq.top() - 1;
                // pop the element from the max heap
                pq.pop();
                // additional check required when frequency of a task becomes 0 then we don't queue it again for next time
                if (count != 0)
                    q.push({count, time+n});
            }

            // if there are some task in our queue then we check whether it can be pushed again to our max heap or not at this time
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        // minimum time taken to complete all tasks
        return time;
    }
};