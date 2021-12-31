// Comment on the choice of name and values in code.

#define TRUE    0
#define FALSE   1

int isEOF(char ch){
    int     not-eof;

    if ((ch = getchar()) == EOF)
        not-eof == FALSE;

    return (not-eof);
}

/*
 * V1: with keeping the original
 */

#define TRUE	1
#define FALSE	0
/* Why Changed False and True value?
 * isEOF will be used with if statement, conventionally, ordiary macros, which name is like is_something usually returns in that way.
 */


int isEOF(char ch) {
	int ret; 
	/* Why not to use not-eof
	 * '-' sign is not good. it embarrse when operator - uses. like(not-eof - is-eof - ????)
	 * not-eof도 나쁘지는 않지만, 굳이 함수명 중첩을 하지 않아도, isEOF에 기대하는 return값은 의미가 정해져 있다
	 */

	ret = ((ch = getchar()) == EOF) ? TRUE : FALSE;
	return (ret);
}

/*
 * My Opinion
 */

int isEOF(char ch) {
	return (((ch = getchar()) == EOF) ? 1 : 0);
}

/*
 * 굳이 간단한 macro급 함수에 자동변수 사용할 필요가 없다면 없애는 것도 좋다.
 * TRUE FALSE는 상황에 따라 다른 값을 쓰는게 맞다, program exit status같은 경우도 있으니, 굳이 constraint를 잡아주지 않는게 자연스럽다.
 */
