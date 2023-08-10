// C++ program to count the number
// of occurrence of a word in
// the given string
#include <bits/stdc++.h>
using namespace std;

int countOccurrences(char *str,
                     string word)
{
    char *p;

    // split the string by spaces in a
    vector<string> a;

    p = strtok(str, " ");
    while (p != NULL)
    {
        a.push_back(p);
        p = strtok(NULL, " ");
    }

    // search for pattern in a
    int c = 0;
    for (int i = 0; i < a.size(); i++)

        // if match found increase count
        if (word == a[i])
            c++;
    return c;
}

int main()
{
    char str[] = "GeeksforGeeks A GeeksforGeeks science GeeksforGeeks for geeks ";
    string word = "GeeksforGeeks";
    cout << countOccurrences(str, word);
    return 0;
}
/* 
std::string input = "My name is Anuj.";

// Create a stringstream from the input string
std::istringstream iss(input);

std::vector<std::string> words;
std::string word;

// Read words from the stringstream and store them in the vector
while (iss >> word)
{
    words.push_back(word);
}

// Print the split words
for (const auto &w : words)
{
    std::cout << w << std::endl;
}
 */