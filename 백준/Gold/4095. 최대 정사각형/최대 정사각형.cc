#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> n >> m;
        if (n == 0) break;

        // 배열 및 dp 초기화
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
                dp[i][j] = 0;  // DP 배열 초기화
            }
        }

        int answer = 0;

        // DP 계산
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    // DP 상태 갱신: 위, 왼쪽, 왼쪽 위를 참고하여 계산
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    answer = max(answer, dp[i][j]);
                }
            }
        }

        cout << answer << endl;
    }
}
