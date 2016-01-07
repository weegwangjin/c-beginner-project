Enter file contents here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprlinkedstack.h"
#include "exprdef.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *pReturn = NULL;
	pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));
	memset(pReturn, 0, sizeof(LinkedStack));
	return pReturn;
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	int ret = FALSE;
	if (!isLinkedStackEmpty(pStack)) {
		StackNode *pNode = NULL;
		pNode = (StackNode *)malloc(sizeof(StackNode));
		memset(pNode, 0, sizeof(StackNode));
		*pNode = element;
		pNode->pLink = pStack->pTopElement;
		pStack->pTopElement = pNode;
		pStack->currentElemnetCount++;
		ret = TRUE;

		return ret;
	}

	else {
		printf("오류 스택이 꽉 찼음");
		return ret;
	}
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *pNode = NULL;
	if (pStack != NULL) {
		if (!isLinkedStackEmpty) {
			pNode = pStack->pTopElement;
			pStack->pTopElement = pNode->pLink;
			pNode->pLink = NULL;
			pStack->currentElemnetCount--;
			return pNode;
		}



	}

	else {
		printf(" 오류 스택 값이 NULL 입니다.");
		return NULL;
	}
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode *pNode = NULL;
	if (pStack != NULL) {
		pNode = pStack->pTopElement;

		return pNode;
	}

	else {
		printf("오류 스택이 NULL 입니다.");
		return NULL;
	}
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (pStack != NULL) {
		StackNode *pNode = NULL;
		StackNode *pDelNode = NULL;

		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			pDelNode = pNode;
			free(pDelNode);
			pNode = pNode->pLink;
		}
		free(pStack);
	}
}

int isLinkedStackFull(LinkedStack* pStack)
{
	int ret = FALSE;
	if (pStack != NULL) {
		ret = FALSE;

	}

	return ret;
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	int ret = FALSE;
	if (pStack != NULL) {
		 ret = FALSE;
		if (pStack->currentElemnetCount == 0) {
			ret = TRUE;

		}

	}

	return ret;
}
