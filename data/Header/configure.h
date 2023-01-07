#include <bits/stdc++.h>
using namespace std;
#ifndef CONFIGURE
#define CONFIGURE
class configure{
    private :
        string users , questions;
    public :
        configure();
        void set();
        string get_path();
        void add_user(string);
        string add_question(string, string, string , string);
        string next_id();
        void print_users();
        void update();
        void reset();
};
#endif