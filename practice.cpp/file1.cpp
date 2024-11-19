#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <stack>
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

int maxArea(vector<int>& height) {
        int max = 0;

        int left = 0;
        int right = height.size() - 1;

        while(left != right){
            int product = height[left] * height[right];
            cout << product << endl;
            if( product > max){
                max = product;
            }

            if(height[left] < height[right]){
                ++left;
            }else{
                ++right;
            }
        } 
        return max;
    }


bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char, int> dict;

        //traverse through each row
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                char number = board[row][col];
                //Check if char is digit and in dict
                if(isdigit(number && dict.find(number) == dict.end())){
                    dict[number] = 1;
                }else if(isdigit(number) && dict.find(number) != dict.end()){
                    return false;
                }

            }
            dict.clear();
        }

        //Traverse through each column
        for(int col = 0; col < board[0].size(); col++){
            for(int row = 0; row < board.size(); row++){
                char number = board[row][col];
                //Check if char is digit and in dict
                if(isdigit(number && dict.find(number) == dict.end())){
                    dict[number] = 1;
                }else if(isdigit(number) && dict.find(number) != dict.end()){
                    return false;
                }
            }
            dict.clear();
        }

        int i = 0;
        int j = 0;
        //Traverse in a 3 by 3 block
        for(int x = 1; x <= 9; x++){
        
            while(i < i+3){
                while(j < j+3){
                    char number = board[i][j];
                    //Check if char is digit and in dict
                    if(isdigit(number && dict.find(number) == dict.end())){
                        dict[number] = 1;
                    }else if(isdigit(number) && dict.find(number) != dict.end()){
                        return false;
                    }
                }
            }

            i+=3;
            j+=3;

        }
    return true;
    }

    void performCalculation(int& result , int num1 , int num2, std::string op){
        if(op == "+"){
            result = num1 + num2;
        }else if(op == "-"){
            result = num1 - num2;
        }else if(op == "/"){
            result = num1 / num2;
        }else if(op == "*"){
            result = num1 * num2;
        }
    }

    void performCalculation(int& result, int num , std::string op){
        
        if(op == "+"){
            result = num + result;
        }else if(op == "-"){
            result = num - result;
        }else if(op == "/"){
            result = num / result;
        }else if(op == "*"){
            result = num * result;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        int result = 0;

        for(string i : tokens){
            cout << "i = " << i << endl;
            //Check if i is number or not
            if(i != "+" && i != "-" && i != "/" && i != "*"){
                stack.push(std::stoi(i));
            }else{

                if(result == 0){
                    int x = stack.top(); stack.pop();
                    int y = stack.top(); stack.pop();
                    performCalculation(result , x , y , i);
                }else{
                    int x = stack.top(); stack.pop();
                    performCalculation(result , x , i);
                }

            }

        }
        return result;
    }
int main(){
    vector<string> x = {"2", "1", "+", "3", "*"};

    cout << evalRPN(x);
   
   return 0;
}
