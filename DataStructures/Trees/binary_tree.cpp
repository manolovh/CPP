#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    struct Node* left;
    struct Node* right;
    int val;
};

Node* create()
{
    Node *p, *temp;
    std::queue<Node*> q;
    int x;
    std::cout << "Enter root value: ";
    std::cin >> x;
    Node *root = new Node{.left=nullptr, .right=nullptr, .val=x};
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        std::cout << "Enter left value: ";
        std::cin >> x;
        if (x != -1)
        {
            temp = new Node{.left=nullptr, .right=nullptr, .val=x};
            p->left = temp;
            q.push(temp);
        }
        std::cout << "Enter right value: ";
        std::cin >> x;
        if (x != -1)
        {
            temp = new Node {.left=nullptr, .right=nullptr, .val=x};
            p->right = temp;
            q.push(temp);
        }
    }
    return root;
}

void display(Node* root)
{
    if (root != nullptr)
    {
        std::cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
}

int main()
{
    Node* node = create();
    display(node);
}
