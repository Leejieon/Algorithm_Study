## 🧩 풀이
>매우 간단한 문제였다.
>방향 그래프라는 점만 주의하여 인접리스트를 구성 후, 다익스트라 알고리즘을 구현하고
>출력 형식만 잘 맞춰주면 됨!

---
## 🧩 전체 코드
```java
import java.util.*;
import java.io.*;

class Vertex implements Comparable<Vertex>{
    int end = 0;
    int weight = 0;
    Vertex(int e, int w){
        end = e;
        weight = w;
    }
    @Override
    public int compareTo(Vertex v){
        return weight - v.weight;
    }
}
public class P_1753 {
    static int V,E,S;
    static PriorityQueue<Vertex> q = new PriorityQueue<>();
    static int [] dist;
    static boolean [] checked;
    static ArrayList<Vertex> [] list;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        list = new ArrayList[V+1];
        dist = new int[V+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        for(int i=0;i<=V;i++){
            list[i] = new ArrayList<>();
        }
        checked = new boolean[V+1];

        E = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(br.readLine());
        //인접리스트 생성.
        for(int i=0;i<E;i++){
            StringTokenizer s = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(s.nextToken());
            int fin = Integer.parseInt(s.nextToken());
            int w = Integer.parseInt(s.nextToken());
            list[start].add(new Vertex(fin,w));
        }

        dijkstra(S);
        for(int i=1;i<=V;i++){
            if(i==S){
                System.out.println(0);
            }
            else if(dist[i] == Integer.MAX_VALUE){
                System.out.println("INF");
            }
            else{
                System.out.println(dist[i]);
            }
        }



    }
    static void dijkstra(int s){
        q.add(new Vertex(s,0));
        dist[s] = 0;

        while(!q.isEmpty()){
            Vertex v = q.remove();
            if(checked[v.end]){
                continue;
            }
            checked[v.end] = true;

            for(int i=0;i<list[v.end].size();i++){
                int next = list[v.end].get(i).end;
                int value = list[v.end].get(i).weight;
                if(dist[next] > dist[v.end] + value){
                    dist[next] = dist[v.end] + value;
                    q.add(new Vertex(next, dist[next]));
                }
            }
        }
    }
}
```
---
## 🧩 Review
대표적인 다익스트라 알고리즘 구현 문제이다.
