#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > produtoCartesiano(
    const vector<vector<vector<int> > >& grupos,
    int indiceGrupo = 0,
    vector<int> acumulado = {0, 0}
) {
    if (indiceGrupo == grupos.size()) {
        return {acumulado};
    }
    
    vector<vector<int> > resultados;
    for (const auto& par : grupos[indiceGrupo]) {
        vector<int> novoAcumulado = {
            acumulado[0] + par[0],
            acumulado[1] + par[1]
        };
        
        auto temp = produtoCartesiano(grupos, indiceGrupo + 1, novoAcumulado);
        resultados.insert(resultados.end(), temp.begin(), temp.end());
    }
    
    return resultados;
}

int main() {
    vector<vector<vector<int>>> vetor = {{{2, 3}, {3, 2}}, {{1, 2}, {2, 1}}};
    
    auto resultado = produtoCartesiano(vetor);
    
    for (const auto& combinacao : resultado) {
        cout << "[" << combinacao[0] << ", " << combinacao[1] << "]" << endl;
    }
    
    return 0;
}