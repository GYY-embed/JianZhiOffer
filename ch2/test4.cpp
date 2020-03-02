//快排
#include <iostream>
#include <time.h>
using namespace std;
 
int RandomInRange(int start,int end)
{
    if(end > start)
    {
        srand(time(NULL));
        return start+rand() % ((end-start)); //产生start~end之间的随机数
    }
    return 0;
}
 
void swap_element(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
int Partition(int data[],int length,int start,int end)
{
    if(data==NULL || length<=0 ||start<0 ||end>=length)
    {
        cout<<"error!"<<endl;
        exit(0);
    }
    int index = RandomInRange(start, end);
    swap_element(&data[index], &data[end]);
    
    int small=start-1;
    for (index=start; index<end;index++)
    {
        if (data[index]<data[end])
        {
            ++small;
            if(small != index)
            {
                swap_element(&data[index], &data[small]);
            }
        }
    }
    ++small;
    swap_element(&data[small],&data[end]);
    return small;
}
 
void Quicksort(int data[],int length,int start,int end)
{
    if (start == end) {
        return;
    }
    int index = Partition(data, length, start, end);
    if(index>start)
        Quicksort(data, length, start, index-1);
    if(index<end)
        Quicksort(data, length, index+1, end);
}
 
int main(int argc,char *argv[]){
 
    int data1[6]={6,2,7,3,8,9};
    Quicksort(data1, 6, 0, 5);
    for(int i=0;i<6;i++)
        cout<<data1[i]<<" ";
    cout<<endl;
    
    int data2[10]={1,4,7,5,6,10,3,8,2,9};
    Quicksort(data2, 10, 0, 9);
    for(int i=0;i<10;i++)
        cout<<data2[i]<<" ";
    cout<<endl;
    return 0;
}
