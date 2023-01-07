#include "../Header/user.h"
#include "../Header/configure.h"
#include "../Header/question.h"
#include "../Cpp/user.cpp"
#include "../Cpp/question.cpp"
#include "../Cpp/configure.cpp"
configure setting;
user client;
void start_page(){
	string choices[] = {
		"Login" , "Sign up" , "reset for DataBase"
	};
	int cnt = 0;
	cout << "Menu : \n";
	for(auto &i : choices) cout << '\t' << ++cnt << ": "<< i << '\n';
	cout << "Enter number in range " << 1 << " - " << cnt << '\n';
	int option; cin >> option;
	if(option == 1){
		client.write();
        menu();
        setting.set();
	}else if(option == 2){
        client.read();
        setting.set();
        menu();
    } else if(option == 3){
         setting.reset();
         cout << "Successful Operation !\n";
         start_page();
    }else{
		cout << "Invalid Choice Try Again\n";
        start_page();
	}
}
void menu(){
    string option[] = {
        "Print Questions To Me",
        "Print Questions From Me",
        "Answer Question",
        "Delete Question",
        "Ask Question",
        "List System Users",
        "Feed",
        "Logout"
    };
    int cnt = 0;
    cout << "\n^^^ Welcome " << client.get_name() << "^^^\n\n";
    cout << "Menu : \n";
	for(auto &i : option) cout << '\t' << ++cnt << ": "<< i << '\n';
	cout << "Enter number in range " << 1 << " - " << cnt << '\n';
	int ope; cin >> ope;
    while (ope > cnt && ope <= 0)
    {
        cout << "invalid number Try again ";
        cin >> ope;
    }
    if(ope == 1) print_question_to_me();
    else if(ope == 2) print_question_from_me();
    else if(ope == 3) answer_question();
    else if(ope == 5) ask_question();
    else if(ope == 6) show_users();
    else if(ope == 8) logout();
}
void ask_question(){
    string q , receiver , test;
    string is_anonymous;
    cout << "Enter Your Question (No_space): "; cin >> q;
    cout << "Enter User_name of someone You want to ask him/her: "; cin >> receiver;
    cout << "Do you want to show your Name (0 - 1): "; cin >> is_anonymous;
    user target;
    target.get_data_by_name(receiver);
    // check if name_receiver is exited
    if(target.get_name().empty()){
        cout << "This User_name not found , Try again";
    }
    // check if target person allow is_annoymous;
    else if(is_anonymous == "0" && !target.allow()){
        cout << target.get_name() << " doesn't allow Annoymous Question \n";
    }else{
        cout << "Question send to " << receiver << " !\n";
        setting.set();
        string id = setting.add_question(client.get_name() , receiver , q);
        string sender = (is_anonymous == "1") ? client.get_name() : "anonymous";
        question(id , q , sender , receiver , string("No_answer_Yet")).create(); 
        client.add_question(id , 0);
        target.add_question(id , 1);
    }
    menu();
}
void answer_question(){
    int id;
    cout << "Enter id of Question: \n"; cin >> id;
    if(!client.find_received_question(id)){
        cout << "Invalid ID , Try Again\n";
    }else{
        question q;
        q.get_by_id(to_string(id));
        cout << "Q : " << q.get_content() << '\n';
        cout << "Enter Your Answer (No_space): ";
        string ans ;cin >> ans;
        q.answer_question(ans);
        cout << "Answered Question Done!";
    }
    menu();
}
void logout(){

    cout << "\n";
    client.reset();
    start_page();
    menu();
}
void show_users(){
    setting.print_users();
    menu();
}
void print_question_from_me(){
    for(auto &q : client.get_send_questions()){
        question cur_question;
        cur_question.get_by_id(to_string(q));
        cur_question.print(0);
    }
    menu();
}
void print_question_to_me(){
    for(auto &q : client.get_receive_question()){
        question cur_question;
        cur_question.get_by_id(to_string(q));
        cur_question.print(1);
    }
    menu();
}