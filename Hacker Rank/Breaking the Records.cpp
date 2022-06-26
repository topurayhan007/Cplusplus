#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores)
{
    vector<int> record;
    int arr[2] = {0, 0};
    int max = scores[0];
    int min = scores[0];
    int countMax = 0;
    int countMin = 0;
    int size = scores.size();
    for (int i = 1; i < size; ++i)
    {
        if (scores[i] < min)
        {
            min = scores[i];
            ++countMin;
        }
        if (scores[i] > max)
        {
            max = scores[i];
            ++countMax;
        }
    }
    record.push_back(countMax);
    record.push_back(countMin);
    return record;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cout<<"Number of games played(eg. 4): ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    cout << "Scores in each game(eg. 12 24 10 24): ";
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);
    cout<<"Records broken number of times(highest score, lowest score): ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "\n";

    fout.close();

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
