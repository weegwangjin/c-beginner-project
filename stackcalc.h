#ifndef _STACK_CALC_
#define _STACK_CALC_


void calcExpr(ExprToken *pExprTokens, int tokenCount);
int pushLSExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
void printToken(ExprToken element);

#endif
