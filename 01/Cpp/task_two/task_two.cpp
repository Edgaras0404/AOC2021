#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream input("input.txt");
    
    std::string line;
    std::vector<int> data; 

    while (!input.eof()) {
        getline(input, line);
        if (line == "") // in case last line is just an empty line 
        {
            break;
        } else {
            data.push_back(std::stoi(line));
        }
    }

    
    int sum, temp, result = 0;

    
    for (int i = 0; i < data.size(); i++)
    {
        temp = 0;
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            temp += data[i+j];
        }
        for (int j = 1; j < 4; j++)
        {

            sum += data[i+j];
        }
        
        if (sum > temp)
        {
            result++;
        }
    }
    
    std::cout << "The result is: " << result << std::endl;

    return 0;
}