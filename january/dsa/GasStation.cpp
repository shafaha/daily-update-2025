// https://leetcode.com/problems/gas-station/submissions/1520412031/?envType=problem-list-v2&envId=greedy

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (cost.size() < 1)
            return cost.size();
        int diff = 0, index = -1, total = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            // cost[i] -= gas[i];
            diff += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (diff >= 0 && index == -1)
            {
                // cout<<i<<endl;
                index = i;
            }
            if (diff < 0)
            {
                index = -1;
                diff = 0;
            }
        }

        if (total < 0)
            return -1;

        return index;
    }
};