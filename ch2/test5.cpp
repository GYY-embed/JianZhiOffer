//排序算法大汇总
#include <iostream>

using namespace std;

void MySwap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

//1、冒泡排序算法实现
void BubbleSort(int array[], int length)
{
    if(array == nullptr || length <= 0)
        return;
    for(int i = 0; i < length - 1; ++i)
    {
        for(int j = length - 1; j > i; --j)
            if(array[j] < array[j - 1])
                MySwap(array, j, j-1);
    }
}
//1-1、冒泡排序优化
void BubbleSort_Better(int array[], int length)
{
    if(array == nullptr || length <= 0)
        return;
    for(int i = 0; i < length - 1; ++i)
    {
        bool flag = false;
        for(int j = length - 1; j > i; --j)
            if(array[j] < array[j - 1])
            {
                MySwap(array, j, j-1);
                flag = true;
            }  
        if(!flag) break;  
    }
}
//2.选择排序
void SelectSort(int array[], int length)
{
    for(int i = 0; i < length -1; ++i)
    {
        int minIndex = i;
        for(int j = i + 1; j < length; ++j)
        {
            if(array[j] < array[minIndex])
                minIndex = j;
        }
        if(minIndex != i)
            MySwap(array, minIndex, i);
    }
    
}
//3、插入排序
void InserttSort(int array[], int length)
{
    for(int i = 0; i < length - 1; ++ i)
    {
        for(int j = i + 1; j > 0; --j)
        {
            if(array[j] < array[j - 1])
                MySwap(array, j, j - 1);
            else
                break;
        }
    }
}
//4、希尔排序
void ShellSort(int array[], int length)
{
    int incre = length;
    while (true)
    {
        incre = incre / 2;
        cout << "incre: " << incre << endl;
        for(int k = 0; k < incre; ++k)//根据增量分为若干子列
        {
            for(int i = k + incre; i < length ; i += incre)
            {
                for(int j = i; j > k; j -= incre)
                {
                    if(array[j] < array[j - incre])
                        MySwap(array, j, j - incre);
                    else
                        break;
                }
                
            }
        }
        if(incre == 1)
            break;
    } 
}
//5、快速排序
void QuickSort(int array[], int left, int right)
{
    if(left >= right)
        return;
    int i = left, j = right, key = array[left];
    while(i < j)
    {
        while(i < j && array[j] >= key)//从右开始找第一个小于等于key的值
            j--;
        if(i < j)
        {
            array[i] = array[j];
            i++;
        }
        while(i < j && array[i] < key)
            i++;
        if(i < j)
        {
            array[j] = array[i];
            j--;
        }
    }
    array[i] = key;
    QuickSort(array, left, right - 1);
    QuickSort(array, left + 1, right);
}
//6、归并排序
void mergeArray(int array[], int first, int middle, int last)
{
    int temp[last - first +1];
    int i = first;
    int m = middle;
    int j = middle + 1;
    int n = last;
    int k = 0;

    while(i <= m && j <= n)
    {
        if(array[i] <= array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }
    while(i <= m)
    {
        temp[k] = array[i];
        k++;
        i++;
    }
    while(j <= n)
    {
        temp[k] = array[j];
        k++;
        j++;
    }
    for(int ii = 0; ii < k; ii++)
        array[first+ii] = temp[ii];
}
void MergeSort(int array[], int first, int last)
{
    if(first < last)
    {
        int middle = (first + last) / 2; 
        MergeSort(array, first, middle);
        MergeSort(array, middle + 1, last);
        mergeArray(array, first, middle, last);
    }
}

int main(int argc, char const *argv[])
{
    int data[10]={1,4,7,5,6,10,3,8,2,9};
    //int data[9]={50,10,90,30,70,40,80,60,20};
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << endl;
    //ShellSort(data, 10);
    MergeSort(data, 0, 9);
    for(int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}
