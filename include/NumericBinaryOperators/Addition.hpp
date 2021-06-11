#ifndef Add_head
#define Add_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>

namespace sadET{
/*------------------------Addition---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand>
class Addition: public BinaryOperator<leftHand,rightHand>{
    public:

    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() + this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID) + this->RH.derivative(ID);}
};
//  operator+ returns a new instance of Addition. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}



 

/*Use  macros for the rest numeric types :)*/
#define addNum(numericType) \
    template<typename Expr> \
    class Addition<Expr,numericType>: public BinaryOperator<Expr,numericType>{ \
        public: \
        using leftHand = Expr;\
        using rightHand = numericType;\
        Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH.evaluate() + this->RH;} \
        inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}\
    };\
    template<typename Expr> \
    class Addition<numericType,Expr>: public Addition<Expr,numericType>{ \
        public: \
        using leftHand = numericType;\
        using rightHand = Expr;\
        Addition(const leftHand &LH, const rightHand &RH):Addition<rightHand,leftHand>(RH,LH){} \
    };\

addNum(float);
addNum(double);
addNum(long double);
addNum(int);
addNum(unsigned int);

}

#endif