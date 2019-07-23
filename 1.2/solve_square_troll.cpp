#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <float.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>

const int advert_time1 = 10100;
const int advert_time2 = 20100;

void advert2(int advert_time);

char SolveSquareEquation(int a, int b, int c, double* x1, double* x2);

void RandomPrint(double x1, double x2, char num_roots);

void initial();

void advert1(int advert_time);

int main()
{

    srand(time(NULL));

    advert1(advert_time1);

    return 0;

}
void advert2(int advert_time){

    clock_t t0 = clock();
    clock_t t1 = clock();

    int i = ( advert_time - 100 ) / 1000 + 1;

    while ( clock()-t0 < advert_time ){

        t1 = clock();
        if(( advert_time - t1 + t0 ) % 1000 == 0 && ( advert_time - t1 + t0) / 1000 != i){

            --i;
            system("cls");
            std::cout << "+------------------------------------------------------------------------------+" << std::endl <<
                    "|Sorry for this adverts, but we needed some money to live as we want, so sorryy|" << std::endl <<
                    "|also i need money to buy learning in mipt, because i don't know do i pass to  |" << std::endl <<
                    "|grand or not, and if not it will be very very bad                             |" << std::endl <<
                    "+------------------------------------------------------------------------------+" << std::endl <<
                    "|I know that you wouldn't read this at all, but i am doing it in 1:08, you ask |" << std::endl <<
                    "|me why? But the answer is easy, because i was going to my home,from 2ka of    |" << std::endl <<
                    "|mipt and i need to do more than 2 more homeworks and i need to do them good   |" << std::endl <<
                    "|and i am doing them, but i have less and less time, so i am doing it right now|" << std::endl <<
                    "|so another time sorry, i want 2 sleep, but i need to code(time: 1:11)(help me)|" << std::endl <<
                    "+------------------------------------------------------------------------------+" << std::endl <<
                    std::endl << std::endl << "seconds of advert left: " << (int)((advert_time - t1 + t0) / CLOCKS_PER_SEC) << std::endl;

        }

    }

    system("cls");
}

char SolveSquareEquation(int a, int b, int c, double* x1, double* x2){
    assert(x1 != NULL);
    assert(x2 != NULL);

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
            double discriminate = 0;
            discriminate = b * b - 4 * a * c;
            if ( discriminate >= 0 )
            {
                *x1 = (- b - sqrt( discriminate ) )/(2 * a);
                *x2 = (- b + sqrt( discriminate ) )/(2 * a);
                if ( x2 - x1 < 0.0001 )
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

void RandomPrint(double x1, double x2, char num_roots){

    std::cout << "Now mine program will print number of roots," << std::endl << "first root and second root, but!!!!" << std::endl <<
    "it will be in a random way plus ++++" << std::endl << " the numbers would be with measurement error of +-25" << std::endl;

    int key_print = 1 + rand() % 6;

    if(std::isnan(x1)){
        x1 = rand() % 6;
        x2 = -(rand() % 13);
    } else {
        if(std::isnan(x2)){
            x2 = rand() % 6;
        }
    }

    switch(key_print){
        case 1:
        {
            std::cout << 0.01 * (rand() % 2501) + num_roots - '0' << std::endl <<
            0.01 * (rand() % 2501) + x1 << std::endl << 0.01 * (rand() % 2501) + x2 << std::endl;
            break;
        }
        case 2:
        {
            std::cout << 0.01 * (rand() % 2501) + num_roots - '0' << std::endl <<
            0.01 * (rand() % 2501) + x2 << std::endl << 0.01 * (rand() % 2501) + x1 << std::endl;
            break;
        }
        case 3:
        {
            std::cout << 0.01 * (rand() % 2501) + x2 << std::endl <<
            0.01 * (rand() % 2501) + num_roots - '0' << std::endl << 0.01 * (rand() % 2501) + x1 << std::endl;
            break;
        }
        case 4:
        {
            std::cout << 0.01 * (rand() % 2501) + x1 << std::endl <<
            0.01 * (rand() % 2501) + num_roots - '0' << std::endl << 0.01 * (rand() % 2501) + x2 << std::endl;
            break;
        }
        case 5:
        {
            std::cout << 0.01 * (rand() % 2501) + x1 << std::endl <<
            0.01 * (rand() % 2501) + x2 << std::endl << 0.01 * (rand() % 2501) + num_roots - '0' << std::endl;
            break;
        }
        case 6:
        {
            std::cout << 0.01 * (rand() % 2501) + x2 << std::endl <<
            0.01 * (rand() % 2501) + x1 << std::endl << 0.01 * (rand() % 2501) + num_roots - '0' << std::endl;
            break;
        }
    }

    std::string user_ans = "";

    std::cout << "Do you want to see numbers without measurement error?{YES/NO}" << std::endl;
    std::cin >> user_ans;

    if(user_ans=="YES"){
        advert2(advert_time2);

        switch (num_roots)
        {
            case '0':
            {
                std::cout << "this equation hasn't got any roots (sorry, but it's true)" << std::endl << std::endl << "thanks for using this program" << std::endl;
                return;
            }
            case '1':
            {
                std::cout << "the only one root that has this equation is: " << x1 << std::endl << std::endl << "thanks for using this program" << std::endl;
                return;
            }
            case '2':
            {
                std::cout << "Yep, we did it, first root that has this equation is: " << x1 << std::endl  << "while the second root is: "  << x2 << std::endl << std::endl << "thanks for using this program" << std::endl;
                return;
            }
            case 'i':
            {
                std::cout << "your equation has infinite number of roots (like your iq)" << std::endl << std::endl << "thanks for using this program" << std::endl;
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

    std::cout << "Write down coefficients of your equation" << std::endl;
    std::cin >> a >> b >> c;
    num_roots = SolveSquareEquation(a,b,c,&x1,&x2);

    RandomPrint(x1, x2, num_roots);

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
            std::cout << "+------------------------------------------------------------------------------+" << std::endl <<
                    "|Subscribe to the best vk group of this eternity!: https://vk.com/russkeevpered|" << std::endl <<
                    "|Here you will see good memes and posts and also you can post your maks's memes|" << std::endl <<
                    "|And of course you need to join our group in telegram: https://t.me/andreevmaxi|" << std::endl <<
                    "+------------------------------------------------------------------------------+" << std::endl <<
                    "|If you have any troubles or there is something you don't like here, than.,....|" << std::endl <<
                    "|You can write your letter to it's author!!!                                   |" << std::endl <<
                    "|vk: https://vk.com/lolmakslol  git: https://github.com/andreevmaxi  tg: @Ne0Xb|" << std::endl <<
                    "                                                                                " << std::endl <<
                    "|and i need to say thanks to mail.ru , because their ideas are just awesome!!!!|" << std::endl <<
                    "+------------------------------------------------------------------------------+" << std::endl <<
                    std::endl << std::endl << "seconds of advert left: " << (int)((advert_time - t1 + t0) / CLOCKS_PER_SEC) << std::endl;
        }

    }

    system("cls");
    initial();
}
