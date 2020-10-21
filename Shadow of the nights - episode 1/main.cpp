#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct Coordinates{
    int x, y;
}coordinates;

struct Limits{
    int maxY, maxX, minY, minX;

    //Values for {maxY, maxX, minY, minX} for the different rules
//     {coordinates.y-1, coordinates.x, coordinates.minY,coordinates.x},       //U
//     {coordinates.y-1, coordinates.maxX, coordinates.minY, coordinates.x+1}, //UR
//     {coordinates.y, coordinates.maxX, coordinates.y, coordinates.x+1},      //R
//     {coordinates.maxY, coordinates.maxX, coordinates.y+1, coordinates.x+1}, //DR
//     {coordinates.maxX, coordinates.x, coordinates.y+1, coordinates.x},      //D
//     {coordinates.maxX, coordinates.x-1, coordinates.y+1, coordinates.minX}, //DL
//     {coordinates.y, coordinates.x-1, coordinates.y, coordinates.minX},      //L
//     {coordinates.y-1, coordinates.x-1, coordinates.minY, coordinates.minX}  //UL
}limits;

typedef struct Coordinates Struct;

Struct BinarySearch(int may, int maxx, int miy, int mix){
    limits.maxY = may;
    limits.maxX = maxx;
    limits.minY = miy;
    limits.minX = mix;

    Struct xy;

    xy.x = ((maxx-mix)/2) + limits.minX;
    xy.y = ((may-miy)/2) + limits.minY;

    return xy;
}

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    struct Coordinates coordinates = { X0, Y0 };
    //  limits.maxY, limits.maxX, limits.minY, limits.minX};
    limits={ H-1, W-1, 0, 0 };
    cout<<"At first Limits are: max y, max x ,min y, min x "<< limits.maxY <<limits.maxX<< limits.minY<<limits.minX<<endl;

    Struct jumpTo;

    // game loop
    bool isFirstJump=true;
    while (N>0) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        if(isFirstJump){
            jumpTo=BinarySearch(
                limits.maxY,
                limits.maxX,
                limits.minY,
                limits.minX);

                isFirstJump=false;
        }else{

            if (bombDir=="U")
            {
                jumpTo=BinarySearch(
                    coordinates.y-1,
                    coordinates.x,
                    limits.minY,
                    coordinates.x);

            }else if(bombDir=="UR")
            {
                jumpTo=BinarySearch(
                    coordinates.y-1,
                    limits.maxX,
                    limits.minY,
                    coordinates.x+1);

            }else if(bombDir=="R")
            {
                jumpTo=BinarySearch(
                    coordinates.y,
                    limits.maxX,
                    coordinates.y,
                    coordinates.x+1);
            }else if(bombDir=="DR")
            {
                jumpTo=BinarySearch(
                    limits.maxY,
                    limits.maxX,
                    coordinates.y+1,
                    coordinates.x+1);

            }else if(bombDir=="D")
            {
                jumpTo=BinarySearch(
                    limits.maxY,
                    coordinates.x,
                    coordinates.y+1,
                    coordinates.x);
            }else if(bombDir=="DL")
            {
                jumpTo=BinarySearch(
                    limits.maxY,
                    coordinates.x-1,
                    coordinates.y+1,
                    limits.minX);
            }else if(bombDir=="L")
            {
                jumpTo=BinarySearch(
                    coordinates.y,
                    coordinates.x-1,
                    coordinates.y,
                    limits.minX);
            }else if(bombDir=="UL")
            {
                jumpTo=BinarySearch(
                    coordinates.y-1,
                    coordinates.x-1,
                    limits.minY,
                    limits.minX);
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        coordinates.x=jumpTo.x;
        coordinates.y=jumpTo.y;
        // the location of the next window Batman should jump to.
        cout << jumpTo.x <<" "<< jumpTo.y<< endl;
        cout<<"The limits are: (my mx miy mix) "<< limits.maxY <<limits.maxX<< limits.minY<<limits.minX<<endl;

        N++;
    }


}
