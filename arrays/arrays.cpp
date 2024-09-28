#include <iostream>
using namespace std;

void printArray(int arr[], int size){
   for(int i = 0; i < size; i++){
      cout<< arr[i] << ",";
   }
   cout<<endl;

}

void reverseArray(int array[], int size){
   for(int i = 0; i < size/2; i++){
      int temp = array[i];
      array[i] = array[size - 1 - i];
      array[size - 1 -i] = temp;
   }
}

void rotateArrayRightward(int arr[], int n, int d){

   int x = 0;
   int* newArr = new int[n];

   for(int i = n - d; i < n; i++){
      newArr[x] = arr[i];
      x++;
   }

   for(int i = 0; i < n - d; i++){
      newArr[x] = arr[i];
      x++;
   }

   //copying the content of newArray to OldArray
   for (int i = 0; i < n; i++) {
        arr[i] = newArr[i];
   }

   //deallocating the memory
   delete newArr;

}

void rotateArrayRightward2(int arr[] , int n , int d){

   //reversing the first elements
   int x = n - d;
   for(int i = 0 ; i < x/2; i++){
      int temp = arr[i];
      arr[i] = arr[x - 1 - i];
      arr[x - 1 - i] = temp;
   }


   for(int i = 0; i < (n - x - 1)/2; i++){
      int temp = arr[x+i];
      arr[x] = arr[n - 1 - i];
      arr[n - 1 - i] = temp;
   }

   //reverse the whole array
   for(int i = 0; i < n/2 ; i++){
      int temp = arr[i];
      arr[i] = arr[n - 1 - i];
      arr[n - 1 - i] = temp;
   }
}


//Insert at specific position
void insertAt(int arr[], int& size, int value, int index){
   

   //move all the elements to right
   for(int i = size; i > index ; i--){
      arr[i] = arr[i-1];
   }

   arr[index] = value;

   size++;
}

void deleteElement(int arr[] , int& size, int value){
   int index = -1;
   for(int i = 0; i < size; i++){
      if(arr[i] == value){
         index = i;
         break;
      }
   }

   //if index with given value isnt found
   if(index == -1){
      cout<< "specified value not found \n";
      return;
   }

   for(int i = index; i < size -1 ; i++){
      arr[i] = arr[i+1];
   }

   size--;

}

//methods for operations in sorted arrays

int binarySearch(int array[], int size, int key){
   int left = 0;
   int right = size - 1;


   while(left <= right){
      int mid = (left + right) / 2;

      if(array[mid] == key){
         return mid;
      }else if(array[mid] > key){
         right = mid - 1;
      } else{
         left = mid + 1;
      }

   }

   return -1;  
}

void insert(int arr[], int& size , int value){
   int index;
   for(index = size - 1; arr[index] > value && index >= 0; index--){
      arr[index + 1] = arr[index];
   }

   arr[index + 1] = value;

   size++;

}

void deleteElementInSortedArray(int arr[], int& size, int key){
   int index = binarySearch(arr, size , key);

   if(index == -1){
      cout << "key not found in array \n";
      return;
   }

   //shift all elements rightward;
   for(int i = index; i < size - 1; i++){
      arr[i] = arr[i+1];
   }

   size--;
}

//traversal
int main(){

   int arr[15] = {1,2,3,4,5};
   int size = 5;


   insert(arr , size , 3);
   cout <<binarySearch(arr, size , 4);
   deleteElementInSortedArray(arr, size , 4);
   printArray(arr, size);
   return 0;
}