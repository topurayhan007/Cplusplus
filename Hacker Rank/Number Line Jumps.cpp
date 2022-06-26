#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the kangaroo function below.

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2)
{
    bool same = false;
    string yes = "YES";
    string no = "NO";
    int j1 = 0;
    int j2 = 0;
    int max = 0;
    if (x1 < 1000 || x2 < 1000)
    {
        max = 95000;
    }
    else
    {
        max = 95000000;
    }
    for (int i = x1; i <= max; i += v1)
    {
        for (int j = x2; j <= max; j += v2)
        {
            if (i == j && j1 == j2)
            {
                same = true;
                break;
            }
            else
            {
                same = false;
            }
            ++j2;
        }
        if (same == true && j1 == j2)
        {
            break;
        }
        j2 = 0;
        j1++;
    }
    if (same == true)
    {
        return yes;
    }
    else
    {
        return no;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x1V1X2V2_temp;
    cout<<"Enter the Kangaroos position and velocity(eg. k1 v1 k2 v2): ";
    getline(cin, x1V1X2V2_temp);

    vector<string> x1V1X2V2 = split_string(x1V1X2V2_temp);

    int x1 = stoi(x1V1X2V2[0]);

    int v1 = stoi(x1V1X2V2[1]);

    int x2 = stoi(x1V1X2V2[2]);

    int v2 = stoi(x1V1X2V2[3]);

    string result = kangaroo(x1, v1, x2, v2);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
