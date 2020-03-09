//面试题20、顺时针打印矩阵
#include <iostream>
#include <vector>

using namespace std;

void printNumber(int num)
{
    cout << num << " ";
}

void PrintMatrixCircle(vector<vector<int> > number, int cols, int rows, int start)
{
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;
    //从左到右打印一行
    for(int i = start; i <= endX; ++i)
    {
        int num = number[start][i];
        printNumber(num);
    }
    //从上到下打印一列
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; i++)
        {
            int num = number[i][endX];
            printNumber(num);
        }
    }
    //从右到左打印一行
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; --i)
        {
            int num = number[endY][i];
            printNumber(num);
        }
    }
    //从下到上打印一行
    if(start < endX && start < endY - 1)
    {
        for(int i= endY-1; i >= start + 1; --i)
        {
            int num = number[i][start];
            printNumber(num);
        }
    }
}

void PrintMatrixClockwisely(vector<vector<int> > number, int cols, int rows)
{
    if((number.size() == 0&&number[0].size() == 0) || cols <= 0 || rows <=0)
        return;
    int start = 0;
    while(cols > start*2 && rows > start *2)
    {
        PrintMatrixCircle(number, cols, rows, start);
        ++start;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int> > array{{1, 2, 3, 4},
    //                         {5, 6, 7, 8},
    //                         {9, 10, 11 ,12},
    //                         {13, 14, 15, 16}};
    vector<vector<int> > array{{1, 2, 3, 4}};
    //vector<vector<int> > array(4, vector<int>(4, 0));
    for(auto i : array)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    PrintMatrixClockwisely(array, 4, 1);
    return 0;
}
