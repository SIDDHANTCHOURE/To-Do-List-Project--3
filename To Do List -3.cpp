#include <iostream>
#include <unistd.h>
using namespace std;

void print_task(string task[], int task_count) {
  cout << " Task To Do: " << endl;
  cout << "-----------------" << endl;
  for (int i = 0; i < task_count; i++) {
    cout << "Task" << i << ": " << task[i] << endl;
  }
  cout << "------------------------" << endl;
}
 
   int main () {
     system("color a");
     string tasks[10] = {""};
     //counter var -> know how many task we have
     int task_count = 0;

     int option = -1;
     while (option != 0) {

       //we will make menuu here
       cout << "--- To Do List  --->" << endl;
       cout << "1 - To Add New Task" << endl;
       cout << "2 - To View Tasks" << endl;
       cout << "3 - To Delete Task" << endl;
       cout << "0 - Terminate the Program" << endl;
       cin >> option;


       switch(option) {
         case 1:
         {
           if(task_count >9) {
             cout << " ''' Task List is Full ''' " << endl;
           }
           else {
             cout << " Enter A New Task: ";
             cin.ignore();
             getline(cin,tasks[task_count]);
             task_count++;
           }
           break;
         }
         case 2:
         {
           print_task(tasks, task_count);
           break;
           case 3:
             {
               int del_task = 0;
               cout << "Enter Task Number To Delete: "; 
               cin >> del_task;

               if (del_task < 0 || del_task > 9) {
                 cout << " You Entered Invalid Task Number " << endl;
                 break;
               }
               for (int i = del_task; i < task_count - 1; i++) {
                 tasks[i] = tasks[i + 1];
               }
               task_count = task_count - 1;
               break;
             }
           case 0:
           cout << "Terminating Program --- --- --- ---" << endl;
           break;
           default:
           cout << "You Entered Invalid Option" << endl;
         }
       }
     }


     return 0;
   } 