#include "../Header/question.h"
question::question(){};
question::question(string id , string content , string sender , string receiver , string answer) :
 id(id) , content(content) , sender(sender) , receiver(receiver) , answer(answer){};
void question::create(){
    string path = get_path();
    ofstream file;
    file.open(path.c_str());
    ofstream fout(path.c_str() , ios::out);
    if(fout.fail()){
        cout << "Error Happen When Creating New question Try again\n";
        return;
    }
    fout << id << '\n' << sender << '\n' << receiver << '\n' << content << '\n' << answer; 
    file.close();
    fout.close();
}
string question::get_path(){
    string path = "./data/question/" + id + ".txt";
    return path;
}
void question::get_by_id(string x){
    id = x;
    string path = get_path();
    ifstream fin(path.c_str() , ios::out);
    fin >> id >> sender >> receiver >> content >> answer;
}
void question::answer_question(string ans){
    answer = ans;
    update();
}
void question::update(){

    string path = get_path();
    ofstream fout(path.c_str() , ios::out);
    fout << id << '\n' << sender << '\n' << receiver << '\n' << content << '\n' << answer; 
    fout.close();
}
string question::get_content(){
    return content;
}
void question::print(int source){
    cout << "ID: " << id << '\n';
    if(source == 0) cout << "To " << receiver << '\n';
    else cout << "From " << sender << '\n';
    cout << "Q : " << content << '\n' << "A : " << answer;
    cout << '\n' << "^^^^^^^" << '\n';
}