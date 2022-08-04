## 🧩 풀이

1. 결국은 x,y간에 이어진 선의 개수를 구하는 문제이다.

2. 서로의 관계를 나타내주어야 한다. (이어져있다는 것을 표시해두어야 함!)

3. 서로의 관계를 list로 표시한다!! (결국에는 그래프를 그려주겠다는 것)

4. 아래의 이미지처럼 나는 서로간의 관계를 list로 표현했다. (1 2) 인 경우는 list[1]에 2, list[2]에 1을 넣어줌.

5. 완성한 그래프를 x부터 탐색하여 현재 노드의 값이 y와 같아지는 순간에 count한 선의 개수를 출력한다!

6. 문제에서 최단거리나 최소시간 등을 묻지 않았으므로, 그래프를 탐색하는 방법은 DFS로 구현하였다.

![image](https://user-images.githubusercontent.com/80253559/182764727-7929985b-6636-402d-86f3-750421bcb465.png)


---

## 🧩 전체코드

```java
import java.nio.Buffer;
import java.util.*;
import java.io.*;
//1. 결국 주어진 2개의 사람간에 이어진 선의 개수를 구하는 문제.
//2. 서로 친척관계라면 그 관계를 나타내주어야 한다.(그래프로 이어줘야함!)
//3. 서로 관계를 list로 표시

public class P_2644 {
    static int n, m, x, y, ans=0;
    static ArrayList<Integer>[] list;
    static boolean [] visited;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine()); //전체 사람의 수
        list = new ArrayList[n+1];
        visited = new boolean[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(br.readLine()); //관계의 수
        for(int i=1;i<=n;i++){
            list[i] = new ArrayList<>();
        }

        for(int i=0;i<m;i++){
            StringTokenizer s = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(s.nextToken());
            int child = Integer.parseInt(s.nextToken());
            list[parent].add(child);
            list[child].add(parent);
        }

        dfs(x, 0);
        if(ans>0){
            System.out.println(ans);
        }
        else{
            System.out.println(-1);
        }
    }
    //cnt는 전역변수로 선언하여 계속 증가시켜주면 안됨!
    //틀린 경로일 경우에는 cnt를 다시 감소시켜주어야하는데 전역변수이면 그냥 감소가 안되고 계속 증가한다!
    //그래서 반드시 cnt를 dfs의 파라미터로 같이 넘겨주어야함!!
    static void dfs(int v, int cnt){
        if(v==y){
            ans = cnt;
            return;
        }
        visited[v] = true;
        for(int i=0;i<list[v].size();i++){
            if(!visited[list[v].get(i)]){
                dfs(list[v].get(i), cnt+1);
            }
        }
    }
}
```

---

## 🧩 Review

보자마자 풀이법이 바로 떠올라서 비교적 쉽게 코드를 완성하여 제출했는데 "틀렸습니다?" 이런 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ;;

 

코드를 아무리 봐도 왜틀렸는지 모르다가 갑자기 오류를 찾았다.

🚨매우 주의🚨

1. 처음에 cnt변수를 전역으로 선언하여 다른 노드로 이동할 때마다 +1을 해주었다.

2. 하지만 진행 경로가 틀렸을 경우는 다시 count를 -1 해주어야하는데 처음 나의 코드에서는 경로가 틀려서 back 할 때도 count는 여전히 +1 되고있었음,,,,,,,,,,,,,

3. 반드시 count값을 dfs메소드의 파라미터로 같이 넘겨주어야 해당 상태에서의 count값을 알 수 있다!! 이 실수는 굉장히 범하기 쉬운거같다 앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,앞으로도 주의하자,,,
