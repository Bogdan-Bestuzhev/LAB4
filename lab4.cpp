#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

class Generator1{
public:
    unsigned long current;

    Generator1(long seed){
        current = seed;
    }

    int next()
    {
        current = 8253729 * current + 2396403;
        return current % 10000;
    }
};

class Generator2{
public:
    long a,b;
    long current;
    Generator2(long n1, long n2){
        a = n1;
        b = n2;
    }

    int next(){
        current = (a + b + 123)%10000;
        a = b;
        b = current;
        return current;
    }
};

void analysis(vector <int> data){
    cout << "\nviborka " << data.size() << " dlini" <<  "\n";

    double mean = 0.0;
    for (auto c : data)
        mean += c;
    mean /= data.size();
    cout << "srednee: " << mean << "\n";

    double dev = 0.0;
    for (auto c : data)
        dev += (c - mean) * (c - mean);
    dev /= data.size();
    dev = pow(dev, 0.5);
    cout << "standartnoe otrklonenie: " << dev << "\n";
    cout << "koefficient variatsii " << dev / mean << "\n";

    vector <long long> n = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (long long i = 0; i < data.size(); i++)
        n[data[i] / 1000]++;

    double xikv = 0.0;
    for (long long i = 0; i < 10; i++)
        xikv += (n[i] * n[i] * 10);

    xikv /= data.size();

    xikv -= data.size();

    cout << "Xi-kvadrat:  " << xikv << "\n";

}

int main(){
    /*
    vector <int> f1 = {}, f2 = {},f3 = {},f4 = {},f5 = {},f6 = {},f7 = {},f8 = {},f9 = {},f10 = {};

    auto nach = chrono::steady_clock::now();
    for (long i = 0; i < 50; i++)
        f1.push_back(rand());
    cout << "Generation time for volume of\t50\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 100; i++)
        f2.push_back(rand());
    cout << "Generation time for volume of\t100\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 500; i++)
        f3.push_back(rand());
    cout << "Generation time for volume of\t500\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 1000; i++)
        f4.push_back(rand());
    cout << "Generation time for volume of\t1000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 5000; i++)
        f5.push_back(rand());
    cout << "Generation time for volume of\t5000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 10000; i++)
        f6.push_back(rand());
    cout << "Generation time for volume of\t10000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 50000; i++)
        f7.push_back(rand());
    cout << "Generation time for volume of\t50000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 100000; i++)
        f8.push_back(rand());
    cout << "Generation time for volume of\t100000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 500000; i++)
        f9.push_back(rand());
    cout << "Generation time for volume of\t500000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";

    nach = chrono::steady_clock::now();
    for (long i = 0; i < 1000000; i++)
        f10.push_back(rand());
    cout << "Generation time for volume of\t1000000\t"
         << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
         << " ns\n";
    */
    int vibor;
    cout << "viberite generator:\n\n1. kongrut\n2. fibbonachi\n\n";
    cin >> vibor;
    cout << endl;

    if (vibor == 1){
        Generator1 gen(3907);
        vector <int> f1 = {}, f2 = {},f3 = {},f4 = {},f5 = {},f6 = {},f7 = {},f8 = {},f9 = {},f10 = {};

        auto nach = chrono::steady_clock::now();
        for (long i = 0; i < 50; i++)
            f1.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t50\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 100; i++)
            f2.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t100\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 500; i++)
            f3.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t500\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 1000; i++)
            f4.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t1000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 5000; i++)
            f5.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t5000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 10000; i++)
            f6.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t10000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 50000; i++)
            f7.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t50000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 100000; i++)
            f8.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t100000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 500000; i++)
            f9.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t500000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 1000000; i++)
            f10.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t1000000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        analysis(f1);
        analysis(f2);
        analysis(f3);
        analysis(f4);
        analysis(f5);
        analysis(f6);
        analysis(f7);
        analysis(f8);
        analysis(f9);
        analysis(f10);
    }

    if (vibor == 2){
        Generator2 gen(5031, 4141);
        vector <int> f1 = {}, f2 = {},f3 = {},f4 = {},f5 = {},f6 = {},f7 = {},f8 = {},f9 = {},f10 = {};

        auto nach = chrono::steady_clock::now();
        for (long i = 0; i < 50; i++)
            f1.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t50\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 100; i++)
            f2.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t100\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 500; i++)
            f3.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t500\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 1000; i++)
            f4.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t1000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 5000; i++)
            f5.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t5000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 10000; i++)
            f6.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t10000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 50000; i++)
            f7.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t50000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 100000; i++)
            f8.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t100000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 500000; i++)
            f9.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t500000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";

        nach = chrono::steady_clock::now();
        for (long i = 0; i < 1000000; i++)
            f10.push_back(gen.next());
        cout << "Vremya generatsii viborki razmerom \t1000000\t"
             << chrono::duration_cast<std::chrono::nanoseconds>(chrono::steady_clock::now() - nach).count()
             << " ns\n";


        analysis(f1);
        analysis(f2);
        analysis(f3);
        analysis(f4);
        analysis(f5);
        analysis(f6);
        analysis(f7);
        analysis(f8);
        analysis(f9);
        analysis(f10);
    }
}
