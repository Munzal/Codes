#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */
#define pii pair<long long int,long long int>
#define f first
#define s second
unsigned long long gridlandMetro(int n, int m, int k, vector<vector<long long int>> &track) {
    map<long long int,vector<pii>> alltracks;
    for(auto &x:track)
    {
        alltracks[x[0]].push_back({x[1],x[2]});
    }
    for(auto &t:alltracks)
    {
        sort(t.s.begin(), t.s.end());
    }
    for(auto &t:alltracks)
    {
        long long int lastpoint=0;
        long long int startpoint=t.s[0].f;
        vector<pii> edited;
        for(auto &k:t.s)
        {
            if(k.f <= lastpoint)
            {
                lastpoint = max(lastpoint, k.s);
            }
            else
            {
                edited.push_back({startpoint, lastpoint});
                startpoint = k.f;
                lastpoint = k.s;
            }
        }
        edited.push_back({startpoint, lastpoint});
        edited.erase(edited.begin());
        t.s  = edited;
    }
    unsigned long long int ans=n*1ll*m;
    /*
    for(auto &t:alltracks)
    {
        for(auto &k:t.s)
        {
            cout<<k.f<<"|"<<k.s<<" ";
        }
        cout<<endl;
    }
    */
    for(auto &t:alltracks)
    {
        for(auto &k:t.s)
        {
            ans -= (k.s-k.f+1);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<long long int>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    unsigned long long int result = gridlandMetro(n, m, k, track);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
