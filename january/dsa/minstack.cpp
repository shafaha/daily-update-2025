// 155. Min Stack
// https://leetcode.com/problems/min-stack/description/

class MinStack
{
public:
    vector<int> s, q;
    MinStack()
    {
        s.clear();
        q.clear();
    }

    void push(int val)
    {
        s.push_back(val);
        if (q.empty())
        {
            q.push_back(val);
        }
        else
        {
            q.push_back(min(q.back(), val));
        }
    }

    void pop()
    {
        if (!q.empty())
        {
            q.pop_back();
            s.pop_back();
        }
    }

    int top()
    {
        if (!s.empty())
            return s.back();

        return -1;
    }

    int getMin()
    {
        if (!q.empty())
        {
            return q.back();
        }

        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */