#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void displayCopyright()
{
    cout << "Copyright: teknisi-anime" << endl;
int main() 
{
	const double gravitasi = 10.0;
	int sudut;
	double kecepatanAwal, tinggiPohon;

	do {
		cout << "Masukkan sudut peluncuran (0-90 derajat): ";
		cin >> sudut;
	} while (sudut <= 0 || sudut > 90);

	do {
		cout << "Masukkan kecepatan awal (m/s): ";
		cin >> kecepatanAwal;
	} while (kecepatanAwal <= 0);

	do {
		cout << "Masukkan tinggi pohon tempat Boro bersarang (meter): ";
		cin >> tinggiPohon;
	} while (tinggiPohon <= 0);

	double sudurRadian = sudut * M_PI / 180.0;
	double jarakHorizontal = (kecepatanAwal * kecepatanAwal * sin(2 * sudurRadian)) / gravitasi;
	double waktu = (2 * kecepatanAwal * sin(sudurRadian)) / gravitasi;
	double ketinggianMaksimum = (kecepatanAwal * kecepatanAwal * sin(sudurRadian) * sin(sudurRadian)) / (2 * gravitasi);

	int statusKetinggian = (ketinggianMaksimum >= tinggiPohon) ? 1 : 0;

	cout << "Jarak terjauh Boro mendarat di tanah adalah: " << fixed << setprecision(3) << jarakHorizontal << " meter" << endl;
	cout << "Waktu yang diperlukan Boro adalah: " << fixed << setprecision(3) << waktu << " detik" << endl;
	cout << "Status ketinggian: " << statusKetinggian << endl;
	cout << "Ketinggian maksimum yang dapat dicapai oleh Boro adalah: " << fixed << setprecision(3) << ketinggianMaksimum << " meter" << endl;

	return 0;
}
