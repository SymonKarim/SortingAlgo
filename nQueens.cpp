//*Bismillahir Rahmanir Raheem
//! symonkarim
#include <bits/stdc++.h>
#define ll long long
#define FASTER ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

// `N × N` chessboard
#define N 4
int N;
// Function to check if two queens threaten each other or not
int isSafe(char mat[][N], int r, int c)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') {
            return 0;
        }
    }

    // return 0 if two queens share the same `` diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }

    // return 0 if two queens share the same `/` diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }

    return 1;
}

void printSolution(char mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nQueen(char mat[][N], int r)
{
    // if `N` queens are placed successfully, print the solution
    if (r == N)
    {
        printSolution(mat);
        return;
    }

    // place queen at every square in the current row `r`
    // and recur for each valid movement
    for (int i = 0; i < N ; i++)
    {
        // if no two queens threaten each other
        if (isSafe(mat, r, i))
        {
            // place queen on the current square
            mat[r][i] = 'Q';

            // recur for the next row
            nQueen(mat, r + 1);
            // backtrack and remove the queen from the current square
            mat[r][i] = '-';
        }
    }

}


int main()
{
    FASTER
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t; cin >> t; for (int i = 1; i <= t; i++) {
        // `mat[][]` keeps track of the position of queens in the current configuration
        cin>>N;
        char mat[N][N];

        // initialize `mat[][]` by `-`
        memset(mat, '-', sizeof mat);

        nQueen(mat, 0);


        return 0;
    }

}

