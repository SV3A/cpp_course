#include <iostream>
#include <cmath>
// Given input: l n set[0] set[1] set[2] ... set[n] return a histogram with l
// intervals.

using namespace std;

int main(int argc, char *argv[]) {
  unsigned int l = 0;      // number of intervals
  unsigned int n = 0;      // size of the data set
  unsigned int m = 0;      // maximum number in the data set
  unsigned int k = 0;      // size of the intervals
  unsigned int *set;       // pointer to the data set array
  unsigned int *histogram; // pointer to the histogram array

  // Read number of intervals, size of the data set, and populate the set array
  cin >> l;
  cin >> n;

  set = new unsigned int[n];
  for (int i = 0; i < n; ++i) {
    cin >> set [i];
  }

  // Determine the largest element in the data set
  for (int i = 0; i < n; ++i) {
    if (set [i] > m) m = set [i];
  }
  // Determine the interval sizes based on m
  k = ceil(m/(double)l);

  // Initialize the histogram array
  histogram = new unsigned int[l];
  for (int i = 0; i < l; ++i) {
    histogram[i] = 0;
  }

  // Create the histogram: Loop over each element in the data set, for each
  // element, find its placement in the l intervals by set[i]/k. To accound for
  // elements with values in the last interval use the min function
  // min(value, l-1) which makes the indexing stay within the boundary of the
  // histogram array
  for (int i = 0; i < n; ++i) {
    histogram[min(set[i]/k, l-1)] ++;
  }

  // Output the histogram
  cout << "HISTOGRAM:" << endl;
  for (int i = 0; i < l; ++i) {
    cout << k*i << ": "<< histogram[i] << endl;
  }

  return 0;
}
