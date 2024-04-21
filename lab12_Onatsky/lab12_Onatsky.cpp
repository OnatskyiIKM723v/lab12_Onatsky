#include <iostream>
#include <stdlib.h>

// ������� ��� ����������� ������� ������� � ������������ ���������
int findMaxColumn(int** matrix, int numrows, int numcols) 
{
    int maxColumnIndex = 0;
    int maxsum = 0;
    for (int j = 0; j < numcols; ++j) 
    {
        int sum = 0;
        for (int i = 0; i < numrows; ++i) 
        {
            sum += matrix[i][j];
        }
        if (sum > maxsum) 
        {
            maxsum = sum;
            maxColumnIndex = j;
        }
    }
    return maxColumnIndex;
}

// ������� ��� ����������� ������� ������� � ��������� ���������
int findMinColumn(int** matrix, int numrows, int numcols) 
{
    int minColumnIndex = 0;
    int minsum = INT_MAX;
    for (int j = 0; j < numcols; ++j) 
    {
        int sum = 0;
        for (int i = 0; i < numrows; ++i) 
        {
            sum += matrix[i][j];
        }
        if (sum < minsum) 
        {
            minsum = sum;
            minColumnIndex = j;
        }
    }
    return minColumnIndex;
}

// ������� ��� ����� ������ �������� � ������������ � ��������� ����������
void swapColumns(int** matrix, int numrows, int numcols) 
{
    int maxColumn = findMaxColumn(matrix, numrows, numcols);
    int minColumn = findMinColumn(matrix, numrows, numcols);
    if (maxColumn != minColumn) 
    {
        for (int i = 0; i < numrows; ++i) 
        {
            int temp = matrix[i][maxColumn];
            matrix[i][maxColumn] = matrix[i][minColumn];
            matrix[i][minColumn] = temp;
        }
    }
}

// ������� ��� ��������� ������� �� �����
void printMatrix(int** matrix, int numrows, int numcols) 
{
    for (int i = 0; i < numrows; ++i) 
    {
        for (int j = 0; j < numcols; ++j) 
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    setlocale(LC_CTYPE, "ukr"); // ��������� ������������ ��������� ����

    int numrows = 3;
    int numcols = 3;

    int** matrix = new int* [numrows];
    for (int i = 0; i < numrows; ++i) 
    {
        matrix[i] = new int[numcols];
        for (int j = 0; j < numcols; ++j) 
        {
            matrix[i][j] = i * numcols + j + 1;
        }
    }

    std::cout << "������� �� ����� ��������:" << std::endl;
    printMatrix(matrix, numrows, numcols);

    swapColumns(matrix, numrows, numcols);

    std::cout << "\n������� ���� ����� ��������:" << std::endl;
    printMatrix(matrix, numrows, numcols);

    for (int i = 0; i < numrows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
