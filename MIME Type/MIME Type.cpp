#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Puts a string in lowercase
std::string toLower(std::string input)
{
    std::string res;
    for (char c : input)
    {
        res += std::tolower(c);
    }
    return res;
}

// Returns the extension of a file given it's filename
std::string getFileExtension(std::string input)
{
    int ind = input.find_last_of('.');
    if (ind < input.size())
    {
        return toLower(input.substr(ind + 1));
    }
    else
    {
        return "";
    }
}

// Input example :
// 2
// 4
// html text / html
// png image / png
// test.html
// noextension
// portrait.png
// doc.TXT
//
// Output example : 
// text/html
// UNKNOWN
// image / png
// UNKNOWN
int main()
{
    // Associative table for correspondence between file extension and MIME Type and output string declaration
    std::map<std::string, std::string> m;
    std::string res;

    // Number of elements which make up the association table.
    int n;
    std::cin >> n; std::cin.ignore();
    // Number Q of file names to be analyzed.
    int q;
    std::cin >> q; std::cin.ignore();
    for (int i = 0; i < n; i++) {
        // file extension
        std::string ext;
        // MIME type.
        std::string mt;
        std::cin >> ext >> mt; std::cin.ignore();
        // Insertion in association table
        m.insert({ toLower(ext), mt });
    }
    for (int i = 0; i < q; i++) {
        std::string fname;
        // One file name per line.
        std::getline(std::cin, fname);

        // See if filename extension matches any of the keys and act accordingly
        std::map<std::string, std::string>::iterator ipos = m.find(getFileExtension(fname));
        if (ipos != m.end())
        {
            res += ipos->second + '\n';
        }
        else
        {
            res += "UNKNOWN\n";
        }
    }
    std::cout << res;
    return 0;
}