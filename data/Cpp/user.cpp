#include "../Header/user.h"
#include "../Header/configure.h"
void user::create(){
	// check if user_name is already created by another one;
	string path = "./data/user/" + user_name + ".txt";
	ifstream fin(path.c_str() , ios::in);
	if(!fin.fail()){
		cout << "user name is already created by another one \n";
		cout << "choice another user name \n";
		read();
	}else add();
	fin.close();
}
void user::read(){
	string test;
	cout << "Enter user name. (No spaces): "; 	cin >> user_name;
	cout << "Enter password: "; cin >> password;
	cout << "Enter name. (No spaces):"; cin >> name;
	cout << "Enter email: "; cin >> email;
	cout << "Allow anonymous questions?: (0 or 1)"; cin >> test;
	while(test != "1" && test != "0"){
        cout << "Invalid Answer Please , answer with 0 or 1\n";
        cin >> test;
    }
    (test == "1") ? allow_anonymous = 1 : allow_anonymous = 0;
	create();
}
void user::add(){
	string path = get_path(user_name);
	// create new file
	ofstream file;
	file.open(path);
	ofstream fout(path.c_str() , ios::out);
    if(fout.fail()){
        cout << "Error Happen When Creating New Account Try again\n";
        return;
    }
	fout << user_name << "\n" <<  password << "\n" <<  name << "\n" <<  email << "\n" << allow_anonymous << '\n' << "0 " << '\n' << "0 ";
	cout << "Successful Sign Up \n";
	// close
	file.close(); fout.close();

	configure().add_user(user_name);
}
void user::write(){
	string cur_password;
	cout << "Enter Your user_name: "; cin >> user_name;
	cout << "Enter Your password: "; cin >> cur_password;
	login(cur_password);
}
void user::login(string pass){
	string path = get_path(user_name);
	ifstream fin(path.c_str() , ios::in);
	if(fin.fail()){
		cout << "Invalid Username/Password please try again \n";
		write();
		return;
	}
	getline(fin , user_name);
	getline(fin , password);
	getline(fin , name);
	getline(fin , email);
	string test;
	getline(fin , test);
	(test == "1") ? allow_anonymous = 1 : allow_anonymous = 0;
	getline(fin , send_questions);
	getline(fin , receive_questions);
	if(pass != password){
		cout << "Invalid Username/Password please try again \n";
		write();
		return;
	}
	cout << "Successful Login \n";
}
bool user::allow(){
	return allow_anonymous;
};
string user::get_path(string target){
	string path = "./data/user/" + target + ".txt";
	return path;
}
void user::update(){
	string path = get_path(user_name);
	ofstream fout(path.c_str() , ios::out);
	fout << user_name << "\n" <<  password << "\n" <<  name << "\n" <<  email << "\n" << allow_anonymous << '\n' << send_questions << "\n" << receive_questions;
}
string user::get_name(){
	return name;
}
void user::get_data_by_name(string supposed_name){
	string path = get_path(supposed_name);
	ifstream fin(path.c_str());
	if(fin.fail())return;
	getline(fin , user_name);
	getline(fin , password);
	getline(fin , name);
	getline(fin , email);
	string test;
	getline(fin , test);
	(test == "1") ? allow_anonymous = 1 : allow_anonymous = 0;
	getline(fin , send_questions);
	getline(fin , receive_questions);
	fin.close();
}
void user::reset(){
	user_name = password = name = email = "";
}
void user::add_question(string id , int type){
	if(type == 0) send_questions += id + " ";
	else receive_questions += id + " ";
	update();
}
bool user::find_received_question(int id){
	stringstream ss(receive_questions);
	int q;
	while(ss >> q){
		if(q == id) return true;
	}
	return false;
}
void user::update_info(){
	string path = get_path(user_name);
	ifstream fin(path.c_str());
	if(fin.fail())return;
	getline(fin , user_name);
	getline(fin , password);
	getline(fin , name);
	getline(fin , email);
	string test;
	getline(fin , test);
	(test == "1") ? allow_anonymous = 1 : allow_anonymous = 0;
	getline(fin , send_questions);
	getline(fin , receive_questions);
	fin.close();
}
vector<int> user::get_send_questions(){
	update_info();
	stringstream ss(send_questions);
	int id;
	vector<int> v;
	while(ss >> id){
		if(id) v.emplace_back(id);
	}
	return v;
}
vector<int> user::get_receive_question(){
	update_info();
	stringstream ss(receive_questions);
	int id;
	vector<int> v;
	while(ss >> id){
		if(id) v.emplace_back(id);
	}
	return v;
}