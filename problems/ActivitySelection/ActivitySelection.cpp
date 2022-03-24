// Main file of the Project
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// =========================================================================
// simple implementation for the activity selection

// // structure for an activity data with start and finish time
// struct Activity
// {
//     int start, finish;
// };

// // this is an activity comperator utility function used by sort
// bool activityCompare(Activity a1, Activity a2)
// {
//     return (a1.finish < a2.finish);
// }

// void printMaxActivity(Activity activityArr[], int len)
// {
//     // sort all job according to finish time
//     std::sort(activityArr, activityArr + len, activityCompare);

//     std::cout << "Following activities are selected : " << std::endl;

//     // first activity is always selected
//     int i = 0;
//     std::cout << "(" << activityArr[i].start << "," << activityArr[i].finish << ")" << std::endl;

//     for (int j = 0; j < len; j++)
//     {
//         // comparing if the start time of activity is greater than the previous activity than print it
//         if (activityArr[j].start >= activityArr[i].finish)
//         {
//             i = j;
//             std::cout << "(" << activityArr[i].start << "," << activityArr[i].finish << ")" << std::endl;
//         }
//     }
// }

// =========================================================================
// using stl for optimizations

void SelectActivity(vector<int> start, vector<int> finish)
{
    // a vector to store results
    vector<pair<int, int>> answer;

    // minimum priority to sort finish time in acending order, O(nlogn)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    for (long unsigned int i = 0; i < start.size(); i++)
    {
        Q.push(make_pair(finish[i], start[i]));
    }

    auto it = Q.top();
    auto s = it.second;
    auto f = it.first;

    Q.pop();

    answer.push_back(make_pair(s, f));

    while (!Q.empty())
    {
        auto itr = Q.top();
        Q.pop();
        if (itr.second >= f)
        {
            f = itr.first;
            s = itr.second;
            answer.push_back(make_pair(s, f));
        }
    }

    std::cout << "Following activities are selected : " << std::endl;

    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        std::cout << "(" << (*i).first << "," << (*i).second << ")" << std::endl;
    }
}

int main(int arg, char *argv[])
{
    // Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // printMaxActivity(arr, len);

    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    SelectActivity(s, f);

    return 0;
}