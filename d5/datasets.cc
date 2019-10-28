#include <iostream>
#include <vector>
#include <string>
// Processing datasets
// e1: Read the datasets and write them into cout in the following order: first
// by dataset (first a, then b) and then by value.
//
// e2: Read the datasets and write them into cout in the following order: first
// the 1st read value of dataset a (if any), then the 1st read value from 
// dataset b (if any), then the 2nd read value from the dataset a (if any), then
// the 2nd read value from dataset b (if any), etc.
//
// e3: Read the datasets. Interpret each dataset as a vector (in the order
// provided by the input) and compute their scalar product. If one of the
// vectors is shorter than the other, the missing dimensions are to be
// considered as having value 0.

// Key-value pair struct
struct Element {
  unsigned char id;
  int num;
};

// Element vector containing the key-value pairs
typedef std::vector<Element> evector;


// Parse input string and populate vector with structs of the type "Element"
void parse_input(evector &b)
{
  std::string input, num_str;
  std::string::iterator it;
  unsigned char identifier;

  // Read entire line
  std::getline(std::cin, input);

  // Remove spaces and non-alphanumericals
  for ( it = input.begin(); it != input.end(); ++it) {
    if (!isalnum(*it)) input.erase(it);
  }

  // Create id and number pairs and add them to element vector
  it = input.begin();
  while (it != input.end()) {
    if (*it == 'a' || *it == 'b') {
      identifier = (unsigned char)*it;
      it++;

      while (isdigit(*it)) {
        num_str.push_back(*it++);
      }

      b.push_back({identifier, std::stoi( num_str )});
      num_str.clear();
    } else {
      it ++;
    }
  }
}


void sort1(evector &bu, evector &bs) {
  unsigned char key;

  // Run over unsorted bag two times checking for 'a' the 'b' and upon location
  // push index to the sorted bag vector
  for (int i = 0; i < 2; ++i) {
    (i == 0 ? key = 'a' : key = 'b');

    for (auto i : bu) {
      if (i.id == key) bs.push_back({i.id, i.num});
    }
  }
}


void sort2(evector &bu, evector &bs) {
  // TODO: Not the cleverest solution...
  evector temp_a;
  evector temp_b;
  int i_a = 1, i_b = 1;

  for (int i = 0; i < 2; ++i) {
    if (i == 0) {
      for (auto i : bu) {
        if (i.id == 'a') temp_a.push_back({i.id, i.num});
      }
    } else {
      for (auto i : bu) {
        if (i.id == 'b') temp_b.push_back({i.id, i.num});
      }
    }
  }

  for (int i = 1; i <= temp_a.size() + temp_b.size(); ++i) {
    if (i%2 == 1 && i_a <= temp_a.size()) {
      bs.push_back(temp_a[i_a-1]);
      i_a++;
    } else if (i_b <= temp_b.size()) {
      bs.push_back(temp_b[i_b-1]);
      i_b++;
    }
  }
}


int sc_product(evector &b) {
  int product = 0;
  std::vector<int> v_a, v_b;

  // Split assigned elements into to vectors
  for (int i = 0; i < 2; ++i) {
    if (i == 0) {
      for (auto i : b) {
        if (i.id == 'a') v_a.push_back(i.num);
      }
    } else {
      for (auto i : b) {
        if (i.id == 'b') v_b.push_back(i.num);
      }
    }
  }

  // Align size
  while (v_a.size() != v_b.size()) {
    if (v_a.size() < v_b.size())
      v_a.push_back(0);
    else
      v_b.push_back(0);
  }

  // Perform the product
  for (int i = 0; i < v_a.size(); ++i) {
    product += v_a[i] * v_b[i];
  }

  return product;
}


// Display contents of unsorted- and sorted bag
void disp(evector &bu, evector &bs) {
  std::cout << "Unsorted bag:" << std::endl;
  for (auto i : bu) {
    std::cout << "  " << i.id << ": " << i.num << std::endl;
  }

  std::cout << "Sorted bag:" << std::endl;
  for (auto i : bs) {
    std::cout << "  " << i.id << ": " << i.num << std::endl;
  }
}


int main()
{
  evector bag_unsorted;
  evector bag_sorted;

  // e1
  parse_input(bag_unsorted);
  sort1(bag_unsorted, bag_sorted);
  disp(bag_unsorted, bag_sorted);

  // e2
  bag_sorted.clear();
  sort2(bag_unsorted, bag_sorted);
  disp(bag_unsorted, bag_sorted);

  // e3
  int prod = sc_product(bag_unsorted);
  std::cout << "Scalar product: " << prod << std::endl;
}
