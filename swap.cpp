#include <iostream>


// float swap( float* pa, float* pb){
//     float t = *pa;
//     *pa = *pb;
//     *pb = t;
//     return *pa,*pb ;
// }
// int main(){
//     float a{7.24}; // <=> a=7.24
//     float b{1.23};
//     float* pa = &a; // pa est une adresse mémoire = pointeur
//     float* pb = &b;
//     // a = (*pa);  // Accéder à la valeur de pa
//     // int a = 82;
//     // int b = 12;
//     swap(pa,pb);
//     std::cout<<"a="<<(*pa)<<" "<<"b="<<(*pb)<<std::endl;
//     return EXIT_SUCCESS;
// }


// Nouvelle version avec la référence
void swap( float& ra, float& rb){
    float t = ra;
    ra = rb;
    rb = t;
}
int main(){
    float a{7.24}; // <=> a=7.24
    float b{1.23};
    float& ra = a; // ra est une référence
    float& rb = b;
    
    swap(ra,rb);
    std::cout<<"a="<<(ra)<<" "<<"b="<<(rb)<<std::endl;
    return EXIT_SUCCESS;
}