#include <iostream>
#include <cmath>

void zad1() {
    double N, x, y;
    std::cout << "Enter N, x and y (separed by spaces): ";
    std::cin >> N >> x >> y;

    if (((x * y) < N*N) || -(x * y) >= N*N)
        std::cout << "In" << std::endl;
    else if (((x * y) == N*N) || -(x * y) == N*N)
        std::cout << "On" << std::endl;
    else if (((x * y) > N*N) || -(x * y) < N*N)
        std::cout << "Out" << std::endl;
    else
    {
        if ((x*x + y*y) < N*N)
            std::cout << "In" << std::endl;
        else if ((x*x + y*y) > N*N)
            std::cout << "Out" << std::endl;
        else if ((x*x + y*y) == N*N)
            std::cout << "On" << std::endl;
    }
}

int andAll(int m, int n) {
    int result = m;
    for (int i = m + 1; i <= n; ++i) {
        result = result & i;
    }
    return result;
}

void zad2() {
    int n = 0;
    std::cout << "Enter N: ";
    std::cin >> n;
    int p1 = 0;
    int p2 = 0;
    for (int i = 2; i <= n/2; ++i)
    {
        if (n % i != 0) {
            if (p1 == 0)
                p1 = i;
            else if (p2 == 0)
                p2 = i;
        }
        
        if (p1 != 0 && p2 != 0) {
            std::cout << andAll(p1, p2) << std::endl;
            p1 = 0;
            p2 = 0;
        }
    }
}

int zad3() {
    /*Фрагментът код взима 2 числа и ги използва за намиране на n-тия корен на k.
      Операцията се извършва докато не се намери стойност с точност до `check`.
      Кодът работи, въпреки неясните имена на променливи, защото компилаторът
      не се интересува от тях. float-овете, дефинирани без десетична стойност,
      се допълват от компилатора, заради уточнението `.f`. Най-големият проблем
      на кода е негоата нечитимост и липсата на контекст.*/
	double root_to_find;
	int number;
	std::cin >> root_to_find >> number;

	const double precision_check = 0.0000001;
	float step_size = 1.0f;
	float result = root_to_find / double(number);
	double difference = 0.0f;
	int error_direction = 1;
	
	do {
		float temp_result = 1.0f;
		for (int i = 0; i < number; i++) {
			temp_result *= result;
		}
		difference = temp_result - root_to_find;
		const int current_state = (difference > 0.f) - (difference < 0);

		if (current_state != error_direction) {
			step_size *= 0.75;
			error_direction = current_state;
		}
		
		if (difference > 0.f) {
			result *= 1.0f/(1 + step_size);
		} else {
			result *= (1.0f + step_size);
		}
	} while(precision_check < fabs(difference)); // 

	std::cout << result;

	return 0;
}

/*Функцията пресмята числата от 1 до `N`, но не връщаше стойност.
  Също така имаше излишна променлива, когато директно може да се
  върне `s`. g++ не иска да компилира командата - дава следната
  грешка: The token '&&' is not a valid statement separator in this version.*/
int sum(int N, int s = 0) {
    if (N == 0)
        return s;
    else
        return sum(N - 1, s + N);
}

int main() {
    std::cout << sum(6);
    return 0;
}