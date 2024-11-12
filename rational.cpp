# include <iostream>
# include <string>

class rational{
    public:

    int num{};
    int denom{1};

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
        if (d == 0){
            throw 1;
        }
        else {
            denom = d;
        }
    }

    float divide(){
        float n{num};
        float d{denom};
        return n/d;

    }

    int printnum(){
        return num;
    }

    int printdenom(){
        return denom;
    }
};


rational addition(int a, int b, int c, int d){ // renvoie a/b + c/d sous la forme d'un rational
    rational r(a*d+b*c,d*b);
    return r;
}
rational add(rational r1, rational r2){
    return rational(r1.num*r2.denom + r2.num*r1.denom, r1.denom*r2.denom);
}

int main(){
    rational r1; // r1 = 0
    rational r2(5); // num = 5 denom =1
    rational r3(1,4); // num = 1 denom = 2


    std::cout<<r1.printnum()<<"/"<<r1.printdenom()<<" "<<
    r2.printnum()<<"/"<<r2.printdenom()<<" "<<
    r3.printnum()<<"/"<<r3.printdenom()<<" "<<
    add(r2,r3).printnum()<<"/"<<add(r2,r3).printdenom()<<" "<<
    r3.divide()<<" "<<
    std::endl;
    return EXIT_SUCCESS;
}