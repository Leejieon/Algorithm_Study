## 📕 풀이

우선, 기본적으로 생각을 해보자. </br>
강의실은 최소 1개에서 하나씩 추가될 수 있다. </br>
그렇다면, 강의 시간이 빠른 수업 A1부터 우선적으로 배정하고, A2의 시작시간이 A1이 끝나는 시간보다 같거나 그 이후라면 A2는 A1과 같은 강의실에 배정 가능하다.
만약 그렇지 않다면 강의실이 하나 더 필요하게 된다.

> 여기서 생각해야 될 것은 바로, 강의실을 어떤 자료구조를 사용해서 구현해야할까? 이다.


강의실이 몇개가 될 지 모르는 상황에서 미리 array나 list를 생성할 수도 없다.
매우 괜찮은 방법은 PriorityQueue를 이용하는 것이다.

1번째 수업부터 n번째 수업까지 쭈욱 탐색하며 Q에 끝나는 시간을 삽입한다.
만약 큐에 들어있는 종료시간보다 현재 수업 시간의 start 시간이 크거나 같다면 큐에서 pop하고 현재 수업시간의 종료시간을 넣는다.

당연히 이해가 안 갈 것이고, 이를 위해 예시를 간단하게 들어봤다.
> 다음 3개의 수업이 있다고 가정한다. ("1~8", "2~3", "4~7")

![IMG_285A2E5EF5D3-1](https://user-images.githubusercontent.com/80253559/194293713-074cf2d1-27d2-4f40-9dcd-07749de0f2cb.jpeg)

그렇다면 위의 그림과 같이 PQ에는 숫자들이 쌓이게 된다. 위의 PQ안에 들어있는 원소의 개수가 의미하는 것은 이미지의 오른쪽에 써놓은 강의실의 개수와 같다.

> 왜 우선순위 큐를 사용해야할까?

위의 예시를 그대로 이용해보자. 만약 우선순위 큐가 아니라면 2번째 시행에서 8-3 이 될 것이고, 4시부터 시작하는 마지막 수업은 큐의 가장 앞의 원소인 8만 보고 그냥 새로운 강의실을 배정 받을 것이다.
현재 수업시간의 시작시간보다 종료시간이 빠른 수업이 없다면 어쩔 수 없지만, 만약에 있다면 그 수업의 종료시간을 큐의 가장 앞으로 오게 해주는 것이 이 알고리즘의 핵심이라고 할 수 있다.

---

## 📕 전체 코드
```java
  import java.util.*;
import java.io.*;


class Time implements Comparable<Time>{
    int start = 0;
    int end = 0;
    Time(int s, int e) {
        start = s;
        end = e;
    }

    @Override
    public int compareTo(Time t) {
        if(start == t.start) { //오름차순으로 정렬
            return end - t.end;
        }
        else {
            return start - t.start;
        }
    }
}
public class P_11000 {
    static int N;
    static ArrayList<Time> list = new ArrayList<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            list.add(new Time(v1, v2));
        }

        Collections.sort(list);
        
        Queue<Integer> q = new PriorityQueue<>();
        for(int i=0;i<list.size();i++) {
            Time t = list.get(i);
            if(!q.isEmpty() && q.peek() <= t.start) {
                q.poll();
            }
            q.add(t.end);
        }

        System.out.println(q.size());

    }
}

```
