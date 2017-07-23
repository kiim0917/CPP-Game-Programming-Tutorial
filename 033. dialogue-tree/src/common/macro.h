/*
 * ���� �̸� : macro.h
 * ���� ��¥ : 2017-07-23
 * ���� ��� : Ruvendix
 *
 * ���� ���� : �������� ����ϴ� ��ũ�ΰ� ���ǵǾ��ֽ��ϴ�.
 */

#ifndef DIALOGUETREE_MACRO_H_
#define DIALOGUETREE_MACRO_H_

#include <iostream>

#define SAFE_DELETE(ptr) if (ptr != nullptr)\
                         {\
                             delete ptr;\
                             ptr = nullptr;\
                         }

#define SAFE_DELETE_ARRAY(arrayPtr) if (arrayPtr != nullptr)\
                                    {\
                                        delete[] arrayPtr;\
                                        arrayPtr = nullptr;\
                                    }

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

#endif