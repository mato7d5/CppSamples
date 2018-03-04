#include "string_format_cpp17.h"
#include <sstream>
#include <iostream>

int main() {
    std::basic_stringstream<char> stream;
    StringFormater<char> f(stream);
    
    f.format("Hello", ", ", "world!", "\n", "Today is:", 11, ". ", 11, ". ", 2016, '\n');

    std::cout << "Formatted std::string:\n" << f() << '\n';

    std::basic_stringstream<wchar_t> wstream;
    StringFormater<wchar_t> wf(wstream);
    
    wf.format(L"wide", L' ', "character size: ", sizeof(wchar_t), " bytes\n");

    std::wcout << "Formatted std::wstring:\n" << wf() << '\n';

    return 0;
}
