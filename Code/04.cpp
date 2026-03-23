#include "library.h"
using namespace std;

int main(int argc, char* argv[]) {
    unordered_map<string, function<long long(int [], int)>> algorithms {
        {"selection-sort", selection},
        {"insertion-sort", insertion},
        {"binary-insertion-sort", bin_insertion},
        {"bubble-sort", bubble},
        {"shaker-sort", shaker},
        {"shell-sort", shell},
        {"heap-sort", heap},
        {"merge-sort", Merge},
        {"quick-sort", quick},
        {"counting-sort", counting},
        {"radix-sort", radix},
        {"flash-sort", flash}
    };
    unordered_map<string, int> order {
        {"-rand", 0}, {"-sorted", 1}, {"-rev", 2}, {"-nsorted", 3}
    };
    unordered_map<string, string> order_names {
        {"-rand", "Randomize"}, {"-sorted", "Sorted"}, 
        {"-rev", "Reversed"}, {"-nsorted", "Nearly Sorted"}
    };
    if (argv[1] == "-a") {
        string algo = argv[2];
        if (argc == 6)
            command2(algo, algorithms[algo], stoi(argv[3]), order[argv[4]], order_names[argv[4]], argv[5]);
        else if (argc == 5) {
            string arg3 = argv[3];
            if (arg3.find(".txt") != string::npos)
                command1(algo, algorithms[algo], arg3, argv[4]);
            else 
            command3(algo, algorithms[algo], stoi(arg3), argv[4]);
        }
    } 
    else if (argv[1] == "-c") {
        string algo1 = argv[2];
        string algo2 = argv[3];
        if (argc == 5)
            command4(algo1, algo2, algorithms[algo1], algorithms[algo2], argv[4]);
        else if (argc == 6)
            command5(algo1, algo2, algorithms[algo1], algorithms[algo2], stoi(argv[4]), order[argv[5]], order_names[argv[5]]);
    }
    return 0;
}