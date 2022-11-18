#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void createArray(int** arr, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    arr[i][j] = Low + rand() % (High-Low+1);

    if(j < colCount-1)
    {
        createArray(arr, rowCount, colCount, Low,High, i, j+1);
    }
        if(i<rowCount-1)
        {
            createArray(arr, rowCount, colCount, Low, High, i+1, 0);
        }

}

void printArray(int** arr, const int rowCount, const int colCount, int i, int j)
{
    cout<< setw(4) << arr[i][j];
    if(j < colCount-1)
    {
        printArray(arr, rowCount, colCount, i, j+1);
    }
    else
    if(i < rowCount-1)
    {
        cout<<endl;
        printArray(arr, rowCount, colCount, i+1, 0);
    }
    else
        cout << endl << endl;

}




void maxElementOfTheMatrix(int** arr, const int rowCount, const int colCount, int i,int j)
{
    int count = 0;
    int maxElement= arr[0][0];

        if(arr[i][j] > maxElement)
        {
            maxElement = arr[i][j];
        }
        if(maxElement == arr[i][j])
        {
            count++;
        }
    if(j<colCount-1)
    {
        maxElementOfTheMatrix(arr, rowCount, colCount, i, j+1);
    }
    else
        if(i<rowCount-1)
        {
            maxElementOfTheMatrix(arr, rowCount, colCount, i+1, 0);
        }
    
    else
        cout<< "Max element: " <<maxElement<<endl;
    
}




int countRow(int** arr, const int rowCount , const int colCount,int i,int j)
{
    int count = 0;
    if(arr[i][j] ==0)
    {
        count++;
    }
    if(j<colCount-1)
    {
        maxElementOfTheMatrix(arr, rowCount, colCount, i, j+1);
    }
    else
        if(i<rowCount-1)
        {
            maxElementOfTheMatrix(arr, rowCount, colCount, i+1, 0);
        }
    
    return count;
    
}



int main()
{
    srand((unsigned)time(NULL));
 
    int Low = 0;
    
    int High = 9;
    
    int rowCount = 4;
    
    int colCount = 4;
    
    int **arr = new int*[rowCount];
    
    for (int i=0; i<rowCount; i++)
        
    arr[i] = new int[colCount];

    createArray(arr, rowCount, colCount, Low, High,0,0);
    maxElementOfTheMatrix(arr, rowCount, colCount,0,0);
    cout<< countRow(arr, rowCount, colCount,0,0);
    printArray(arr, rowCount, colCount,0,0);
    
    for (int i=0; i<rowCount; i++)
        
    delete [] arr[i];
    
    delete [] arr;
    
    return 0;

}
