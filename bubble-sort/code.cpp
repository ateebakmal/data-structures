#include <iostream>

//Simple bubble sort
void bubble_sort(int array[] , int size){
   for(int i = 0; i < size - 1; i++){

      for(int j = 0; j < size - 1 - i; j++){

         if(array[j] > array[j+1]){
            //swap elements
            int x = array[j];
            array[j] = array[j + 1];
            array[j + 1] = x;

         }

      }
   }
}

//Adaptive Bubble Sort
void adaptive_bubble_sort(int array[] , int size){
   int flag;
   
   for(int i = 0; i < size -1 ; i++){

      flag = 0;
      for(int j = 0; j < size - 1 - i; j++){

         
         if(array[j] > array[j + 1]){
            //swap
            int x = array[j];
            array[j] = array[j + 1];
            array[j + 1] = x;

            //increment the flag
            flag++;

         }

      }

      //Check if swapping wasnt done, If no swapping means array is already sorted so break
      
      if(flag == 0){
         break;
      }
   }

}

//Function that prints the array
void print_array(int array[] , int size){
   for(int i = 0; i < size; i++){
      std::cout<< array[i] << ",";
   }
}

int main(){

   int unordered_array[] = {8,2,3,4,5};
   int size = 5;
   
   adaptive_bubble_sort(unordered_array, size);

   //printing the array
   print_array(unordered_array, size);
   return 0;
}