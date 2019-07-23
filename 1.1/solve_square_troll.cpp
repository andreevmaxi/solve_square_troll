#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <float.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int advert_time1 = 10100;
const int advert_time2 = 20100;



void advert2(int advert_time){

    clock_t t0 = clock();
    clock_t t1 = clock();

    int i = ( advert_time - 100 ) / 1000 + 1;

    while ( clock()-t0 < advert_time ){

        t1 = clock();
        if(( advert_time - t1 + t0 ) % 1000 == 0 && ( advert_time - t1 + t0) / 1000 != i){

            --i;
            system("cls");
            cout << "+------------------------------------------------------------------------------+" << endl <<
                    "|Sorry for this adverts, but we needed some money to live as we want, so sorryy|" << endl <<
                    "|also i need money to buy learning in mipt, because i don't know do i pass to  |" << endl <<
                    "|grand or not, and if not it will be very very bad                             |" << endl <<
                    "+------------------------------------------------------------------------------+" << endl <<
                    "|I know that you wouldn't read this at all, but i am doing it in 1:08, you ask |" << endl <<
                    "|me why? But the answer is easy, because i was going to my home,from 2ka of    |" << endl <<
                    "|mipt and i need to do more than 2 more homeworks and i need to do them good   |" << endl <<
                    "|and i am doing them, but i have less and less time, so i am doing it right now|" << endl <<
                    "|so another time sorry, i want 2 sleep, but i need to code(time: 1:11)(help me)|" << endl <<
                    "+------------------------------------------------------------------------------+" << endl <<
                    endl << endl << "seconds of advert left: " << (int)((advert_time - t1 + t0) / CLOCKS_PER_SEC) << endl;

        }

    }

    system("cls");
}

char solve_square_equation(int a, int b, int c, double* x1, double* x2){

    switch(a)
    {
        case 0:
        {
            if (b == 0 && c == 0){
                return 'i';
            }
            if (b == 0 && c != 0){
                return '0';
            }
            *x1=-c/b;
            return '1';
        }
        default:
        {
            int discriminate = 0; /// variable used for calculate discriminate of square equation
            discriminate = b * b - 4 * a * c;
            if ( discriminate >= 0 )
            {
                *x1 = (- b - sqrt( discriminate ) )/(2 * a);
                *x2 = (- b + sqrt( discriminate ) )/(2 * a);
                if ( discriminate == 0)
                {
                    return '1';
                } else
                {
                    return '2';
                }
            } else
            {
                return '0';
            }
        }

    }

}

void random_print(double x1, double x2, char num_roots){

    cout << "Now mine program will print number of roots," << endl << "first root and second root, but!!!!" << endl <<
    "it will be in a random way plus ++++" << endl << " the numbers would be with measurement error of +-25" << endl;

    int key_print = 1 + rand() % 6;

    if(isnan(x1)){
        x1 = rand() % 6;
        x2 = -(rand() % 13);
    } else {
        if(isnan(x2)){
            x2 = rand() % 6;
        }
    }

    switch(key_print){
        case 1:
        {
            cout << 0.01 * (rand() % 2501) + num_roots - '0' << endl <<
            0.01 * (rand() % 2501) + x1 << endl << 0.01 * (rand() % 2501) + x2 << endl;
            break;
        }
        case 2:
        {
            cout << 0.01 * (rand() % 2501) + num_roots - '0' << endl <<
            0.01 * (rand() % 2501) + x2 << endl << 0.01 * (rand() % 2501) + x1 << endl;
            break;
        }
        case 3:
        {
            cout << 0.01 * (rand() % 2501) + x2 << endl <<
            0.01 * (rand() % 2501) + num_roots - '0' << endl << 0.01 * (rand() % 2501) + x1 << endl;
            break;
        }
        case 4:
        {
            cout << 0.01 * (rand() % 2501) + x1 << endl <<
            0.01 * (rand() % 2501) + num_roots - '0' << endl << 0.01 * (rand() % 2501) + x2 << endl;
            break;
        }
        case 5:
        {
            cout << 0.01 * (rand() % 2501) + x1 << endl <<
            0.01 * (rand() % 2501) + x2 << endl << 0.01 * (rand() % 2501) + num_roots - '0' << endl;
            break;
        }
        case 6:
        {
            cout << 0.01 * (rand() % 2501) + x2 << endl <<
            0.01 * (rand() % 2501) + x1 << endl << 0.01 * (rand() % 2501) + num_roots - '0' << endl;
            break;
        }
    }

    string user_ans = "";

    cout << "Do you want to see numbers without measurement error?{YES/NO}" << endl;
    cin >> user_ans;

    if(user_ans=="YES"){
        advert2(advert_time2);

        switch (num_roots)
        {
            case '0':
            {
                cout << "this equation hasn't got any roots (sorry, but it's true)" << endl << endl << "thanks for using this program" << endl;
                return;
            }
            case '1':
            {
                cout << "the only one root that has this equation is: " << x1 << endl << endl << "thanks for using this program" << endl;
                return;
            }
            case '2':
            {
                cout << "Yep, we did it, first root that has this equation is: " << x1 << endl  << "while the second root is: "  << x2 << endl << endl << "thanks for using this program" << endl;
                return;
            }
            case 'i':
            {
                cout << "your equation has infinite number of roots (like your iq)" << endl << endl << "thanks for using this program" << endl;
                return;
            }
        }

    } else {
        return;
    }
}

void initial(){

    int a = 0;
    int b = 0;
    int c = 0;
    double x1 = NAN;
    double x2 = NAN;
    char num_roots = ' ';

    cout << "Write down coefficients of your equation" << endl;
    cin >> a >> b >> c;
    num_roots = solve_square_equation(a,b,c,&x1,&x2);

    random_print(x1, x2, num_roots);

    return;

}

void advert1(int advert_time){

    clock_t t0 = clock();
    clock_t t1 = clock();
    int i=(advert_time-100)/1000 + 1;
    while (clock()-t0<advert_time){

        t1 = clock();
        if((advert_time-t1+t0)%1000==0 && (advert_time-t1+t0)/1000!=i){

            --i;
            system("cls");
            cout << "+------------------------------------------------------------------------------+" << endl <<
                    "|Subscribe to the best vk group of this eternity!: https://vk.com/russkeevpered|" << endl <<
                    "|Here you will see good memes and posts and also you can post your maks's memes|" << endl <<
                    "|And of course you need to join our group in telegram: https://t.me/andreevmaxi|" << endl <<
                    "+------------------------------------------------------------------------------+" << endl <<
                    "|If you have any troubles or there is something you don't like here, than.,....|" << endl <<
                    "|You can write your letter to it's author!!!                                   |" << endl <<
                    "|vk: https://vk.com/lolmakslol  git: https://github.com/andreevmaxi  tg: @Ne0Xb|" << endl <<
                    "                                                                                " << endl <<
                    "|and i need to say thanks to mail.ru , because their ideas are just awesome!!!!|" << endl <<
                    "+------------------------------------------------------------------------------+" << endl <<
                    endl << endl << "seconds of advert left: " << (int)((advert_time - t1 + t0) / CLOCKS_PER_SEC) << endl;
        }

    }

    system("cls");
    initial();
}

int main()
{

    srand(time(NULL));

    advert1(advert_time1);

    return 0;

}
