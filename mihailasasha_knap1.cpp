#include<fstream>
using namespace std;
int G,n;
float O[100][3];

int read_data(){
    ifstream f("input.dat");
    f>>G>>n;
    for(int i=1;i<=n;i++){
        f>>O[i][1]>>O[i][2];
    }
}

int fill_data(){
    for(int i=1;i<=n;i++){
        O[i][3]=O[i][2]/O[i][1];
    }
}

int sort_data(){
    int i=1;
    int locul;
    while(i<=n){
        float minim=INT_MAX;
        for(int j=i;j<=n;j++){
            if(O[j][3]<minim){
                minim=O[j][3];
                locul=j;
            }

        }
        for(int k=1;k<=3;k++){
            swap(O[i][k],O[locul][k]);
        }
        i++;
    }
}

float greedy(){
    float profit=0;
    int i=n;
    while((G>0)&&(i>=1)){
        if(G>=O[i][1]){
            profit=profit+O[i][2];
            G=G-O[i][1];
        }
        else {
            profit=profit+(G*O[i][3]);
            G=0;
            break;
        }
        i--;
    }
    return profit;
}

int print_data(){
    ofstream g("output.dat");
    g<<greedy();
}

int main(){
    read_data();
    fill_data();
    sort_data();
    print_data();
    return 0;
}
