c++ pair와 vector의 사용법
==========================
마크다운 배운 곳: [깃허브][githublink]
[githublink]: https://gist.github.com/ihoneymon/652be052a0727ad59601 "go link"
출처: [블로그][tistorylink]
[tistorylink]: http://ihwoo.tistory.com/110 "go link"
----------------------------------
pair는 utility header를 추가함으로써 사용할 수 있다.
꼴은 pair\<int,int\> 이런 식이고 벡터 안에서 쓸 때는 vector\<pair\<int,int\> \> 이런식이다.
make_pair(int1,int2) 이런 식으로 pair를 생성할 수도 있다.
접근할 때는 pairname.first pairname.second 이런 식으로 접근한다.

**추가
pair의 sorting은 first를 기준으로 sorting하고 , first가 같은 경우에는 second를 기준으로 sorting한다.


<hr>
int와 size_t의 차이점
=====================
출처: [블로그][blogspotlink]
[blogspotlink]: http://mwultong.blogspot.com/2007/06/c-sizet-unsigned-int.html "go link"
-----------------------
size_t 는 사실 unsigned int 와 같다. 
그렇지만 size_t는 운영체제의 32/62bit에 의존하여 비트 수도 바뀐다.
unsigned int 는 운영체제와 상관없이 32비트일 수도 있다.

