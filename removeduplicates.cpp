#include <iostream>
#include <vector>
#include <algorithm>
 
void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
 
int main()
{
    std::vector<int> v = { 5, 2, 1, 3, 4, 2, 2, 4, 5, 5, 6 };
 
    remove(v);
 
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << ' ';
    }
 
    return 0;
}
