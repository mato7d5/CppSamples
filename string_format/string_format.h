#include <string>
#include <sstream>

template<typename CHAR_T>
class StringFormater {
private:
    std::basic_string<CHAR_T> mStr;

public:
    StringFormater() { }
    ~StringFormater() { }

    void format(std::basic_stringstream<CHAR_T>& s) {
        mStr = s.str();
    }

    template<typename H, typename... T>
    void format(std::basic_stringstream<CHAR_T>& s, H head, T... tail) {
        s << head;
        format(s, tail...);
    }

    std::basic_string<CHAR_T> operator() () {
        return mStr;
    }
};

