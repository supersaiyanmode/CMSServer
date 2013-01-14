#if defined(REGEX_MATCHER_TEST) || defined(ENABLE_ALL_TESTS)
#include <iostream>
#include "../RegexMatcher.h"

int main(){
    RegexMatcher re("([A-Za-z0-9-]+):[ \\t]+([A-Za-z0-9]+)/([A-Za-z0-9]+)");
    std::string testString[] = {
        "+|++$Content-Type:  \t  application/jsona CRAP!",
        "+|++$Content-Length:  \t  143255/WHAT?!!",
        "-: dumb/LOL!"
    };
    for (size_t i=0; i<sizeof(testString)/sizeof(testString[0]); i++){
        if (re.search(testString[i])){
            std::cout<<"String matched: "<<testString[i]<<std::endl;;
            ExtractResult res = re.extract();
            for (int i=0; i<=res.max(); i++){
                if (res[i]){
                    std::cout<<"["<<res[i].tag<<"] "<<res[i].begin<<" -> "
                                <<res[i].end<<": "<<res[i].value<<std::endl;
                }
            }
        } else {
            std::cout<<"Couldn't match the string: "<<testString[i]<<std::endl;;
        }
    }    
}
#endif