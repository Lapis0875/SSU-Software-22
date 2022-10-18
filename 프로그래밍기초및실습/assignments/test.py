with open('./test.txt', mode='rt', encoding='utf-8') as f:
    print("시작")
    print("=" * 5)
    for i in range(-128, 128):
        if bin(i).replace("0b", "") == f.readline().split(':')[-1]:
            print("정답")
        else:
            print(f"오답 : {i} = {bin(i)}")
    print("=" * 5)
    print("종료")
