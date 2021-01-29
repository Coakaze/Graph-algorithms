#include <iostream>
#include <fstream>
using namespace std;

ifstream f("royfloyd.in");
ofstream g("royfloyd.out");

int n, dp[101][101];

int main()
{
    f>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            f>>dp[i][j];
            if(dp[i][j] == 0 && i != j)
                dp[i][j] = 1001;
        }
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i ++)
            for(int j=0; j<n; j++)
                if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    for(int i=0; i<n; i ++)
        {
            for(int j=0; j<n; j++)
                g<<dp[i][j]<<" ";
            g<<endl;
        }
    return 0;
}
