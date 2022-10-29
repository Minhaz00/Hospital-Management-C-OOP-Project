#include<bits/stdc++.h>
using namespace std;
//======================HOSPITAL CLASS============================
class Hospital{
	string user, password;
	public:
		Hospital(){		//============CONSTRUCTOR=================
		user = "admin";
		password = "CUET";
		}
		virtual void show(){}
		virtual void get_data(){}	
		friend int Admin(Hospital admin); //====ADMIN LOGIN=======
		friend void main_menu();	//=========MAIN MENU==========	
		friend istream & operator >> (istream &din, Hospital &s);
};
istream & operator >> (istream &din, Hospital &s){ //OPERATOR OVERLOADING
	cin>>s.user;
	cin>>s.password;
}
void main_menu(){
	cout<<"\n\t------------CUET MEDICAL CENTER--------------";
	cout<<"\n\tAre you a doctor/ patient/ admin: ";
	cout<<"\n\t1.Doctor";
	cout<<"\n\t2.Patient";
	cout<<"\n\t3.Admin";
	cout<<"\n\t4.Exit";
	cout<<"\n\t";
}
int Admin(Hospital admin){
	string name, pass;
	cout<<"\n\tEnter username: ";
	cin>>name;
	cout<<"\tEnter Password: ";
	cin>>pass;
	if(name == admin.user && pass == admin.password){
		return 1;		
	}
	else {
		cout<<"\tInvalid User!\n\n";
		return 0;	
	}
}
//========================DOCTORS CLASS===========================
class Doctors:public Hospital{
	string name, time, day;
	int room, contact, id;
	public:
		string catagory;
		void get_data(){
			cout<<"\tEnter name: ";
			getline(cin>>ws, name);
			cout<<"\tEnter ID: ";
			cin>>id;
			cout<<"\tEnter Catagory: ";
			getline(cin>>ws, catagory);
			cout<<"\tEnter duty day: ";
			getline(cin>>ws, day);
			cout<<"\tEnter presence time: ";
			getline(cin>>ws, time);
			cout<<"\tEnter room no: ";
			cin>>room;
			cout<<"\tEnter contact no: ";
			cin>>contact;
		} 
		void show(){
			cout<<"\n\tDoctor's Name: "<<name;
			cout<<"\n\tDoctor's ID: "<<id;
			cout<<"\n\tAvailable day: "<<day;
			cout<<"\n\tAvailable time: "<<time;
			cout<<"\n\tRoom No.: "<<room;
			cout<<"\n\tContact No: "<<contact<<" BDT";
		}
		friend int doc(Doctors d);
}; 
int doc(Doctors d){  //========RETURNS PRIVATE MEMBER==============
	return d.id;
}
//========================PATIENTS CLASS===========================
class patients: public Hospital{
	public:
		string name, catagory, gender, age;
		void get_data(){
			cout<<"\tEnter patient name: ";
			getline(cin>>ws, name);
			cout<<"\tEnter age: ";
			getline(cin>>ws, age);
			cout<<"\tEnter gender(M or F): ";
			getline(cin>>ws, gender);
			cout<<"\tEnter catagory: ";
			getline(cin>>ws, catagory);
		}
		string cat(){
			return catagory;
		}
		void show(){
		cout<<"\n\tName: "<<name;
		cout<<"\n\tAge: "<<age;
		cout<<"\n\tGender: "<<gender;
		cout<<"\n\tCatagory: "<<catagory;
		}
};
//====================MAIN FUNCTON STARTS==========================
int main()
{
	Doctors d[50];
	Hospital admin, *ptr;
	patients p;
	int total_doc = 0, choice, c;
	while(1){
		main_menu(); 
		cin>>choice;
		switch(choice){
			case 1:  //=================DOCTORS MENU=====================
				cout<<"\n\n\t****************DOCTOR******************"<<endl;
				cout<<"\n\t1.Login";
				cout<<"\n\t2.EXIT\n\t";
				int i;
				cin>>c;
				if(c==1) {
					cout<<"\n\tEnter your ID: ";
					int pass;
					cin>>pass;
					for(i=0; i<total_doc;i++){
						if(doc(d[i]) == pass){
							ptr = &d[i];
							ptr->show();
							break;
						}
					}
					if(i==total_doc) cout<<"\tInvalid ID\n\n";
				}
				break;
			case 2://=================PATIENTS MENU=====================
				cout<<"\n\n\t****************PATIENT******************"<<endl;
				cout<<"\n\t1.ADMIT";
				cout<<"\n\t2.EXIT\n\t";
				cin>>c;
				if(c==1){
					ptr = &p;
					ptr->get_data();
					string s = p.cat();
					cout<<"\n\tAvailable doctors for you: \n";
					for(int i=0; i<total_doc; i++){
						if(d[i].catagory == s){
							ptr = &d[i];
							ptr->show();
						}
					}
				}
				break;
			case 3://=================ADMIN MENU=====================
				if(Admin(admin)){
					cout<<"\n\n\t****************ADMIN******************"<<endl;
					cout<<"\n\t1.Add doctors";
					cout<<"\n\t2.Set New user and password";;
					cout<<"\n\t3.Exit\n\t";
					int c;
					cin>>c;
					if(c==1) {
						cout<<"\n\tEnter the number of doctors you want to add: \n\t";
						int n;
						cin>>n;
						int total = total_doc;
						for(int i=0+total_doc; i<n+total; i++){
							cout<<"\tEnter the information of doctor "<<i+1<<endl;
							ptr = &d[i];
							ptr->get_data();
							total_doc++;
						}
					}
					else if (c == 2){
						cout<<"\n\tNew Admin user and password: \n\t";
						cin>>admin;
					}						
				}			
				break;
			case 4:	
				exit(0);
				break;
			default:
				cout<<"\n\tInvalid input\n\n";	
		}
	}
}
//======================MAIN FUNCTON ENDS================================

