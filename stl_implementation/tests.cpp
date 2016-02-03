#include <iostream>
#include "vector.h"
#include <vector>
#include <algorithm>
#include "linkedlist.h"
#include "sorting.h"
#include <gtest/gtest.h>

//vector
TEST(VectorTest, push_back_test) {
    vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(i);
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , i);
    ASSERT_EQ(V.capacity(), 10);
    ASSERT_EQ(V.size(), 10);
}

TEST(VectorTest, capacity_size_test) {
    vector<int> V;
    int noOfElements = 12;
    for(int i=0; i!= noOfElements; ++i)
        V.push_back(i);
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , i);
    EXPECT_EQ(V.capacity(), 20);
    ASSERT_EQ(V.size(), noOfElements);
}

TEST(VectorTest, clear_test) {
    vector<int> V;
    int noOfElements = 12;
    for(int i=0; i!= noOfElements; ++i)
        V.push_back(i);
    V.clear();
    for(int i=0; i!= noOfElements; ++i)
        V.push_back(i);
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , i);
    EXPECT_EQ(V.capacity(), 20);
    ASSERT_EQ(V.size(), noOfElements);
}
TEST(VectorTest, back_front_begin_end_test) {
    vector<int> V;
    int noOfElements = 12;
    for(int i=0; i!= noOfElements; ++i)
        V.push_back(i);
    ASSERT_EQ(V.front(), 0);
    ASSERT_EQ(V.back(), 11);
    ASSERT_EQ(*(V.begin()), 0);
    ASSERT_EQ(*(V.end() -1), 11);
    V.clear();
    ASSERT_EQ(V.front(), NULL);
    ASSERT_EQ(V.back(), NULL);
    ASSERT_EQ(V.begin(), nullptr);
    ASSERT_EQ(V.end(), nullptr);
}

TEST(VectorTest, pop_back_test) {
    vector<int> V;
    int noOfElements = 12;
    for(int i=0; i!= noOfElements; ++i)
        V.push_back(i);
    for(int i=0; i!= noOfElements/2; ++i)
        V.pop_back();
    ASSERT_EQ(V.size(), noOfElements/2);
    ASSERT_EQ(V.capacity(), 20);
    for(int i=0; i <= noOfElements; ++i)
        V.pop_back();
    EXPECT_EQ(V.capacity(), 20);
    ASSERT_EQ(V.size(), NULL);
}

//sortingtest
TEST(SortingTest, bubbleSort_test) {
    std::vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(std::rand() % 20);
    bubbleSort(V);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::vector<int> Vcopy(V);
    std::sort(Vcopy.begin(), Vcopy.end());
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , Vcopy[i]);
}

TEST(SortingTest, insertionSort_test) {
    std::vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(std::rand() % 20);
    insertionSort(V);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::vector<int> Vcopy(V);
    std::sort(Vcopy.begin(), Vcopy.end());
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , Vcopy[i]);
}

TEST(SortingTest, selectionSort_test) {
    std::vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(std::rand() % 20);
    selectionSort(V);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::vector<int> Vcopy(V);
    std::sort(Vcopy.begin(), Vcopy.end());
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , Vcopy[i]);
}

TEST(SortingTest, mergeSort_test) {
    std::vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(std::rand() % 20);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    mergeSort(V, 0 ,V.size()-1);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::vector<int> Vcopy(V);
    std::sort(Vcopy.begin(), Vcopy.end());
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , Vcopy[i]);
}

TEST(SortingTest, quickSort_test) {
    std::vector<int> V;
    for(int i=0; i!= 10; ++i)
        V.push_back(std::rand() % 20);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    quickSort(V, 0 ,V.size()-1);
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "  "));
    std::vector<int> Vcopy(V);
    std::sort(Vcopy.begin(), Vcopy.end());
    for(int i=0; i!= V.size(); ++i)
        ASSERT_EQ(V[i] , Vcopy[i]);
}
TEST(Test, test1) {
int A[] = {1,2,3,4,5};
int N = 5;
int Total = 1 << N;
for ( int i = 0; i < Total; i++ ) {
 for ( int j = 0; j < N; j++) {
 if ( (i >> j) & 1 )
 std::cout << A[j];
 }
 std::cout << std::endl;
}
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
