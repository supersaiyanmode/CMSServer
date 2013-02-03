#if defined(ENABLE_ALL_TESTS) || defined(STRING_TEST)

#include "../StringUtils.h"
#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
    std::string str = "\tWhat the    hell??? Really!! ";
    std::vector<std::string> ret = StringUtils::splitAny(str, " \t",true);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

#endif