#include<iostream>
#include <random>
#include<algorithm>
#include<fstream>  

// CHECK IF PAIR IS EQUAL
int checkPair(char c1, char c2, int wmat, int wmis, int score){
    if(c1==c2){
        return wmat;
    }
    else{
        return wmis;
    }
}

int main(){
    int n, m;
    int wmat = 2;
    int wmis = -1;
    int wgap = -1;
    int k, p, j, score;

    std::string a, b;
    std::string bestA, bestB;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cin >> b;

    std::random_device rd;
    // int seed = 5;
    // std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution2(1,m);
    std::uniform_int_distribution<int> distribution1(1,n);
    std::string subA, subB;
    int max_score;

    if(n>m){
        k = distribution2(rd);  
        max_score = -n*2;
    }
    else{
        k = distribution1(rd);
        max_score = -m*2;
    }

    std::uniform_int_distribution<int> distribution21(0,m-k);
    for(int rounds = 0; rounds<100000; rounds++){
        p = distribution2(rd);
        // int scoreList[p];
        subA = a.substr(0,k);
        for(int i = 0; i < p; i++){
            score = 0;
            j = distribution21(rd);
            subB = b.substr(j,k);
            for(int index = 0; index < k; index++){
                score += checkPair(subA[index], subB[index], wmat, wmis, score);
            }
            // scoreList[i] = score;
            if(score > max_score){
                max_score = score;
                bestA = subA;
                bestB = subB;
            }
            // std::cout << subA << std::endl << subB << std::endl;
            // std::cout << score << std::endl;
        }
    }
    // std::cout << std::endl << "n: " << n << std::endl << "m: " << m << std::endl << "k: " << k << std::endl << "p: " << p << std::endl;
    // std::cout << "max_score: " << max_score << std::endl;
    // std::cout << "bestA: " << bestA << std::endl;
    // std::cout << "bestB: " << bestB << std::endl;
    std::ofstream outfile ("output.txt");
    outfile << max_score << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
    outfile.close();
}