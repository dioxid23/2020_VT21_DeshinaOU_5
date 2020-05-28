#ifndef ANTIPLAGIAT_H
#define ANTIPLAGIAT_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<class T>
class SmartPtr
{
public:
    SmartPtr(T *ptr):ptr(ptr){}
    ~SmartPtr()
    {
        delete ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
private:
    T *ptr;
};

class Antiplag
{
public:
    string adjective(string &word);
    string delete_ending(string &word);
    vector<string> read_file(string fname);
    string get_word(string str, int &i);
    vector<string> check_text(vector<string> vecint, string &intext);
};

#endif // ANTIPLAGIAT_H
