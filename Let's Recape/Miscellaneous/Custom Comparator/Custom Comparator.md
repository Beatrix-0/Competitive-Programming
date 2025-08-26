# Custom Comparator In C++

[Tutorial Blog](https://medium.com/@itz_scaria/custom-comparator-in-c-bfff04a901e1)

## 1. Custom Comparator for sort (vector, array) 
```cpp
// Example: sort by first increasing, if tie then second decreasing
bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

vector<pair<int,int>> v = {{1,2},{1,5},{2,3}};
sort(v.begin(), v.end(), cmp);
```

## 2. Custom Comparator for priority_queue
Syntax : priority_queue<T, vector<T>, Compare> pq;
```cpp
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first) return a.second > b.second; // smaller second first
        return a.first < b.first; // larger first first
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
```

## 3. Custom Comparator for set / multiset
Syntax : set<T, Compare> s;
```cpp
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first) return a.second < b.second; // normal increasing
        return a.first > b.first; // descending by first
    }
};

set<pair<int,int>, cmp> s;
```
## 4. Custom Comparator for map / multimap
Syntax : map<Key, Value, Compare> mp;
```cpp
struct cmp {
    bool operator()(const int& a, const int& b) const {
        return a > b; // descending order of keys
    }
};

map<int,string,cmp> mp;
```

## 5. Custom Comparator using lambda (C++11+)
For sort :
```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
});
```
For priority_queue :
```cpp
auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
};

priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```


