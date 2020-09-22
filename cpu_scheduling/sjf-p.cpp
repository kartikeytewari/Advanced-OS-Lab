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
    int rem_time;
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
        temp.start_time=-1;
        temp.duration=(rand()%100)+1;
        temp.rem_time=temp.duration;
        process_data.push_back(temp);
    }
}

void debug_data()
{
    for (auto it=process_data.begin();it!=process_data.end();it++)
    {
        cout << it->id << " " << it->arrival_time << " " << it->duration << endl;
    }
}

bool compare (process a, process b)
{
    if (a.arrival_time!=b.arrival_time)
    {
        return a.arrival_time<b.arrival_time;
    }
    else
    {
        return a.id<b.id;
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

    int t=0;
    int avg_wt=0;
    int avg_tat=0;
    int comp_process=0;
    while (comp_process<=n-1)
    {
        vector<pair<int,int>> buffer;
        for (int i=0;i<=n-1;i++)
        {
            if ((process_data[i].rem_time!=0)&&(process_data[i].arrival_time<=t))
            {
                buffer.push_back(make_pair(process_data[i].rem_time,i));
            }
        }

        if (buffer.size()!=0)
        {
            sort(buffer.begin(),buffer.end());
            int local_id=buffer.begin()->second;
            process_data[local_id].rem_time--;
            if (process_data[local_id].start_time==-1)
            {
                process_data[local_id].start_time=t;
                process_data[local_id].waiting_time=process_data[local_id].start_time-process_data[local_id].arrival_time;
                avg_wt+=process_data[local_id].waiting_time;
            }
            if (process_data[local_id].rem_time==0)
            {
                process_data[local_id].end_time=t;
                process_data[local_id].turn_around_time=process_data[local_id].end_time-process_data[local_id].arrival_time;
                avg_tat+=process_data[local_id].turn_around_time;
                comp_process++;
            }
        }

        t++;
    }

    for (int i=0;i<=n-1;i++)
    {
        print_info(i);
    }

    avg_wt/=n;
    avg_tat/=n;
    
    cout << "Average waiting time= " << avg_wt << endl;
    cout << "Average turn around time= " << avg_tat << endl;

    return 0;
}