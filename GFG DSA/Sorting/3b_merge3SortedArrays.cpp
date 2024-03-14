#include <bits/stdc++.h>
using namespace std;

// No need to note, but just look at how it's solved!
vector<int> mergeThree(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    int m = B.size();
    int p = C.size();
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < n || j < m || k < p)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i < n)
            a = A[i];
        if (j < m)
            b = B[j];
        if (k < p)
            c = C[k];
        /* Smart Thinking
        So that, if some array remains untraversed, the other variables won't be updated and will stay max, which when compared to non fully traversed value, the right values keeps getting inserted in vector through loop, till every array is traversed.*/

        // Cheking if 'a' is the minimum
        if (a <= b && a <= c)
        {
            ans.push_back(a);
            i++;
        }
        // Cheking if 'b' is the minimum
        else if (b <= a && b <= c)
        {
            ans.push_back(b);
            j++;
        }
        // Cheking if 'c' is the minimum
        else
        {
            if (c <= a && c <= b)
            {
                ans.push_back(c);
                k++;
            }
        }
    }
    return ans;
}

int main()
{

    int n, m, o;
    cin >> n >> m >> o;
    vector<int> A, B, C;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        B.push_back(x);
    }

    for (int i = 0; i < o; i++)
    {
        int x;
        cin >> x;
        C.push_back(x);
    }

    vector<int> ans = mergeThree(A, B, C);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C));
    return 0;
}

// My Code
/*
    vector<int> merge2SortedArrays(vector<int>&X, vector<int>& Y,int i,int j){
        int xn=X.size() , yn = Y.size();
        vector<int> addOn;
        while(i<xn && j<yn){
            if(X[i]<= Y[j]){
                addOn.push_back(X[i++]);
            }else{
                addOn.push_back(Y[j++]);
            }
        }
        while(i<xn){
            addOn.push_back(X[i++]);
        }
        while(j<yn){
            addOn.push_back(Y[j++]);
        }
        return addOn;
    }
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C)
    {
        //Your code here
        int an=A.size(), bn=B.size(),cn=C.size();
        vector<int> res;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<an && j<bn && k<cn){
            if(A[i]<=B[j]){
                if(A[i]<=C[k]){
                    res.push_back(A[i++]);
                }else{
                    res.push_back(C[k++]);
                }
            }else{
                if(B[j]<=C[k]){
                    res.push_back(B[j++]);
                }else{
                    res.push_back(C[k++]);
                }
            }
        }
        vector<int> addOn;
        if(i == an){
            addOn = merge2SortedArrays(B, C, j,k);
        }else if(j == bn){
             addOn = merge2SortedArrays(A, C, i,k);
        }else if(k == cn){
             addOn = merge2SortedArrays(A, B, i,j);
        }

        res.insert(res.end(), addOn.begin(), addOn.end());
        return res;
    }

*/