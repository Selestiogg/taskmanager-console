#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;

void loadTasks(vector<string>& tasks) {
    ifstream file("tasks.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
}

void saveTasks(const vector<string>& tasks) {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

int main() {
    int choice;
    vector<string> tasks;

    loadTasks(tasks);

    do {
        cout << "\n=== Task Manager ===" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Show all tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose action: ";

        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string task;
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            saveTasks(tasks);
            cout << "Task added!" << endl;
            break;
        }
        case 2:
            if (tasks.empty()) {
                cout << "Task list is empty" << endl;
            }
            else {
                for (size_t i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
            break;
        case 3:
            if (tasks.empty()) {
                cout << "No tasks to delete" << endl;
            }
            else {
                int num;
                cout << "Enter task number to delete: ";
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks.erase(tasks.begin() + num - 1);
                    saveTasks(tasks);
                    cout << "Task deleted!" << endl;
                }
                else {
                    cout << "Invalid number" << endl;
                }
            }
            break;
        case 0:
            cout << "Exit..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}