//BRUTE FORCE 
//TIME- O(m+n)
//SPACE- O(m++n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int m=v1.size();
        int n=v2.size();
  
        int i=0, j=0, k=0;
        int med=0;
        int p;
        int mid=(m+n)/2 ;
        while(i<m && j<n && k<=mid) {
            if(v1[i]<=v2[j]){
                p=med;
                med=v1[i++];
                k++;
            }
            else{
                p=med;
                med=v2[j++];
                k++;           
            }
        }

        while(i<m  && k<=mid){
            p=med;
            med=v1[i++];
            k++;
        }
        while(j<n && k<=mid){
            p=med;
            med=v2[j++];
            k++; 
        }
        int s=m+n;
        if(s%2==0) return (med+p)/2.0;
        else return med;
    }
};

//OPTIMAL FORCE 
//TIME- O(m+n)
//SPACE- CONSTANT

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int m=v1.size();
        int n=v2.size();
  
        int i=0, j=0, k=0;
        int med=0;
        int p=0;
        int s=m+n;
        while(k<=s/2) {
            p=med;
            if(i<m && (j>=n || v1[i]<=v2[j]))med=v1[i++];
            else med=v2[j++];
            k++;
        }

        return (s%2==0) ? (med+p)/2.0 : med;
    }
};




//BEST - BINARY SEARCH
//TIME- O(LOG(m+n))
//SPACE- CONST
