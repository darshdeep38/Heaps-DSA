class Solution {
public:


    void heapify(vector<int>& arr , int n ,int i){
        int largest = i ; 
        int left = 2*i + 1;
        int right = 2*i + 2;


        // if left child is larger than the root 
        if(left < n &&  arr[left] > arr[largest]){
            largest = left;
        }

        //If right child is larger than the largest so far
        if( right < n && arr[right] > arr[largest]){
            largest =  right ;
        }



        // if largest is not root 

        if(largest != i ){
        swap(arr[i] , arr[largest]);   // swap current root with largest 
        heapify(arr , n , largest);    // recursively heapify the affected subtree 

        }

    }



    //main function to do heap sort
    void heapSort(vector<int>& arr){
        int n = arr.size();

            // Build a max heap: start from last non-leaf node
            for( int i =  n/2 -1 ; i>= 0 ; i--){
                heapify(arr, n , i);
            }

                // One by one extract elements from heap
                for(int i = n - 1; i> 0 ; i--){
                    swap(arr[0] , arr[i]);   // move current node to the end
                    heapify(arr , i , 0);    // call max heapify on the reduced heap
                }


    }


    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
