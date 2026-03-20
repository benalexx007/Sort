#include "Code/process.h"
using namespace std;

int main(int argc, char* argv[]){
    unordered_map<string, function<int(int [], int n, int mode)>> algorithms {
        {"selection", selection},
        {"insertion", insertion},
        {"bin_insertion", bin_insertion},
        {"bubble", bubble},
        {"shaker", shaker},
        {"shell", shell},
        {"heap", heap},
        {"quick", quick},
        {"counting", counting},
        {"radix", radix},
        {"flash", flash}
    };
    bool isNumber = [](string s){
        return all_of(s.begin(), s.end(), [](unsigned char c){ return isdigit(c); });
    };
    bool isTXT = [](string s){
        return s.substr(s.size() - 4) == ".txt";
    };
    if(argv[1] == "-a"){
        cout<<"ALGORRITHM MODE\n";
        if(argc == 6)
            command2(algorithms[argv[2]], stoi(argv[3]), argv[4], argv[5]);
        else{
            if(((string) argv[3]).substr(((string) argv[3]).size() - 4) == ".txt")
                command1(algorithms[argv[2]], argv[3], argv[4]);
            else 
                command3(algorithms[argv[2]], stoi(argv[3]), argv[4]);
        }
    }
    else{
        cout<<"COMPARE MODE\n";
        if(argc == 5)
            command4(algorithms[argv[2]], algorithms[argv[3]], argv[4]);
        else 
            command5(algorithms[argv[2]], algorithms[argv[3]], stoi(argv[4]), argv[5]);
    }
    return 0;
}