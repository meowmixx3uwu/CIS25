#include <iostream>
using namespace std;
int main() {    
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    if(n1 >= n2 && n1 >= n3){
        cout << "Largest number: " << n1 << endl;
        return 0;
    }
    if(n2 >= n1 && n2 >= n3)
   {     cout << "Largest number: " << n2 << endl;
    return 0;
   }
    if(n3 >= n1 && n3 >= n2) {
        cout << "Largest number: " << n3 << endl;
        return 0;
  }
    return 0;
}
