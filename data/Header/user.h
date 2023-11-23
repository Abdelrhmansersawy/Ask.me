#include <bits/stdc++.h>
using namespace std;
#ifndef USER
#define USER
class user{
	private :
		string user_name ,
		password , 
		name ,
		email ,
		send_questions = "0 ",
		receive_questions = "0 ";
		bool allow_anonymous ;
		public: 
		void create();
		void read();
		void add();
		void write();
		void login(string);
		bool allow();
		string get_path(string);
		void get_data_by_name(string);
		string get_name();
		void add_question(string , int);
		bool find_received_question(int);
		void update();
		void reset();
		void update_info();
		vector<int> get_send_questions();
		vector<int> get_receive_question();
};
void start_page();
#endif