// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=problem-list-v2&envId=greedy

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        prices.push_back(0);
        int c = prices[0];
        int total = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                if (c < prices[i - 1])
                    total += (prices[i - 1] - c);
                c = prices[i];
            }
        }

        return total;
    }
};