#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

int task1 ();
int task2 ();
int task3 ();
int task4 ();

int main() {
    task1();
    task2();
    task3();
    task4();
    return 0;
}

int task1 (){
    int i;
    float nmbrs [10];
    std::srand(std::time(nullptr));
    std::cout << "Random digits: " << std::endl;
    for (i=0; i<10; i++){
        nmbrs[i] = std::rand()%21-10;
        std::cout << nmbrs[i] << ' ';
    }
    float a = nmbrs[0];
    std::cout << "\n\nRandom digits / 1st: " << std::endl;
    for (i=0; i<10; i++){
        nmbrs[i] /= a;
        std::cout << nmbrs[i] << ' ';
    }
    return 0;
}

int task2 (){
    int e;
    int k1, k2;
    int sum=0;
    std::cout << "\n\nEnter value: " << std::endl;
    std::cin >> e;
    std::cout << "\nEnter digits: " << std::endl;
    int *dyn=new int[e];
    for (int i=0; i<e; i++){
        std::cin >> dyn[i];
    }
    std::cout << "\nYour array: " << std::endl;
    for (int i=1; i<e+1; i++) {
        std::cout << dyn[i-1] << ' ';
    }
    std::cout << "\nYour modified array: " << std::endl;
    for (int i=0; i<e;i++){
        if (dyn[i]==0) dyn[i]+=3;
        std::cout << dyn[i] << ' ';
    }
    std::cout << "\nEnter k1 & k2: " << std::endl;
    std::cin >> k1 >> k2;
    k1--;
    k2--;
    for (k1; k1<=k2; k1++){
        sum+=dyn[k1];
    }
    std::cout << "\nAnswer: "<< sum << std::endl;
    delete [] dyn;
    return 0;
}

int task3(){
    int m;
    int sum=0;
    std::cout << "\nEnter your length: " << std::endl;
    std::cin >> m;
    std::vector<int> vec(m);
    std::cout << "Enter your digits: " << std::endl;
    for (int i=0; i<m; i++){
        std::cin >> vec[i];
    }
    for (int i=0; i<m; i++){
        std::cout << vec[i] << ' ';
    }
    vec.push_back(22);
    std::cout << std::endl;
    for (int i : vec)
        std::cout << i << ' ';
    for (int i:vec)
        sum+=i;
    std::cout << "\nSummary of all digits: " << sum << std::endl;
    for(int i=0; i < vec.size(); i++){
        if ( vec[i]==0){
            vec.erase(vec.begin()+i);
            break;
        }
    }
    for (int i : vec)
        std::cout << i << ' ';
}

int task4 (){
    int l1,l2;
    float prop = 0.;
    std::string str1 = "";
    std::string str2 = "";
    std::string str3 = "Can you can a can as a canner can can a can?";
    std::cout << "\nEnter your string: " << std::endl;
    std::cin >> str1;
    std::cout << str1 << std::endl;
    for ( int i = 0; i < str1.size(); i++){
        if (48 <= str1[i] && str1[i] <= 57) {
            prop++;
        }
    }
    std::cout << "Length: " << str1.size() << "\nDigits in fraction: " << prop/str1.size() << std::endl;
    std::cout << "Enter l1" << std::endl;
    std::cin >> l1;
    std::cout << "Enter l2" << std::endl;
    std::cin >> l2;
    l1--;
    l2--;
    std::cout << "Result: " <<  str1.substr(l1,l2) << std::endl;
    std::cout << "Your word: " << std::endl;
    std::cin >> str2;
    for (int i = 0; i < str3.size(); i++){
        if (( str3.substr(i,3) == "Can") || (str3.substr(i,4) == "can " || (str3.substr(i,4) == "can?" ))) {
            str3.erase(i,3);
            str3.insert(i, str2);
        }
    }
    std::cout << str3 << std::endl;
    return 0;
}
