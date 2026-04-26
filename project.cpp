#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    int id;
    string subject;
    string topic;
    string deadline;
    string priority;
    bool completed;

    Task(int i, string s, string t, string d, string p) {
        id = i;
        subject = s;
        topic = t;
        deadline = d;
        priority = p;
        completed = false;
    }
};

class StudySession {
public:
    string subject;
    float hours;
    string date;

    StudySession(string s, float h, string d) {
        subject = s;
        hours = h;
        date = d;
    }
};

vector<Task> tasks;
vector<StudySession> sessions;

void addTask() {
    int id = tasks.size() + 1;
    string subject, topic, deadline, priority;

    cout << "Enter Subject: ";
    cin >> subject;
    cout << "Enter Topic: ";
    cin >> topic;
    cout << "Enter Deadline: ";
    cin >> deadline;
    cout << "Enter Priority (High/Medium/Low): ";
    cin >> priority;

    tasks.push_back(Task(id, subject, topic, deadline, priority));
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- TASK LIST ---\n";
    for (auto &t : tasks) {
        cout << "ID: " << t.id
             << " | " << t.subject << " - " << t.topic
             << " | Deadline: " << t.deadline
             << " | Priority: " << t.priority
             << " | Status: " << (t.completed ? "Done" : "Pending") << endl;
    }
}

void markCompleted() {
    int id;
    cout << "Enter Task ID to mark complete: ";
    cin >> id;

    for (auto &t : tasks) {
        if (t.id == id) {
            t.completed = true;
            cout << "Marked as completed!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask() {
    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {                //deleting task needs iterator, so we use it instead of auto &t
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void addSession() {
    string subject, date;
    float hours;

    cout << "Enter Subject: ";
    cin >> subject;
    cout << "Enter Study Hours: ";
    cin >> hours;
    cout << "Enter Date: ";
    cin >> date;

    sessions.push_back(StudySession(subject, hours, date));
    cout << "Session added!\n";
}

void viewSessions() {
    if (sessions.empty()) {
        cout << "No study sessions.\n";
        return;
    }

    cout << "\n---Study sessions---\n";
    for (auto &s : sessions) {
        cout << s.subject << " | " << s.hours << " hrs | " << s.date << endl;
    }
}

void showSummary() {
    int completed = 0, pending = 0, highPending = 0;
    float totalHours = 0;

    for (auto &t : tasks) {
        if (t.completed) 
            completed++;
        else {
            pending++;
            if (t.priority == "High") highPending++;
        }
    }

    for (auto &s : sessions) {
        totalHours += s.hours;
    }

    int focusScore = (completed * 10) + (totalHours * 5) - (highPending * 7);

    cout << "\n===== SUMMARY =====\n";
    cout << "Total Tasks: " << tasks.size() << endl;
    cout << "Completed: " << completed << endl;
    cout << "Pending: " << pending << endl;
    cout << "Total Study Hours: " << totalHours << endl;
    cout << "Focus Score: " << focusScore << "/100\n";
}

int main() {
    int choice;

    do {
        cout << "\nSMART STUDY PLANNER\n";
        cout << "1) Add Task\n";
        cout << "2) View Tasks\n";
        cout << "3) Mark Task Completed\n";
        cout << "4) Delete Task\n";
        cout << "5) Add Study Session\n";
        cout << "6) View Study Sessions\n";
        cout << "7)Show Summary\n";
        cout << "8) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                addTask(); 
                break;
            case 2: 
                viewTasks();
                break;
            case 3: 
                markCompleted(); 
                break;
            case 4: 
                deleteTask(); 
                break;
            case 5: 
                addSession(); 
                break;
            case 6: 
                viewSessions(); 
                break;
            case 7: 
                showSummary(); 
                break;
            case 8: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}