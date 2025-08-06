#include<iostream>

using namespace std;

int main(){
     
    int  choice , size, pos,  ele;

     cout << "size";
     cin >> size;

     int arr[100];

    for (int i=0; i<size; i++){

        cout << "arr["<< i << "]: ";
        cin >> arr[i];

    }
    while(choice != 0)
    {
        cout << "_________________________"<< endl;
        cout << "prass 1 for insert"<< endl;
        cout << "prass 2 for delate"<< endl;
        cout << " prass 3 for update "<< endl;
        cout << " prass 4 for read"<< endl;
        cout << "prass 0 for exit...!" << endl;


        cout << "choice";
        cin >> choice;

        switch (choice)
        {
            case 1 :
                cout << "pos: ";
                cin >> pos;

                cout << "ele: ";
                cin >> ele;
                 
                for (int i=size; i>pos; i--)
                {
                    arr[i] = arr [i-1];

                }

                arr[pos] =ele;
                size++;

                cout << "ele inserted...!"<< endl;
            break;

            case 2: cout << "pos :";
                        cin >pos;

                        for (int i=pos; i<size; i++)
                        {
                            arr[i] = arr[i+1];

                        }
                        size--;

                        cout << "ele delated...!"<< endl;

                break;
                case 3: cout << "pos: ";
                        cin >> pos;

                        cout << "ele: ";
                        cin >> ele;



        }
    }

    return 0;
}