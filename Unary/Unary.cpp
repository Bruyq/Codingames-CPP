#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>


int main()
{
    std::cout << "Please enter a message to be converted to unary code :\n";
    std::string message;
    getline(std::cin, message);

    std::string res = "";
    std::string s = "";

    for (int i = 0; i <= message.size() - 1; i++)
    {
        std::bitset<7> b(message[i]);
        s += b.to_string();
    }
    switch (s[0])
    {
    case '0':
        res.append("00 0");
        break;
    case '1':
        res.append("0 0");
        break;
    }
    for (int j = 1; j < s.size(); j++)
    {
        if (s[j] == s[j - 1])
        {
            res.append("0");
        }
        else
        {
            switch (s[j])
            {
            case '0':
                res.append(" 00 0");
                break;
            case '1':
                res.append(" 0 0");
                break;
            }
        }
    }
    std::cout << res;
}