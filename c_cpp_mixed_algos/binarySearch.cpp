#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
int binarySearch(const std::vector<int>& V, int value, int low, int high){
    if(low > high)
      return -1;
    int mid = low + (high - low)/2;
    if(V[mid] == value)
      return mid;
    else if (V[mid] > value)
      return binarySearch(V, value, low, mid-1);
    else
      return binarySearch(V, value, mid+1 , high);
}

 
int main() {
  std::vector<int> V = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
  std::sort(V.begin(), V.end());
  copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n Index is "<< binarySearch(V, 200, 0 , V.size()-1)<< std::endl;
}