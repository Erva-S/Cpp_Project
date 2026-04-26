#include<iostream>
#include<vector>
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
vector<Task> tasks;
int main()
{
    cout<<tasks.size()+1<<endl;
    cout<<tasks.size()+1<<endl;
    return 0;
}