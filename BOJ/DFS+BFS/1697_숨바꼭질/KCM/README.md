## 🧩 풀이
1. 수빈이의 위치(X)에서 1초 후 갈 수 있는 곳은 {2X, X-1, X+1} 이렇게 세 군데이다.

2. 매 초, X에 대하여 이동할 수 있는 지점 3군데의 정보를 담고 있는 Point클래스 객체를 만든다.

3. 만든 객체는 (현재 지점, 시간(초)) 에 대한 정보를 담고 있다.

4. 예를 들어 현재 위치가 5라면 1초후 수빈이가 갈 수 있는 곳은 {10, 6, 4}이며 이 10, 6, 4 에 대한 정보를 담은 Point 클래스 객체는 각각의 지점에 대한 정보와 "1초"라는 정보를 담고 있다.

5. 4에서 만든 3개의 Point클래스 객체들을 Queue에 담고 Bfs를 수행한다.

>🚨주의🚨
>큐에, 이동 가능한 지점에 대한 Point클래스 객체를 담을 때 조건이 있다.
>"문제에서 점의 범위는 0이상 100000이하라 했으므로"


>3군데의 지점(V) 는 0 <= V <= 100,000 이어야 한다. 
>"또한, 방문했던 지점을 다시 Queue에 삽입하면 안된다!"


bfs 진행 중, 현재 지점에 동생의 지점과 같아지는 순간에

해당 Point객체의 "시간 값" 이 정답이 된다.


---

## 🧩 전체 코드
```java
import java.util.*;
import java.io.*;

class Where{
    int point=0;
    int sec=0;
    Where(int p, int s){
        point = p;
        sec = s;
    }
}
public class P_1697 {
    static int N,K;
    static Queue<Where> q = new LinkedList<>();
    static boolean [] visited = new boolean[100001];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        int ans = bfs(N,K);
        System.out.println(ans);
    }

    static int bfs(int n, int k){
        q.add(new Where(n,0));
        visited[n] = true;
        while(!q.isEmpty()){
            Where locate = q.remove();
            visited[locate.point] = true;
            if(locate.point == k){
                return locate.sec;
            }
            else{
                int v1 = 2*locate.point;
                int v2 = locate.point-1;
                int v3 = locate.point+1;

                if(v1>=0 && v1 <= 100000 && !visited[v1]){
                    q.add(new Where(v1, locate.sec+1));
                    visited[v1] = true;
                }
                if(v2>=0 && v2 <= 100000 && !visited[v2]){
                    q.add(new Where(v2, locate.sec+1));
                    visited[v2] = true;
                }
                if(v3>=0 && v3 <= 100000 && !visited[v3]){
                    q.add(new Where(v3, locate.sec+1));
                    visited[v3] = true;
                }
            }

        }
        return 0;
    }
}
```

---

## 🧩 Review
큐에 담을 수 있는 정보에 대한 조건을 정해주지 않는다면, 엄청나게 많은 정보가 큐에 들어가서 메모리가 초과될 수 있다.

 

조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!조건을 설정해주는게 중요!!!!!!
