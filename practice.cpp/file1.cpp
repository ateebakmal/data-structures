#include <iostream>
using namespace std;

int main(){
   int marks[] = {1,2,3,4};
   int* p = marks;
   cout<< &marks <<endl;
   cout<< p << endl;

   //Value of default p
   cout << "Value of current p : " << *p <<endl;
   cout << "Value of current p with 1 increment: " << *(p+1) <<endl;
   cout << "Value of current p with 2 increment: " << *(p+2) <<endl;
   cout << "Value of current p with 1 increment: " << *(p+3) <<endl;
   p+= 5;
   cout << "Value of current p with 5 increment: " << *p <<endl;
   
   
   return 0; 
}