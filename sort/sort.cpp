#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T>
void swap(T *arr, int i, int j){
    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


template<class T>
void d_sort(T *arr, int n){
int i, j;                             
	T temp;                                    
	for (i = 1; i < n; i++) {
		j = i;
		temp = arr[i];                         
		while (j > 0 && temp < arr[j - 1]) {   
			arr[j] = arr[j - 1];             
			j--;                               
		}
		arr[j] = temp;                        
	}
} 


template<class T>
void c_sort(T *arr, int n){
int i, j;                             
    int temp;                                  
	for (i = 0; i < n; i++) {
        temp = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[temp]){
                temp = j;
            }
        }

        if (temp != i){
            swap(arr, i, temp);
        }
	}
} 


template<class T>
void max_heapify(T* arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {    
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else {
            swap(arr, dad, son);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
 

template<class T>
void heap_sort(T arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--){
        max_heapify(arr, i, len - 1);
    }

    for (int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        max_heapify(arr, 0, i - 1);
    }
}


template<class T>
void b_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr, j, j+1);
            }
        }
    }

}


template<class T>
void quick_sort(T* arr, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = arr[l];
        while (i < j)
        {
            while(i < j && arr[j] >= x){
                j--;
            }
            if(i < j){
                arr[i++] = arr[j];
            }
            while(i < j && arr[i] < x){
                i++;  
            }
            if(i < j){
                arr[j--] = arr[i];
            }
        }
        arr[i] = x;
        quick_sort(arr, l, i - 1); 
        quick_sort(arr, i + 1, r);
    }
}


template<class T>
void merge(T arr[],int low,int mid,int high){
    int i=low,j=mid+1,k=0;  
    T *temp=new int[high-low+1]; 
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]) 
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)
	arr[i]=temp[k];
    delete []temp;
}


template<class T>
void merge_sort (T arr [], int low,int high) {
    if(low>=high) { return; } 
    int mid =  low + (high - low)/2;  
    merge_sort(arr,low,mid);  
    merge_sort(arr,mid+1,high);  
    merge(arr,low,mid,high); 
  }


int main(){
    int a[] = {3,2,1,5,8,4,6,7};
    merge_sort(a, 0, 7);
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
}