#include <stdio.h>

int main(void)
{
    int arr[10] = {1,5,1,513,53,56,343,2,0,74};  // char_freq[ASCII_SIZE];
    int top_int[10] = {0};                          // top_char[15];    15 == size

    top_int[0] = 8;
    top_int[1] = 3;

    /*
    char_freq[ASCII_SIZE];
    ASCII_SIZE == 255;
    ASCII 코드 전체 255개.

    ASCII 코드 65 == 'A'
    char_freq[65] => 'A'

    char_freq[69] => 'E'
    'E' 가 제일 많이 나왔다, 빈도 수가 가장 크다.
    top_char[0] = 69;

    NIV.txt.을 읽으면서 'E'를 찾아서 10000 로 변형을 해준다.
    top_char[0]
    char(69) == 'E';
    */
    
    /*
    가장 큰 빈도부터 그위치를 top_char[]에 넣는다.
    */


   /*
   자주 나오는 순서로:
   10000


   */

    /*
    get_top_char()


	int arr[10] = {1,5,1,513,53,56,343,2,4135,74};
	int top_int[3] = {0};


    * 빈도 수 체크 -> 많은 순서대로 배열에 정렬.
    a. 빈도 수 체크 == char_freq[] 배열을 체크	=> 	for-문 사용하여 체크
	b. 많은 순서대로 배열에 정렬 == top_char[] 배열에 정렬, [0]이 제일 큰 값, [14]가 배열에 안에서 제일 작은 값.
		b.i. 정렬 : 가장 큰값을 알아야하고, 그 값의 인덱스를 알아야한다.
			가장 큰 값 : 변수 하나를 정해서, 그 변수가 돌아다니면서, 더 크면 얘가 가진다.
			가장 큰 값의 위치 : (hint - 지금 체크를 하는 방법을 고민 = for-문을 사용중이다) 
							위치는 i를 사용한다.

							for (int j = 0; j < length_of_top_char; j++) {
								for (int i = 0; i < length_of_char_freq; i++) {
									if (max보다 크면) {
										max = 더 큰값;
										int max_index = i;
									}
								}

								삭제한다 - 0을 넣어준다.
											a. 삭제해야하는 곳을 찾는다 =  char_freq[max_index]
											b. 0을 넣어준다 = 			char_freq[max_index] = 0;

								max == 제일 큰 값
								max_index == 제일 큰 값의 인덱스

								top_char[j] = i;
							}

							top_char[1] = 두 번째로 큰 수
							...

			가장 큰 값 -> 2번째로 큰 값 -> 3번쨰로 ...
			top_char[0] = max = char_freq[] 에서 가장 큰 값
			top_char[1] = max = char_freq[] 에서 가장 2번째로 큰 값
			top_char[2] = max = char_freq[] 에서 가장 3번쨰로 큰 값
			...
    */
   
   for (int j = 0; j < length_of_top_char; j++) {
		for (int i = 0; i < length_of_char_freq; i++) {
			if (max보다 크면 현재 값이) {
				max = 더 큰값;
				max_index = i;
			}
		}

		// 삭제한다 - 0을 넣어준다.
					// a. 삭제해야하는 곳을 찾는다 =  char_freq[max_index]
					b. 0을 넣어준다 = 			char_freq[max_index] = 0;

		// max == 제일 큰 값
		// max_index == 제일 큰 값의 인덱스

		top_char[j] = i;
	}


    return 0;
}