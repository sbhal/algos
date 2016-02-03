#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
void insertionSort(std::vector<int>& V){
    for(int i=1; i != V.size(); ++i){
        int temp = V[i];
        int j=i-1;
        while(j >= 0 && V[j] > temp){
                V[j+1] = V[j];
                j--;
        }
        V[j+1] = temp;
    }
}

 
int main() {
  std::vector<int> V = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
  insertionSort(V);
  copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}