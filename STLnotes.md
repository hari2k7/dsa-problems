# CPP STL

To get all libraries use `#include <bits/stdc++.h>`.  

## Pair
To store something in pair irrespective of data type use pair.  
Syntax: `pair<int, int> p = {1, 3};`.  
To access first element use pair.first similary p.second.  
  
#### Nested Pair
`pair<int, pair<int, int>> p ={1, {3, 4}};`  
to access use p.second.escond or p.second.first.

#### Pair Array
`pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};`  
to accuse do like arr[1].second.

Example code:  
```cpp
// Pairs
void explainPair() {
pair<int, int> p = {1, 3};

cout << p.first << " " << p.second;

pair<int, pair<int, int>> p = {1, {3, 4}};

cout << p.first << " " << p.second.second << " " << p.second.first;

pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1}};

cout << arr[1].second;
}
```

## Vector

Use: When we declare a array of size 5 it will allocate five places and later we cannot modify its size. But in vector it is dynamic in nature.

Declaration: `vector<int> v;`  
To add element: `v.push_back(1);`, `v.emplace_back(2);`  

To define vector of a pair  data-type: `vector<pair<int, int>>vec;`

To insert in pair vector: `v.push_back({1, 2});`, `v.emplace_back(1, 2);`  

`vector<int> v(5, 100);` will define 5 instence of 100.  

`vector<int> v(5);` will define 5 instence of garbage value.  

Copying vector in other vector: 
```cpp
vector<int> v1(5, 20);
vector<int> v2(v1);
```
after defining with size also if you use push_back it increases the size and keep the element at last.  

#### Accesing vector
- `v[index_num]` or `v.at(0);`
- Using itrators:
  ```cpp
  vector<int> :: iterator it = v.begin();

  it++:
  cout << *(it) << " ";
  
  it = it + 2;
  cout << *(it) << "";
  
  vector<int> :: iterator it = v.end();
  
  vector<int> :: iterator it = v.rend();
  
  vector<int> :: iterator it = v.rbegin();
  
  cout << v[0] << "" << v.at(0);
  cout << v.back() << " ";
  ```
  here `v.begin()` points the memory address of 0th index so we use `*(v.begin())` to print the element.  
  `v.end();` points the memory location that is right after the last element so we need to `it--;`  
  `v.back()` is the last element.  

- Printing vector using loop:
  ```cpp
  for (vector<int> :: iterator it = v.begin(); it != v.end(); it++) {
  cout << *(it) << " ";
  }
  
  for (auto it = v.begin(); it != v.end(); it++) {
  cout << *(it) << "";
  
  for (auto it : v) {
  cout << it << " ";
  }
  ```

- Deletion in vector:
  v.erase(address_of element) like `v.erase(v.begin()+1);` will erase second element.  

- To erase couple of element:  
  `v.erase(start, end) like v.erase(v.begin()+2 , v.begin()+4);` (like for loop the endis not included in this) 

- Insert:
  v.insert(index, element)  
  v.insert(index, no_of_ele, element)  
  ex:
  ```cpp
  vector<int>v(2, 100); // {100,100}
  v.insert(v.begin(), 300); //{300,100,100};
  v.insert(v.begin() +1, 2, 10); // {300, 10,10, 100,100}
  ```
- Insering vector in other one or copy:
  ```cpp
  vector<int> copy(2, 50);//{50,50}
  v.insert(v.begin(), copy.begin(), copy.end()); //{50,50, 300, 10, 10,100,100}
  ```

- To get size: `v.size();`

- To pop last ele: `v.pop_back();`

- swaping Two vectors: `v1.swap(v2);` in this v1 has v2's element and v2 has v1's element.

- To erase entire vector or empty the vector: `v.clear();`

- To check vector is empty or not: `v.empty();`

## List
```cpp
void explainList() {
list<int> ls;

ls.push_back(2); // {2}
ls.emplace_back(4); // {2, 4}

ls.push_front(5); // {5, 2, 4};

ls.emplace_front(); {2, 4};

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
}
```

## Deque
```cpp
void explainDeque() {

deque<int>dq;
dq.push_back(1); // {1}
dq. emplace_back(2); // {1, 2}
dq.push_front(4); // {4, 1, 2}
dq.emplace_front(3); // {3, 4, 1, 2}

dq.pop_back(); // {3, 4, 1}
dq.pop_front(); // {4, 1}

dq.back();

dq. front();

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
}
```
## Stack
It is LIFO
```cpp
void explainStack() {
  stack<int> st;
  st.push(1);//{1}
  st.push(2); // {2,1}
  st.push(3); // {3,2, 1}
  st.push(3); // {3, 3, 2, 1}
  st.emplace(5); // {5, 3, 3, 2, 1}
  
  cout << st.top(); // prints 5 " ** st[2] is invalid ** "
  // indexing not allowed in stack
  st.pop(); // st looks like {3, 3, 2, 1}
  
  cout << st.top(); // 3
  
  cout << st.size(); // 4
  
  cout << st.empty(); // False
  
  stack<int>st1, st2;
  st1.swap(st2);
}
```


## Queue
This is FIFO
```cpp
void explainQueue() {
  queue<int> q;
  q.push(1); // {1}
  q.push(2); // {1, 2}
  q. emplace(4); // {1, 2, 4}
  
  q.back() += 5
  
  cout << q.back(); // prints 9
  
  // Q is {1, 2, 9}
  cout << q.front();//prints 1
  
  q.pop(); // {2, 9} delets first ele
  
  cout << q.front(); //prints 2
  
  // size swap empty same as stack
}
```


## Priority Queue
The guy who have largest value stays at top.
```cpp
void explainPQ() {
  priority_queue<int>pq;
  
  pq.push(5) ; // {5}
  pq.push(2); // {5, 2}
  pq.push(8); // {8, 5, 2}
  pq.emplace(10); // {10, 8, 5, 2}
  
  cout << pq.top(); //prints 10
  
  pq.pop(); // {8, 5, 2}  top most ele is poped
  
  cout << pq.top(); // prints 8
  
  // size swap empty function same as others
  
  // Minimum Heap (stores minimum ele at top)
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(5) ; // {5}
  pq.push(2); // {2, 5}
  pq.push(8); // {2, 5, 8}
  pq.emplace(10); // {2, 5, 8, 10}
  
  cout << pq.top();//prints 2
}
```

## Set
It stores everything in sorted order and everything is unique.  

```cpp
void explainSet() {
  set<int>st;
  st.insert(1); // {1}
  st.emplace(2); // {1, 2}
  st.insert(2); // {1, 2}
  st.insert(4); // {1, 2, 4}
  st.insert(3); // {1, 2, 3, 4}
  
  // Functionality of insert in vector
  // can be used also, that only increases
  // efficiency
  
  // begin(), end(), rbegin(), rend(), size(),
  // empty() and swap() are same as those of above
  
  // {1, 2, 3, 4, 5}
  auto it = st.find(3); // return itrator that points to 3
  
  // {1, 2, 3, 4, 5}
  auto it = st.find(6);  // as ele is not in set it will return set.end() the itrator that points after the last element (not the last ele)
  
  // {1, 4, 5}
  st.erase(5); // erases 5 -> {1, 4} // takes logarithmic time
  
  int cnt = st.count(1); // as set is unique if the ele exists then 1 or 0

  auto it = st.find(3);
  st.erase(it); // can also give itrator

  // {1, 2, 3, 4, 5}
  auto it1 = st.find(2);
  auto it2 = st.find(4);
  st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

  // lower_bound() and upper_bound() function works in the same way
  // as in vector it does.
  
  // This is the syntax
  auto it = st.lower_bound(2);
  
  auto it = st.upper_bound(3);
}
```

## MultiSet
It is sorted but will not obey unique.
```cpp
void explainMultiSet() {
  // Everything is same as set
  // only stores duplicate elements also
  
  multiset<int>ms;
  ms.insert(1); // {1}
  ms.insert(1); // {1,1}
  ms.insert(1); // {1, 1, 1}
  
  ms.erase(1); // all 1's erased
  
  int cnt == ms.count(1);
  
  // only a single one erased
  ms.erase(ms.find(1)); // first occurance of 1, here find points itrator and it will erase that occurance only
  
  ms.erase(ms.find(1),ms.find(1)+2);
  
  // rest all function same as set
}
```

## UnorderedSet
- It won't be sorted and it will be **unique**.  
- We don't know how it will store it has randomized order.  

```cpp
void explainUSet() {
  unordered set<int> st;
  // lower_bound and upper_bound function does not works, rest all functions are same
  // as above, it does not stores in any particular order
  // it has a better complexity (mostly O(1) worst case or very rare O(N))
  // than set in most cases, except some when collision happens
```