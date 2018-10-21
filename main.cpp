#include <iostream>
#include <iterator>
#include "md5.h"
#include "tests.h"

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
        std::string arg = std::string(argv[1]);
        if(arg == "assert")
        {
            tests_assertions();
            exit(0);
        }
    }  
    MD5 m;
    std::istreambuf_iterator<char> begin(std::cin), end;
    std::string s(begin, end);
    
    m.update(s);
    std::cout << m.hexdigest() << std::endl;
}