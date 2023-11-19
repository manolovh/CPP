#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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

void PreorderIteration(Node* root)
{
    std::vector<Node*> stack;
    std::cout << "Preorder = ";
    while (root || !stack.empty())
    {
        if (root)
        {
            std::cout << root->val << " ";
            stack.push_back(root);
            root = root->left;
        }
        else if (!stack.empty())
        {
            root = stack[stack.size() - 1];
            stack.pop_back();
            root = root->right;
        }
    }
}

void InorderIteration(Node* root)
{
    std::vector<Node*> stack;
    std::cout << "Inorder = ";
    while (root || !stack.empty())
    {
        if (root)
        {
            stack.push_back(root);
            root = root->left;
        }
        else if (!stack.empty())
        {
            root = stack[stack.size() - 1];
            stack.pop_back();
            std::cout << root->val << " ";
            root = root->right;
        }
    }
}

void PostorderIteration(Node* root)
{
    std::vector<std::pair<Node*, bool>> stack;
    std::cout << "Postorder = ";
    std::pair<Node*, bool> p = std::make_pair(root, false);
    while (p.first || !stack.empty())
    {
        if (p.first)
        {
            stack.push_back(p);
            p = std::make_pair(p.first->left, false);
        }
        else if (!stack.empty())
        {
            p = stack[stack.size() - 1];
            stack.pop_back();
            if (!p.second)
            {
                p = std::make_pair(p.first, true);
                stack.push_back(p);
                p = std::make_pair(p.first->right, false);
            } else
            {
                std::cout << p.first->val << " ";
                p = std::make_pair(nullptr, false);
            }
        }
    }
}

int main()
{
    Node* node = create();

    InorderIteration(node);
    std::cout << std::endl;

    PreorderIteration(node);
    std::cout << std::endl;
    
    PostorderIteration(node);
    std::cout << std::endl;
}
