#include "RegexMatcher.h"


class REString : public CharacterIndexer {
    std::string value;
public:
    REString(const std::string& s):value(s){}
    ~REString(){}
    char CharAt(int i){ return value[i]; }
};

//--------------------------------------

SearchResult::SearchResult(bool f):found(f){}


//--------------------------------------

ExtractResult::ExtractResult(bool f):found(f) {}

SearchResult ExtractResult::operator[](int index) const{
    std::map<int, SearchResult>::const_iterator it;
    if ((it=values.find(index)) == values.end())
        return SearchResult();
    return it->second;
}

//--------------------------------------

RegexMatcher::RegexMatcher(const std::string& p, bool caseSensitive, bool posix): pattern(p) {
    re.Compile(pattern.c_str(), pattern.size(), caseSensitive, posix);
}

SearchResult RegexMatcher::group(int i) const {
    if (i < 0 || i > RESearch::MAXTAG || !re.pat[i])
        return SearchResult();
    
    SearchResult s(true);
    s.value = re.pat[i];
    s.begin = re.bopat[i];
    s.end = re.eopat[i];
    s.tag = i;
    return s;
}

SearchResult RegexMatcher::search(const std::string& str){
    REString restring(str);
    if (re.Execute(restring, 0, str.length())){
        lastMatchedString = str;
        re.GrabMatches(restring);
        return group(0);
    } else {
        lastMatchedString = "";
        return group(-1);
    }
}

ExtractResult RegexMatcher::extract() const{
    if (lastMatchedString == "")
        return ExtractResult();
    
    ExtractResult ret(true);
    for (unsigned int i = 0; i < RESearch::MAXTAG; i++) {
        if (re.pat[i]) {
            SearchResult s(group(i));
            ret.values[s.tag] = s;
            ret.maxTag = i;
        }
    }
    return ret;
}
