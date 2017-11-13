#include <iostream>

void CustomSwap(int& iFirst, int& iSecond)
{
    const int iFirstCopy = iFirst;
    iFirst = iSecond;
    iSecond = iFirstCopy;
}

void CustomPointersSwap(int*& pFirst, int*& pSecond)
{
    int* pFirstCopy = pFirst;

    pFirst  = pSecond;
    pSecond = pFirstCopy;
}

void Exercise6()
{
    // Exercise6: имеется упорядоченный массив чисел, который циклический сдвинули на
    // какое-то число позиций. Требуется найти, на сколько позиций был сдвинут массив.
    // Решить нужно за оптимальное время.
    // Допустим, исходный массив: 1 4 5 6 8 9 10 11 15. Его циклически сдвинули на 2 позиции влево,
    // и получили: 5 6 8 9 10 11 15 1 4.

    const int iBaseArray[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int iMovedArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    int iMovedArray[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    const int iArrayLastIndex = sizeof(iBaseArray) / sizeof(int) - 1;

    int iMoveIndexLeft  = 0;
    int iMoveIndexRight = iArrayLastIndex;

    while (true)
    {
        if (iBaseArray[iMoveIndexLeft] == iMovedArray[0])
        {
            std::cout << "Array moved (left): "  << iMoveIndexLeft << std::endl;
            break;
        }

        if (iMovedArray[iArrayLastIndex] == iBaseArray[iMoveIndexRight])
        {
            std::cout << "Array moved (right): " << iArrayLastIndex - iMoveIndexRight << std::endl;
            break;
        }

        iMoveIndexLeft++;
        iMoveIndexRight--;
    }
}

void Exercise5()
{
    // Exercise5: найти в массиве пару чисел,
    // которая в произведении даст максимальный результат

    int szIntArray[] = {1, 2, 3, 10, 12, 4, 121, 30, 3, 4, 3};

    int iSize = sizeof(szIntArray) / sizeof(int);
    int iMaxProduct = 0;
    int iFirstIndex = 0, iSecondIndex = 0;

    for (int i = 0; i < iSize; i++)
    {
        for (int j = i + 1; j < iSize; j++)
        {
            if (szIntArray[i] * szIntArray[j] > iMaxProduct)
            {
                iMaxProduct = szIntArray[i] * szIntArray[j];
                iFirstIndex  = i;
                iSecondIndex = j;
            }
        }
    }

    std::cout << "Max product pair is: " << szIntArray[iFirstIndex]
              << " (index #" << iFirstIndex << "), " << szIntArray[iSecondIndex]
              << " (index #" << iSecondIndex << ")" << std::endl;

}

void Exercise4()
{
    // Exercise4: дан упорядоченный массив, требуется реализовать бинарный поиск

    int szSortedIntArray[] = {1, 2, 3, 4, 5, 200, 400, 500, 1000, 7000, 15000};
    int iArraySize = sizeof(szSortedIntArray) / sizeof(int);
    bool bCantBeFound = false;
    int iFindInt = 7000;
    int iStageNum = 1;

    int iStartIndex = 0;
    int iEndIndex = iArraySize - 1;

    while (szSortedIntArray[iStartIndex] != iFindInt)
    {
        int iDelta = (iEndIndex - iStartIndex)/2;
        int iMiddleIndex = iStartIndex + iDelta;

        if (szSortedIntArray[iMiddleIndex] < iFindInt)
            (iDelta) ? (iStartIndex = iMiddleIndex) : ++iStartIndex;
        else
            iEndIndex = iMiddleIndex;

        std::cout << "Step #" << iStageNum << " [" << iStartIndex << " "
                  << iEndIndex << "];" << std::endl;

        if (iStartIndex == iEndIndex && szSortedIntArray[iStartIndex] != iFindInt)
        {
            bCantBeFound = true;
            std::cout << "Number " << iFindInt << " cant be found" << std::endl;
            break;
        }

        ++iStageNum;
    }

    if (!bCantBeFound)
        std::cout << "Number " << iFindInt << " found in " << iStageNum << " steps" << std::endl;
}

void Exercise3()
{
    // Exercise3: даны два упорядоченных массива. Требуется получить третий массив,
    // который будет результатом слияния первых двух
    // (результирующий массив упорядочен)

    const int szArrayFirst[]  = {1, 2, 3, 5, 10};
    const int szArraySecond[] = {0, 1, 4, 5, 9, 11};

    const int iSizeFirstArray  = sizeof(szArrayFirst)  / sizeof(int);
    const int iSizeSecondArray = sizeof(szArraySecond) / sizeof(int);
    const int iSizeThirdArray  = iSizeFirstArray + iSizeSecondArray;

    int szThirdArray[iSizeThirdArray];
    int iCurrentThirdIndex  = 0, iCurrentFirstIndex  = 0, iCurrentSecondIndex = 0;

    while (iCurrentFirstIndex != iSizeFirstArray || iCurrentSecondIndex != iSizeSecondArray)
    {
        if (szArrayFirst[iCurrentFirstIndex] < szArraySecond[iCurrentSecondIndex])
        {
            szThirdArray[iCurrentThirdIndex++] = szArrayFirst[iCurrentFirstIndex];
            ++iCurrentFirstIndex;
        }
        else
        {
            szThirdArray[iCurrentThirdIndex++] = szArraySecond[iCurrentSecondIndex];
            ++iCurrentSecondIndex;
        }
    }

    for (int i = 0; i < iSizeThirdArray; i++)
        std::cout << szThirdArray[i] << std::endl;
}

void Exercise2()
{
    // Exercise2: перевернуть динамический массив

    const int iSize = 10;
    int* szIntArray = new int[iSize];

    int iStartIndex = 0;
    int iLastIndex  = iSize - 1;

    for (int i = 0; i < iSize; i++)
        szIntArray[i] = i;

    while (iStartIndex < iLastIndex)
    {
        CustomSwap(szIntArray[iStartIndex++], szIntArray[iLastIndex--]);

        // without function realization:
        //const int iFirstCopy = szIntArray[iStartIndex];
        //szIntArray[iStartIndex++] = szIntArray[iLastIndex];
        //szIntArray[iLastIndex--] = iFirstCopy;
    }

    delete[] szIntArray;
}

void reverse(int* first, int* last)
{
    if (last < first)
        CustomPointersSwap(first, last);

    while (first < last)
        CustomSwap(*first++, *last--);
}

void Exercise1()
{
    // Exercise1: реализовать функцию reverse(int* first, int* last)

    const int iSize = 10;
    int* szIntArray = new int[iSize];

    for (int i = 0; i < iSize; i++)
    {
        szIntArray[i] = i;
        std::cout << szIntArray[i] << std::endl;
    }

    reverse(&szIntArray[0], &szIntArray[iSize - 1]);

    std::cout << std::endl << "After reverse:" << std::endl << std::endl;

    for (int i = 0; i < iSize; i++)
        std::cout << szIntArray[i] << std::endl;

    delete[] szIntArray;
}

int main()
{
//    Exercise6();
//    Exercise5();
//    Exercise4();
//    Exercise3();
//    Exercise2();
//    Exercise1();

    return 0;
}
