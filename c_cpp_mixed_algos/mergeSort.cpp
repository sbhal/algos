#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

int main(){
    std::vector<int> V = {4,7,8,2,3,10,1,20};
    mergeSort(V, 0, V.size()-1);
    for (auto& itr: V)
        cout << itr<<" ";
}