#ifndef Expr_head
#define Expr_head

template<typename LD, typename Type>
class GenericExpression{
    public:
    // This allows us to convert any expression to its sub-expressions, giving us access to their members. 
    inline const Type& subExpression() const {return  *static_cast<const Type*>(this);} 
};

#endif