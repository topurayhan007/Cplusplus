#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr)
{
    long int min = 0;
    long int max = 0;
    long int min_sum = 0;
    long int max_sum = 0;

    min = *min_element(arr.begin(), arr.end());
    max = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < 5; ++i)
    {
        if (max == min)
        {
            if (i != 4)
            {
                min_sum += arr[i];
            }
            if (i != 0)
            {
                max_sum += arr[i];
            }
        }
        else
        {
            if (arr[i] != max)
            {
                min_sum += arr[i];
            }
            if (arr[i] != min)
            {
                max_sum += arr[i];
            }
        }
    }
    cout <<"The minimum sum is: " <<min_sum << '\n'<<"The maximum sum is: " << max_sum << endl;
}

int main()
{
    string arr_temp_temp;
    cout<<"Enter 5 elements of an array(eg. 1 3 4 10 2): ";
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
