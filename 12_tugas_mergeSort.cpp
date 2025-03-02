#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;
struct Buku
{
    string judul;
    string penulis;
    int tahunTerbit;
    string nomorRak;
    Buku() : judul(""), penulis(""), tahunTerbit(0), nomorRak(""){}
    Buku(string j, string p, int t, string n)
    : judul(j), penulis(p), tahunTerbit(t), nomorRak(n){}
};
bool compare(const Buku &a, const Buku &b){
    if (a.judul != b.judul)
    {
        return a.judul < b.judul;
    }
    if (a.penulis != b.penulis)
    {
        return a.penulis < b.penulis;
    }
    if (a.tahunTerbit != b.tahunTerbit)
    {
        return a.tahunTerbit < b.tahunTerbit;
    }
    return a.nomorRak < b.nomorRak;
}
void merge(vector<Buku> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Buku> L(n1);
    vector<Buku> R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (compare(L[i], R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(vector<Buku> &arr, int left, int right){
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "masukkan jumlah data buku: ";
    cin >> n;
    cin.ignore();
    vector<Buku> perpustakaan;
    for (int i = 0; i < n; i++)
    {
        string judul, penulis, nomorRak;
        int tahunTerbit;
        cout << "Masukkan Judul buku: ";
        getline(cin, judul);
        cout << "Masukkan Nama Penulis Buku: ";
        getline(cin, penulis);
        cout << "Masukkan Tahun Terbit Buku: ";
        cin >> tahunTerbit;
        cin.ignore(); // Ignore newline after tahunTerbit input
        cout << "Masukkan Nomor Rak Buku: ";
        getline(cin, nomorRak);
        perpustakaan.push_back(Buku(judul, penulis, tahunTerbit, nomorRak));
    }
    mergesort(perpustakaan, 0, perpustakaan.size() - 1);
    cout << "\nData Buku Yang telah diurutkan:\n";
    for (const auto &buku : perpustakaan)
    {
        cout << "Judul: " << buku.judul << ", Penulis: " << buku.penulis << ", Tahun Terbit: " << buku.tahunTerbit << ", Nomor rak: " << buku.nomorRak << endl;
    }
    return 0;
}
