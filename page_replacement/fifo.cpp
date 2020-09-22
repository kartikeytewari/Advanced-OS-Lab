#include <bits/stdc++.h>
using namespace std;

vector<int> page;
void spawn_pages(int n)
{
    srand(time(NULL));
    for (int i=0;i<=n-1;i++)
    {
        int a=(rand()%100)+1;
        page.push_back(a);
    }
}

int main()
{
    int n, max_buffer_size;
    cout << "Enter number of pages to simulate= ";
    cin >> n;
    cout << "Enter number of pages that can be inserted in buffer= ";
    cin >> max_buffer_size;

    spawn_pages(n);
    vector<int> buffer;
    int page_fault=0;
    for (int i=0;i<=n-1;i++)
    {
        bool flag=false;
        for (auto it=buffer.begin();it!=buffer.end();it++)
        {
            if (*it==page[i])
            {
                flag=true;
            }
        }

        if (!flag)
        {
            page_fault++;
            buffer.push_back(page[i]);
            if (max_buffer_size==(int)buffer.size())
            {
                buffer.erase(prev(buffer.end()));
            }
        }
    }

    cout << "Number of page faults= " << page_fault << endl;
    cout << "Percentage of page fault= " << (page_fault*100)/n << endl;

    return 0;
}