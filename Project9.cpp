#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;
void GetInput(int& inp) {
    fstream out;
    string path = "logs.txt";
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
    out << std::ctime(&end_time) << "Pol'zovatel' vvel: " << inp << endl;
}
void GetOutput(string& outp) {
    fstream out;
    string path = "logs.txt";
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
    out << std::ctime(&end_time) << outp << endl;
}

int main()
{
    string x;
    int n;
    x = "Enter the maximum number: ";
    cout << x;
    GetOutput(x);
    cin >> n;
    GetInput(n);

    int k;
    x = "Enter the number of attempts: ";
    cout << x;
    GetOutput(x);
    cin >> k;
    GetInput(k);

    srand(time(nullptr));
    int target = rand() % n + 1; // Generate a random number between 1 and n

    for (int i = 0; i < k; i++)
    {
        int guess;
        x = "Enter your guess: ";
        cout << x;
        GetOutput(x);
        cin >> guess;
        GetInput(guess);

        if (guess == target)
        {
            x = "You guessed correctly!";
            cout << x << endl;
            GetOutput(x);
            return 0;
        }
        else if (guess < target)
        {
            x = "Your guess is too low.";
            cout << x << endl;
            GetOutput(x);
        }
        else
        {
            x = "Your guess is too high.";
            cout << x << endl;
            GetOutput(x);
        }
    }

    x = "Attempts finished.";
    cout << x << endl;
    GetOutput(x);
    return 0;
}