#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
void selectionSort(std::vector<int>& V){
    for(int i=0; i!= V.size(); ++i){
        for(int j=i; j!= V.size(); ++j){
            if(V[j] < V[i])
                std::swap(V[i], V[j]);
        }
    }
}

 
int main() {
  std::vector<int> V = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
  selectionSort(V);
  copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}