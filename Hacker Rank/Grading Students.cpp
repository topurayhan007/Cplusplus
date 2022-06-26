#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades)
{
    vector<int> finalGrade(grades.size());
    for (int i = 0; i < grades.size(); ++i)
    {
        int x = ((grades[i]) / 5 + 1) * 5;
        if (grades[i] % 5 != 0 && !(grades[i] < 38) && (x - grades[i]) < 3)
        {
            finalGrade[i] = x;
        }
        else
        {
            finalGrade[i] = grades[i];
        }
    }
    return finalGrade;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    cout << "Enter the no. of students(eg. 4): ";
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++)
    {
        string grades_item_temp;
        cout << "Enter the mark of the student "<<i+1<<" (eg. 93): ";
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }
    cout<<endl;
    vector<int> result = gradingStudents(grades);
    cout << "The new marksheet is: "<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
