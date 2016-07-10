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
void insertionSort(std::vector<int>& V) {
	auto start = V.begin();
	auto end = V.end();
	// Rotate(first, middle, last)- takes a range [first, last) and rotates it so that the middle element becomes the first in that range.
	//upper_bound - Returns an iterator pointing to the first element in the range [first,last) which compares greater than val. The range should be already sorted (or at least partitioned).
	for (auto i = start; i != end; ++i)
		std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
}

int main() {
  std::vector<int> V = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
  insertionSort(V);
  copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}
