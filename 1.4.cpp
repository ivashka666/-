#include <vector>

long calculateOddPentaFibCount(long n) {
    size_t oddCount = 0;

    if (n == 0) {
        return 0;
    }
    if (n < 5) {
        return 1;
    }

    std::vector<long> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    sequence.push_back(1);
    sequence.push_back(2);
    sequence.push_back(4);

    for (long i = 5; i < n + 1; ++i) {
        sequence.push_back(sequence[i - 1] + sequence[i - 2] + sequence[i - 3] + sequence[i - 4] + sequence[i - 5]);
        if (sequence[i] % 2 != 0) {
            oddCount += 1;
        }
    }

    return oddCount + 1;
}
