int	read(int *ip) 
{
	scanf("%d", ip);
	return *ip;
}

int	main(void)
{
	insert(&graph[vert], read(&val), read(&ch));
}

