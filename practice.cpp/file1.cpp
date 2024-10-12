#include <iostream>
using namespace std;

double calculateAverage(int array[], int size){
   double sum = 0;
   for(int i = 0; i < size; i++){
      sum += array[i];
   }

   return sum / (double)size;
}

char findGrade(double average){
   if (average >= 85) return 'A';
    if (average >= 70) return 'B';
    if (average >= 60) return 'C';
    if (average >= 50) return 'D';
    return 'F';
}

void arraysUnion (int arr1[], int arr1Size ,int arr2[], int arr2Size, int newArray[]){

   int i = 0;
   for(int j = 0; j < arr1Size; j++){
      newArray[i++] = arr1[j];
   }

   for(int j = 0; j < arr2Size; j++){
      newArray[i++] = arr2[j];
   }  
}

void print(int arr[], int size){
   for(int i = 0; i < size; i++){
      cout << arr[i] << ",";
   }
   cout << endl;
}

void mergeSortedArrays(int arr1[], int arr1size, int arr2[], int arr2size , int mergedArray[]){

   int i = 0, j = 0, k = 0;

   //keep merging until one of the array is exhausted
  while(i < arr1size && j < arr2size){
      if(arr1[i] < arr2[j]){
         mergedArray[k++] = arr1[i++];
      }else{
         mergedArray[k++] = arr2[j++];
      }
  }
      //add the elements of remaining array
   while(i < arr1size){
      mergedArray[k++] = arr1[i++];
   }

   while(j < arr2size){
      mergedArray[k++] = arr2[j++];
   }
  
}

float max(float arr[], int size){
   float max = -99999;

   for(int i = 0; i < size; i++){
      max = (arr[i] > max)? arr[i]: max;
   }

   return max;
}

float calculateAverageMarks(int marks[], int totalStudents, int totalMarks){

   float sum = 0;
   totalMarks = totalMarks * totalStudents;
   for(int i = 0; i < totalStudents; i++){
      sum += marks[i];
   }

   return sum / totalStudents;
   
}

int main(){

   string s = "ateeb";
   s += 'a';
   cout << s;
   return 0;
}
