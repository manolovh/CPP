#include <iostream>
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
        ListNode* list;
        return list;
    }
};

int main()
{
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(9, l1);
    ListNode* l3 = new ListNode(9, l2);

    ListNode* h1 = new ListNode(9);
    ListNode* h2 = new ListNode(9, h1);
    ListNode* h3 = new ListNode(9, h2);

    std::vector<int> l_vector;
    std::vector<int> h_vector;
    std::vector<int> final_vector;

    int total_nodes_l = 0;
    while (true)
    {
        total_nodes_l++;

        if (!l3->next)
        {
            l_vector.push_back(l3->val);
            break;
        }
        else
        {
            l_vector.push_back(l3->val);
            l3 = l3->next;
        }
    }

    int total_nodes_h = 0;
    while (true)
    {
        total_nodes_h++;

        if (!h3->next)
        {
            h_vector.push_back(h3->val);
            break;
        }
        else
        {
            h_vector.push_back(h3->val);
            h3 = h3->next;
        }
    }

    std::cout << "\nTotal l: " << total_nodes_l;
    std::cout << "\nTotal h: " << total_nodes_h;

    // ListNode* final_list = new ListNode();
    int temp_value;
    bool has_one_plus;

    if (total_nodes_h == total_nodes_l)
    {
        for (int i=0; i < total_nodes_l; i++)
        {
            temp_value = l_vector[i] + h_vector[i];
            if (temp_value > 9)
            {
                has_one_plus = true;
                final_vector.push_back(temp_value - 10);
            }
            else if (has_one_plus)
            {
                temp_value++;
                has_one_plus = false;
                if (temp_value > 9)
                {
                    has_one_plus = true;
                    final_vector.push_back(temp_value - 10);

                }
                else
                {
                    final_vector.push_back(temp_value);
                }
            }
            else
            {
                final_vector.push_back(temp_value);
            }

            if (i == (total_nodes_l - 1) && has_one_plus)
                final_vector.push_back(1);
        }
    }
    else if (total_nodes_h < total_nodes_l)
    {
        for (int i=0; i < total_nodes_h; i++)
        {

        }
    }
    else if (total_nodes_h > total_nodes_l)
    {
        for (int i=0; i < total_nodes_h; i++)
        {
            
        }
    }
    std::cout << std::endl;

    for (auto elem: final_vector)
        std::cout << elem;
}
