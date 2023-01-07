#include "../Header/configure.h"
configure::configure(){
    string path = get_path();
    ifstream fin(path.c_str(), ios::in);
    getline(fin , users);
    getline(fin , questions);
    fin.close();
}
void configure::set(){
    string path = get_path();
    ifstream fin(path.c_str(), ios::in);
    getline(fin , users);
    getline(fin , questions);
    fin.close();
}
void configure::add_user(string name){
    users += name + " ";
    update();
}
void configure::update(){
    string path = get_path();
    ofstream fout(path.c_str() , ios::out);
    fout << users << '\n' << questions;
}
string configure::get_path(){
    string path = "./data/configure.txt";
    return path;
}
string configure::add_question(string sender , string receiver , string q , string ans = "No answer Yet"){
    string id = next_id();
    questions += id + " ";
    update();
    return id;
}
string configure::next_id(){
    stringstream ss(questions);
    int mex = 1 , id = 1;
    vector<int> v;
    while(ss >> id) v.emplace_back(id);
    sort(v.begin() , v.end());
    for(auto &i : v) if(mex == i) mex++;
    return to_string(mex);
}
void configure::reset(){
    stringstream stream_user(users) , stream_question(questions);
    string name; 
    int id;
    while (stream_user >> name)
    {
        string path = "./data/user/" + name + ".txt";
        remove(path.c_str());
    }
    while (stream_question >> id)
    {
        string path = "./data/question/" + to_string(id) + ".txt";
        remove(path.c_str());
    }
    ofstream fout("./data/configure.txt" , ios::out);
    fout << "";
    fout.close();
}
void configure::print_users(){
    cout << users << '\n';
}