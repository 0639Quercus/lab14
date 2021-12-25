#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool img[][M], int s, int x, int y){
    int pos[2][2];
    pos[0][0] = x-s+1 >= 0 ? x-s+1 : 0;     // left border
    pos[0][1] = x+s-1 <= N-1 ? x+s-1 : N-1; // right border
    pos[1][0] = y-s+1 >= 0 ? y-s+1 : 0;     // top border
    pos[1][1] = y+s-1 <= M-1 ? y+s-1 : M-1; // bottom border
 
    bool inside;
    for(int i = pos[0][0]; i <= pos[0][1]; i++){
        for(int j = pos[1][0]; j <= pos[1][1]; j++){
            inside = (sqrt(pow(i-x,2) + pow(j-y,2)) <= s-1);
            if(inside) img[i][j] = true;
        }
    }
}

void showImage(const bool img[][M]){
    cout << "------------------------------------------------------------------------\n";
    for(int i = 0; i < N; i++){
        cout << '|';
        for(int j = 0; j < M; j++){
            if(img[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '|' << '\n';
    }
    cout << "------------------------------------------------------------------------\n";
}