#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

const int MAX = 100;
const int subject = 5;

struct student{
	int id;
	string name;
	float marks[subject];
	float gpa;
	char grade;
};

student students[MAX];
int studentcount = 0;


char calculategrade(float gpa){
	if(gpa >= 4.0)
		return 'A';
	else if(gpa >= 3.5)
		return 'B';
	else if(gpa >= 3.0)
		return 'C';
	else if(gpa >= 2.5)
		return 'D';
	else if(gpa >= 2.0)
		return 'E';
	else 
		return 'F';
}

void calculategpa(student &s){
	float sum = 0;
	for(int i = 0; i < subject; i++)
		sum += s.marks[i];

	float avg = sum / subject;

	if(avg >= 85)
		s.gpa = 4.0;
	else if(avg >= 75)
		s.gpa = 3.5;
	else if(avg >= 65)
		s.gpa = 3.0;
	else if(avg >= 55)
		s.gpa = 2.5;
	else if(avg >= 50)
		s.gpa = 2.0;
	else
		s.gpa = 1.0;
	s.grade = calculategrade(s.gpa);
}

void loadfromfile(){
	ifstream fin("student.txt");
	if(!fin)
		return;
	studentcount = 0;
	while(fin >> students[studentcount].id){
		fin.ignore();
		getline(fin, students[studentcount].name);
		for(int i = 0; i < subject; i++)
			fin >> students[studentcount].marks[i];
		calculategpa(students[studentcount]);
		studentcount++;
	}
	fin.close();
}

void savetofile(){
	ofstream fout("student.txt");

	for(int i = 0; i < studentcount; i++){
		fout << students[i].id << endl;
		fout << students[i].name << endl;
		for(int j = 0; j < subject; j++)
			fout << students[i].marks[j] << " ";
		fout << endl;
	}
	fout.close();
}

void addstudent(){
	student s;
	cout<<"enter student id:";
	cin>>s.id;
	cin.ignore();
	cout<<"enter student name:";
	getline(cin,s.name);
	for(int i = 0; i < subject; i++){
		do{
			cout<<"enter marks of subject "<<i + 1<<":";
			cin>>s.marks[i];
		}while(s.marks[i] < 0 || s.marks[i] > 100);
	}
	calculategpa(s);
	students[studentcount++] = s;
	cout<<"student added successfully"<<endl;
}

void displaystudent(){
	cout<< left << setw(8)<<"id"
		<<setw(18)<<"name"
		<<setw(10)<<"gpa"
		<<setw(8)<<"grade"<<endl;
	for(int i = 0; i < studentcount; i++){
		cout<<left<<setw(8)<<students[i].id
			<<setw(18)<<students[i].name
			<<setw(10)<<fixed<<setprecision(2)<<students[i].gpa
			<<setw(8)<<students[i].grade<<endl;
	}
}

int searchbyid(int id){
	for(int i = 0; i < studentcount; i++)
		if(students[i].id == id)
			return i;

	return -1;
}

void sortbygpa(){
	for(int i = 0; i < studentcount - 1; i++){
		for(int j = i + 1; j < studentcount; j++){
			if(students[j].gpa > students[i].gpa){
				student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void exportReport() {
    ofstream fout("report.txt");
    if(!fout) {
        cout << "Unable to create report file.\n";
        return;
    }

    fout << "------ Top 3 Students ------\n";
    for(int i = 0; i < studentcount && i < 3; i++) {
        fout << students[i].name << " | GPA: " << fixed << setprecision(2) << students[i].gpa
             << " | Grade: " << students[i].grade << endl;
    }
    fout << "\n";

    fout << "------ Subject Averages ------\n";
    for(int s = 0; s < subject; s++) {
        float sum = 0;
        for(int i = 0; i < studentcount; i++)
            sum += students[i].marks[s];
        fout << "Subject " << s + 1 << ": " 
             << (studentcount ? sum / studentcount : 0) << endl;
    }
    fout << "\n";

    int pass = 0, fail = 0;
    for(int i = 0; i < studentcount; i++){
        if(students[i].gpa >= 2.0)
            pass++;
        else
            fail++;
    }
    fout << "------ Pass/Fail Ratio ------\n";
    fout << "Pass: " << pass << endl;
    fout << "Fail: " << fail << endl;

    fout.close();
    cout << "Report exported successfully to 'report.txt'.\n";
}

void updatestudent(){
	int id;
	cout<<"enter student id to update:"<<endl;
	cin>>id;

	int index = searchbyid(id);
	if(index == -1){
		cout<<"student not found";
		return;
	}
	cout<<"enter new id:"<<endl;
	cin>>students[index].id;
	cin.ignore();
	cout<<"enter new name:"<<endl;
	getline(cin, students[index].name);
	for(int i = 0; i < subject; i++){
		cout<<"enter new marks for subject "<<i + 1<<":";
		cin>>students[index].marks[i];
	}
	calculategpa(students[index]);
	cout<<"student record updated."<<endl;
}

int main(){
	loadfromfile();
	int choice;
	do{
		cout<<"-------student grading system--------"<<endl;
		cout<<"1.Add student"<<endl;
		cout<<"2.Display student"<<endl;
		cout<<"3.update student"<<endl;
		cout<<"4.search student"<<endl;
		cout<<"5.sort by gpa"<<endl;
		cout<<"6.Export Report to file"<<endl;
		cout<<"7.exit"<<endl;
		cout<<"enter the choice :"<<endl;

		cin>>choice;
		switch(choice){
			case 1: addstudent(); break;
			case 2: displaystudent(); break;
			case 3: updatestudent(); break;
			case 4:{
				int id;
				cout<<"enter id to search:";
				cin>>id;
				int idx = searchbyid(id);
				if(idx == -1)
					cout<<"record not found.\n";
				else{
					cout<<"name:"<<students[idx].name<<endl;
					cout<<"GPA:"<<students[idx].gpa<<endl;
					cout<<"grade:"<<students[idx].grade<<endl;
				}
				break;
			}
			case 5: sortbygpa();
				cout<<"sort successful:"<<endl;
				break;
		
			case 6:exportReport();
			 break;
			case 7: savetofile();
				cout<<"data saved and program exit."<<endl;
				break;
			default:
				cout<<"invalid choice:"<<endl;
		}

	}while(choice != 7);

	return 0;
}
