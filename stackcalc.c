Enter file contents here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"
#include "stackcalc.h"


int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	if (pStack != NULL)
	{
		StackNode node = { 0, };
		node.data = data;
		return pushLS(pStack, node);
	}
}

void calcExpr(ExprToken *pExprTokens, int tokenCount)
{
	LinkedStack *pStack = NULL;
	StackNode *pNode1 = NULL;
	StackNode *pNode2 = NULL;
	Precedence tokentype;
	float ret;
	ExprToken pReturn = { 0, };
	pStack = createLinkedStack();
	for (int i = 0; i < tokenCount; i++) {
		tokentype = pExprTokens[i].type;
		if (tokentype == operand) {
			pushLSExprToken(pStack, *(pExprTokens + i));
		}
		else {
			
			pNode2 = popLS(pStack);
			pNode1 = popLS(pStack);
			switch (tokentype) {
			case times :
				
				ret = (pNode1->data.value) * (pNode2->data.value);
				pReturn.value = ret;
				pushLSExprToken(pStack, pReturn);
				break;
			case divide :
				ret = (pNode1->data.value) / (pNode2->data.value);
				pReturn.value = ret;
				pushLSExprToken(pStack, pReturn);
				break;
			case plus :
				ret = (pNode1->data.value) + (pNode2->data.value);
				pReturn.value = ret;
				pushLSExprToken(pStack, pReturn);
			case minus :
				ret = (pNode1->data.value) - (pNode2->data.value);
				pReturn.value = ret;
				pushLSExprToken(pStack, pReturn);
			}
		}
		free(pNode1);
		free(pNode2);
	}
	pNode1 = popLS(pStack);
	printf("계산 결과 : %d", pNode1->data);
	free(pNode1);
	deleteLinkedStack(pStack);
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount)
{
	LinkedStack *pStack = NULL;
	Precedence tokentype;
	Precedence tokentype1;
	StackNode *pNode = NULL;
	StackNode *ppNode = NULL;
	pStack = createLinkedStack();
	if (pStack != NULL) {
		for (int i = 0; i < tokenCount; i++) {
			tokentype = pExprTokens[i].type;
			ExprToken exprtoken = pExprTokens[i];
			ExprToken pretoken;
			if (exprtoken.type == operand) {
				printToken(exprtoken);
			}
			else {
				if (!isLinkedStackEmpty) {
					pretoken = peekLS(pStack)->data;
					tokentype1 = pretoken.type;
					if ((tokentype1 == times || tokentype1 == divide) && (tokentype == minus || tokentype == plus) || ((tokentype == times && tokentype1 == divide) || (tokentype == divide && tokentype == times)) ) {
						pNode = popLS(pStack);
						pushLSExprToken(pStack, exprtoken);
						printToken(pNode->data);
					}

					else if (pretoken.type == lparen) {
						ppNode = popLS(pStack);
						free(ppNode);
					}

					else if (tokentype == lparen) {
						pushLSExprToken(pStack, exprtoken);
					}

					else if (tokentype == rparen) {
						while (peekLS(pStack)->data.type != lparen) {
							
							ppNode = popLS(pStack);
							printToken(ppNode->data);
							free(ppNode);
						}
					}

					
				}
				else {
					pushLSExprToken(pStack, pExprTokens[i]);
				}
			}

		}

		while (!isLinkedStackEmpty) {
			pNode = popLS(pStack);
			printToken(pNode->data);
			free(pNode);
		}
	}

	deleteLinkedStack(pStack);
}

void printToken(ExprToken element)
{
	switch (element.type) {
	case lparen :
		printf("(\n");
		break;
	case rparen:
		printf(")\n");
	case plus :
		printf("+\n");
	case minus:
		printf("-\n");
		break;
	case times:
		printf("*\n");
		break;
	case divide:
		printf("/\n");
		break;
	case operand:
		printf("%f\n", element.value);
		break;
	}
}
