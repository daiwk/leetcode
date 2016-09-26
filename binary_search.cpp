#include <iostream>

using namespace std;

/*
 *���ֲ���˼�룺1�������С��������2�����ҵ�keyÿ�κ��м����Ƚϣ����keyС��mid
 ����mid�������鲿�֣����key����mid�������mid�Ҳ�����鲿�֣������ȣ���ֱ�ӷ���mid��

 ���룺��������-array,�����С-aSize,����ֵ-key
 ���أ����������е���Ӧλ�ã����򷵻�-1
 */
//�ǵݹ����
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
//�ݹ�
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
