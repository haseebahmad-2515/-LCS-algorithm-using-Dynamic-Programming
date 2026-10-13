
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string A = "stone";
    string B = "longest";

    int m = A.length();
    int n = B.length();

    int LCS[100][100] = {0};

    //  Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j],
                                LCS[i][j - 1]);
            }
        }
    }

    cout << "Length of LCS: " << LCS[m][n] << endl;

    //  Backtrack to find the actual LCS
    string result = "";

    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            result += A[i - 1];

            i--;
            j--;
        }
        else if (LCS[i - 1][j] >= LCS[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Reverse the collected characters
    reverse(result.begin(), result.end());

    cout << "Actual LCS: " << result << endl;

    return 0;
}
