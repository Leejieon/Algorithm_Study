## 🧩  풀이
[문제에 대한 접근]

- 어쨋든, 알파벳에 0~9까지의 숫자를 부여하여 결국 가장 큰 숫자를 만들어야 하므로, 자리수가 가장 큰 알파벳에 가장 큰 숫자를 부여해야겠다고 생각해씀!

 
- 그러나 아래와 같은 예시에서는 애매한 상황이 발생할 수 있다.

>ABB
>BBB


그래서, 모든 단어를 탐색하여 그 알파벳의 자리수와 빈도수를 Map에 저장하였다. 위의 예를 이용하여 설명하겠다.

>자리수로 표현하면
>ABB = 100 * A + 10 * B + 1 * B = 100A + 11B
>BBB = 100 * B + 10 * B + 1 * B = 100B + 11B
>--> ABB + BBB = 122B + 100A

따라서, 자리수가 같은 알파벳이라도 그 빈도수에 따라 B = 9, A = 8이 된다.

---

## 🧩  전체 코드
```java
import java.util.*;
import java.io.*;

//쉬웠다 의외로.
public class P_1339 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String [] s = new String[N];
        Map <Character, Integer> map = new HashMap<>();

        for(int i=0;i<N;i++){
            s[i] = br.readLine();
            for(int j=0; j<s[i].length() ; j++){
                if(!map.containsKey(s[i].charAt(j))){
                    map.put(s[i].charAt(j), (int)Math.pow(10,(s[i].length() - j - 1)));
                }
                else{
                    map.put(s[i].charAt(j), map.get(s[i].charAt(j)) + (int)Math.pow(10,(s[i].length() - j - 1)));
                }
            }
        }

        ArrayList <Integer> list = new ArrayList<>();
        for(Map.Entry <Character, Integer> m : map.entrySet()){
            list.add(m.getValue());
        }
        Collections.sort(list, Collections.reverseOrder());

        int num = 9;
        int total = 0;
        for(int i = 0; i<list.size();i++){
            total = total + num*list.get(i);
            num--;
        }
        System.out.println(total);
    }
}
```

---

## 🧩 Review
의외로 간단했던 문제. 문제에서 원하는 것이 무엇인지만 파악하면 그대로 코딩하면 된다!!!!

그래도 생각이 빨리 떠오르지 않으면 정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...정말 끝없는 낭떠러지에 빠질 수도...
