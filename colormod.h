#include <ostream>
namespace Color {
    enum Code {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 34,
        FG_DEFAULT = 39,
    };
    const Code colors[4] {FG_DEFAULT, FG_RED, FG_GREEN, FG_BLUE};
    class Modifier {
        Code code;

    public:
        Modifier(Code pCode) : code(pCode) {}
        Modifier(int pCode) {
            code = colors[pCode % 4];
        }
        friend std::ostream &
        operator<<(std::ostream &os, const Modifier &mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}// namespace Color