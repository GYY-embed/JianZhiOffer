//排序算法大汇总
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

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
//7、堆排序
void AdjustHeapNode(int array[], int i, int length)//调整大顶堆
{
    // cout << "调整位置：" << i << "该位值：" << array[i] << endl;
    // cout << "调整前: " << endl;
    // for(int h = 0; h < 10; h++)
    //     cout << array[h] << " ";
    // cout << endl;
    //int temp = array[i];
    int k = i * 2 + 1;
    while(k < length)
    {
        if(k + 1 < length && array[k] < array[k + 1])//如果左子节点小于右子节点，k指向右子节点
            ++k;
        if(array[k] > array[i])//如果子节点大于父节点，将子节点赋值给父节点（不用进行交换）
        {
            MySwap(array, i, k);
        }
        else   
            break;
        i = k;      //检查更换的节点是否满足最大堆的特性
        k = 2 * i + 1;
    }

    // cout << "调整后: " << endl;
    // for(int h = 0; h < 10; h++)
    //     cout << array[h] << " ";
}
void HeapSort(int array[], int length)
{
    //构建大顶堆
    for(int i = (length - 1) / 2; i >= 0; i--) //最后一个非叶子节点开始
    {
        cout << i << " "; 
        AdjustHeapNode(array, i, length);
    }
    cout << endl;
    //调整堆结构+交换堆顶元素与末尾元素
    for(int j = length - 1; j > 0; j--)
    {
        MySwap(array, 0, j);
        AdjustHeapNode(array, 0, j);
    }
}
//8、计数排序
int get_max(int array[], int length)//获取数组中最大值的函数
{
     if(array == nullptr || length <= 0)
        return -1;
    int max = array[0];
    for(int i = 1; i < length; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    return max;
}
void CountSort(int array[], int length)
{
    if(array == nullptr || length <= 0)
        return;
    int max = get_max(array, length) + 1;//获取数组中的最大值
    cout << max << endl;
    int *count= new int[max];//分配空间
    for(int i = 0; i < max; i++)//初始化计数数组各位为0
        count[i] = 0;
    // for(int i = 0; i < max; i++)
    //     cout << count[i] << " ";
    // cout <<endl;
    for(int i = 0; i < length; i++)//计数
    {
        count[array[i]]++;
    }
    for(int i = 0; i < max; i++)
        cout << count[i] << " ";
    cout <<endl;
    for(int i = 0, j = 0; i < max; i++)//输出到源数组，完成排序
    {
        for(int k = count[i]; k > 0; k--)
        {
            array[j] = i;
            j++;
        }    
    }
}
//9、桶排序
int DataMap(int num) //桶排序映射函数
{
    return num / 10;    
}
void BucketSort(int array[], int length)
{
    if(array == nullptr || length <= 0)
        return;
    //vector<list<int>> bucket;//使用双向链表来存储桶内元素，同vector来组织桶
    list<int> bucket[10];//使用双向链表来存储桶内元素，用数组来组织桶
    for(int i = 0; i < length; i++)
    {
       bucket[DataMap(array[i])].push_back(array[i]);//给对应的桶中插入，插入操作O(1)时间复杂度
    }
    for(int i = 0; i < 10; i++)//分别对每个桶中的元素进行排序
    {
        bucket[i].sort();
    }
    for(int i = 0, k = 0; i < 10; i++)//输出桶中的元素到序列中，完成排序
    {
        for(auto j : bucket[i])
        {
            if(k < length)
            {    
                array[k] = j;
                k++;
            }
        }
    }
}
//10、基数排序
void BitCountSort(int array[], int length, int exp)//按位计数排序函数
{
    int range[10];
    int temparr[length];
    for(int i = 0; i <10; i++)
        range[i] = 0;
    
    for(int i = 0; i < length; i++)
    {
        range[(array[i]/exp)%10]++;
    }
    cout << "range :" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << range[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < 10; i++)
    {
        range[i] += range[i-1];//统计本应出现的位置
    }
    cout << "range :" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << range[i] << " ";
    }
    cout << endl;
    for(int i = length - 1; i >=0; i--)
    {
        temparr[range[(array[i]/exp)%10] - 1] = array[i];
        range[(array[i]/exp)%10]--;
    }
    for(int i = 0; i < length; i++)
    {
        array[i] = temparr[i];
    }
}

void RadixSort(int array[], int length)
{
    int max = -1;
    //提取最大值
    for(int i = 0; i < length; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    //提取每一位进行比较位数不足的高位补0
    for(int exp = 1; max/exp > 0; exp *= 10)
        BitCountSort(array, length, exp);
}

int main(int argc, char const *argv[])
{
    //int data[10]={1,4,7,5,6,10,3,8,2,9};
    int data[20]={57,13,95,13,77 ,41,83,62,25,78 ,53,19,92,33,75 ,46,85,61,22,48};
    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
        cout << data[i] << " ";
    cout << endl;
    RadixSort(data, sizeof(data)/sizeof(int));
    //MergeSort(data, 0, 9);
    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}

