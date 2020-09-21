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
    bool valid;
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
        temp.valid=true;
        process_data.push_back(temp);
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
    cout << "End Data= " << process_data[i].end_time << endl;
    cout << "Waiting time= " << process_data[i].waiting_time << endl;
    cout << "Turn Around Time= " << process_data[i].turn_around_time << endl << endl;
}

int main()
{
    int n, quantum;
    cout << "Enter number of processes to spawn= ";
    cin >> n;
    cout << "Quantum Value= ";
    cin >> quantum;

    spawn_process(n);
    sort(process_data.begin(),process_data.end(),compare);
    
    int t=0;
    int avg_wt=0;
    int avg_tat=0;
    int comp_process=0;
    vector<int> buffer;
    while (comp_process<=n-1)
    {
        for (int i=0;i<=n-1;i++)
        {
            if ((process_data[i].valid)&&(process_data[i].arrival_time<=t))
            {
                buffer.push_back(i);
            }
        }

        if (buffer.size()==0)
        {
            for (int i=0;i<=n-1;i++)
            {
                if (process_data[i].valid)
                {
                    t=process_data[i].arrival_time;
                    buffer.push_back(i);
                    break;
                }
            }
        }

        int local_id=buffer.begin()->id;
        
    }


    avg_tat/=n;
    avg_wt/=n;

    cout << "Average waiting time= " << avg_wt << endl;
    cout << "Average turn around time= " << avg_tat << endl;

    return 0;
}