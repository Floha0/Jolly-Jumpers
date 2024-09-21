#include <iostream>
#include <vector>
#include <set>
#include <sstream>

      /*
       A sequence of "n > 0" integers is called a "jolly jumper" if the absolute values of the differences between successive
      elements take on all possible values 1 through "n - 1".
      */

      /*
       Input:
       4 1 4 2 3
       5 1 4 2 -1 6

       Output:
       Jolly
       Not jolly
      */

int main() {
    std::vector<int> input;

    std::cout << "Enter numbers: ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        input.push_back(number);
    }

    std::set<int> absDiff;
    for (int i = 1; i < input.size(); i++) {
        absDiff.insert(abs(input[i] - input[i - 1]));
    }

    std::vector<int> vAbsDiff;
    vAbsDiff.assign(absDiff.begin(), absDiff.end());

    std::vector<int> neededDiffs;
    for(int i = 1; i < input.size() - 1; i++) {
        neededDiffs.push_back(i);
    }

    if (neededDiffs.size()  > vAbsDiff.size()) {
        std::cout << "Not jolly";
        return 0;
    }

    for (int i = 0; i < neededDiffs.size(); i++) {
        if (vAbsDiff[i] != i + 1) {
            std::cout << "Not jolly";
            return 0;
        }
    }

    std::cout << "Jolly";

    return 0;
}
