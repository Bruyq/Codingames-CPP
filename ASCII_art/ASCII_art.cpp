#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Hash function returning an int between 0 and 25 if the first element of input string is a letter from the alphabet, it returns 26 otherwise
int hash_function(char key)
{
    int idx = (0 <= int(key) - int('A')  && int(key) - int('A') <= 25) ? int(key) - int('A') : 26;
    idx = (0 <= int(key) - int('a')  && int(key) - int('a') <= 25) ? int(key) - int('a') : idx;
    return idx;
}

// Class handling ASCII art
class ASCIIString
{
private:
    std::vector<std::string> str;

public:
    ASCIIString() {};
    ASCIIString(int size) 
    {
        for (int i = 0; i < size; i++)
        {
            str.push_back("");
        }
    }
    ASCIIString(std::vector<std::string> value) { str = value; }
    ~ASCIIString() {};
    ASCIIString& operator+=(const ASCIIString& letter)
    {
        for (int i = 0; i < str.size(); i++)
        {
            str[i] += letter.str[i];
        }
        return *this;
    }
    void print()
    {
        for (int i = 0; i < str.size(); i++)
        {
            std::cout << str[i] << std::endl;
        }
    }
};

// Class handling the correspondence between ASCII art and integers (characters are transformed into integers thanks to the hash_function)
class ASCIITable 
{
private:
    std::vector<ASCIIString> table;

public:
    ASCIITable() {};
    ASCIITable(int length, int height, std::vector<std::string> alphabet)
    {
        int nb_letters = alphabet[0].size() / length;
        for (int i = 0; i < nb_letters; i++)
        {
            std::vector<std::string> temp;
            for (int h = 0; h < height; h++)
            {
                temp.push_back(alphabet[h].substr(i * length, length));
            }
            ASCIIString letter(temp);
            table.push_back(letter);
        }
    }
    ~ASCIITable() {};
    ASCIIString at(int i)
    {
        return ASCIITable::table[i];
    }
};

// Input example :
// 4
// 5
// MANHATTAN
//  #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### 
// # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # 
// ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ##
// # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       
// # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  
// 
// Output example :
// # #  #  ### # #  #  ### ###  #  ###  
// ### # # # # # # # #  #   #  # # # #
// ### ### # # ### ###  #   #  ### # #
// # # # # # # # # # #  #   #  # # # #  
// # # # # # # # # # #  #   #  # # # # 
// 
// I changed the code behavior to make it simple. You can just type the sentence to be converted.
// If you want the first behavior, please uncomment/comment some lines below.
//
int main()
{
    // Initialize the correspondence table
    std::vector<std::string> alphabet = {
    " #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### ",
    "# # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # ",
    "### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ## ",
    "# # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       ",
    "# # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  "
    };
    int l = 4;
    int h = alphabet.size();
    ASCIITable table(l, h, alphabet);
    std::string s;
    getline(std::cin, s);

    //// If you want to type the full input, or to use a file to use this string to ASCII representation code, please comment the lines above and uncomment the next part :
    // 
    //// Read inputs
    //int l;
    //std::cin >> l; std::cin.ignore();
    //int h;
    //std::cin >> h; std::cin.ignore();
    //std::string t;
    //std::vector<std::string> alphabet;
    //getline(std::cin, t);
    //for (int i = 0; i < h; i++) {
    //    std::string row;
    //    getline(std::cin, row);
    //    alphabet.push_back(row);
    //}
    //ASCIITable table(l, h, alphabet);

    // Create ASCII Art and print the result
    ASCIIString str(h);
    for (int i = 0; i < s.size(); i++)
    {
        str += table.at(hash_function(s[i]));
    }
    str.print();
}