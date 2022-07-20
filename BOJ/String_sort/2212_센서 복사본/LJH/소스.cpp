#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    vector<int> sensor(n, 0);
    vector<int> dif(n - 1, 0);
    if (n > k) //���� ������ �������� ���߱��� ������ ���ٸ� ��� ������ Ŀ��ġ�Ƿ� 0��.
    {
        int sum = 0;
        for (int i = 0; i < n; i++) //sensor�� ��ǥ�� �Է¹���.
        {
            cin >> sensor[i];
        }
        sort(sensor.begin(), sensor.end()); //sensor�� ��ǥ�� ������������ ������.
        for (int i = 0; i < n - 1; i++) //�� ��ǥ���� �Ÿ����� ����.
        {
            dif[i] = sensor[i + 1] - sensor[i];
        }
        sort(dif.begin(), dif.end()); //�Ÿ����� ������������ ������.
        for (int i = 0; i < k - 1; i++) //k���� ���߱��� ����ؼ� k-1���� ������ Ŀ���� �� ����.
        {
            dif.pop_back(); //�Ÿ��� �ּҰ��� ���ؾ� �ϹǷ�, �Ÿ��� ū ������ Ŀ����.
        }
        for (auto a : dif)
        {
            sum += a; //�����ִ� �Ÿ� ���̸� ����.
        }
        cout << sum;
    }
    else //���� ���߱��� �������� ���ٸ� ��� ������ Ŀ���� �� ����.
    {
        cout << 0;
    }
}