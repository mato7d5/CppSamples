#include "string_format.h"
#include <sstream>
#include <iostream>

int main() {
    StringFormater<char> f;
    std::stringstream stream;

    f.format(stream, "Hello", ", ", "world!", "\n", "Today is:", 11, ". ", 11, ". ", 2016, '\n');

    std::cout << "Formatted std::string:\n" << f() << '\n';

    StringFormater<wchar_t> wf;
    std::wstringstream wstream;

    wf.format(wstream, L"wide", L' ', "character size: ", sizeof(wchar_t), " bytes\n");

    std::wcout << "Formatted std::wstring:\n" << wf() << '\n';

    return 0;
}
