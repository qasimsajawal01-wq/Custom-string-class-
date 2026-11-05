#include "mystring.h"
#include<iostream>


bool memeoryComp(void * a , void * b)
{
  return a == b; 
}

using namespace std;

int main()
{


    // int a [2][2][2]; 
    // int * (*p)[2][2] = &a[0] ; 
    // Thermostat th;
    // th.switchIt(0);

    // Array arr(5);
    // arr.getSet(0) = 5;
    // cout << arr.getSet(0);
    // Array arr(3);

    // const char *a = "hello";
    // const char *b = "hello";
    // const char y[6] = "hello";
    // cout << (void *)a << "\n";
    // cout << (void *)b << "\n";
    // cout << (void *)y;

    // arr.getSet(0) = 10;
    // arr.getSet(1) = 20;
    // arr.getSet(2) = 30;

    // cout << "Before resizing:\n";

    // for (int i = 0; i < arr.getCapacity(); i++)
    // {
    //     cout << arr.getSet(i) << " ";
    // }

    // arr.reSize(5);

    // cout << "\n\nAfter increasing capacity to 5:\n";

    // for (int i = 0; i < arr.getCapacity(); i++)
    // {
    //     cout << arr.getSet(i) << " ";
    // }

    // arr.reSize(2);

    // cout << "\n\nAfter decreasing capacity to 2:\n";

    // for (int i = 0; i < arr.getCapacity(); i++)
    // {
    //     cout << arr.getSet(i) << " ";
    // }

    // cout << "\n";

    // return 0;

    // String st , st1;
    // st.input();
    // st1.input();
    // if (st.compare(st1) == 0)
    // {
    //     cout << "both are equal";
    // }
    // else
    // {
    //     cout << "both are not equal";
    // }

    // st.display();

    // String str("");
    // str.reverse();
    // str.display();
    // cout << str.getLenght();
    // String sub(" ");

    // str.insert(5, sub);
    // str.display();

    // String str("HelloWorld");
    // String sub(" Beautiful ");

    // str.insert(5, sub);
    // str.display();
    

    // int a; 
    // int *p = &a ;
    // int **ptr = &p;

    // float b;
    // float *bp = (float *)&a;
    // float **bptr = &bp;

    // cout << memeoryComp(ptr , bptr); 



   String s , b , t;

   b.input();
   s.input();
   s.concatEqual(b);  

   return 0;
}