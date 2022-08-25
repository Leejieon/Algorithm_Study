## 🧩 풀이
1. 들어간 순서를 (번호판, 순서) 쌍으로 inmap에 저장한다.

2. 들어간 순서를 앞으로 "원래 순서"라고 하겠다.

3. 이제 남은 문자열은 나온 차들의 순서 목록이다.

4. 남은 문자열의  inmap.get("문자열")을 통하여 value값 즉, 원래 순서를 찾은 다음 outlist배열에 하나씩 저장한다.

5. outlist배열은 나온차들의 순서대로, 원래의 순서가 저장되어있다.

## Logic
>예를 들어, " 1 -> 2 -> 3 -> 4 -> 5 "순으로 들어간 차가 터널을 나올 때는 2 -> 4-> 3-> 1-> 5 로 나왔다고 가정하자.
그럼 outlist = {2, 4, 3, 1, 5}가 되있을 것이다. (여기서 번호판의 값은 편하게 들어갈 때의 순서로 하였다.)

>들어갈 때 2등으로 들어온 원소 outlist[0] 보다 뒤에 있는 원소 중 들어올 때 2등보다 먼저 들어온 원소를 찾으면 outlist[3] = 1이 있다. 이말은 즉, outlist[0]은 반드시 적어도 한 번 추월을 하였다는 소리이다. 

>같은 원리로, 각각의 원소에 대하여 해당 원소 뒤에 있는 놈들과 비교를 하여 자신보다 들어온 순서가 앞인데도 자신의 뒤에 있다면 그 원소는 반드시 추월을 적어도 한 번 했다는 뜻이다.


---

```java
import java.util.*;
import java.io.*;
//들어간 순서와 나온 순서를 비교해야 한다.
//나온차를 하나씩 탐색하며, 해당 차량 뒤의 차 중, 들어온 순서가 자신보다 빠른 놈이 있다면 해당차량은 무조건 추월한것!
public class P_2002 {
    static int N, total = 0;
    public static void main(String[] args) throws IOException{
        Map<String, Integer> inmap = new LinkedHashMap<>();
        Map<String, Integer> outmap = new LinkedHashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int [] outlist = new int [N]; //나온 차들의 순서대로 들어간 순서를 저장할 리스트
        //들어간 차의 (번호판,순서) 맵에 저장.
        for(int i=1;i<=N;i++){
            inmap.put(br.readLine(), i);
        }
        for(int i=0;i<N;i++){
            outlist[i] = inmap.get(br.readLine());
        }
        //나온차를 하나씩 탐색하며, 해당 차량 뒤의 차 중, 들어온 순서가 자신보다 빠른 놈이 있다면 해당차량은 무조건 추월한것!
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                if(outlist[i] > outlist[j]){
                    total++;
                    break;
                }
            }
        }
        System.out.println(total);
    }
}
```

---

## 🧩 Review 
로직을 생각하기 쉬운 문제였다. 

번호판이 매우 복잡한 문자열이므로, 번호판에 너무 의미를 부여하지말고 들어온 순서와 나온 순서를 잘 생각할 것...
