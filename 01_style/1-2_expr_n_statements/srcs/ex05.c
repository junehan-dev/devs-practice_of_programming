int	read(int *ip)
{
	scanf("%d", ip);
	return *ip;
}

int	main(void)
{
	//insert(&graph[vert], read(&val), read(&ch));
	/*
	 * I/O작업은 순서가 애매하면 불분명한 동작으로 이어질 가능성이 높다.
	 * 함수 호출은 매개변수 표기순서의 역순으로 일어나는 것으로 알고 있지만, 사실 어떤 언어냐 CPU 아키텍쳐에 따라 다를 수도 있으니 프로그래머의 권한 밖의 일이기도 하다.
	 *
	 * 100% 장담할 수 있는게 아니라면?
	 * 	안전한 방식을 선택하자.
	 * 	hard input은 기본이다.
	 */

	read(val);
	read(ch);
	insert(&graph[vert], val, ch);
}

