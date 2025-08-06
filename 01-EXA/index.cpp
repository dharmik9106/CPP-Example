#include <iostream>

using namespace  std;

int main() {
  

    int size= 5;
    int arr[5]= {99, 200, 306, 580, 400};


    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;

cout <<" _________________________________________" << endl;


    for (int i=0; i<size; i++){
        cin >> arr [i];
    }
    
 
    for (int i=0; i<size; i++)
    {
        cout << arr [i] << endl;

    }

}