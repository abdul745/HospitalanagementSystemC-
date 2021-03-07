#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
void chk_app();
void reg();
bool check(int r);
void emergency();
void guest();
void data();
void main()
{ 
while(true)
	{
		char permission;
   
	int option;
		cout<<"    ***WELCOME TO THE CITY HOSPITAL***       "<<endl;
	cout<<"How can we Help You? "<<endl;
	cout<<"1. Checking and Appointments of Patients"<<endl;
	cout<<"2. Patient Registeration"<<endl;
	cout<<"3. Emergency Situation"<<endl;
	cout<<"4. Meeting a Patient"<<endl;
	cout<<"5. Searching Data of Patient"<<endl;
	cout<<endl;
	cout<<"Enter your Respective Number"<<endl;
	cin>>option;	
	switch(option)
	{
		case 1:
			chk_app();
			break;
		case 2:
			reg();
			break;
		case 3:
			emergency();
			break;	
		case 4:
			guest();
			break;
		case 5:
			data();
			break;
	}
	cout<<"Press Y to Continue and any other key to close"<<endl;
	cin>>permission;	
if(permission=='Y'||permission=='Y')
	continue;
else 
	break;
}
		_getch();
}
void chk_app()
{   int name;
	string p_name;
	fstream app_chk;
	cout<<"Enter Name of Patient"<<endl;
	cin.ignore();	
	getline(cin,p_name);
		cout<<endl;
	cout<<"Select your Doctor"<<endl;
	cout<<"1. Doctor Ahmad(Sergeon)"<<endl;
	cout<<"2. Doctor Raza(Cardiologist)"<<endl;
	cout<<"3. Doctor Usama(Emergency Medicine Specialist)"<<endl;
	cout<<"4. Doctor Maryam(Gynecologist)"<<endl;
	cin>>name;
	app_chk.open("appointments.txt",ios::app);
	if(app_chk.is_open())
	{app_chk<<setw(20)<<p_name<<"   ";
	if(name==1)
	{ app_chk<<"Doctor Ahmad(Sergeon)"<<endl;          }
	if(name==2)
	{app_chk<<"Doctor Raza(Cardiologist)"<<endl;            }
	if(name==3)
	{app_chk<<"Doctor Usama(Emergency Medicine Specialist)"<<endl;            }
	if(name==4)
	{app_chk<<"Doctor Maryam(Guyenocologist)"<<endl;            }
	}
	app_chk.close();
}
void reg()
{

	int r = 1,dept,age,cnic;
	bool flag = 0;
	string fname,lname,phone;
	ofstream write_file;
	ofstream timeout;
	write_file.open("Record.txt", ios::app);
	timeout.open("Recordbill.txt",ios::app);
	cout << "\n Enter Patient Details"<<endl;
	cout<<"Select Disease of Patient"<<endl;
	cout<<"1. Surgery "<<endl;
	cout<<"2. Cardiology "<<endl;
	cout<<"3. Medicine "<<endl;
	cout<<"4. Gynecology "<<endl;
	cin>>dept;
	cout<<"Enter Room Number"<<endl;
	cin>>r;
	flag = check(r);
	if (!flag)
	{
		cout << "Enter First Name: (Without Space)"<<endl;
		cin.ignore();
		getline(cin,fname);
		cout<<endl;
		cout << "Enter Last Name: (Without Space)"<<endl;
		getline(cin,lname) ;
		cout<<"Enter age of Patient"<<endl;
		cin>>age;
		cout<<"Enter CNIC Of Patient"<<endl;
		cin>>cnic;
		cout << "Enter Phone No: (Without Space)"<<endl;;
		getline(cin,phone) ;
		cin.ignore();
		if(dept==1)
			{write_file <<" Surgery";}
		if(dept==2)
			{write_file <<" Cardiology";}
		if(dept==3)
			{write_file <<" Medicine";}
		if(dept==4)
		{write_file <<" Guynocology";}
		write_file<<setw(10) << r <<"  ";
		write_file<<setw(15) << fname << " ";
		write_file<<setw(3) << lname << " ";
		write_file<<setw(6) << age << " ";
		write_file<<setw(8) << cnic <<"  ";
		write_file<<setw(19
			) << phone << " "<<endl;
		timeout<<r<<endl;
		cout << "\n Room is booked!!!";
		_getch();
	}

	else
		cout << "\n Sorry..!!!Room is already booked";
	write_file.close();
	cout << "\n Press any key to continue!!";
	_getch();
}

bool check(int r)
{
	int room_no;
	bool flag = 0;
	ifstream read_file;
	read_file.open("Recordbill.txt");
	while (!read_file.eof())
	{
		read_file >> room_no;
		if (room_no == r)
		{
			flag = 1;
		}
	}	
	return flag;
}
void emergency()
{
	int svrty,disease;
	cout<<"Enter Disease"<<endl;
	cout<<"1. Accident\n2. Heart Attack\n3. Blood Pressure/Sugar\n4. Delivery"<<endl;
	cin>>disease;
	if(disease==4)
	{cout<<"Admit in ICU Immediately"<<endl;}
	else if(disease==1 || disease==2 ||disease==3)
	{
	cout<<"Enter severity of Disease\n1. Stage 1\n2. Stage 2\n3. Stage 3"<<endl;
	cin>>svrty;
	if(svrty==1)
	{cout<<"Call Respective Doctor"<<endl;}
	if(svrty==2)
	{cout<<"Admit in Emergecy Ward"<<endl;}
	if(svrty==3)
	{cout<<"Admit in ICU Immediately"<<endl;}}
	cout<<"Enter Details of patient given by relative for Registeration"<<endl;
	reg();
}

void guest()
{
	string line, dept, f_name, last_name;
	int age, room_nu;
	int s_cnic,cnic;
cout<<"Enter 5 digit CNIC told by the Patient";
cin>>s_cnic;
ifstream read_file;
read_file.open("Record.txt");
bool isFound = false;
if(read_file.is_open())
{
	/*if(s_cnic==cnic)
	{*/
getline (read_file,line);

while(!read_file.eof())
{
read_file>>dept>>room_nu >>f_name>>last_name>>age>>cnic;
if(cnic == s_cnic)
{
cout<<"found"<<endl;

cout<<dept<<"   "<<room_nu<<"   "<<f_name<<"   "<<last_name<<"   "<<age<<"   "<<cnic<<endl;
isFound = true;
break;
}

}
	/*}
	else
	{cout<<"No Record Found";}*/
read_file.close();
}
}
void data()
{
	string line, dept, f_name, last_name;
	int age, room_nu;
	int s_cnic,cnic;
cout<<"Enter 5 digit CNIC told by the Patient";
cin>>s_cnic;
ifstream read_file;
read_file.open("Record.txt");
bool isFound = false;
if(read_file.is_open())
{
getline (read_file,line);

while(!read_file.eof())
{
read_file>>dept>>room_nu >>f_name>>last_name>>age>>cnic;
if(cnic == s_cnic)
{
cout<<"found"<<endl;

cout<<dept<<"   "<<room_nu<<"   "<<f_name<<"   "<<last_name<<"   "<<age<<"   "<<cnic<<endl;
isFound = true;
break;
}

}
read_file.close();
}

}