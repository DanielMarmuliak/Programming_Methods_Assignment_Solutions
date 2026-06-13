#include <iostream>







int main(){
    int arr[5] = {5,4,-1,7,8};
    int local_sum {0};
    int max_sum = INT_MIN;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        local_sum += arr[i];
        if(local_sum > max_sum){
            max_sum = local_sum;
        }
        if(local_sum < 0){
            local_sum = 0;
        }
    }
    std::cout << max_sum;

    
    
    return 0;
}