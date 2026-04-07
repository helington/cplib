#include <bits/stdc++.h>

using namespace std;

// ==========================================
// Expected Value DP (Sem ciclos)
// ==========================================
// Exemplo: Jogar um dado de 6 faces para chegar a N pontos.
// Qual o número esperado de lançamentos?

double expected_dice_rolls(int N) {
    // dp[i] = número esperado de lançamentos para chegar em N estando em i
    vector<double> dp(N + 1, 0.0);
    
    // dp[N] é 0, pois já chegamos no alvo.
    dp[N] = 0;

    // Calculamos de trás para frente
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = 1.0; // 1 lançamento que faremos agora
        
        // Somamos as esperanças dos próximos estados
        for (int face = 1; face <= 6; face++) {
            if (i + face <= N) {
                dp[i] += (1.0 / 6.0) * dp[i + face];
            } else {
                // Se ultrapassar N, refazemos o turno (exemplo de regra)
                // Ou apenas adicionamos a probabilidade de falha, dependendo do problema.
                dp[i] += (1.0 / 6.0) * dp[i]; 
            }
        }
        
        // IMPORTANTE: Se o estado puder voltar para si mesmo (como o 'else' acima)
        // a equação seria: dp[i] = 1 + P * dp[i] + (1-P) * dp[next]
        // Isolando dp[i]: dp[i] = (1 + (1-P)*dp[next]) / (1 - P)
    }

    return dp[0];
}

// Problema do valor esperado do numero de pacotes à se abrir até conseguir x cartas raras

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

const int MAXN = 5e3 + 10;

void solve() {
    int n, x; cin >> n >> x;

    vector<double> p(n);
    for (auto &it : p) {cin >> it; it /= 100.0;}

    vector<vector<double>> dp1(n+1, vector<double>(n+1, 0));
    dp1[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j > 0) dp1[i][j] += dp1[i-1][j-1] * (p[i-1]);
            dp1[i][j] += dp1[i-1][j] * (1 - p[i-1]);
        }
    }

    vector<double> dp2(MAXN, 0);

    for (int i = 1; i <= x; i++) {
        dp2[i] = 1.0;
        for (int j = 1; j <= n; j++) {
            dp2[i] += dp2[max(i-j, 0)] * dp1[n][j];
        }
        dp2[i] /= (1.0 - dp1[n][0]);
    }

    cout << setprecision(10) << dp2[x] << endl;
}