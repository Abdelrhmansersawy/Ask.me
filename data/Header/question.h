#include <bits/stdc++.h>
using namespace std;
#ifndef QUESTION
#define QUESTION
class question{
    private:
        string id ,
        content , 
        sender , 
        receiver , 
        answer; 
    public:
        question();
        question(string , string , string , string , string);
        void create();
        void get_by_id(string);
        string get_path();
        string get_content();
        void answer_question(string);
        void update();
        void print(int );
};
#endif