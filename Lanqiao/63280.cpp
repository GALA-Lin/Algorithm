#include <iostream>
#include <string>
#include <algorithm>

std::string swapAB(std::string str) {
    int n = str.length();
    for(int i = 0; i < n; i+=3) {
        for(int j = i + 1; j < n; j+=3) {
            if(str[i] == 'A' && str[j] == 'B') {
                std::swap(str[i], str[j]);
            }
        }
    }
    return str;
}

int main() {
    std::string input = "ABBAB";
    std::string output = swapAB(input);
    std::cout << "输入: " << input << "\n";
    std::cout << "输出: " << output << "\n";
    return 0;
}
