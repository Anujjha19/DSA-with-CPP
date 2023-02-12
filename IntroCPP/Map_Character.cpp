#include <iostream>
#include <string>
#include <map>

int main()
{
    std::string str = "hello world";
    std::map<char, int> map;

    for (int i = 0; i < str.length(); i++)
    {
        if (map.count(str[i]) == 0)
        {
            map[str[i]] = i;
        }
    }

    for (const auto &pair : map)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}
