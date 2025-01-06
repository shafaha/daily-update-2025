// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto fx = [](ListNode *n, ListNode *m)
        {
            return n->val > m->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(fx)> pq(fx);

        for (auto &l : lists)
        {
            if (l)
                pq.push(l);
        }

        ListNode *temp;
        ListNode *head = new ListNode(-1), *xemp = head;
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            if (temp->next)
            {
                pq.push(temp->next);
            }

            temp->next = NULL;
            xemp->next = temp;
            xemp = xemp->next;
        }

        return head->next;
    }
};