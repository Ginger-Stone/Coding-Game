//Author: Doreen Chemweno
//Project: There is no spoon - episode 1
//Link to Problem: https://www.codingame.com/training/medium/there-is-no-spoon-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int neighborSearchRight(string a[], int width, int node_x, int node_y){
    for (int j=node_x+1; j<width; j++){
        if(a[node_y][j]=='0'){
            return j;
        }
    }
    return -1;
}

int neighborSearchBottom(string a[], int height,int node_x, int node_y){
    for (int j=node_y+1; j<height; j++){
        if(a[j][node_x]=='0'){
            return j;
        }
    }
    return -1;
}

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    string allStrings[height];
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        allStrings[i]=line;
    }

    int bottom_y, right_x;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(allStrings[i][j]=='0'){
                right_x=neighborSearchRight(allStrings,width,j,i);
                bottom_y=neighborSearchBottom(allStrings,height,j,i);

                int right_y=i, bottom_x=j;
                if(right_x==-1){
                   right_y=-1;
                }
                if(bottom_y==-1){
                   bottom_x=-1;
                }

                cout << j<<" "<< i<<" "<< right_x<<" "<< right_y<<" "<< bottom_x<<" "<< bottom_y << endl;
            }
        }
    }
}
