#pragma once

struct Pengguna {
	string user, pin;
} pengguna;

bool login(string gantipin) {
	cout << "+======================================================+" << endl;
	cout << "|                       DUITKU                         |" << endl;
	cout << "|        Silahkan Masukkan Username dan PIN Anda       |" << endl;
	cout << "| ---------------------------------------------------- |" << endl;
	cout << "| Tekan Enter Jika Selesai Memasukkan Username dan PIN |" << endl;
	cout << "+======================================================+" << endl;
	cout << endl;
	cout << "Username : ";
	cin >> pengguna.user;

	if (pengguna.user == "sihab")
	{
		cout << "PIN\t : ";
		int password;
		string pin = "";
		int loop = 0;
		password = _getch();
		while (password != 13 && loop <= 5)
		{
			pin.push_back(password);
			cout << "*";
			password = _getch();
			loop++;
		}
		cout << endl;

		// cin >> pin;
		if (pin == gantipin)
		{
			cout << "Login Sukses" << endl;
			return true;
		}
		else
		{
			system("cls");
			cout << "PIN Salah!" << endl;
			return false;
		}
	}
	else
	{
		system("cls");
		cout << "Username Salah!" << endl;
		return false;
	}
}
