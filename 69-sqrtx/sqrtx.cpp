class Solution {
public:
    int mySqrt(int x) {
     int start = 0;
     int end = x;
     int mid;
     while(start <= end){
        mid = start + (end - start)/2;
        long long square = 1LL * mid * mid;
        if(square == x){
            return mid;
        }
        else if(square > x){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
     }   
     return end;
    }
};