#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>

using std::cout; using std::endl;
using std::vector; using std::copy;
using std::setw; using std::left;

int main() {
    vector<int> int_vec = { 10, 23, 10, 324, 10, 10, 424,
                           649, 110, 110, 129, 40, 424 };

    cout << left << setw(10) << "vec: ";
    copy(int_vec.begin(), int_vec.end(),
        std::ostream_iterator<int>(cout, "; "));
    cout << endl;


    std::sort(int_vec.begin(), int_vec.end());
    auto last = std::unique(int_vec.begin(), int_vec.end());
    int_vec.erase(last, int_vec.end());

    cout << left << setw(10) << "vec: ";
    copy(int_vec.begin(), int_vec.end(),
        std::ostream_iterator<int>(cout, "; "));
    cout << endl;


    return 0;
}
//сложность nlogn