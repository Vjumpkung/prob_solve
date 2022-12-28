#include <ctime>
#include <iostream>

using namespace std;

char Graph[125][125];

int col, row;

int mode = 0; // left = 0 right = 1

int lemmo(int r, int c, int mode)
{
    if (Graph[r][c] == '@')
    {
        return 0;
    }

    if (Graph[r][c] == '$')
    {
        return 1;
    }

    if (Graph[r][c] == '.')
    {
        r++;
        return lemmo(r, c, mode);
    }

    else if (mode == 0)
    {
        while (c > 0)
        {
            c--;
            if (Graph[r][c] == '.')
            {
                r++;
                break;
            }
            else if (Graph[r][c] == '$')
            {
                break;
            }
            else if (Graph[r][c] == '@')
            {
                break;
            }
        }
        if (c == 0)
        {
            mode = 1;
        }
        return lemmo(r, c, mode);
    }

    else if (mode == 1)
    {
        while (c < col - 1)
        {
            c++;
            if (Graph[r][c] == '.')
            {
                r++;
                break;
            }
            else if (Graph[r][c] == '$')
            {
                break;
            }
            else if (Graph[r][c] == '@')
            {
                break;
            }
        }
        if (c == col - 1)
        {
            mode = 0;
        }
        return lemmo(r, c, mode);
    }

    return 0;
}

int main()
{
    clock_t tStart = clock();
    cin >> col >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> Graph[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < col; i++)
    {
        count += lemmo(0, i, 0);
        count += lemmo(0, i, 1);
    }

    int max_count = -1;

    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Graph[i][j] != '#')
            {
                continue;
            }
            Graph[i][j] = '.';
            int temp = 0;
            for (int k = 0; k < col; k++)
            {
                temp += lemmo(0, k, 0);
                temp += lemmo(0, k, 1);
            }
            if (temp > max_count)
            {
                max_count = temp;
            }
            Graph[i][j] = '#';
        }
    }

    cout << count << " " << max_count;

    // cout << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;

    return 0;
}