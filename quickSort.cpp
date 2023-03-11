//*Bismillahir Rahmanir Raheem
//! symonkarim
#include <bits/stdc++.h>
#define FASTER ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
//!------

#include<vector>
using namespace std;


int partition(std::vector<int> &v, int s, int e) {
    int pivot = v[s], cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (  v[i] <= pivot ) cnt++;
    }
    int pivotIndex = s + cnt;
    swap(v[pivotIndex], v[s]);
    int i = s, j = e;
    while (i<pivotIndex and j>pivotIndex) {
        while (v[i] < pivot) i++;
        while ( v[j] > pivot) j--;
        if (i<pivotIndex and j>pivotIndex) swap(v[i++], v[j--]);
    }
    return pivotIndex;
}
void quickSort(std::vector<int> &v, int s, int e) {
    if (s >= e) return;

    int pivotIndex = partition(v, s , e);
    //cout << pivotIndex << endl;
    quickSort(v, s, pivotIndex - 1);
    quickSort(v, pivotIndex + 1, e);
}
int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t; cin >> t; for (int i = 1; i <= t; i++) {
  int size; cin>>size
    vector<int>v(size);
    quickSort(v, 0, size-1);
   
    for (auto i : v)cout << i << " ";
    cout << endl;

   }

    return 0;
}
