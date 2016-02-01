#ifndef SORTING_CPP
#define SORTING_CPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void bubbleSort(std::vector<int> &V)
{
    for(int i=0; i != V.size(); ++i){
        for(int j=0; j != V.size() - i-1; ++j){
            if(V[j] > V[j+1])
                std::swap(V[j+1], V[j]);
        }
    }
}

void insertionSort(std::vector<int>& V){
    for(int i=1; i != V.size(); ++i){
        int temp = V[i];
        int j=i;
        while(j > 0 && V[j] > temp){
                V[j+1] = V[j];
                j--;
        }
        V[j+1] = temp;
    }
}

void selectionSort(std::vector<int>& V){
    for(int i=0; i!= V.size(); ++i){
        for(int j=i; j!= V.size(); ++j){
            if(V[j] < V[i])
                std::swap(V[i], V[j]);
        }
    }
}

void mergePartition(std::vector<int>& V, int start, int mid, int end){
    int itr1 = start;
    int itr2 = mid+1;
    int itr3 = 0;

    std::vector<int> Vout(end-start+1);
    while( itr1 <= mid && itr2 <= end){
        if(V[itr1] <= V[itr2]){
            Vout[itr3++] = V[itr1++];
        }else{
            Vout[itr3++] = V[itr2++];
        }
    }
    if(itr1 > mid){
        for(int i=itr2; i <= end; ++i)
            Vout[itr3++] = V[i];
    } else {
        for(int i=itr1; i <= mid; ++i)
            Vout[itr3++] = V[i];
    }

    std::copy(Vout.begin(), Vout.end(), V.begin()+start);
}

void mergeSort(std::vector<int>& V, int start, int end){
    if(end <= start)
        return;
    int mid = start + (end - start)/2;
    mergeSort(V, start, mid);
    mergeSort(V, mid+1, end);
    mergePartition(V, start, mid, end);
}
int quickSortPartition(std::vector<int>& V, int low, int high){
    int pivot = V[high];
    int leftwall = low;
    for (int i=leftwall; i < high; ++i){
        if(V[i] < pivot)
            std::swap(V[i], V[leftwall++]);
    }
    std::swap(V[leftwall], V[high]);
    return leftwall;
}

void quickSort(std::vector<int> & V, int start, int end){
    if( start >= end)
        return;
    int mid = quickSortPartition(V, start, end);

    quickSort(V, start, mid -1 );
    quickSort(V, mid + 1, end);
}

#endif // VECTOR_CPP
