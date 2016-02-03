#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

int main(){
    std::vector<int> V = {4,7,8,2,3,10,1,20};
    quickSort(V, 0, V.size()-1);
    for (auto& itr: V)
        cout << itr<<" ";
}