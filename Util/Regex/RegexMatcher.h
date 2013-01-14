#ifndef REGEX_MACTCHER_H
#define REGEX_MACTCHER_H

#include "Scintilla/RESearch.h"
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

class RegexMatcher;

class SearchResult {
    bool found;
    friend class RegexMatcher;
public:
    SearchResult(bool=false);
    std::string value;
    int begin, end, tag;
    operator bool() const;
};


class ExtractResult {
    bool found;
    std::map<int, SearchResult> values;
    int maxTag;                         //maxTag will be set inside RegexMatcher::extract()
    
    friend class RegexMatcher;
public:
    ExtractResult(bool = false);
    int max() const;
    operator bool() const;
    SearchResult operator[](int index) const; //Not returning a reference..
    SearchResult& operator[](int index);
};

class RegexMatcher {
    std::string lastMatchedString;
    std::string pattern;
    RESearch re;
    
public:
    RegexMatcher(const std::string&, bool caseSensitive=true, bool posix=true);
    SearchResult group(int) const;
    ExtractResult extract() const;
    SearchResult search(const std::string&);
};


//INLINE FUNCTIONS
inline SearchResult::operator bool() const{
    return found;
}

inline ExtractResult::operator bool() const{
    return found;
}

inline SearchResult& ExtractResult::operator[](int index) {
    return values[index];
}

inline int ExtractResult::max() const {
    return maxTag;
}


#endif