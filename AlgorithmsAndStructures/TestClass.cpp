#include "TestClass.h"

TestClass::TestClass()
{
    m_vecSortAlg.push_back(new SelectionSort());
    m_vecSortAlg.push_back(new InsertionSort());
    m_vecSortAlg.push_back(new BubbleSort());
    m_vecSortAlg.push_back(new QuickSort());
    m_vecSortAlg.push_back(new MergeSort());

    m_vecSearchAlg.push_back(new LinearSearch());
    m_vecSearchAlg.push_back(new BinarySearch());

    m_fPrint = [] (int &x) {cout << x << " ";};
}

TestClass::~TestClass()
{
    for(auto s : m_vecSortAlg)
    {
        delete s;
    }

    for(auto s : m_vecSearchAlg)
    {
        delete s;
    }
}

void TestClass::TestSortAlgorithms()
{
    cout << "TESTING SORT ALGORITHMS..." << endl;

    //Testing all algorithms
    for(auto s : m_vecSortAlg)
    {
        cout << endl;
        cout << "----- " << s->GetAlgorithmName() << " -----" << endl;
        TestEmptyArray(s);
        TestSameNumberArray(s);
        TestOrderedArray(s);
        TestReverseOrderedArray(s);
        TestSomeEqualNumberArray(s);
        TestNegativeArray(s);
        cout << "----- " << s->GetAlgorithmName() << " Finished -----" << endl;

    }

    cout << "TESTING SORT ALGORITHMS FINISHED!!!" << endl;
}

void TestClass::TestSearchAlgorithms()
{
    cout << "TESTING SEARCH ALGORITHMS..." << endl;

    //Testing all algorithms
    for(auto s : m_vecSearchAlg)
    {
        cout << endl;
        cout << "----- " << s->GetSearchName() << " -----" << endl;
        std::vector<int> v = {1, 5, 9, 14, 54, 2, -2, 48, 72, 3};
        size_t pos = 0;
        size_t expectedResult = 0;
        if(s->GetSearchName().compare("Binary Search") == 0)
        {
            QuickSort sort;
            sort.Sort(v);
            expectedResult = 6;
            pos = s->Search(v, 14);
        }
        else
        {
            expectedResult = 3;
            pos = s->Search(v, 14);
        }
        cout << "Search should return " << expectedResult
             << " and returned " << pos << "." << endl;
        cout << "----- " << s->GetSearchName() << " Finished -----" << endl;
    }

    cout << "TESTING SEARCH ALGORITHMS FINISHED!!!" << endl;
}


void TestClass::TestEmptyArray(ISort *pAlg)
{
    cout << "Empty array:" << endl;
    vector<int> v;

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}

void TestClass::TestSameNumberArray(ISort *pAlg)
{
    cout << "Same number array:" << endl;
    vector<int> v = {2, 2, 2, 2, 2, 2};

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}

void TestClass::TestOrderedArray(ISort *pAlg)
{
    cout << "Ordered array:" << endl;
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}

void TestClass::TestReverseOrderedArray(ISort *pAlg)
{
    cout << "Reverse ordered array:" << endl;
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}

void TestClass::TestSomeEqualNumberArray(ISort *pAlg)
{
    cout << "Some equal numbers array:" << endl;
    vector<int> v = {0, 0, 1, 4, 6, 9, 3, 6, 4, 3, 2, 1, 0, 10, 35, 35, 10};

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}

void TestClass::TestNegativeArray(ISort *pAlg)
{
    cout << "Negative numbers array:" << endl;
    vector<int> v = {0, 0, 1, -4, 6, 9, 3, -6, 4, 3, 2, -1, -0, 10, -35, -35, -10};

    //Print array before order it
    for_each(v.begin(), v.end(), m_fPrint);

    //Skip line
    cout << endl;

    pAlg->Sort(v);

    //Print array After order it
    for_each(v.begin(), v.end(), m_fPrint);
    //Skip line
    cout << endl << "---" << endl;
}
