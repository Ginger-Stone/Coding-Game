#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    vector<vector<int>> vv;

    bool isFirst=true;

    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();

        vector<int> v;
        if(isFirst){
            v.push_back(x);
            v.push_back(y);

            vv.push_back(v);

        }else if(!isFirst){
            for(int j=0; j<vv.size(); j++){
                if(vv[j].back()==x){
                    vv[j].push_back(y);
                }else if(vv[j].front()==y){
                    vv[j].insert(vv[j].begin(), x);
                }else if(vv[j].back()==y){
                    for(int m=0; m<vv.size(); m++){
                        if(vv[m].back()==x){
                            int newVect = vv.size()+1;
                            vv[newVect]=vv[m];
                            vv[newVect].push_back(y);
                        }
                    }
                }else if(j==vv.size()-1 && vv[j].back()!=x && vv[j].front()!=y && vv[j].back()!=y){
                    v.push_back(x);
                    v.push_back(y);
                    vv.push_back(v);
                }

            }
        }

        v.clear();

        isFirst=false;
    }

    int cc = 0;
    int maxLength=0;
    while(cc<vv.size()){
        if(vv[cc].size()>maxLength){
            maxLength=vv[cc].size();
        }
        cc++;
    }

    for (int y=0; y<vv.size(); y++){
        for (int z=0; z<vv[y].size(); z++){
            cout << vv[y][z];
        }
        cout<<endl;
    }
    cout << maxLength << endl;
}
