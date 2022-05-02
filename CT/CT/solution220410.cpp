#include "exercise1.h"

/*
 <문제>
 바구니 가장 아래 칸 부터 인형이 순서대로 쌓임 --> 스텍 바구니
 바구니에 연속해서 쌓이면 터뜨려지면서 사라짐.
 인형이 없는 곳에서 작동하는 경우 아무런 일도 일어나지 않음
 board size 5*5 ~ 30*30, value(인형의 종류) 1~100
 move size 1~1000
*/

/*
 <아이디어>
 인형 찾기--> moves의 value가 col이고 0이 아닌 수를 찾으면 스택에 push하기
  만약, row다 돌았는데 모두 0이면 그냥 넘어가고

 스택에서 같은 수가 연속하여 들어오면 같은 수 다 pop하고 2개씩 answer에 더해주기 
*/

int main()
{
	// 문제 1
	exercise1 problem1;

	problem1.createBoard();
	problem1.dollMove();
	problem1.printResult();

	return 0;
}