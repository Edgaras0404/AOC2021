#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main () {
    std::ifstream input("input.txt");
    int horizontal = 0, depth = 0;
    std::string line;

    enum mov {
        forward, down, up
    };

    while(!input.eof()) {
        
        getline(input, line);
        if (line == "")
        {
            break;
        }
        
        int num;



        std::stringstream ss(line);

        ss.ignore(10, ' ');
        ss >> num;

        switch (line[0])
        {
        case 'f':
            horizontal += num;
            break;
        case 'd':
            depth += num;
            break;
        case 'u':
            depth -= num;
            break;

        default:
            std::cerr << "False input (failed to read file?)"  << std::endl;
            return 100;
            break;
        }
    }

    std::cout << "The horizontal position is: " << horizontal << std::endl;
    std::cout << "The depth is: " << depth << std::endl;
    std::cout << "******************************\n";
    std::cout << "The answer is: " << horizontal * depth << std::endl;

    return 0;
}