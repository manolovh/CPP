#include <iostream>
#include <memory>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp_node = new ListNode();
        ListNode* first_node = temp_node;
        ListNode* current_node = first_node;

        delete temp_node;
        int extra_point = 0;

        while (l1 != nullptr || l2 != nullptr || extra_point)
        {
            int total_sum = 0;

            if (l1 != nullptr)
            {
                total_sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                total_sum += l2->val;
                l2 = l2->next;
            }

            total_sum += extra_point;
            extra_point = total_sum / 10;

            ListNode* node_ptr = new ListNode(total_sum % 10);
            current_node->next = node_ptr;
            current_node = current_node->next;
        }
        return first_node;
    }
};

int main()
{
    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(4, l1);
    ListNode* l3 = new ListNode(2, l2);

    ListNode* h1 = new ListNode(4);
    ListNode* h2 = new ListNode(6, h1);
    ListNode* h3 = new ListNode(5, h2);


    Solution sol;
    ListNode* p = sol.addTwoNumbers(l3, h3);

    while (p)
    {
        std::cout << p->val;
        p = p->next;
    }

    std::cout << std::endl;
}
