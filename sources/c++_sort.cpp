#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    for (int i = 0; i < 10; i++) {
        vector<long long> numbers;
        long long num;

        for (int j = 0; j < 1e6; j++) {
            infile >> num;
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());
    }

    infile.close();
    outfile.close();
    return 0;
}
