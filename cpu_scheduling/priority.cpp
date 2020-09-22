// Name: Kartikey Tewari
// Roll No.: 17MI551
// Computer Science and Engineering (Dual Degree)
// National Institute of Technology, Hamirpur
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id;
    int arrival_time;
    int start_time;
    int duration;
    int end_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};

vector<process> process_data;
void spawn_process(int n)
{
    for (int i=0;i<=n-1;i++)
    {
        srand(time(NULL)+100*i);
        process temp;
        temp.id=i;
        temp.arrival_time=(rand()%100)+1;;
        temp.duration=(rand()%100)+1;
        temp.priority=(rand()%10)+1;
        process_data.push_back(temp);
    }
}

bool compare (process a, process b)
{
    if (a.arrival_time!=b.arrival_time)
    {
        return a.arrival_time<b.arrival_time;
    }
    else if (a.priority!=b.priority)
    {
        return a.priority<b.priority;
    }
    else
    {
        return a.id<b.id;
    }
}

void debug_data()
{
    for (auto it=process_data.begin();it!=process_data.end();it++)
    {
        cout << it->id << " " << it->arrival_time << " " << it->duration << endl;
    }
}

void print_info(int i)
{
    cout << "Process id= " << process_data[i].id << endl;
    cout << "Arrival Time= " << process_data[i].arrival_time << endl;
    cout << "Start Time= " << process_data[i].start_time << endl;
    cout << "Process CPU Burst Time= " << process_data[i].duration << endl;
    cout << "End Time= " << process_data[i].end_time << endl;
    cout << "Waiting time= " << process_data[i].waiting_time << endl;
    cout << "Turn Around Time= " << process_data[i].turn_around_time << endl << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes to spawn= ";
    cin >> n;

    spawn_process(n);
    sort(process_data.begin(),process_data.end(),compare);
    debug_data();

    int t=0;
    int avg_wt=0;
    int avg_tat=0;
    for (int i=0;i<=n-1;i++)
    {
        t=max(t,process_data[i].arrival_time);
        process_data[i].start_time=t;
        t+=process_data[i].duration;
        process_data[i].end_time=t;
        process_data[i].waiting_time=process_data[i].start_time-process_data[i].arrival_time;
        process_data[i].turn_around_time=process_data[i].end_time-process_data[i].arrival_time;

        avg_wt+=process_data[i].waiting_time;
        avg_tat+=process_data[i].turn_around_time;
        print_info(i);
    }

    avg_wt/=n;
    avg_tat/=n;

    cout << "Average waiting time= " << avg_wt << endl;
    cout << "Average turn around time= " << avg_tat << endl;

    return 0;
}