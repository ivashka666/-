#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int a = 10, b = 10, c = 8, d = 8, e = 10, f = 6;
    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(e);
    vec.push_back(f);

    std::sort(vec.begin(), vec.end());
    std::vector<int> result;
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(result));

    std::cout << "Result: ";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl; 
    return 0;
}