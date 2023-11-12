#include <iostream>
#include <vector>

struct mapping_t
{
    int value;
    mapping_t* next;

    mapping_t(int value)
        : value{value}, next{nullptr} {}

    mapping_t(mapping_t* copy)
        : value{copy->value}, next{copy->next} {}

    mapping_t(int value, mapping_t* next)
        : value{value}, next{next} {}
};

class HashTable
{
private:
    std::vector<mapping_t*> hash_table;

public:
    HashTable()
        : hash_table(50, nullptr) {}

    int hash_key(int x)
    {
        return x % 10;
    }

    void insert(int x)
    {
        int key = hash_key(x);
        if (!hash_table[key])
        {
            hash_table[key] = new mapping_t(x);
        } else
        {
            mapping_t* prev = hash_table[key];
            mapping_t* running = prev->next;

            while (running)
            {
                if (running->value > x)
                {
                    mapping_t* temp = new mapping_t(x);
                    temp->next = running;
                    prev->next = temp;
                    break;
                }
                prev = running;
                running = running->next;
            }
            if (!running)
            {
                if (prev->value > x)
                {
                    mapping_t* next = new mapping_t(prev->value, prev->next);
                    delete(prev);
                    mapping_t* temp = new mapping_t(x, next);
                    prev = temp;
                }
                else
                {
                    prev->next = new mapping_t(x);
                }
            }
        }
    }
    
    void display()
    {
        for (int i = 0; i < hash_table.size(); i++)
        {
            if (hash_table[i])
            {
                mapping_t* temp = hash_table[i];
                while (temp)
                {
                    std::cout << temp->value << " ";
                    temp = temp->next;
                }
                std::cout << std::endl;
            }
        }
    }
};

int main()
{
    HashTable hash_table;
    hash_table.insert(105);
    hash_table.insert(65);
    hash_table.insert(5);
    hash_table.insert(25);
    hash_table.insert(35);
    hash_table.insert(15);
    hash_table.display();
}