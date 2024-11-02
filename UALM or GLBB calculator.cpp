#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void displayCopyright() {
    cout << "Copyright: teknisi-anime" << endl;
}

double getValidInput(const string& prompt, double minValue) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= minValue) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan coba lagi." << endl;
        }
    } while (value <= minValue);
    return value;
}

void calculateAndDisplayResults(int sudut, double kecepatanAwal, double tinggiPohon) {
    const double gravitasi = 10.0;
    double sudurRadian = sudut * M_PI / 180.0;
    double jarakHorizontal = (kecepatanAwal * kecepatanAwal * sin(2 * sudurRadian)) / gravitasi;
    double waktu = (2 * kecepatanAwal * sin(sudurRadian)) / gravitasi;
    double ketinggianMaksimum = (kecepatanAwal * kecepatanAwal * sin(sudurRadian) * sin(sudurRadian)) / (2 * gravitasi);
    int statusKetinggian = (ketinggianMaksimum >= tinggiPohon) ? 1 : 0;

    cout << "Jarak terjauh Boro mendarat di tanah adalah: " << fixed << setprecision(3) << jarakHorizontal << " meter" << endl;
    cout << "Waktu yang diperlukan Boro adalah: " << fixed << setprecision(3) << waktu << " detik" << endl;
    cout << "Status ketinggian: " << statusKetinggian << endl;
    cout << "Ketinggian maksimum yang dapat dicapai oleh Boro adalah: " << fixed << setprecision(3) << ketinggianMaksimum << " meter" << endl;
}

int main() {
    displayCopyright();

    int sudut = static_cast<int>(getValidInput("Masukkan sudut peluncuran (0-90 derajat): ", 0));
    double kecepatanAwal = getValidInput("Masukkan kecepatan awal (m/s): ", 0);
    double tinggiPohon = getValidInput("Masukkan tinggi pohon tempat Boro bersarang (meter): ", 0);

    calculateAndDisplayResults(sudut, kecepatanAwal, tinggiPohon);

    return 0;
}
