#include <iostream>
#include <vector>


using namespace std;

//从上找，从左下找同理
//时间复杂度O(n)
//空间复杂度O(1)
bool find(int num, vector<vector<int> > array)
{
    int size = array.size() - 1;
    int row = 0, col = size;
    while(row <= size && col >= 0)
    {
        //cout << array[row][col] << endl;
        if(array[row][col] == num) 
            return true;
        else if (array[row][col] > num)
            --col;
        else
            ++row;            
    } 
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > a = {{1, 2,8, 9},
                            {2, 4, 9, 12},
                            {4, 7, 10, 13},
                            {6, 8, 11, 15}};
    cout << find(7, a) << endl;
    return 0;
}
