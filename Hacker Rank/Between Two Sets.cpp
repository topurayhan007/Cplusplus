#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b)
{
    int szA = a.size();
    int szB = b.size(); 
    int start = a[szA - 1]; 
    int end = b[0]; 
    int factorA = 0;
    int factorB = 0;
    int count = 0;

    for (int i = start; i <= end; ++i)
    {
        for (int j = 0; j < szA; ++j)
        {
            if (a[j] % i == 0 || i % a[j]==0)
            {
                factorA = i;
            }
            else
            {
                factorA = 0;
                break;
            }
        }
        for (int k = 0; k < szB; ++k)
        {
            if (b[k] % i == 0 || i % b[k]==0)
            {
                factorB = i;
            }
            else
            {
                factorB = 0;
                break;
            }
        }
        if ((factorA > 0) && (factorB > 0) && (factorA == factorB))
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    cout<<"Enter the size of two arrays(eg. 2 3): ";
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    cout<<"Enter the element of the array(eg. 2 4): ";
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    cout << "Enter the element of the array(eg. 16 32 96): ";
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    cout <<"The number of factors of the two arrays are: " << total << "\n";

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
