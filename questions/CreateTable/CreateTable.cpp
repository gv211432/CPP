// // Main file of the Project
// #include <bits/stdc++.h>
// using namespace std;

// namespace boxes
// {

//     void print_pipe(int a, int b)
//     {
//         std::cout << "|  ";
//         for (size_t j = 0; j <= b; j++)
//             std::cout << "  |   ";
//         std::cout << std::endl;

//         std::cout << "|  ";
//         for (size_t j = 0; j <= b; j++)
//             std::cout << "  |   ";
//         std::cout << std::endl;

//         std::cout << "|  ";
//         for (size_t j = 0; j <= b; j++)
//             std::cout << "  |   ";
//         std::cout << std::endl;
//     }

//     void print_pipe_content(vector<int> v)
//     {
//         int b = v.size() - 1;

//         // std::cout << "|  ";
//         // for (size_t j = 0; j <= b; j++)
//         //     std::cout << "  |   ";
//         // std::cout << std::endl;

//         for (size_t j = 0; j < v.size(); j++)
//         {
//             int len = 0;
//             int num = v[j];
//             while (num > 0)
//                 num /= 10, len++;

//             if (j == 0)
//             {
//                 std::cout << "|";
//                 int mid = (4 - len) / 2;
//                 for (size_t k = 0; k < 5; k++)
//                 {
//                     if (k == mid)
//                     {
//                         cout << "\033[32m" << v[j] << "\033[0m";
//                         k += len;
//                         continue;
//                     }
//                     cout << " ";
//                 }
//             }
//             else
//             {
//                 std::cout << "|";
//                 int mid = (5 - len) / 2;
//                 for (size_t k = 0; k < 6; k++)
//                 {
//                     if (k == mid)
//                     {
//                         cout << "\033[32m" << v[j] << "\033[0m";
//                         k += len;
//                         continue;
//                     }
//                     cout << " ";
//                 }
//                 if (j >= (v.size() - 1))
//                     cout << "|\n";
//             }
//         }

//         // std::cout << "|  ";
//         // for (size_t j = 0; j <= b; j++)
//         //     std::cout << "  |   ";
//         // std::cout << std::endl;
//     }

//     class Solution
//     {
//     public:
//         void Table(size_t a, size_t b)
//         {
//             if (b == 0)
//             {
//                 for (size_t i = 0; i <= a; i++)
//                 {
//                     if (i > 0 and i < a)
//                         print_pipe(a, b);

//                     if (i == a - 1)
//                         continue;

//                     for (size_t j = 0; j <= b; j++)
//                     {
//                         if (i == 0 && j == 0)
//                             std::cout << "┌────┐";
//                         else if (i == 0 and j == b)
//                             std::cout << "┌────┐";
//                         else if (i == a and j == 0)
//                             std::cout << "└────┘";
//                         else if (i == a and j == b)
//                             std::cout << "└────┘";
//                         else if (j == 0)
//                             std::cout << "+────+";
//                         else if (j == b)
//                             std::cout << "+────+";
//                         else
//                             std::cout << "──────";
//                     }
//                     std::cout << " " << std::endl;
//                 }
//                 std::cout << " " << std::endl;
//             }
//             else if (a == 1)
//             {
//             }
//             else
//             {
//                 for (size_t i = 0; i <= a; i++)
//                 {
//                     if (i > 0 and i < a)
//                         print_pipe(a, b);

//                     if (i == a - 1)
//                         continue;

//                     for (size_t j = 0; j <= b; j++)
//                     {
//                         if (i == 0 && j == 0)
//                             std::cout << "┌─────";
//                         else if (i == 0 and j == b)
//                             std::cout << "─────┐";
//                         else if (i == a and j == 0)
//                             std::cout << "└─────";
//                         else if (i == a and j == b)
//                             std::cout << "─────┘";
//                         else if (j == 0)
//                             std::cout << "+─────";
//                         else if (j == b)
//                             std::cout << "─────+";
//                         else
//                             std::cout << "──────";
//                     }
//                     std::cout << " " << std::endl;
//                 }
//                 std::cout << " " << std::endl;
//             }
//         }

//         void table_with_content(vector<vector<int>> &v)
//         {
//             int a = v.size() + 1, b = v[0].size() - 1;
//             if (b == 0)
//             {
//                 for (size_t i = 0; i <= a; i++)
//                 {
//                     if (i > 0 and i < a)
//                         print_pipe_content(v[i - 1]);

//                     if (i == a - 1)
//                         continue;

//                     for (size_t j = 0; j <= b; j++)
//                     {
//                         if (i == 0 && j == 0)
//                             std::cout << "┌────┐";
//                         else if (i == 0 and j == b)
//                             std::cout << "┌────┐";
//                         else if (i == a and j == 0)
//                             std::cout << "└────┘";
//                         else if (i == a and j == b)
//                             std::cout << "└────┘";
//                         else if (j == 0)
//                             std::cout << "+────+";
//                         else if (j == b)
//                             std::cout << "+────+";
//                         else
//                             std::cout << "──────";
//                     }
//                     std::cout << " " << std::endl;
//                 }
//                 std::cout << " " << std::endl;
//             }
//             else if (a == 1)
//             {
//             }
//             else
//             {
//                 for (size_t i = 0; i <= a; i++)
//                 {
//                     if (i > 0 and i < a)
//                         print_pipe_content(v[i - 1]);

//                     if (i == a - 1)
//                         continue;

//                     for (size_t j = 0; j <= b; j++)
//                     {
//                         if (i == 0 && j == 0)
//                             std::cout << "┌─────";
//                         else if (i == 0 and j == b)
//                             std::cout << "─────┐";
//                         else if (i == a and j == 0)
//                             std::cout << "└─────";
//                         else if (i == a and j == b)
//                             std::cout << "─────┘";
//                         else if (j == 0)
//                             std::cout << "+─────";
//                         else if (j == b)
//                             std::cout << "─────+";
//                         else
//                             std::cout << "──────";
//                     }
//                     std::cout << " " << std::endl;
//                 }
//                 std::cout << " " << std::endl;
//             }
//         }
//     };

// } // namespace boxes
// int main(int arg, char *argv[])
// {
//     // int a = atoi(argv[1]);
//     // int b = atoi(argv[2]);
//     vector<vector<int>> v = {{5000, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

//     if (arg == 3)
//     {
//         if (atoi(argv[1]) == 0 or atoi(argv[2]) == 0)
//         {
//             std::cout << "Invalid Dimensionss" << std::endl;
//             return 0;
//         }
//         boxes::Solution s;
//         s.Table(atoi(argv[1]) + 1, atoi(argv[2]) - 1);

//         // s.Table(v.size() + 1, v[0].size() - 1);

//         // s.table_with_content(v);
//     }
//     else
//     {
//         std::cout << "Please enter dimensions! Eg: boxes 5 5" << std::endl;
//     }
//     return 0;
// }