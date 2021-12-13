/*
*Questo programma è per trovare la massima sequenza di zeri 
*che si possono trovare in una sequenza di numeri binaria(N.Neccessariamente) 
*il programma può essere ottimazato(miglioramento performance) utilizzando l'HashMap e distinguere le condizioni una dall'altra.
*/

#include<iostream>
using namespace std;
int main() {

int element = 0, conta = 0;

int arr[] = {0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0};
int size = sizeof(arr)/sizeof(arr[0]);
int *count = new int[size];

  for(int i = 0; i < size; i++){
    if((i != size-1 && arr[i] == 0 && arr[i+1] == 0)|| 
      (i != size-1 && arr[i] == 0 && arr[i+1] != 0)){
        conta++;
      }else if(i == size-1 && arr[i] == 0) { 
        conta++;
        count[element] = conta;
        element++;
    }else{
      count[element] = conta;
      element++;
      conta = 0;
    }
  }

int t = count[0];
  for(int i = 0; i < element; i++){
    if(i != element-1 && count[i] < count[i+1]){
      t = count[i+1];
    }
    if(i == element-1 && count[i] > t){
      t = count[i];
    }
  }

cout << t;
delete[] count;
return 0;
}