#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <array>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iterator> // for std::advance


class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};


std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ": " << p.age;
    return os;
}


void iterator_ex() {
    std::vector<int> vec {1, 5, 10};
    std::vector<int>::iterator it;

    it = vec.begin();
    while (it != vec.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    std::vector<int>::reverse_iterator reverse_it = vec.rbegin();
    while (reverse_it != vec.rend()) {
        std::cout << *reverse_it << std::endl;
        ++reverse_it;
    }
}


void subset_looping() {
    std::vector<int> vec {1, 5, 10, 20, 50, 100};
    auto start = vec.begin() + 1;
    auto end = vec.end() - 1;

    // will print elements from the second to the last(exclusive)
    while (start != end) {
        std::cout << *start << std::endl;
        ++start;
    }
}


void count_if_ex() {
    std::vector<int> vec {1, 5, 1, 20, 50, 1};
    int even_nums = std::count_if(std::begin(vec), std::end(vec), [](int num) {return num % 2 == 0;});
    int odd_nums = std::count_if(std::begin(vec), std::end(vec), [](int num) {return num % 2 != 0;});

    std::cout << "Odd: " << odd_nums << " | Even: " << even_nums << std::endl;
    
    std::replace(vec.begin(), vec.end(), 1, 33);
    for (auto elem: vec)
        std::cout << elem << " ";
}


void all_any_of_ex() {
    std::vector<int> vec {1, 5, 10, 15, 20, 10, 25, 5};
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 10;}))
        std::cout << "All elements are greater than 10" << std::endl;
    else
        std::cout << "Not all elements are greater than 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x < 50;}))
        std::cout << "All elements are less than 50" << std::endl;
    else
        std::cout << "Not all elements are less than 50" << std::endl;

    if (std::any_of(vec.begin(), vec.end(), [] (int x) { return x == 25;}))
        std::cout << "At least one element is equal to 25" << std::endl;
    else
        std::cout << "There's no element equal to 25" << std::endl;    
}


void transform_ex() {
    std::string str {"Gosho goes hunting."};
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // `::` for global scope
    std::cout << str << std::endl;
}


void array_ex() {    
    std::array<int, 5> arr1 {{1, 2, 3, 4, 5}}; // C++11
    std::array<int, 5> arr2 {5, 4, 3, 2, 1};

    std::cout << arr1.at(0) << std::endl;
    std::cout << arr2[1] << std::endl;
    std::cout << arr1.front() << std::endl;
    std::cout << arr1.back() << std::endl;
    std::cout << arr1.size() << std::endl;
    arr1.fill(5);
    std::cout << arr1.at(3) << std::endl;
    arr1.swap(arr2);

    std::cout << arr2.front() << std::endl;
    int count = std::count(arr2.begin(), arr2.end(), 5);
    std::cout << "Count: " << count << std::endl;
}


void vector_ex() {
    std::vector<Person> vec1 {Person("Pesho", 25)};
    std::vector<int> vec2 (10, 100); // create vec2 with ten 100s

    vec1.emplace_back("Gosho", 20);
    
    std::cout << vec1.at(0) << std::endl;
    std::cout << vec1.at(1) << std::endl;

    std::vector<int> vec3 {10, 15, 20, 25, 30, 50, 100, 50, 100, 500};
    std::vector<int> vec4;

    std::transform(vec2.begin(), vec2.end(), vec3.begin(), std::back_inserter(vec4),
                    [](int x, int y) {return y * x + 1;});

    for (auto elem: vec4)
        std::cout << elem << std::endl;
}


bool deque_ex() {
    std::string str {"Ivan Navi"};
    for (size_t i {0}; i < str.size(); i++) {
        if (isalpha(str[i]))
            str += toupper(str[i]);
    }

    std::deque<char> d;
    std::copy(str.begin(), str.end(), std::front_inserter(d));
    for (size_t i {0}; i < d.size(); ++i) {
        if (!(d[i] == d[d.size() - (i + 1)]))
            return false;
    }
    return true;
}


void list_ex() {
    std::list<int> l {1, 2, 3, 4, 5};
    std::cout << l.front() << " " << l.back() << std::endl;

    auto it = std::find(l.begin(), l.end(), 4);
    l.insert(it, 10); // add 10 before 4
    l.erase(it); // erase 4
    l.resize(3); // 1 2 3
    l.resize(5); // 1 2 3 0 0

    l = {1, 2, 3, 4, 5};
    auto it1 = std::find(l.begin(), l.end(), 3);
    std::cout << *it1++ << std::endl;
    std::cout << *it1-- << std::endl;
    std::cout << *it1 << std::endl;

    auto it2 = std::find(l.begin(), l.end(), 2);
    std::list<int> l2 {1000, 2000, 3000};
    l.insert(it2, l2.begin(), l2.end()); // l = 1, 1000, 2000, 3000, 2, 3, 4, 5

    std::advance(it2, -4); // move it2 four elements back (to 1)
    std::cout << *it2 << std::endl;   
}


void set_ex() {
    std::set<int> set1 {6, 7, 7, 1, 2, 2, 3, 3, 4, 5}; //ordered
    for (auto elem: set1)
        std::cout << elem << " ";
    
    std::cout << "\n" << set1.count(1) << std::endl; // 0 or 1
    std::cout << set1.size() << std::endl;
    set1.insert(9);
    
    auto iter = set1.find(10);
    if (iter != set1.end())
        set1.erase(iter);
        
    for (auto elem: set1)
        std::cout << elem << " ";
}


void map_ex() {
    std::map<int, std::string> map1 {
        {2, "Pesho"},
        {7, "Gosho"},
        {3, "Ivan"}
    };

    std::pair<int, std::string> tosho {9, "Tosho"};
    map1.insert(tosho);
    // or directly create an object
    map1.insert(std::make_pair(5, "Mitio"));

    map1[2] = "Peshko"; // update value of key
    map1[11] = "Hagrid"; // add key-value pair

    for (auto elem: map1)
        std::cout << elem.first << ": " << elem.second << std::endl;
}


void stack_ex() {
    std::stack<int> s; // uses deque as container by default

    std::stack<int, std::vector<int>> s1; // use vector as container
    std::stack<int, std::list<int>> s2; // use list as container

    s.push(10);
    s.push(20);

    s1.push(30);

    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    s.pop();
    std::cout << s.empty() << std::endl;
}


void queue_ex() {
    std::queue<int> q; // deque as containter by default
    std::queue<int, std::list<int>> q1; // list as containter

    q1.push(10);
    q1.push(50);
}


void priority_queue_ex() {
    std::priority_queue<int> pq;
    
    for (int i: {1, 7, 5, 10, 15, 3, 2, 6})
        pq.push(i);

    std::cout << pq.top() << std::endl;
    std::cout << pq.size() << std::endl;

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}


int main() {
    priority_queue_ex();
    return 0; 
}