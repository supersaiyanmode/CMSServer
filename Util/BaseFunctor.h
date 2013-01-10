#ifndef BASE_FUNCTOR_H
#define BASE_FUNCTOR_H
template <typename T>
class BaseFunctor {
    virtual bool operator()(const T& other)=0;
};

#endif