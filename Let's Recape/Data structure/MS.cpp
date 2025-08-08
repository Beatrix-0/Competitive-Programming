#include <bits/stdc++.h>
using namespace std;

// 1. Next Greater Element
vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

// 2. Previous Greater Element
vector<int> previousGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) result[i] = arr[st.top()];
        st.push(i);
    }

    return result;
}

// 3. Next Smaller Element
vector<int> nextSmallerElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

// 4. Previous Smaller Element
vector<int> previousSmallerElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) result[i] = arr[st.top()];
        st.push(i);
    }

    return result;
}

// Helper to print results
void printVector(string name, vector<int>& v) {
    cout << name << ": ";
    for (int val : v) cout << val << " ";
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};

    vector<int> nge = nextGreaterElements(arr);
    vector<int> pge = previousGreaterElements(arr);
    vector<int> nse = nextSmallerElements(arr);
    vector<int> pse = previousSmallerElements(arr);

    printVector("Next Greater       ", nge);
    printVector("Previous Greater   ", pge);
    printVector("Next Smaller       ", nse);
    printVector("Previous Smaller   ", pse);

    return 0;
}
