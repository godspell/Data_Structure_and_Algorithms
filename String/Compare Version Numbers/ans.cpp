class Solution {
public:
    int compareVersion(string A, string B) {
    int n1 = A.size();
    int n2 = B.size();
    int i = 0, j= 0;
    while(i < n1 || j < n2){
        int num1 = 0, num2 = 0;
        while(i<n1 && A[i] != '.'){
            num1 = num1*10 + (A[i] - '0');
            i++;
        }
        
        while(j<n2 && B[j] != '.'){
            num2 = num2*10 + (B[j] - '0');
            j++;
        }
        
        if(num1 > num2) return 1;
        else if(num2 > num1) return -1;
        
        i++, j++;
    }
    
    return 0;
    }
};