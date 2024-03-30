#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added successfully!\n";
    }

    void viewTasks() {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - "
                 << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }
};

int main() {
    TodoList todoList;
    char choice;
    string taskDescription;
    size_t taskIndex;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter task description: ";
                cin.ignore(); // Clear the buffer before getline
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case '2':
                todoList.viewTasks();
                break;
            case '3':
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskAsCompleted(taskIndex);
                break;
            case '4':
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case '5':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}

