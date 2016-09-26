#include <iostream>

using namespace std;

/*
 *二分查找思想：1、数组从小到大排序；2、查找的key每次和中间数比较，如果key小于mid
 查找mid左侧的数组部分；如果key大于mid，则查找mid右侧的数组部分；如果相等，则直接返回mid。

 输入：排序数组-array,数组大小-aSize,查找值-key
 返回：返回数组中的相应位置，否则返回-1
 */
//非递归查找
int BinarySearch(int *array, int aSize, int key)
{
    if ( array == NULL || aSize == 0 )
        return -1;
    int low = 0;
    int high = aSize - 1;
    int mid = 0;

    while ( low <= high )
    {
        mid = (low + high )/2;

        if ( array[mid] < key)
            low = mid + 1;
        else if ( array[mid] > key )   
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
//递归
int BinarySearchRecursive(int *array, int low, int high, int key)
{
    if ( low > high )
        return -1;
    int mid = ( low + high )/2;

    if ( array[mid] == key )
        return mid;
    else if ( array[mid] < key )
        return BinarySearchRecursive(array, mid+1, high, key);
    else
        return BinarySearchRecursive(array, low, mid-1, key);
}

int main()
{
    int array[10];
    for (int i=0; i<10; i++)
        array[i] = i;

    cout<<"No recursive:"<<endl;
    cout<<"position:"<<BinarySearch(array, 10, 6)<<endl;
    cout<<"recursive:"<<endl;
    cout<<"position:"<<BinarySearchRecursive(array, 0, 9, 6)<<endl;

    return 0;
}
