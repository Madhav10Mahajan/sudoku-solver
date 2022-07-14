#include <bits/stdc++.h>
using namespace std;
int sqrt(int n)
{
    for (int i = 1; i <= n / 2; i++)
    {
        if (i * i == n)
        {
            return i;
        }
    }
    return -1;
}
bool ispossible(int row, int col, int n, int m, vector<vector<int>> &grid, int num)
{

    for (int i = 0; i < n; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (grid[row][j] == num)
        {
            return false;
        }
    }
    row = row - row % sqrt(n);
    col = col - col % sqrt(m);
    for (int i = 0; i < sqrt(n); i++)
    {
        for (int j = 0; j < sqrt(m); j++)
        {
            if (grid[row + i][col + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solvesudoku(int n, int m, vector<vector<int>> &grid)
{
    if (n != m)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (ispossible(i, j, n, m, grid, num))
                    {
                        grid[i][j] = num;
                        bool ans = solvesudoku(n, m, grid);
                        if (ans == true)
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printsudoku(int n, int m, vector<vector<int>> &grid)
{
    cout << "\n======================================\n";
    for (int i = 0; i < n; i++)
    {
        cout << "||  ";
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << "  ";
            count++;
            if (count == sqrt(n))
            {
                cout << "|| ";
                count = 0;
            }
        }
        cout << endl;
        cout << "++-----------++-----------++------++" << endl;
    }
    cout << "======================================\n\n";
}
int main()
{
    cout << "\n=======================\n";
    cout << "    Sudoku Generator\n";
    cout << "=======================\n\n";

    cout << "Welcome to Sudoku solver game!\n";
    cout << "We shall begin generating your puzzle now.\n\n";
    cout << "Before we start, you will have to input the puzzle into this program.\n\n";
    cout << "Please first enter the number of rows and columns of the sudoku" << endl;
    int n, m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "the solution of the above given sudoku does not exist" << endl;
    }
    else
    {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        cout << "Now enter the value of each cell one by one" << endl;
        cout << "Blank cells must be filled in as 0 (eg; 1 0 0 2 0 0 ...).\n";
        cout << endl;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] = 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << "The give sudoku doesn't have any empty cells" << endl;
        }
        else
        {
            bool ans = solvesudoku(n, m, grid);
            cout << "\nCalculating possibilities...\n";
            cout << "Backtracking across puzzle....\n";
            cout << "Validating cells and values...\n\n";

            cout << endl;
            if (ans == true)
            {
                cout << "the solution for the sudoke problem is given below" << endl;
                printsudoku(n, m, grid);
                cout << "Your puzzle has been solved!\n\n";
            }
            else
            {
                cout << "the solution of the above given sudoku does not exist" << endl;
            }
        }
    }

    return 0;
}