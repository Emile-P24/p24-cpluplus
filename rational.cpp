# include <iostream>
# include <string>

class rational{
    int num{};
    int denom{};

    public:
    rational(){
        num = 0;
        denom = 1;
    }

    rational(int n){
        num = n;
        denom = 1;
        }

    rational(int n,int d){
        num = n;
        denom = d;
    }
    int printnum(){
        return num;
    }
    int printdenom(){
        return denom;
    }
};


int main(){
    rational r1; // r1 = 0
    rational r2(5); // num = 5 denom =1
    rational r3(1,2); // num = 1 denom = 2


    std::cout<<r1.printnum()<<"/"<<r1.printdenom()<<" "<<
    r2.printnum()<<"/"<<r2.printdenom()<<" "<<
    r3.printnum()<<"/"<<r3.printdenom()<<" "<<
    std::endl;
    return EXIT_SUCCESS;
}