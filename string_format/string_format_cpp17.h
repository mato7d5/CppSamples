#include <string>
#include <sstream>

template<typename CHAR_T>
class StringFormater {
private:
    std::basic_stringstream<CHAR_T>& mStream;

public:
    explicit StringFormater(std::basic_stringstream<CHAR_T>& stream) : mStream(stream) { }
    ~StringFormater() { }

    void format() { }

    template<typename H, typename... T>
    void format(H head, T... toPrint) {
        mStream << head;
        if constexpr (sizeof...(toPrint) > 0) {
            format(toPrint...);
        }
    }

    std::basic_string<CHAR_T> operator() () {
        return mStream.str();
    }
};
