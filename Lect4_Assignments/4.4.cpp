#include <iostream>
using namespace std;
struct Student{
	int id;
	char name[101];
	char className[31];
	bool exists;
};
Student students[1000];
int studentCount = 0;
void insertStudent(int id, const char* name, const char* className){
	for(int i = 0; i < studentCount; i++){
		if (students[i].id == id){
		}
	}
	students[studentCount].id = id;
	int i = 0;
	while (name[i] != '\0'){
		students[studentCount].name[i] = name[i];
		i++;
	}
	students[studentCount].name[i] = '\0';
	i = 0;
	while (className[i] != '\0'){
		students[studentCount].className[i]= className[i];
		i++;
	}
	students[studentCount].className[i] = '\0';
	students[studentCount].exists = true;
	studentCount++;
}
void deleteStudent(int id){
	for (int i = 0; i < studentCount; i++){
		if (students[i].id == id){
			student[i].exists = false;
			return;
		}
	}
}
void getInfo(int id){
	for(int i = 0; i < studentCount; i++){
		if(students[i].id == id && students[i].exists){
			cout << students[i].name << " , " << students[i].className << endl;
			return;
		}
	}
	cout <<"NA, NA" << endl;
}
void processCommand(const char* command){
	if (command[0] == 'I'){
		int id;
		char name[101], className[31];
		sscanf(command, "Insert(%d,%[^,],%[^)])", &id, name, className);
        insertStudent(id, name, className);
    } 
    else if (command[0] == 'D') {  // Delete
        int id;
        sscanf(command, "Delete(%d)", &id);
        deleteStudent(id);
    } 
    else if (command[0] == 'I' && command[1] == 'n') {
    	int id;
        sscanf(command, "Infor(%d)", &id);
        getInfo(id);
	}
}
int main() {
    char command[200];
    while (cin.getline(command, 200)) {
        processCommand(command);
    }
    return 0;
}
