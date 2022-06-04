#ifndef gauravsConvertVector
#define gauravsConvertVector

namespace convert_vec
{

#include <iostream>
#include <vector>
    using namespace std;

    class Convert
    {

        // ╻┏┓╻╺┳╸┏━╸┏━╸┏━╸┏━┓
        // ┃┃┗┫ ┃ ┣╸ ┃╺┓┣╸ ┣┳┛
        // ╹╹ ╹ ╹ ┗━╸┗━┛┗━╸╹┗╸
        vector<vector<int>> aoa_to_vov(int *arr_of_arr, size_t len, size_t width)
        {
            // generating new vector of vector using array of array
            vector<vector<int>> v(len, vector<int>(width, 0));
            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    v[i][j] = *(arr_of_arr + i + j);
            return v;
        }

        vector<int> arr_to_vec(int *arr, size_t len)
        {
            vector<int> v(len, 0);
            for (size_t i = 0; i < len; i++)
                v[i] = *(arr + i);
            return v;
        }

        int *vov_to_aoa(vector<vector<int>> &v)
        {
            int len = v.size(), width = v[0].size();
            int arr_of_arr[len][width] = {};

            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    arr_of_arr[i][j] = v[i][j];

            return *arr_of_arr;
        }

        int *vec_to_arr(vector<int> &v)
        {
            int len = v.size();
            int arr[len] = {};

            for (size_t i = 0; i < len; i++)
                arr[i] = v[i];

            return arr;
        }

        // ┏┓ ┏━┓┏━┓╻  ┏━╸┏━┓┏┓╻
        // ┣┻┓┃ ┃┃ ┃┃  ┣╸ ┣━┫┃┗┫
        // ┗━┛┗━┛┗━┛┗━╸┗━╸╹ ╹╹ ╹
        vector<vector<bool>> aoa_to_vov(bool *arr_of_arr, size_t len, size_t width)
        {
            // generating new vector of vector using array of array
            vector<vector<bool>> v(len, vector<bool>(width, 0));
            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    v[i][j] = *(arr_of_arr + i + j);
            return v;
        }

        vector<bool> arr_to_vec(bool *arr, size_t len)
        {
            vector<bool> v(len, 0);
            for (size_t i = 0; i < len; i++)
                v[i] = *(arr + i);
            return v;
        }

        bool *vov_to_aoa(vector<vector<bool>> &v)
        {
            size_t len = v.size(), width = v[0].size();
            bool arr_of_arr[len][width] = {};

            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    arr_of_arr[i][j] = v[i][j];

            return *arr_of_arr;
        }

        bool *vec_to_arr(vector<bool> &v)
        {
            size_t len = v.size();
            bool arr[len] = {};

            for (size_t i = 0; i < len; i++)
                arr[i] = v[i];

            return arr;
        }

        // ┏━╸╻ ╻┏━┓┏━┓┏━┓┏━╸╺┳╸┏━╸┏━┓
        // ┃  ┣━┫┣━┫┣┳┛┣━┫┃   ┃ ┣╸ ┣┳┛
        // ┗━╸╹ ╹╹ ╹╹┗╸╹ ╹┗━╸ ╹ ┗━╸╹┗╸
        vector<vector<char>> aoa_to_vov(char *arr_of_arr, size_t len, size_t width)
        {
            // generating new vector of vector using array of array
            vector<vector<char>> v(len, vector<char>(width, 0));
            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    v[i][j] = *(arr_of_arr + i + j);
            return v;
        }

        vector<char> arr_to_vec(char *arr, size_t len)
        {
            vector<char> v(len, 0);
            for (size_t i = 0; i < len; i++)
                v[i] = *(arr + i);
            return v;
        }

        char *vov_to_aoa(vector<vector<char>> &v)
        {
            size_t len = v.size(), width = v[0].size();
            char arr_of_arr[len][width] = {};

            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    arr_of_arr[i][j] = v[i][j];

            return *arr_of_arr;
        }

        char *vec_to_arr(vector<char> &v)
        {
            size_t len = v.size();
            char arr[len] = {};

            for (size_t i = 0; i < len; i++)
                arr[i] = v[i];

            return arr;
        }

        // ┏━┓╺┳╸┏━┓╻┏┓╻┏━╸
        // ┗━┓ ┃ ┣┳┛┃┃┗┫┃╺┓
        // ┗━┛ ╹ ╹┗╸╹╹ ╹┗━┛
        vector<vector<string>> aoa_to_vov(string *arr_of_arr, size_t len, size_t width)
        {
            // generating new vector of vector using array of array
            vector<vector<string>> v(len, vector<string>(width, 0));
            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    v[i][j] = *(arr_of_arr + i + j);
            return v;
        }

        vector<string> arr_to_vec(string *arr, size_t len)
        {
            vector<string> v(len, 0);
            for (size_t i = 0; i < len; i++)
                v[i] = *(arr + i);
            return v;
        }

        string *vov_to_aoa(vector<vector<string>> &v)
        {
            size_t len = v.size(), width = v[0].size();
            string arr_of_arr[len][width] = {};

            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    arr_of_arr[i][j] = v[i][j];

            return *arr_of_arr;
        }

        string *vec_to_arr(vector<string> &v)
        {
            size_t len = v.size();
            string arr[len] = {};

            for (size_t i = 0; i < len; i++)
                arr[i] = v[i];

            return arr;
        }

        // ┏━╸╻  ┏━┓┏━┓╺┳╸
        // ┣╸ ┃  ┃ ┃┣━┫ ┃
        // ╹  ┗━╸┗━┛╹ ╹ ╹
        vector<vector<float>> aoa_to_vov(float *arr_of_arr, size_t len, size_t width)
        {
            // generating new vector of vector using array of array
            vector<vector<float>> v(len, vector<float>(width, 0));
            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    v[i][j] = *(arr_of_arr + i + j);
            return v;
        }

        vector<float> arr_to_vec(float *arr, size_t len)
        {
            vector<float> v(len, 0);
            for (size_t i = 0; i < len; i++)
                v[i] = *(arr + i);
            return v;
        }

        float *vov_to_aoa(vector<vector<float>> &v)
        {
            size_t len = v.size(), width = v[0].size();
            float arr_of_arr[len][width] = {};

            for (size_t i = 0; i < len; i++)
                for (size_t j = 0; j < width; j++)
                    arr_of_arr[i][j] = v[i][j];

            return *arr_of_arr;
        }

        float *vec_to_arr(vector<float> &v)
        {
            size_t len = v.size();
            float arr[len] = {};

            for (size_t i = 0; i < len; i++)
                arr[i] = v[i];

            return arr;
        }
    };

};

#endif