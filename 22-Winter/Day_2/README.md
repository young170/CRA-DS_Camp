## Abstract Data Type

> 해당 자료의 출처는 윤성우의 "열혈 자료구조"임을 밝힘.

Abstract Data Type (ADT)는 한국말로 말하면 추상자료형이라고 한다.

추상 자료형에 대한 설명 이전에, 직관적인 예시를 들면 다음과 같다.

```c
typedef struct _wallet
{
  int coin100;
  int bill5000;
} Wallet;
```

위의 구조체는 지갑에 넣을 수 있는 현금을 매우 단순화 하여 동전 100원과 지폐 5000원만 고려하여 작성하였다.

![wallet](https://kuku-keke.com/wp-content/uploads/2020/05/2677_1.png)

Wallet의 ADT는 다음과 같다.

> Operations:
>
> ```c
> int take_out_money(Wallet* pw, int coin_num, int bill_num)
>   - 첫 번째 인자로 전달된 주소의 자갑에서 돈을 꺼낸다.
>   - 두 번째 인자로 꺼낼 동전의 수, 세 번째 인자로 꺼낼 지폐의 수를 전달한다.
>   - 꺼내고자 하는 돈의 총액이 반환된다. 그리고 그만큼 돈은 차감된다.
>   
> void put_money(Wallet* pw, int coin_num, int bill_num)
>   - 첫 번째 인자로 전달된 주소의 지갑에 돈을 넣는다.
>   - 두 번째 인자로 넣을 동전의 수, 세 번째 인자로 넣을 지폐의 수를 전달한다.
>   - 넣은 만큼 동전과 지폐의 수가 증가한다.
> ```



이처럼 추상자료형은 '**어떤 대상에 대해서 순수하게 기능이 무엇인지를 나열한 것**'이다. 

지갑을 쓰기 위한 행동은 '지갑을 열고 동전 주머니를 찾아서 동전 주머니의 지퍼를 내리고 동전 주머니에 동전을 넣는다. 이어서 동전 주머니의 지퍼를 올린 다음 마지막으로 지갑을 닫는다.'와 같이 특정 일을 처리 하기 위한 여러 과정들이 존재한다는 것을 알 수 있다.

여기서 지갑이 순수하게 제공하는 기능들에 대해서 특징을 추출한 것이 ADT라는 개념인 것이다.