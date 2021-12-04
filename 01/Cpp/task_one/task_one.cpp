#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    
    std::string line;
    getline(input, line);
    int num = std::stoi(line), result = 0;
    int temp = num;

    while (!input.eof()) {
        getline(input, line);
        if (line == "")
        {
            break;
        }
        
        num = std::stoi(line);
        if (num > temp)
        {
            result++;
        }
        temp = num;
    }

    std::cout << "The result is: " << result << std::endl;


    return 0;
}