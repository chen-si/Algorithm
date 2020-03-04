//
// Created by liu on 2020/2/16.
//

#include<iostream>
using namespace std;

const int INF = INT32_MAX;

void FindMaxCrossingSubArray(const int a[],int low,int mid,int high,int &max_left,int &max_right,int &sum);
void FindMaximumSubArray(int a[],int low,int high,int &max_low,int &max_high,int &max_sum);

int main(){
    int a[16] ={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int max_low,max_high,max_sum;
    FindMaximumSubArray(a,0,15,max_low,max_high,max_sum);
    cout<<max_low<<" "<<max_high<<" "<<max_sum<<endl;
}

void FindMaximumSubArray(int a[],int low,int high,int &max_low,int &max_high,int &max_sum){
    if(high == low){
        max_low = low;
        max_high = high;
        max_sum = a[low];
        return;
    }else{
        int mid = (low+high)/2;
        int left_low,left_high,left_sum,right_low,right_high,right_sum,cross_low,cross_high,cross_sum;
        
        FindMaximumSubArray(a,low,mid,left_low,left_high,left_sum);
        FindMaximumSubArray(a,mid+1,high,right_low,right_high,right_sum);
        FindMaxCrossingSubArray(a,low,mid,high,cross_low,cross_high,cross_sum);

        if(left_sum >= right_sum && left_sum >= cross_sum){
            max_low = left_low;
            max_high = left_high;
            max_sum = left_sum;
        } else if(right_sum >= left_sum && right_sum >= cross_sum){
            max_low = right_low;
            max_high = right_high;
            max_sum = right_sum;
        }else{
            max_low = cross_low;
            max_high = cross_high;
            max_sum = cross_sum;
        }
    }
}

void FindMaxCrossingSubArray(const int a[],int low,int mid,int high,int &max_left,int &max_right,int &left_right_sum){
    int left_sum = -INF;
    int sum = 0;
    for(int i = mid;i >= low;i--){
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -INF;
    sum = 0;

    for(int i = mid + 1;i <= high;i++){
        sum += a[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    left_right_sum = left_sum + right_sum;
}



