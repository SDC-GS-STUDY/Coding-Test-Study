#include "exercise1.h"

/*
 <����>
 �ٱ��� ���� �Ʒ� ĭ ���� ������ ������� ���� --> ���� �ٱ���
 �ٱ��Ͽ� �����ؼ� ���̸� �Ͷ߷����鼭 �����.
 ������ ���� ������ �۵��ϴ� ��� �ƹ��� �ϵ� �Ͼ�� ����
 board size 5*5 ~ 30*30, value(������ ����) 1~100
 move size 1~1000
*/

/*
 <���̵��>
 ���� ã��--> moves�� value�� col�̰� 0�� �ƴ� ���� ã���� ���ÿ� push�ϱ�
  ����, row�� ���Ҵµ� ��� 0�̸� �׳� �Ѿ��

 ���ÿ��� ���� ���� �����Ͽ� ������ ���� �� �� pop�ϰ� 2���� answer�� �����ֱ� 
*/

int main()
{
	// ���� 1
	exercise1 problem1;

	problem1.createBoard();
	problem1.dollMove();
	problem1.printResult();

	return 0;
}