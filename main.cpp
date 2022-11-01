#include <vector>
#include <list>
#include <numeric>
#include <iostream>

using namespace std;
int somaBruta(vector<vector<int>>& matriz);
int somaDividindo(vector<vector<int>>& matriz);
int somaDividindo(vector<int>& matrizL, int begin, int end);
int somaDiminuindo(vector<vector<int>>& matriz);
int somaDiminuindo(vector<int>& matrizL, int indice);

int main() {
	
	vector<vector<int>> v = { {5, 1, 1, 5, 1}, {2, 4, 2, 5, 9}, {3, 6, 3, 5, 10}, {5, 5, 5, 5, 19}, {8, 7, 5, 10, 19} };
	cout <<"dividir para conquistar: " << somaDividindo(v) << endl;
	cout <<"forca bruta:             " << somaBruta(v) << endl;
	cout <<"diminuir para conquistar " << somaDiminuindo(v) << endl;
}

int somaBruta(vector<vector<int>>& matriz)
{
	int n = matriz[0].size();
	int soma = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			soma = soma + matriz[i][j];
		}
	}
	return soma;
}

int somaDividindo(vector<int>& matrizL, int begin, int end)
{
	if ((end - begin) == 1) 
		return matrizL[begin];
	
	
	else {
		int x1 = somaDividindo(matrizL, begin, (begin + end) / 2);
		int x2 = somaDividindo(matrizL, (begin + end) / 2, end);
		return x1 + x2;
	}
}//problema sendo dividido em duas instâncias a cada chamada da função 

int somaDividindo(vector<vector<int>>& matriz)
{
	int n = matriz[0].size();
	int SomaT = 0;

	for (int i = 0; i < n; i++)
	{
		SomaT = SomaT + somaDividindo(matriz[i], 0, n); //realiza a soma de cada linha da matriz
	}
	return SomaT;
}


int somaDiminuindo(vector<int>& matrizL, int indice) 
{
	if (indice >= 0)
		return matrizL[indice] + somaDiminuindo(matrizL, indice - 1);
	else
		return 0;
} //A cada passoa a instância do problema vai diminuindo


int somaDiminuindo(vector<vector<int>>& matriz)
{
	int n = matriz[0].size();
	int SomaT = 0;

	for (int i = 0; i < n; i++)
	{
		SomaT = SomaT + somaDiminuindo(matriz[i], n-1); //realiza a soma de cada linha da matriz
	}
	return SomaT;
}