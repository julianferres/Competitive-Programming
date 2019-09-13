#include <bits/stdc++.h>
using namespace std;
int main(){
    double m;
    cin >> m ;
    for(double n = m+2; n<10000000+2 ; n++){
        double i = (pow(n,2)+n+pow(m,2)-m)/2;
        if(pow((int)sqrt(i),2) == i){
            cout << m <<" " << (int) sqrt(i) <<" " << (int) n << endl;
            return 0;
        }
    }
    return 0;
}
